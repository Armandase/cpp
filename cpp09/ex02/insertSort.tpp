#ifndef INSERT_SORT_TPP
#define INSERT_SORT_TPP

template <typename T>

void	insertSort(T array, int end)
{
	int	i = 1;
	while (i < end)
	{
		int	j = i;
		while (j > 0  && array[(j - 1)] > array[j])
		{
			std::swap(array[j], array[j - 1]);
			j--;
		}
		i++;
	}
}

#endif
