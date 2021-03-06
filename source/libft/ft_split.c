#include "libft.h"

/*
 * @brief free all alocated pointer in split
 * 
 * @param arr pointer to pointers (array of strings)
 */
static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*
**	@brief	counts the number of substrings in a string
**	
**	@param	s		pointer to string
**	@param	c		delimiter character
**	@return	size_t	counts substrings
*/
static size_t	ft_count(char *s, char c)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			cnt++;
		s++;
	}
	return (cnt);
}

/*
**	@brief	creates array of strings obtained by splitting āsā 
**			using the character ācā as a delimiter.
**	
**	@param	s		pointer to string
**	@param	c		delimiter character
**	@return	char**	pointer to new array of strings, terminated by a NULL
*/
char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;
	size_t	row;

	row = 0;
	out = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!out)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		out[row] = ft_substr(s, 0, i);
		if (!out[row++])
			ft_free_split(out);
		s += i;
	}
	out[row] = NULL;
	return (out);
}
