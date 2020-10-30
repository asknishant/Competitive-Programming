#include<iostream>
using namespace std;


void dnf_sort(int arr[], int n) {

    int lo = 0;
    int mid = 0;
    int hi = n-1;

    while(mid <= hi) {
        if(arr[mid]==0) {
            swap(arr[mid],arr[lo]);
            lo++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2) {
            swap(arr[mid],arr[hi]);
            hi--;
        }
    }
    swap(arr[hi+1],arr[mid]);
}
int main() {

    int arr[] = {1,2,0,1,0,1,1,1,1,2,1,0,1,2,2,2,0,0,0,2,0,0,1,0,2,0};
    int n = sizeof(arr)/sizeof(int);

    dnf_sort(arr,n);
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
