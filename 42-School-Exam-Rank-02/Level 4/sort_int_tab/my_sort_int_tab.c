void sort_int_tab(int *tab, unsigned int size)
{
	int i;
	int tmp;

	while (i < (size - 1)
	{
		i = 0;
		if (tab[i] < tab[i + 1])
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;;
		}
	}
}
