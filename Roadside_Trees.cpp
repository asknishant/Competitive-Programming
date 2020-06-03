/*
  Codeforces 256B
  Roadside Trees (Simplified Edition)
  by-asknishant
*/


#include<bits/stdc++.h>
using namespace std;

int main(void){
    
    int n;  cin>>n;
    int nuts=n;
    
    int curr;
    int prev=0; 
    int totalTime = 0;
    while(n--){
        cin>>curr;
        if(prev<=curr){
            totalTime += (curr-prev);
        }else if(prev>curr){
            totalTime += (prev-curr);
        }
        prev=curr;
    }
    
    totalTime += (2*nuts-1);
    cout<<totalTime;
    return 0;
}
