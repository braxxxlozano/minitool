#include "minitalk.h"

void	binary_to_text(int signum)
{
	static int	byte;
	static int	i;

	if (signum == SIGUSR1)
		byte |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

static void	get_pid(void)
{
	int	pid;

	pid = getpid();
	if (pid == 0)
		printf ("ERROR");
	else
		printf ("pid %i\n", pid);
}

int	main(void)
{
	get_pid();
	ft_printf("waiting..\n");
	while (1)
	{
		signal(SIGUSR1, bynary_to_text);
		signal(SIGUSR2, bynary_to_text);
		pause();
	}
	return (0);
}
