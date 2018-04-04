/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:19:50 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/21 17:37:24 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>

void	memset_test(void)
{
	char *test = "This is test string";
	char *buf1 = strdup(test);
	char *buf2 = strdup(test);
	int i = -1;
	while (++i < 300)
	{
		memset(buf1, i, strlen(test));
		ft_memset(buf2, i, strlen(test));
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memset('%s', %c, %zu): '%s' <=> '%s'\n",
			test, i, strlen(test), buf2, buf1);
	}
}

void	bzero_test(void)
{
	struct example
	{
		char	*s;
		int		len;
	};
	struct example test[] =	{
								"abcdefgh", 9,
								"", 1,
								"\0", 1,
								"\0\0\0", 3,
								"abc\0\0abc\0", 6
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	char *buf1;
	char *buf2;
	while (++i < count)
	{
		buf1 = strdup(test[i].s);
		buf2 = strdup(test[i].s);
		bzero(buf1, test[i].len);
		ft_bzero(buf2, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_bzero('%s'): '%s' <=> '%s'\n",
			test[i].s, buf2, buf1);
	}
}

void	memcpy_test(void)
{
	char *test[] =	{
						"This is string0rrr",
						"This is string0",
						"This is string2",
						"This is string22",
						"This",
						"This is string5",
						"This is ",
						"is string7",
						"This is string8test",
						"This is string8test"
					};
	int count = sizeof(test) / sizeof(test[0]);
	char *buf1 = malloc(sizeof(char) * 25);
	char *buf2 = malloc(sizeof(char) * 25);
	int i = -1;
	while (++i < count)
	{
		buf1 = memcpy(buf1, test[i], strlen(test[i]));
		buf2 = ft_memcpy(buf2, test[i], strlen(test[i]));
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memcpy('', '%s', %zu): '%s' <=> '%s'\n",
			test[i], strlen(test[i]), buf1, buf2);
	}
}

void	memccpy_test(void)
{
	struct example
	{
		char	*s;
		char	c;
		int		len;
	};
	struct example test[] =	{
								"This is string1", 's', 15,
								"This is string1", 'r', 15,
								"This is string1", 'l', 15,
								"This is string1", '1', 15,
								"This is string1", '\0', 15
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	char buf1[100] = "";
	char buf2[100] = "";
	while (++i < count)
	{
		memccpy(buf1, test[i].s, test[i].c, test[i].len);
		ft_memccpy(buf2, test[i].s, test[i].c, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_memccpy('', '%s', %c, %i): '%s' <=> '%s'\n",
			test[i].s, test[i].c, test[i].len, buf2, buf1);
	}
}

void	memmove_test(void)
{
	char	str1[100] = "This is test string!";
	char	str2[100] = "This is test string!";
	char	buf1[100];
	char	buf2[100];

	memmove(&str1[20], &str1[6], 15);
	ft_memmove(&str2[20], &str2[6], 15);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);

	memmove(&str1[2], &str1[6], 10);
	ft_memmove(&str2[2], &str2[6], 10);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);

	memmove(&str1[0], &str1[28], 50);
	ft_memmove(&str2[0], &str2[28], 50);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", str1, str2);
	
	memmove(buf1, str1, 15);
	ft_memmove(buf2, str2, 15);
	if (strcmp(str1, str2) != 0)
		printf("     Fail! ft_memmove: '%s' <=> '%s'\n", buf1, buf2);
}

static int strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	memchr_test(void)
{
	int i = -1;
	char *s1;
	char *s2;
	char *s = "This is string1";
	while (++i < 300)
	{
		s1 = memchr(s, i, 15);
		s2 = ft_memchr(s, i, 15);
		if (strequ(s1, s2) == 0)
			printf("     Fail! ft_memchr('%s', %c, 15): '%s' <=> '%s'\n",
			s, i, s2, s1);
	}
}

void	memcmp_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"This is string0", "This is string0", 15,
								"This is string0", "This is string2", 15,
								"This is string2", "This is string22", 15,
								"This is string22", "This", 15,
								"This", "This is string5", 15,
								"This is string5", "This is ", 15,
								"This is ", "is string7", 15,
								"is string7", "This is string8test", 15,
								"This is string8test", "This is string8test", 15,
								"This", "This ", 3,
								"This", "This ", 4,
								"This", "This ", 5,
								"This", "This ", 6
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int res1 = memcmp(test[i].s1, test[i].s2, test[i].len);
		int res2 = memcmp(test[i].s1, test[i].s2, test[i].len);
		if (res1 != res2)
			printf("     Fail! ft_memcmp('%s', '%s', %i): %i <=> %i\n",
			test[i].s1, test[i].s2, test[i].len, res2, res1);
	}
}

