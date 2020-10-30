//Counting Sort- Used when the we need to sort the arrays within a range.  
//Used when the range of number is small we can get this in O(N).

#include <iostream>
using namespace std;


void countingSort(int arr[],int n) {

    int largest = -1;

    for(int i=0;i<n;i++) {
        largest = max(largest,arr[i]);
    }

    int *freq = new int[largest+1]{0};

    for(int i=0;i<=n;i++) {
        freq[arr[i]]++;
    }

    int j = 0;
    for(int i=0;i<=largest;i++) {
        while(freq[i] > 0) {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }

    delete [] freq;
}
int main() {


    int arr[] = {4,3,2,7,6,5,9,8};
    int n = sizeof(arr)/sizeof(int);
    countingSort(arr,n);

    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
