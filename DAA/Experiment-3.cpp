#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b)
{
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}
void jobSequencing(Job jobs[], int n)
{

    qsort(jobs, n, sizeof(Job), compare);

    int result[n];

    int slotOccupied[n];

    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
        slotOccupied[i] = 0;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (!slotOccupied[j])
            {
                slotOccupied[j] = 1;
                result[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job Sequence with Maximum Profit:\n");
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            printf("Job ID %d with Profit %d\n", jobs[result[i]].id, jobs[result[i]].profit);
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}

int main()
{
    printf("Rakesh Yadav(3049)\n");
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