void	strlen_test(void)
{
	char *test[] =	{
						"This is test string!",
						"This",
						"",
						" \t\022",
						0
					};
	int i = -1;
	while (test[++i])
	{
		if (strlen(test[i]) != ft_strlen(test[i]))
			printf("     Fail! ft_strlen('%s'): %zu <=> %zu\n",
			test[i], ft_strlen(test[i]), strlen(test[i]));
	}
}

void	strdup_test(void)
{
	char *test[] =	{
						"String!",
						"",
						" \t\022",
						0
					};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (test[++i])
	{
		char *buf = ft_strdup(test[i]);
		if (strequ(buf, test[i]) != 1)
			printf("     Fail! ft_strdup('%s'): '%s' <=> '%s'\n",
			test[i], buf, test[i]);
	}
}

void	strcpy_test(void)
{
	char *test[] =	{
						"This is test string!",
						"This",
						"Just one more test",
						"",
						" \t\022",
						0
					};
	char buf1[25];
	char buf2[25];
	int i = -1;
	while(test[++i])
	{
		strcpy(buf1, test[i]);
		ft_strcpy(buf2, test[i]);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strcpy('', '%s'): '%s' <=> '%s'\n",
			test[i], buf2, buf1);
	}
}

void	strncpy_test(void)
{
	struct example
	{
		char	*s;
		int		len;
	};
	struct example test[] =	{
								"This is test string!", 25,
								"This", 2,
								"Just one more test", 0,
								"", 0,
								"", 5
							};
	char *buf1;
	char *buf2;
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		buf1 = malloc(sizeof(char) * 25);
		buf2 = malloc(sizeof(char) * 25);
		strncpy(buf1, test[i].s, test[i].len);
		ft_strncpy(buf2, test[i].s, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strncpy('%s', %i): '%s' <=> '%s'\n",
			test[i].s, test[i].len, buf2, buf1);
	}
}

void	strcat_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
	};
	struct example test[] =	{
								"This is ", "test string",
								"This is", "",
								"", "This is",
								"", "",
								" \t\022", "\t\022"
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		char *buf1 = malloc(sizeof(char) * 100);
		char *buf2 = malloc(sizeof(char) * 100);
		strcpy(buf1, test[i].s1);
		strcpy(buf2, test[i].s1);
		strcat(buf1, test[i].s2);
		ft_strcat(buf2, test[i].s2);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strcat('%s', '%s'): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, buf2, buf1);
	}
}

void	strncat_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"This is ", "test string", 5,
								"This is", "", 3,
								"This is", "abcdefghijklmnopqrstuvwxyz", 10,
								"", "This is", 3,
								"", "", 0,
								" \t\022", "\t\022", 1,

							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while(++i < count)
	{
		char *buf1 = malloc(sizeof(char) * 100);
		char *buf2 = malloc(sizeof(char) * 100);
		strcpy(buf1, test[i].s1);
		strcpy(buf2, test[i].s1);
		strncat(buf1, test[i].s2, test[i].len);
		ft_strncat(buf2, test[i].s2, test[i].len);
		if (strcmp(buf1, buf2) != 0)
			printf("     Fail! ft_strncat('%s', '%s', %i): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, test[i].len, buf2, buf1);
	}
}

void	strlcat_test(void)
{
	struct example
	{
		char *dst;
		char *src;
		int n;
	};
	struct example test[] =	{
								"abc", "abc", 3,
								"", "abc", 0,
								"abc", "", 3,
								"", "", 1,
								"This is ", "string1", 5,
								"This is ", "string1", 20,
								"test", "This is string1", 0
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *s1 = strdup(test[i].dst);
		char *s2 = strdup(test[i].dst);
		int r1 = strlcat(s1, test[i].src, test[i].n);
		int r2 = ft_strlcat(s2, test[i].src, test[i].n);
		if (strcmp(s1, s2) != 0 || r1 != r2)
			printf("     Fail! ft_strlcat('%s', '%s'): '%s' = %i <=> '%s' = %i\n",
			test[i].dst, test[i].src, s1, r1, s2, r2);
	}
}

