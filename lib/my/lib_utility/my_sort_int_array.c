/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

void swap_my_two_ptr(int *array, int i, int j)
{
    int swap;

    if (array[i] > array[j]) {
        swap = array[i];
        array[i] = array[j];
        array[j] = swap;
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j;

    while (i < size) {
        j = i + 1;
        while (j < size) {
            swap_my_two_ptr(array, i, j);
            j++;
        }
        i++;
    }
}
