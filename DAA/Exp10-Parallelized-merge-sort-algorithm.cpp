#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define MAX_SIZE 1000000 // Define maximum array size for testing

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[], if any

    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    // Free allocated memory
    free(L);
    free(R);
}

// Parallel merge sort function
void parallelMergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

// Recursively sort the two halves in parallel
#pragma omp parallel sections
        {
#pragma omp section
            parallelMergeSort(arr, left, mid);

#pragma omp section
            parallelMergeSort(arr, mid + 1, right);
        }

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to generate random numbers for testing
void generateRandomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }
}

// Function to print the array (optional for debugging)
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX_SIZE];
    int size = MAX_SIZE; // Change this to test different sizes
    generateRandomArray(arr, size);

    // Set the number of threads to use
    omp_set_num_threads(4); // Set to 4 threads, adjust as needed

    // Start the timer
    double start_time = omp_get_wtime();

    // Sort the array using parallel merge sort
    parallelMergeSort(arr, 0, size - 1);

    // Stop the timer
    double end_time = omp_get_wtime();

    // Optionally print the sorted array (uncomment if needed)
    // printArray(arr, size);

    // Output the time taken for sorting
    printf("Time taken for parallel merge sort: %f seconds\n", end_time - start_time);

    return 0;
}

// To run this
// gcc -fopenmp -o Exp10-Parallelized-merge-sort-algorithm Exp10-Parallelized-merge-sort-algorithm.cpp
// ./Exp10-Parallelized-merge-sort-algorithm