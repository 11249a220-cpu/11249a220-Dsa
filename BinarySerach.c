Aim:To serach an element in  a sorted array using binary search

Algorithm:
1.Start
2.input sorted array and key
3.set low=0,high=1
4.Repeat while low<=high
5.Find mid=(low+high)/2
6.if a[mid]==key,print found
7.if a[mid]>key,set high=mid-1,else low=mid+1
8.stop

Program:

#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int searchSpace[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }
    printf("Enter the element to search ");
    scanf("%d",&targetElement);
    start = 0;
    end = size-1;
    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
    
   return 0;
}
