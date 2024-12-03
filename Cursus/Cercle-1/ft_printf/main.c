int main(void) 
{
	int	i;
	i = 0;
	i = ft_printf("%s%d", "ceci est un nombre de test : ", -123456789);
	ft_printf("	|	Return : %d\n", i);
	i = ft_printf("ceci est un nombre de test : %i", -123456789);
	ft_printf("	|	Return : %d\n", i);
	i = ft_printf("ceci est un nombre de test : %u", -123456789);
	ft_printf("	|	Return : %d\n", i);
	i = ft_printf("ceci est un nombre Hexa de test : %x", -123456789);
	ft_printf("	|	Return : %d\n", i);
	i = ft_printf("ceci est un nombre Hexa de test : %X", -123456789);
	ft_printf("	|	Return : %d\n", i);
	i = ft_printf("pointeur :%p", "NULL");
	ft_printf("	|	Return : %d\n\n", i);'
	printf("Ceci est la reference :\n");
	i = printf(%s%d, ceci est un nombre de test : , -123456789);
	printf(	|	Return : %d\n, i);
	i = printf(ceci est un nombre de test : %i, -123456789);
	printf(	|	Return : %d\n, i);
	i = printf(ceci est un nombre de test : %u, -123456789);
	printf(	|	Return : %d\n, i);
	i = printf(ceci est un nombre Hexa de test : %x, -123456789);
	printf(	|	Return : %d\n, i);
	i = printf(ceci est un nombre Hexa de test : %X, -123456789);
	printf(	|	Return : %d\n, i);
	i = printf("pointeur :%p", "NULL");
	printf("	|	Return : %d\n", i);
	return (0);
}
