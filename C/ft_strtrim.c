#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen((char *) s1);
	while (i < j && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	if (i > ft_strlen((char *) s1))
		return (ft_strdup(""));
	return (ft_substr(s1, i, (j - i)));
}
