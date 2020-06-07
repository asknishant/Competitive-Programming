//Reference YT
//finding sum of three numbers whether present inside the array or not.We can solve this using three for loops which will give the complexity as O(n^3)
//Two Pointer reduces this complexity to O(n^2).


#include<bits/stdc++.h>

using namespace std;

int two_sum(int a[],int j,int k, int x)
{
    
    while(j<k){
        if((a[j]+a[k]) > x){
            k--;
        }else if((a[j]+a[k]) < x){
            j++;
        }else{
            return true;
        }
        return false;
    }
    
}
int main(void) {
    
    int size;   cin>>size;
    int arr[size];
    
    for(int i=0;i<size;i++)
        cin>>arr[i];
    int num;    cin>>num;
    
    for(int i=0;i<size-2;i++){
        if((two_sum(arr,i+1,size-1,num-arr[i])))
            cout<<"yes";
    }
    return 0;
}