void	strchr_test(void)
{
	char s[] = "This is test string!";
	int i = -1;
	while (++i < 300)
	{
		char *r1 = strchr(s, i);
		char *r2 = ft_strchr(s, i);
		if (strequ(r1, r2) != 1)
	 		printf("     Fail! ft_strchr('%s', %i): '%s' <=> '%s'\n",
			s, i, r2, r1);
	}
}

void	strrchr_test(void)
{
	char s[] = "This is test string!";
	int i = -1;
	char *r1;
	char *r2;
	while (++i <= 300)
	{
		r1 = strrchr(s, i);
		r2 = ft_strrchr(s, i);
		if (strequ(r1, r2) != 1)
			printf("     Fail! ft_strrchr('%s', %i): '%s' <=> '%s'\n",
			s, i, r2, r1);
	}
}

void	strstr_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
	};
	struct example test[] =	{
								"This is string0rrr", "This is string0",
								"This is string0", "This is string2",
								"This is string2", "This is string22",
								"This is string22", "This",
								"This", "This is string5",
								"This is string5", "This is ",
								"This is ", "is string7",
								"is string7", "This is string8test",
								"This is string8test", "This is string8test",
								"", "",
								"abc", ""
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r1 = strstr(test[i].s1, test[i].s2);
		char *r2 = ft_strstr(test[i].s1, test[i].s2);
		if (strequ(r1, r2) == 0)
			printf("     Fail! ft_strstr('%s', '%s'): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, r2, r1);
	}
}

void	strnstr_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		n;
	};
	struct example test[] =	{
								"This is test string", "is", 19,
								"This is test string", "", 20,
								"This is test string", "This is test strin1", 19,
								"This is test string", "This is test string", 19,
								"This is test string", "This is test string", 18,
								"This is test string", "test", 11,
								"This is test string", "test", 12,
								"", "", 1,
								"", "", 0,
								"abc", "", 0,
								"abc", "", 3
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r1 = strnstr(test[i].s1, test[i].s2, test[i].n);
		char *r2 = ft_strnstr(test[i].s1, test[i].s2, test[i].n);
		if (strequ(r1, r2) == 0)
			printf("     Fail! ft_strnstr('%s', '%s', %i): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, test[i].n, r2, r1);
	}
}

void	strcmp_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
	};
	struct example test[] =	{
								"abc", "abc",
								"", "abc",
								"abc", "abcd",
								"abcd", "abc",
								"This", "This is string5",
								"This is string5", "string5",
								"", ""
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r1 = strcmp(test[i].s1, test[i].s2);
		int r2 = ft_strcmp(test[i].s1, test[i].s2);
		if (r1 != r2)
			printf("     Fail! ft_strcmp('%s', '%s'): %i <==> %i\n",
			test[i].s1, test[i].s2, r2, r1);
	}
}

void	strncmp_test(void)
{
	struct example
	{
		char	*s1;
		char	*s2;
		int		len;
	};
	struct example test[] =	{
								"abc", "abc", 3,
								"", "abc", 1,
								"abc", "abcd", 4,
								"abcd", "abc", 3,
								"This", "This is string5", 5,
								"This is string5", "string5", 25,
								"This is test string", "is", 19,
								"This is test string", "", 20,
								"This is test string", "This is test strin1", 19,
								"This is test string", "This is test string", 19,
								"This is test string", "This is test string", 18,
								"This is test string", "test", 11,
								"This is test string", "test", 12,
								"", "", 3
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r1 = strncmp(test[i].s1, test[i].s2, test[i].len);
		int r2 = ft_strncmp(test[i].s1, test[i].s2, test[i].len);
		if (r1 != r2)
			printf("     Fail! ft_strncmp('%s', '%s', %i): %i <==> %i\n",
			test[i].s1, test[i].s2, test[i].len, r2, r1);
	}
}

void	atoi_test(void)
{
	char *test[] =	{
						"2147483647",
						"-2147483648",
						"-210",
						"-2147bbb483648",
						"+2",
						"0",
						"-0",
						"+0",
						"++20",
						"--2",
						"\r\f\v\t\n 567 567 ",
						"922337203685477580",
						"-922337203685477580",
						"9223372036854775807",
						"9223372036854775808",
						"-9223372036854775807",
						"-9223372036854775808",
						"19223372036854775807",
						"-19223372036854775808",
						0
					};

	int i = -1;
	while (test[++i])
	{
		if (atoi(test[i]) != ft_atoi(test[i]))
			printf("     Fail! ft_atoi('%s'): %d <=> %d\n", test[i], ft_atoi(test[i]), atoi(test[i]));
	}
}

