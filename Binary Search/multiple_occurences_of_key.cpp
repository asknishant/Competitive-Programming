//CB -> FInding multiple occurences of an element in a sorted array in a binary search.

#include<bits/stdc++.h>
using namespace std;

int first_occurence(int arr[], int key, int size) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(arr[mid] > key) {
            end = mid - 1;
        } else if(arr[mid] < key) {
            start = end + 1;
        } else if(arr[mid] == key) {
            ans = mid;
            //As we are asked to find the first occurence so end = mid -1.
            end = mid -1;
        }
    }
    return ans;
}

int last_occurence(int arr[], int key, int size) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(arr[mid] > key) {
            end = mid - 1;
        } else if(arr[mid] < key) {
            start = end + 1;
        } else if(arr[mid] == key) {
            ans = mid;
            //As we are asked to find the last occurence so start = mid + 1(Exploring the right side).
            start = mid +1;
        }
    }
    return ans;
}

int main() {
    
    int key;    cin >> key;
    
    int arr[] = {2,3,4,5,8,8,8,8,9,9};
    int n = sizeof(arr)/sizeof(int);
    cout << first_occurence(arr, key, n) << endl;
    cout <<  last_occurence(arr,key,n);
    return 0;
}
