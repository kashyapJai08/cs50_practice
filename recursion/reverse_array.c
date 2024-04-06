
/********** PROGRAM REVERSES AN ARRAY ****************/

#include <cs50.h>
#include <stdio.h>

void reverseArray(int arr[], int start, int end);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]); // calculating the size of array by dividing the total memory allocated to the
                                                 // array by memory allocated to one element of the array

    // /* Implementation of loop */
    // for (int i = 0, j = size - 1, temp = 0; i <= j; i++, j--)
    // {
    //     temp = array[i];
    //     array[i] = array[j];
    //     array[j] = temp;
    // }

    /* Implementation of recursion */
    // int start = 0, end = size;
    reverseArray(arr, 0, size - 1);


    /* Prints the reversed array */
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

// reverses the array
void reverseArray(int arr[], int start, int end)
{
    int temp = 0;
    // base case
    if (start > end)
    {

        return;
    }

    // recursive case
    reverseArray(arr, start + 1, end - 1);

    // swapping the required elements of the array to reverse them
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

}
