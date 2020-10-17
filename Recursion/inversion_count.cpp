#include<bits/stdc++.h>
using namespace std;


int merge(int arr[],int start,int end) {
    
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;
    int k = start;
    int temp[100];

    int count = 0;
    while(i<=mid and j<=end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }else { 
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=end) {
        temp[k++] = arr[j++];
    }

    for(int i=start;i<=end;i++) {
        arr[i] = temp[i];
    }

    return count;
}
int inversion_count(int arr[], int start, int end) {
    if(start>=end)  return 0;

    int mid = (start+end)/2;
    int x = inversion_count(arr,start,mid);
    int y = inversion_count(arr,mid+1,end);

    int z = merge(arr,start,end);

    return x+y+z;
}
int main() {


    int n;  cin >> n;   
    int arr[n];
    for(int i=0;i<n;i++)    cin >> arr[i];

    cout << inversion_count(arr,0,n-1);
    return 0;
}
