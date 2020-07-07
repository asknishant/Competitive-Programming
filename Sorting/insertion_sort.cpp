#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
  for(int i=1;i<n;i++) {
    int element = arr[i];
      int j = i-1;
      while(j>=0 and element<arr[j]) {
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = element; 
  }
}

int main(void ){
  int n;  cin >> n;
  int arr[1000];
  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }

  insertion_sort(arr, n);
  for(int i=0;i<n;i++)
    cout <<  arr[i] << ",";
}
