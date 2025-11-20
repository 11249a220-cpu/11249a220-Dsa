o write a C program that performs linear search using recursion to find the position of a given element in an array.

✅ ALGORITHM (Linear Search Using Recursion)
Algorithm

Start.

Read the array elements and the search key.

Call a recursive function linearSearch(arr, index, key, size).

In the recursive function:

If index >= size, return -1 (element not found).

If arr[index] == key, return index.

Else, call the function again with index + 1.

In the main function, check the returned value:

If result is -1, print "Element not found".

Else print "Element found at position (index + 1)".

program:

#include <stdio.h>
#include <stdbool.h>

int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);

    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }

    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }

    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);

    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);

    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind);
}
Stop.