void	isalpha_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isalpha(i) != ft_isalpha(i))
			printf("     Fail! ft_isalpha(%i): %i <=> %i\n",
			i, ft_isalpha(i), isalpha(i));
}

void	isdigit_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isdigit(i) != ft_isdigit(i))
			printf("     Fail! ft_isdigit(%i): %i <=> %i\n",
			i, ft_isdigit(i), isdigit(i));
}

void	isalnum_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isalnum(i) != ft_isalnum(i))
			printf("     Fail! ft_isalnum(%i): %i <=> %i\n",
			i, ft_isalnum(i), isalnum(i));
}

void	isascii_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isascii(i) != ft_isascii(i))
			printf("     Fail! ft_isascii(%i): %i <=> %i\n",
			i, ft_isascii(i), isascii(i));
}

void	isprint_test(void)
{
	int i = -300;
	while (++i < 300)
		if (isprint(i) != ft_isprint(i))
			printf("     Fail! ft_isprint(%i): %i <=> %i\n",
			i, ft_isprint(i), isprint(i));
}

void	toupper_test(void)
{
	int i = -300;
	while (++i < 300)
		if (toupper(i) != ft_toupper(i))
			printf("     Fail! ft_toupper(%c): %c <=> %c\n",
			i, toupper(i), ft_toupper(i));
}

void	tolower_test(void)
{
	int i = -300;
	while (++i < 300)
		if (tolower(i) != ft_tolower(i))
			printf("     Fail! ft_tolower(%c): %c <=> %c\n",
			i, tolower(i), ft_tolower(i));
}

void	memalloc_test(void)
{
	char	*buf1;
	char	*buf2;
	size_t	i;

	i = 0;
	buf1 = (char*)malloc(sizeof(char) * 10000);
	bzero(buf1, 10000);
	buf2 = (char*)ft_memalloc(10000);
	if (strcmp(buf1, buf2) != 0)
		printf("     Fail! ft_memalloc(100): '%s' <=> '%s'\n",
		buf2, buf1);
}

void	memdel_test(void)
{
	char *test[] = {
						"This is string0rrr",
						"This is string0",
						"This is string2",
						"This is string22",
						"This",
						"This is string5",
						"This is ",
						"is string7",
						"This is string8test",
						0
					};
	int i = -1;
	while(test[++i])
	{
		void *buf = strdup(test[i]);
		ft_memdel(&buf);
		if (buf != 0)
			printf("     Fail! ft_memdel('%s'): '%s' <=> (null)\n",
			test[i], buf);
	}
}

void	strnew_test(void)
{
	char	*s;

	s = ft_strnew(100);
	int i = -1;
	while (++i < 100)
		if (s[i] != '\0')
		{
			printf("     Fail! ft_strnew(100): '%s' <=> ''\n",
			s);
			return ;
		}
}

void	strdel_test(void)
{
	char *test[] =	{
						"This is string0rrr",
						"This is string0",
						"This is string2",
						"This is string22",
						"This",
						"This is string5",
						"This is ",
						"is string7",
						"This is string8test",
						0
					};
	int i = -1;
	while (test[++i])
	{
		char *buf = strdup(test[i]);
		ft_strdel(&buf);
		if (buf != NULL)
			printf("     Fail! ft_strdup(%s): %s <=> (null)\n", test[i], buf);
	}
}

void	strclr_test(void)
{
	char buffer[] = "Test";
	int len = strlen(buffer);
	ft_strclr(buffer);
	int i = -1;
	while (++i < len)
		if (buffer[i] != '\0')
		{
			printf("     Fail! ft_strclr('Test'): '%s' <=> ''\n",
			buffer);
			return ;
		}
}

int count;
static void	iter_action(char *c)
{
	count++;
}

void	striter_test(void)
{
	char *buffer;
	buffer = strdup("abcde");
	count = 0;
	ft_striter(buffer, &iter_action);
	if (count != 5)
		printf("     Fail! ft_striter(\"abcde\", f): %i times <=> 5 times\n", count);
}

static void	iteri_action(unsigned int i, char *c)
{
	count += i;
}

void	striteri_test(void)
{
	char *buffer;
	buffer = strdup("abcde");
	count = 0;
	ft_striteri(buffer, &iteri_action);
	if (count != 10)
		printf("     Fail! ft_striteri(\"abcde\", f): %i <=> 10\n", count);
}

