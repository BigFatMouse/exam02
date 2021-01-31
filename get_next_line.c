#include "get_next_line.h"

// int	get_next_line(char **line)
// {
// 	int	rb;
// 	int	i;
// 	char *temp;
// 	char buff;
	
// 	i = 0;
// 	if (!(temp = malloc(10000)))
// 		return (-1);
// 	*line = temp;
// 	while ((rb = read(0, &buff, 1)) > 0 && buff != '\n' && buff != '\0')
// 	{
// 		temp[i] = buff;
// 		i++;
// 	}
// 	temp[i] = '\0';
// 	if (rb > 0)
// 		return (1);
// 	else 
// 		return (rb);
//  }
 
 
 
 int get_next_line(char **line)
 {
	char *tmp;
	char buff;
	int i;
	int rb;
	 
	i = 0;
	 
	tmp = malloc(100000);
	*line = tmp;
	 
	while ((rb = read(0, &buff, 1)) > 0 && buff != '\n' && buff != '\0')
	{
		tmp[i] = buff;
		i++;
	}
	tmp[i] = '\0';
	if (rb > 0)
	 	return (1);
	else
		return (rb);
 }