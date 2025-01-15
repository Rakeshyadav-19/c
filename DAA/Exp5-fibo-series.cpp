#include <stdio.h>

void fibonacci(int n)
{
    int fib[n + 1]; // Array to store Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibonacci Series: ");
    for (int i = 0; i <= n; i++) // Changed loop to `i <= n` to print `n` terms
    {
        if (i == n) // No comma after the last number
            printf("%d", fib[i]);
        else
            printf("%d, ", fib[i]);
    }
    printf("\n"); // Newline after printing the series
}

int main()
{
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
