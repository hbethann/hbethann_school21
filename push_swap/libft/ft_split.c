/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 06:10:15 by hbethann          #+#    #+#             */
/*   Updated: 2021/11/15 23:21:52 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwords(const char *str, char c)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			ct++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (ct);
}

char	**ft_free(int i, char **str)
{
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
	return (NULL);
}

static char	*ft_create(const char *str, char c)
{
	int		i;
	char	*nstr;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	nstr = malloc(sizeof(char) * (i + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**spstr;
	int		wrds;
	int		i;

	if (!s)
		return (NULL);
	wrds = ft_cwords(s, c);
	spstr = malloc(sizeof(char *) * (wrds + 1));
	if (!spstr)
		return (NULL);
	i = 0;
	while (i < wrds)
	{
		while (*s && *s == c)
			s++;
		spstr[i] = ft_create(s, c);
		if (!spstr[i])
			return (ft_free(i, spstr));
		while (*s && *s != c)
			s++;
		i++;
	}
	spstr[i] = NULL;
	return (spstr);
}
