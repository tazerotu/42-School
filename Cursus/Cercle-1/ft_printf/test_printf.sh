#!/bin/bash

make re
echo "int main(void) " > main.c
echo "{" >> main.c
echo "	int	i;" >> main.c
echo "	i = 0;" >> main.c
echo "	i = ft_printf("'"%s%d", "ceci est un nombre de test : "'", -123456789);" >> main.c
echo "	ft_printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = ft_printf("'"ceci est un nombre de test : %i"'", -123456789);" >> main.c
echo "	ft_printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = ft_printf("'"ceci est un nombre de test : %u"'", -123456789);" >> main.c
echo "	ft_printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = ft_printf("'"ceci est un nombre Hexa de test : %x"'", -123456789);" >> main.c
echo "	ft_printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = ft_printf("'"ceci est un nombre Hexa de test : %X"'", -123456789);" >> main.c
echo "	ft_printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = ft_printf("'"pointeur :%p"'", "'"NULL"'");" >> main.c
echo "	ft_printf("'"	|	Return : %d\n\n"'", i);'" >> main.c
echo "	printf("'"Ceci est la reference :\n"'");" >> main.c
echo "	i = printf("'"%s%d:"'", "'"ceci est un nombre de test : "'", -123456789);" >> main.c
echo "	printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = printf("'"ceci est un nombre de test : %i"'", -123456789);" >> main.c
echo "	printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = printf("'"ceci est un nombre de test : %u"'", -123456789);" >> main.c
echo "	printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	i = printf("'"ceci est un nombre Hexa de test : %x"'", -123456789);" >> main.c
echo "	printf("'	|	Return : %d\n'", i);" >> main.c
echo "	i = printf("'ceci est un nombre Hexa de test : %X'", -123456789);" >> main.c
echo "	printf("'	|	Return : %d\n'", i);" >> main.c
echo "	i = printf("'"pointeur :%p"'", "'"NULL"'");" >> main.c
echo "	printf("'"	|	Return : %d\n"'", i);" >> main.c
echo "	return (0);" >> main.c
echo "}" >> main.c

cc main.c libftprintf.a


