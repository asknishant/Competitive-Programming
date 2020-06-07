

#include<bits/stdc++.h>

using namespace std;

int main(void){
   //Find four elements that sum to a given value | Set 1 (n^3 solution) 
    
   int A[] = {4,3,5,6,7,9,8};
   
   int l;
   int r;
   int x=18; //4+3+5+6
   for(int i=0;i<4;i++){
       for(int j=i+1;j<5;j++){
           l=j+1;
           r=6;
           
           while(l<r) {
               if(A[i]+A[j]+A[l]+A[r] == x){
                cout<<i << " " << j << " " << l << " " << r;
                return 0;
               }
               else if(A[i]+A[j]+A[l]+A[r] > x)
                r--;
               else 
                l++;
           }
       }
   }
    
    
    return 0;
}