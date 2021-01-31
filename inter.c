#include <unistd.h>
int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}
int ft_strnchar(char c, char *str, int len)
{
    int i = 0;
    while (i < len)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
int main(int argc, char *argv[])
{
    int i = 0;
	int	len1;
	int	len2;
	
    if (argc == 3)
    {
		len1 = ft_strlen(argv[1]);
    	len2 = ft_strlen(argv[2]);
    	while(i < len1)
    	{
        	if (ft_strnchar(argv[1][i], argv[2], len2) && !(ft_strnchar(argv[1][i], argv[1], i)))
            	write(1, &argv[1][i], 1);
            	i++;
    	}
    }
    write(1, "\n", 1);
}