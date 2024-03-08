// Milan Castro
// Lab Assignment #7

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct element
{
    int data;
    int numswaps;
} element;

// Bubble Sort
element *numSwapsBubbleSort(int *arr, int size)
{
    element *swaps = (element *)malloc(sizeof(element) * size);
    for (int i = 0; i < size; i++)
    {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (swaps[j].data > swaps[j + 1].data)
            {

                // Swap the elements
                element temp = swaps[j];
                swaps[j] = swaps[j + 1];
                swaps[j + 1] = temp;

                // Increment the number of swaps for the current element
                swaps[j].numswaps++;
                swaps[j + 1].numswaps++;
            }
        }
    }
    return swaps;
}

// Selection Sort
element *numSwapsSelectionSort(int *arr, int size)
{
    int min_idx;
    element *swaps = (element *)malloc(sizeof(element) * size);

    for (int i = 0; i < size; i++)
    {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    // Selection Sort Algorithm
    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (swaps[j].data < swaps[min_idx].data)
            {
                min_idx = j;
            }
        }
        if (i != min_idx)
        {
            element temp = swaps[i];

            swaps[i] = swaps[min_idx];

            swaps[min_idx] = temp;

            swaps[i].numswaps++;
            swaps[min_idx].numswaps++;
        }
    }
    return swaps;
}

    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    void printSwaps(element * arr, int size)
    {
        int totalSwap = 0;

        for (int i = 0; i < size; i++)
        {
            totalSwap += arr[i].numswaps;
           // printf("\nArray %d", i+1);
            printf("%d: %d swaps\n", arr[i].data, arr[i].numswaps);
        }
        printf("The total number of swaps: %d\n", totalSwap / 2);
        // printf("The total number of swaps: %d\n", totalSwap);

        printf("\n");
    }

    int main()
    {
        int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
        int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

        element *swaps1 = numSwapsBubbleSort(arr1, SIZE);
        element *swaps2 = numSwapsBubbleSort(arr2, SIZE);

        element *swaps3 = numSwapsSelectionSort(arr1,SIZE);
        element *swaps4 = numSwapsSelectionSort(arr2, SIZE);

        printf("\nAfter Bubble Sort:");
        printf("\nArray 1:\n");
        printSwaps(swaps1, SIZE);
        printf("\nArray 2:\n");
        printSwaps(swaps2, SIZE);

        printf("\nAfter Selection Sort:");
        printf("\nArray 1:\n");
        printSwaps(swaps3, SIZE);
        printf("\nArray 2:\n");
        printSwaps(swaps4, SIZE);

        return 0;
    }
