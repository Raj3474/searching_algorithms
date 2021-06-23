// fibonacci search

#include <stdio.h>
#include <math.h>
#include "/home/ubuntu/my_header_file/array.h"

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int main(void)
{
    int n, key;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    get_array(arr, n);

    printf("Enter the target element to search\n");
    scanf("%d", &key);

    int fibo0 = 0, i = 0, fibo1 = 1, fibo = fibo0 + fibo1, jump = 0;

    while (fibo < n)
    {
        fibo0 = fibo1;
        fibo1 = fibo;
        fibo = fibo0 + fibo1;
        jump++;
    }

    int offset = -1;

    while (fibo > 1 && i != n - 1)
    {
        jump++;
        i = min(offset + fibo0, n - 1);

        if (arr[i] < key)
        {
            fibo = fibo1;
            fibo1 = fibo0;
            fibo0 = fibo - fibo1;
            offset = i;
        }

        else if (arr[i] > key)
        {
            fibo = fibo0;
            fibo1 = fibo1 - fibo0;
            fibo0 = fibo0 - fibo1;
        }
        else
        {
            printf("key found at %d\n", i);
            printf("jump= %d\n", jump);
            return 0;
        }
    }

    if(fibo1 && arr[offset] == key)
    {
        printf("key found at %d\n", offset + 1);
        printf("jump= %d\n", jump);
        return 0;
    }

    printf("error: Not found\n");
    printf("jump= %d\n", jump);
}