/*
 * week4_1_dynamic_array.c
 * Author: Anna Anaastasija Jansone
 * Student ID: 241ADC002
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // TODO: Allocate memory for n integers using malloc
    arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
        return 1;
    }
    for(int i = 0; i < n; ++i)
    {
        printf("Enter number %d, please\n", i + 1);
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    int sum = 0;
    double average = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    average = (double)sum/(double)n;
    printf("sum: %1d, average: %2f\n", sum, average);

    free(arr);

    return 0;
}
