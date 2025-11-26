#include "../include/cub3d.h"

const char	*skip_ws(const char *s)
{
	while (*s && (unsigned char)*s <= 32)
		s++;
	return (s);
}
int	is_pure_num(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}