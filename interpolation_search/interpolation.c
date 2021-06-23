// Interpolation search

#include <stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

int main(void)
{
    int i, n, key;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    get_array(arr, n);

    printf("Enter the target element to search\n");
    scanf("%d", &key);

    int low = 0, high = n - 1;

    while (low <= high)
    {
        // mid = low + (high - low)*(key - arr[low])/(arr[high]) - arr[low]
        int mid = low + (high - low) * (key - arr[low]) / (arr[high] - arr[low]);

        if (mid < 0)
        {
            printf("error: sorted array is required for the interpolation search\n");
            break;
        }
        if (arr[mid] == key)
        {
            printf("Key %d is found at %d\n", key, mid);
            break;
        }
        else if (arr[mid] > key)
        {
            high  = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(low > high)
    {
        printf("Key not found\n");
    }
}