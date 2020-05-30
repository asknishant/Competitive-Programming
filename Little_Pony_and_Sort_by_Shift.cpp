/*

Codeforces 454-B
*/

    #include<bits/stdc++.h>
    using namespace std;
     
     
    int main(void){
        
        long n;  cin>>n;
        long arr[n];
        
        for(long i=0;i<n;i++)
            cin>>arr[i];
        
        long k=n;
        for(long i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                 k=i+1;
                 break;
            }
        }
        if(k==(n)){
            cout<<0;
            return 0; 
        }
        
        if(arr[n-1]>arr[0]){
            cout<<-1;
            return 0;
        }
        
        for(long i=k;i<n-1;i++){
            if(arr[i]>arr[i+1] && i!=n-1){
                cout<<-1;
                return 0;
            }
        }
        cout<<n-k;
    }
