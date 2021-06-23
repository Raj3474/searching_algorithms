//binary search

#include <stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

int main(void)
{
    int n, small, k, target, start, end, middle, flag = 0;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the target element to search\n");
    scanf("%d",&target);

    // sorting the array using selection sort
    for(int i = 0; i < n - 1; i++)
    {
        small = arr[i];
        k = i + 1;

        for(int j = i + 1; j < n; j++)
        {
            if (small > arr[j])
            {
                small = arr[j];
                k = j;
            }
        }

        if (arr[i] > arr[k])
        {
            arr[k] = arr[i];
            arr[i] = small;
        }
    }

    printf("The sorted elements are:\n");
    display_array(arr, 0, n - 1);

    start = 0;
    end = n - 1;
    while( start <= end)
    {
        middle = (start + end) / 2;

        if( arr[middle] == target)
        {
            flag = 1;
            break;
        }
        else if (arr[middle]<target)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    if(flag == 1)
    {
        printf("The target element %d is found\n",target);
    }
    else
    {
        printf("Not found\n");
    }

}