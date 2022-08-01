#ifndef FT_MINITALK
# define FT_MINITALK

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_server
{
	int		bit;
	int		counter;
	char	c;
	char	messg[1000000];

}				t_server;

void	ft_initialize(void);
#endif