static char	map_action(char c)
{
	c += 1;
	return (c);
}

void	strmap_test(void)
{
	char s[] = "abcde";
	char *buf = ft_strmap(s, &map_action);
	if (strequ(buf, "bcdef") != 1)
		printf("     Fail! ft_strmap('%s', f): '%s' <=> 'bcdef'\n",
		s, buf);
}

static char	mapi_action(unsigned int i, char c)
{
	c += i;
	return (c);
}

void	strmapi_test(void)
{
	char s[] = "abcde";
	char *buf = ft_strmapi(s, &mapi_action);
	if (strequ(buf, "acegi") != 1)
		printf("     Fail! ft_strmap('%s', f): '%s' <=> 'acegi'\n",
		s, buf);
}

void	strequ_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
		int	 res;
	};
	struct example test[] =	{
								"This is test string", "This is test string", 1,
								"This is test string1", "This is test string", 0,
								"This is test string", "This is test string1", 0,
								"\220This", "\220This", 1,
								"\220This", "\222This", 0,
								NULL, "", 0,
								"", NULL, 0,
								NULL, NULL, 1
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r = ft_strequ(test[i].s1, test[i].s2);
		if (r != test[i].res)
			printf("     Fail! ft_strequ('%s', '%s'): %i <=> %i\n",
				test[i].s1, test[i].s2, r, test[i].res);
	}
}

void	strnequ_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
		int	 len;
		int	 res;
	};
	struct example test[] =	{
								"This is test string", "This is test string", 19, 1,
								"This is test string1", "This is test string", 19, 1,
								"This is test string", "This is test string1", 20, 0,
								"\220This ", "\220This", 3, 1,
								"\220This ", "\222This", 5, 0,
								NULL, "", 1, 0,
								"", NULL, 1, 0,
								NULL, NULL, 5, 1
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		int r = ft_strnequ(test[i].s1, test[i].s2, test[i].len);
		if (r != test[i].res)
			printf("     Fail! ft_strnequ('%s', '%s', %i): %i <=> %i\n",
				test[i].s1, test[i].s2, test[i].len, r, test[i].res);
	}
}

void	strsub_test(void)
{
	struct example
	{
		char *s;
		int p;
		int	n;
		char *res;
	};
	struct example test[] =	{
								"This is test string", 1, 3, "his",
								NULL, 1, 3, NULL,
								"Test", 0, 10, "Test",
								"Test", 0, 0, ""
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r = ft_strsub(test[i].s, test[i].p, test[i].n);
		if (strequ(r, test[i].res) != 1)
			printf("     Fail! ft_strsub('%s', %i, %i): '%s' <=> '%s'\n",
				test[i].s, test[i].p, test[i].n, r, test[i].res);
	}
}

void	strjoin_test(void)
{
	struct example
	{
		char *s1;
		char *s2;
		char *res;
	};
	struct example test[] =	{
								"abc", "abc", "abcabc",
								"", "abc", "abc",
								"abc", "", "abc",
								"", "", "",
								NULL, "abc", "abc",
								"abc", NULL, "abc",
								NULL, NULL, NULL
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r = ft_strjoin(test[i].s1, test[i].s2);
		if (strequ(r, test[i].res) != 1)
			printf("     Fail! ft_strjoin('%s', '%s'): '%s' <=> '%s'\n",
			test[i].s1, test[i].s2, r, test[i].res);
	}
}

void	strtrim_test(void)
{
	struct example
	{
		char *s;
		char *res;
	};
	struct example test[] =	{
								"abc", "abc",
								"  \t\t\n\t   \t\ntest \n\n\t   \t\n  ", "test",
								"  \t\v\r\f test\n", "\v\r\f test",
								"   a b c   ", "a b c",
								"    a c", "a c",
								NULL, NULL
							};
	int count = sizeof(test) / sizeof(test[0]);
	int i = -1;
	while (++i < count)
	{
		char *r = ft_strtrim(test[i].s);
		if (strequ(r, test[i].res) != 1)
			printf("     Fail! ft_strtrim('%s'): '%s' <=> '%s'\n",
			test[i].s, r, test[i].res);
	}
}

