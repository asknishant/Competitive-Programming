/*
Codeforces 451-B
Sort the Array
Status-Accepted
by-asknishant.39
*/


#include <bits/stdc++.h>
#define ll long long
#define MAX 100005
using namespace std;
int arr[MAX];
int arr1[MAX];
int main(void){
  int size; cin>>size;
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }

  for(int i=0;i<size;i++)
    arr1[i]=arr[i];

  sort(arr1,arr1+size);
  //If the array is alredy sorted.
  for(int i=0;i<size;i++){
    if(arr[i]!=arr1[i])
      break;
    else  if(i==size-1 && (arr[i]==arr1[i])){
      cout<<"yes"<<endl<<1<<" "<<1;
      return 0;
    }
  }


  int initial=0;
  int final=0;
  for(int i=0;i<size;i++){
    if(arr[i]>arr[i+1]){
      initial=i+1;
      break;
    }
  }
  for(int i=initial-1;i<size;i++){
    if(arr[i]<arr[i+1] || arr[i+1]==0){
      final=i+1;
      break;
    }
  }
  if(arr[initial-1]>arr[final] && arr[final]!=0){
    cout<<"no";
    return 0;
  }

  int k=final-1;
  int l=initial-1;
  int mid=(final-(initial))/2;
  

  for(int i=1;i<=mid+1;i++){
    int temp=arr[l];
    arr[l]=arr[k];
    arr[k]=temp;
    k--;
    l++;
  }
  for(int i=0;i<size;i++){

    //cout<<" "<<arr[i]<<" "<<arr1[i];
    if(arr[i]!=arr1[i]){
      cout<<"no";
      return 0;
    }
  }
  cout<<"yes"<<endl<<initial<<" "<<final;
  return 0;
}
