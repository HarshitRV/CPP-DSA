#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the element in the array that is closest to the given number
int findClosest(int arr[], int n, int target)
{
    int closest = 0;                     // Index of the element closest to the target
    int min_diff = abs(arr[0] - target); // Minimum difference between the target and an element in the array

    // Iterate through the array and update the minimum difference and the index of the closest element
    for (int i = 1; i < n; i++)
    {
        int diff = abs(arr[i] - target);
        if (diff < min_diff)
        {
            min_diff = diff;
            closest = i;
        }
    }

    return closest; // Return the index of the closest element
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int closest_index = findClosest(arr, n, target);
    int closest_element = arr[closest_index];

    printf("The element in the array that is closest to %d is %d at index %d\n", target, closest_element, closest_index);

    return 0;
}
