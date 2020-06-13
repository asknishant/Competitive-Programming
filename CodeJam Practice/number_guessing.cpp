//https://codingcompetitions.withgoogle.com/codejam/round/0000000000000130/0000000000000523

//Number Guessing


#include<bits/stdc++.h>
using namespace std;

int main(void) {
    
    int test;    cin >> test;
    
   
    while(test-- ) {

        int a,b;
        int n;
        cin >> a >> b;
        cin >> n;
        int start,end,mid;
        start = a;
        end = b;
        string str;

        while(start<=end) {
            
            mid = start+(end-start)/2;
            cout << mid << "\n";
            fflush(stdout);
            
            cin >> str;
            if(str == "CORRECT") {
                break;
            }
            else if(str == "WRONG_ANSWER") {
                return 0;
            }
            else if(str == "TOO_SMALL") {
                start = mid + 1;
            }
            else if(str == "TOO_BIG") {
                end = mid-1;
            }
        }
    }
    
  
    return 0;
}