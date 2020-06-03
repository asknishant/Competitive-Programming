/*
Codeforces 285B
Find Marble
status-asknishant
*/


#include<bits/stdc++.h>
using namespace std;

int main(void){
    
    int n;  cin>>n;
    int arr[n];
    int s,l;    cin>>s>>l;
    for(int i=0;i<n;i++)    cin>>arr[i];
    
    if(s == l){
        cout<<0;
        return 0;
    }
    
    int index;
    int count=0;
    while(n--){
        index=arr[s-1];
        count++;
        if(index==l){
            cout<<count;
            return 0;
        }
        s=index;
    }
    
    cout<<-1;
   return 0;
}
