#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct s_arg
{
	int		len;
	int		width;
	int		prec;
	char	type;
	int		minus;	
}			t_arg;

// void put_width(int numlen, t_arg param)
// {
// 	while(param.width > numlen)
// 		ft_putchar(' ', param);
// }

// void put_prec(int nulls, t_arg param)
// {
// 	if 
// }

void	ft_putchar(char c, t_arg *param)
{
	param->len += write(1, &c, 1);
}

int	ft_strlen (char *str);
void putstr (char *str, t_arg *param);
int	ft_numlen(unsigned num, int base)
{
	int len;
	len = 0;
	
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

int ft_atoi(char **str)
{
	int num;
	num = 0;
	
	if (**str == '\0')
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

void ft_putnbr_base(unsigned num, int base, t_arg *param)
{
	char	c;
	
	if (num < base)
	{
		if (num < 10)
			c = num + '0';
		else 
			c = num - 10 + 'a';
		ft_putchar(c, param);
	}
	if (num >= base)
	{
		ft_putnbr_base(num / base, base, param);
		ft_putnbr_base(num % base, base, param);
	}	
}

int	ft_printf(char *str, ...)
{
	t_arg	param;
	va_list	args;
	int numlen;
	int nulls;
	
	param.len = 0;
	param.width = 0;
	param.prec = 0;
	param.minus = 0;
	param.type = 0;
	
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			param.width = ft_atoi(&str);
			if (*str == '.')
			{
				str++;
				param.prec = ft_atoi(&str);
			}
			param.type = *str;
	}
		else
			ft_putchar(*str, &param);
		str++;
	}
	if (param.type == 'd')
	{
		int num = va_arg(args, int);
		nulls = 0;
		if (num < 0)
		{
			param.minus = 1;
			num = -num;
		}
		numlen = ft_numlen(num, 10);
		if (param.minus == 1)
			param.width--;
		if (param.prec > numlen)
		{
			nulls = param.prec - numlen;
			numlen = param.prec;
		}
		while(param.width > numlen)
		{
			ft_putchar(' ', &param);
			numlen++;
		}
		if (param.minus == 1)
			ft_putchar('-', &param);
		while (nulls--)
			ft_putchar('0', &param);
		ft_putnbr_base(num, 10, &param);
	}
	
	
	va_end(args);
	printf("\nwidth[%d] prec[%d] len[%d] type[%c]", param.width, param.prec, param.len, param.type);
	return (param.len);
}

int main (void)
{
	t_arg	param;
	param.len = 0;
	//ft_putnbr_base(125, 10, &param);
	ft_printf("%10.7d\n", -42);
	printf ("\n%10.7d\n", -42);
}
