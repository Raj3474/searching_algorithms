// jump search

#include <stdio.h>
#include <math.h>
#include "/home/ubuntu/my_header_file/array.h"

int main(void)
{
    int i = 0, n, key;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    get_array(arr, n);

    printf("Enter the target element to search\n");
    scanf("%d", &key);

    int low = 0, step = sqrt(n), jump = 0;
    int high = step;

    if (key < arr[low])
    {
        printf("error: key not found\n");
        return 0;
    }

    // deciding number of jumps to be made
    while(arr[high] <= key && high < n - 1)
    {
        low = high;
        high += step;

        if (high > n - 1)
        {
            high = n - 1;
        }


        /*This block is only for the modified jump search
          it further reduces the step if key value lies
          between the low and high index
        if (key > arr[low] && key <= arr[high])
        {
            if (step > 5)
            {
                step = sqrt(step);
                high = low + step;
            }
        }
        */

        jump++;
    }

    for (i = low; i <= high; i++)
    {
        if (arr[i] == key)
        {
            printf("key found at %d\n", i);
            break;
        }
        jump++;
    }

    if (i == high + 1)
    {
        printf("error: key not found\n");
    }
    printf("Number of jumps to be made: %d\n", jump);
}