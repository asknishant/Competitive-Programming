//Binary Search on Rotated array

#include<bits/stdc++.h>
using namespace std;

int bin_on_rot_array(int arr[], int size, int key) {
    int start = 0;
    int end = size -1;
    while(start<=end) {
        int mid = start +(end-start)/2;
        
        if(arr[mid] == key) {
            return mid;
        }
        //for the key to be on right side.
        if(arr[mid] <= arr[start]) {
            //If the key is on the right half of the right part.
            if(key >= arr[mid] and key < arr[start]) {
                start = mid + 1;
            }
            //If the key is on the left half of the right part.
            else {
                end = mid - 1;
            }
        }
        //for the key to be on left side.
        else if(arr[mid] > arr[start]) {
            //If the key is on the right half of the left part.
            if(key > arr[mid] and key > arr[start]) {
                start = mid + 1;
            }
            //If the key is on the left half of the left part.
            else {
                end = mid -1;
            }
        }
    }
}
int main(void) {
    
    int arr[] = {4, 5, 1, 2 ,3};
    int key;    cin >> key;
    
    int n = sizeof(arr)/sizeof(int);
    cout << bin_on_rot_array(arr, n, key);
}
