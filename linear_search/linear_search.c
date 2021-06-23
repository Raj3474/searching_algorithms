//linear_search

#include<stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

int main(void)
{
    int i, n, target;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    get_array(arr, n);

    printf("Enter the target element to search\n");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("The target element %d is found at %d\n", target, i + 1);
            break;
        }
    }

    if (i == n)
    {
        printf("Not found\n");
    }


}