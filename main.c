#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		a;

	while((a = get_next_line(&line)) > 0)
	{
		printf("%d: %s\n", a, line);
		free (line);
	}
	printf("%d: %s\n", a, line);
	free (line);
	return (0);
}