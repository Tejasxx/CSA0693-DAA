#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n;
    
    printf("Enter the number till which you want prime numbers\n");
    scanf("%d", &n);
    
    printf("Prime numbers are:-\n");    
    for (i = 2; i <= n; i++)
    {
        int c = 0;
        for (j = 1; j <= sqrt(i); j++)  // Iterate up to the square root of i
        {
            if (i % j == 0)
            {
                c++;
            }
        }
         
        if (c == 1)  // Prime numbers have only two divisors: 1 and the number itself
        {
            printf("%d ", i);
        }
    }
    
    return 0;
}

