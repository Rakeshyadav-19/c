#include <stdio.h>
#include <stdlib.h>
// Job structure
typedef struct
{
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
} Job;
// Function to compare jobs basedon their profit
int compare(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit; // Descending order of profit
}
// Function to find the maximum profit job sequence
void jobSequencing(Job jobs[], int n)
{
    // Sort jobs based on profit in descending order
    qsort(jobs, n, sizeof(Job), compare);
    // Array to keep track of free time slots
    int result[n];
    // Initialize all slots as free
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }
    // Array to keep track of whether a slot is occupied
    int slotOccupied[n];
    for (int i = 0; i < n; i++)
    {
        slotOccupied[i] = 0; // Initialize all slots as free
    }
    // To keep track of total profit
    int totalProfit = 0;
    // Iterate through all the jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            // If slot is free
            if (!slotOccupied[j])
            {
                slotOccupied[j] = 1; // Mark this slot as occupied
                result[j] = i;       // Assign this job to the slot
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    // Print the result
    printf("Job Sequence with Maximum Profit:\n");
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            printf("Job ID %d with Profit % d\n ", jobs[result[i]].id, jobs[result[i]].profit);
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}
int main()
{
    Job jobs[] = {
        {1, 4, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}