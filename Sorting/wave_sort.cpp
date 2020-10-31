//Sort the array in wave form.
#include<iostream>
using namespace std;

void wave_sort(int *a,int n) {
    for(int i=0;i<n;i+=2) {
        if(i!=0 and a[i]<a[i-1]) {
            swap(a[i],a[i-1]);
        }
        if(i!=(n-1) and a[i]<a[i+1]) {
            swap(a[i],a[i+1]);
        }
    }
}

int main() {


    int arr[] = {1,3,5,2,7,4};
    int size = sizeof(arr)/sizeof(int);

    wave_sort(arr,size);
        
    for(int i=0;i<size;i++)    cout << arr[i] << " ";
    return 0;
}