void	strsplit_test(void)
{
	struct example
	{
		char *s;
		char sep;
	};
	struct example test[] =	{
								"***This*is***test******string*******", '*',
								"This*is***test******string", '*',
								"***This*is***test******string", '*',
								"This*is***test******string", '*',
								"This is test", '*',
								NULL, ' '
							};
	char *res0[] =	{ "This", "is", "test", "string", 0 };
	char *res1[] =	{ "This is test", 0 };
	char *res2[] =	{ 0 };
	int i = -1;
	char **r = ft_strsplit(test[0].s, test[0].sep);
	while (res0[++i])
	{
		if (strequ(res0[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[0].s, test[0].sep, i, r[i], res0[i]);
	}
	i = -1;
	r = ft_strsplit(test[1].s, test[1].sep);
	while (res0[++i])
	{
		if (strequ(res0[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[1].s, test[1].sep, i, r[i], res0[i]);
	}
	i = -1;
	r = ft_strsplit(test[2].s, test[2].sep);
	while (res0[++i])
	{
		if (strequ(res0[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[2].s, test[2].sep, i, r[i], res0[i]);
	}
	i = -1;
	r = ft_strsplit(test[3].s, test[3].sep);
	while (res0[++i])
	{
		if (strequ(res0[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[3].s, test[3].sep, i, r[i], res0[i]);
	}
	i = -1;
	r = ft_strsplit(test[4].s, test[4].sep);
	while (res1[++i])
	{
		if (strequ(res1[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[4].s, test[4].sep, i, r[i], res1[i]);
	}
	i = -1;
	r = ft_strsplit(test[5].s, test[5].sep);
	while (res2[++i])
	{
		if (strequ(res2[i], r[i]) != 1)
			printf("     Fail! ft_strsplit('%s', %c): res[%i] = '%s' <=> '%s'\n",
			test[5].s, test[5].sep, i, r[i], res2[i]);
	}
}

void	itoa_test(void)
{
	int test[] = 	{
						-2147483648,
						-2147483647,
						-1234567
						-123,
						-0,
						0,
						123,
						123456,
						2147483647
					};

	int i = -1;
	int count = sizeof(test) / sizeof(test[0]);
	while (++i < count)
	{
		if (atoi(ft_itoa(test[i])) != test[i])
			printf("     Fail! ft_itoa(%i): '%s' <=> '%i'\n",
			test[i], ft_itoa(test[i]), test[i]);
	}
}

void	putchar_test(void)
{
	char	buffer[] = "PUTHCAR TESTING...\n";
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		ft_putchar(buffer[i]);
		i++;
	}
}

void	putstr_test(void)
{
	ft_putstr("PUTSTR TESTING...\n");
}

void	putendl_test(void)
{
	ft_putendl("PUTENDL TESTING...");
}

void	putnbr_test(void)
{
	ft_putstr("     TEST1: -2147483648 ");
	ft_putnbr(-2147483648);
	ft_putstr("\n     TEST2: 2147483647 ");
	ft_putnbr(2147483647);
	ft_putstr("\n     TEST3: -2147 ");
	ft_putnbr(-2147);
	ft_putstr("\n     TEST4: 0 ");
	ft_putnbr(0);
	ft_putstr("\n     TEST5: 1232147 ");
	ft_putnbr(1232147);
	ft_putstr("\n");
}

void	putchar_fd_test(void)
{
	int		fd;
	char	buffer[1];

	fd = open("putchar_fd.txt", O_RDWR | O_CREAT, 0777);
	ft_putchar_fd('a', fd);
	close(fd);
	fd = open("putchar_fd.txt", O_RDWR);
	read(fd, buffer, 1);
	if (buffer[0] != 'a')
		printf("     Fail! ft_putchar_fd('a'): '%c' <=> 'a'\n", buffer[0]);
	close(fd);
}

void	putstr_fd_test(void)
{
	int		fd;
	char	buffer[9];

	fd = open("putstr_fd.txt", O_RDWR | O_CREAT, 0777);
	ft_putstr_fd("Success!", fd);
	close(fd);
	fd = open("putstr_fd.txt", O_RDWR);
	read(fd, buffer, 8);
	if (strcmp(buffer, "Success!") != 0)
		printf("     Fail! ft_putstr_fd('Success!'): '%s' <=> 'Success!'\n", buffer);
	close(fd);
}

void	putendl_fd_test(void)
{
	int		fd;
	char	buffer[10];

	fd = open("putendl_fd.txt", O_RDWR | O_CREAT, 0777);
	ft_putendl_fd("Success!", fd);
	close(fd);
	fd = open("putendl_fd.txt", O_RDWR);
	read(fd, buffer, 10);
	if (strcmp(buffer, "Success!\n") != 0)
		printf("     Fail! ft_putendl_fd('Success!'): '%s' <=> 'Success!\n'\n", buffer);
	close(fd);
}

void	putnbr_fd_test(void)
{
	int		fd;
	char	buffer[12];

	fd = open("putnbr_fd.txt", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	fd = open("putnbr_fd.txt", O_RDWR);
	read(fd, buffer, 11);
	if (strequ(buffer, "-2147483648") != 1)
		printf("     Fail! ft_putnbr_fd(-2147483648): '%s' <=> '-2147483648'\n", buffer);
	close(fd);
}

void	lstnew_test(void)
{
	t_list	*elem;

	elem = NULL;
	elem = ft_lstnew("String1", 7);
	if (elem == NULL || strcmp(elem->content, "String1") != 0 || elem->next != NULL || elem->content_size != 7)
		printf("     Fail! ft_lstnew(\"String1\", 7): %s->%s <=> String1->(null)\n", (char*)elem->content, (char*)elem->next);
}

void	lstadd_test(void)
{
	t_list	*elem;

	elem = ft_lstnew("String1", 10);
	ft_lstadd(&elem, ft_lstnew("String2", 10));
	ft_lstadd(&elem, ft_lstnew("String3", 10));
	if (strcmp(elem->content, "String3") != 0 ||
			strcmp(elem->next->content, "String2") ||
			strcmp(elem->next->next->content, "String1") ||
			elem->next->next->next != NULL)
		printf("     Fail! %s->%s->%s->%s\n", elem->content, elem->next->content, elem->next->next->content,
				(char *)elem->next->next->next);
}

static void	ft_memset_test(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n - 1)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	lstdel_test(void)
{
	t_list	*ptr1 = ft_lstnew("String1", 16);
	ptr1->next = ft_lstnew("String2", 16);
	ptr1->next->next = ft_lstnew("String3", 16);
	t_list *ptr2 = ptr1->next;
	t_list *ptr3 = ptr1->next->next;
	ft_lstdel(&ptr1, &ft_memset_test);
	if (ptr1 != NULL)
		printf("     Fail! ft_lstdel(String1->String2->String3): %s -> %s -> %s\n", (char*)ptr1, (char*)ptr2, (char*)ptr3);
}

void	lstdelone_test(void)
{
	t_list	*curr;

	t_list *ptr = ft_lstnew("String1", 16);
	ptr->next = ft_lstnew("String2", 16);
	curr = ptr;
	ft_lstdelone(&ptr, &ft_memset_test);
	if (ptr != NULL || strcmp(curr->next->content, "String2") != 0)
		printf("     Fail! ft_lstdelone(String1->String2): %s->%s <=> (null)->String2\n", (char*)curr, (char*)curr->next->content);
}



static void	change_list(t_list *elem)
{
	char *s = elem->content;
	int i = -1;
	while(++i < 7)
		s[i] = '0';
}

void	lstiter_test(void)
{
	t_list	*elem;
	t_list	*curr;

	elem = ft_lstnew("String1", 10);
	elem->next = ft_lstnew("String2", 10);
	elem->next->next = ft_lstnew("String3", 10);
	curr = elem;
	ft_lstiter(curr, &change_list);
	if (strcmp(curr->content, "0000000") != 0 || strcmp(curr->next->content, "0000000") != 0 || strcmp(curr->next->next->content, "0000000") != 0)
		printf("     Fail! ft_lstiter(String1->String2->String3): %s->%s->%s <=> 0000000->0000000->0000000\n",
		(char*)curr->content, (char*)curr->next->content, (char*)curr->next->next->content);

}

static t_list	*change_data(t_list *elem)
{
	char	*ptr;
	t_list	*newelem;

	ptr = elem->content;
	int i = -1;
	while (++i < 7)
		ptr[i] = '0';
	return (elem);
}

void	lstmap_test(void)
{
	t_list	*elem;
	t_list	*curr;
	t_list	*list;

	elem = ft_lstnew("String1", 16);
	elem->next = ft_lstnew("String2", 16);
	elem->next->next = ft_lstnew("String3", 16);
	curr = elem;
	list = ft_lstmap(curr, &change_data);
	if (strcmp(list->content,"0000000") != 0 || strcmp(list->next->content,"0000000") != 0 || strcmp(list->next->next->content,"0000000") != 0)
		printf("     Fail! ft_lstmap(String1->String2->String3): %s->%s->%s <=> 0000000->0000000->0000000\n",
		(char*)list->content, (char*)list->next->content, (char*)list->next->next->content);
	if (strcmp(curr->content,"String1") != 0 || strcmp(curr->next->content,"String2") != 0 || strcmp(curr->next->next->content,"String3") != 0)
		printf("     Fail! lst: String1->String2->String3 => %s->%s->%s\n",
		(char*)curr->content, (char*)curr->next->content, (char*)curr->next->next->content);
}

int		main(void)
{
	printf("Part 1\n");
	printf("MEMSET TESTING...\n"); memset_test();
	printf("BZERO TESTING...\n"); bzero_test();
	printf("MEMCPY TESTING...\n"); memcpy_test();
	printf("MEMCCPY TESTING...\n"); memccpy_test();
	printf("MEMMOVE TESTING...\n"); memmove_test();
	printf("MEMCHR TESTING...\n"); memchr_test();
	printf("MEMCMP TESTING...\n"); memcmp_test();
	printf("STRLEN TESTING...\n"); strlen_test();
	printf("STRDUP TESTING...\n"); strdup_test();
	printf("STRCPY TESTING...\n"); strcpy_test();
	printf("STRNCPY TESTING...\n"); strncpy_test();
	printf("STRCAT TESTING...\n"); strcat_test();
	printf("STRNCAT TESTING...\n"); strncat_test();
	printf("STRLCAT TESTING...\n"); strlcat_test();
	printf("STRCHR TESTING...\n"); strchr_test();
	printf("STRRCHR TESTING...\n"); strrchr_test();
	printf("STRSTR TESTING...\n"); strstr_test();
	printf("STRNSTR TESTING...\n"); strnstr_test();
	printf("STRCMP TESTING...\n"); strcmp_test();
	printf("STRNCMP TESTING...\n"); strncmp_test();
	printf("ATOI TESTING...\n"); atoi_test();
	printf("ISALPHA TESTING...\n"); isalpha_test();
	printf("ISDIGIT TESTING...\n"); isdigit_test();
	printf("ISALNUM TESTING...\n"); isalnum_test();
	printf("ISASCII TESTING...\n"); isascii_test();
	printf("ISPRINT TESTING...\n"); isprint_test();
	printf("TOUPPER TESTING...\n"); toupper_test();
	printf("TOLOWER TESTING...\n"); tolower_test();
	printf("Part 2\n");
	printf("MEMALLOC TESTING...\n"); memalloc_test();
	printf("MEMDEL TESTING...\n"); memdel_test();
	printf("STRNEW TESTING...\n"); strnew_test();
	printf("STRDEL TESTING...\n"); strdel_test();
	printf("STRCLR TESTING...\n"); strclr_test();
	printf("STRITER TESTING...\n"); striter_test();
	printf("STRITERI TESTING...\n"); striteri_test();
	printf("STRMAP TESTING...\n"); strmap_test();
	printf("STRMAPI TESTING...\n"); strmapi_test();
	printf("STREQU TESTING...\n"); strequ_test();
	printf("STRNEQU TESTING...\n"); strnequ_test();
	printf("STRSUB TESTING...\n"); strsub_test();
	printf("STRJOIN TESTING...\n"); strjoin_test();
	printf("STRTRIM TESTING...\n"); strtrim_test();
	printf("STRSPLIT TESTING...\n"); strsplit_test();
	printf("ITOA TESTING...\n"); itoa_test();
	putchar_test();
	putstr_test();
	putendl_test();
	printf("PUTNBR TESTING...\n"); putnbr_test();
	printf("PUTCHAR_FD TESTING...\n"); putchar_fd_test();
	printf("PUTSTR_FD TESTING...\n"); putstr_fd_test();
	printf("PUTENDl_FD TESTING...\n"); putendl_fd_test();
	printf("PUTNBR_FD TESTING...\n"); putnbr_fd_test();
	printf("Bonus Part\n");
	printf("LSTNEW TESTING...\n"); lstnew_test();
	printf("LSTADD TESTING...\n"); lstadd_test();
	printf("LSTDEL TESTING...\n"); lstdel_test();
	printf("LSTDELONE TESTING...\n"); lstdelone_test();
	printf("LSTITER TESTING...\n"); lstiter_test();
	printf("LSTMAP TESTING...\n"); lstmap_test();
	//system("leaks a.out");
	return (0);
}
