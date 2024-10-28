#include "sort.h"

/**
 * bubble_sort - sorts an array by comparing adjacen stuffs.
 * @array: a pointer to array of integers.
 * @size: size of how big is the array.
 */

void bubble_sort(int *array, size_t size)
{
    size_t i, j, k;
    int temp;

    if (size == 0 || size == 1)
    {
        return;
    }

    i = 0;
    while (array && i < size)
    {
        j = 0;
        while (j < size - 1)
        {
            k = 0;
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                while (k < size - 1)
                {
                    printf("%d, ", array[k]);
                    k++;
                }
                printf("%d\n", array[k]);
            }
            j++;
        }
        i++;
    }
    return;
}