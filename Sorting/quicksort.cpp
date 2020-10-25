//Quick Sort 
//Inplace algo - It is inplace does not require extra space.
//O(N^2) - worst case
//O(NlogN)

#include <bits/stdc++.h>
using namespace std;

int Partition(int *arr, int start, int end) {

    int i = start - 1;
    int j = start;
    int pivot = arr[end];

    for(;j<end;) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }

    swap(arr[i+1],arr[end]);//i+1 will be greater than pivot So sendint it to the end of the array.
    return i+1; 
}
void QuickSort(int *arr, int start, int end) {

    if(start >= end)    return;

    int p = Partition(arr, start, end);//p is fixed and now net strp is doing this again recursively.

    QuickSort(arr,start,p-1);
    QuickSort(arr, p+1, end);

}
int main() {

    int arr[] = {3,2,7,6,5,8,9};
    int size = sizeof(arr)/sizeof(int);
    QuickSort(arr,0,size-1);

    for(int i=0;i<size;i++) cout << arr[i] << " ";

    return 0;
}
