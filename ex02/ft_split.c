#include <stdlib.h>
static int	is_separator(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	while (*str != '\0')
	{
		if (!is_separator(*str, charset))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}
static char	*copy_words(char *start, char *end)
{
	char	*word;
	int		len;
	int		i;

	len = end - start + 1;
	word = (char *)malloc(len * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*start;
	int		word_count;
	int		i;

	word_count = count_words(str, charset);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*str != '\0')
	{
		while (is_separator(*str, charset) && *str)
			str++;
		start = str;
		while (*str && is_separator(*str, charset))
			str++;
		if (start != str)
		{
			result[i] = copy_words(start, str);
			if (!result[i])
				return (NULL);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
static void	free_result(char **str)
{
	char	**temp;

	if (!str)
		return ;
	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}
#include <stdio.h>
int	main()
{
	char *str = "Deepseek is greater than ChatGPT";
	char *charset = " ";
	char **result = ft_split(str, charset);
	int	i;

	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("%d: %s\n", i, result[i]);
			i++;
		}
		free_result(result);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
