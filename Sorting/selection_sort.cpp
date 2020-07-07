#include <bits/stdc++.h>
using namespace std;


//As swap is in built function in stl.
void swape(int* x, int* y) {
  int temp;
  temp = *x; 
  *x = *y;
  *y = temp;
}

void selection_sort(int arr[], int n) {
   for(int i=0;i<n-1;i++) {
    int min_index = i;
    for(int j=i;j<=n-1;j++) {
      if(arr[min_index] > arr[j]) {
        min_index = j;
      }
    }
    //After applying above a linear search operation.Swap ar[i] and a[j];
    swape(&arr[i], &arr[min_index]);
  }
}
int main(void) {
  int arr[1000];
  int n;  cin >> n;
  for(int i=0;i<n;i++) 
    cin >> arr[i];
  
  selection_sort(arr, n);

  for(int i=0;i<n;i++)
    cout << arr[i];
  

  return 0;
}
