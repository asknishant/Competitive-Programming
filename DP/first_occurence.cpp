#include<bits/stdc++.h>
using namespace std;

//Linear search

int firstOcc(int *a, int key, int size) {

    if(size == 0) {
        return 0;;
    }
    if(a[0] == key) {
        return 1;
    }
    return firstOcc(a+1 , key , size-1);
}

int main() {

    int arr [] = {2,3,4,5,6,7,8,9};
    cout << "Enter the element to be searched";
    int key;    cin >> key;

    int size = sizeof(arr)/sizeof(int);
    if(firstOcc(arr, key, size)) {
        cout << "Present";
    }

    return 0;
}
