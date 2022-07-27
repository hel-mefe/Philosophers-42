#include "philo.h"

void	get_err(char *err)
{
	int	i;

	i = 0;
	while (err[i])
	{
		write(1, &err[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	*alloc_mem(int bytes, int size)
{
	void	*mem;

	mem = malloc (bytes * size);
	if (!mem)
		get_err(ALLOC_ERR);
	return (mem);
}
