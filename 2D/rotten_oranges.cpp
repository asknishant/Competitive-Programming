#include<bits/stdc++.h>
using namespace std;

void inlineDebug() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

const int R = 3;
const int C = 5;

bool isSafe(int i,int j) {
    if(i>=0 and j>=0 and i<R and j<C) {
        return true;
    }
    return false;
}

int rotOrange(int arr[R][C]) {


    
    int no = 2;
    int change = false;


    while(true) {

         for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(arr[i][j] == no) {
                     if(isSafe(i+1,j) and arr[i+1][j] == 1) {
                        arr[i+1][j] = arr[i][j] + 1;
                        change = true;
                     }  
                       if(isSafe(i-1,j) and arr[i-1][j] == 1) {
                        arr[i-1][j] = arr[i][j] + 1;
                        change = true;
                     }
                       if(isSafe(i,j+1) and arr[i][j+1] == 1) {
                        arr[i][j+1] = arr[i][j] + 1;
                        change = true;
                     }
                       if(isSafe(i,j-1) and arr[i][j-1] == 1) {
                        arr[1][j-1] = arr[i][j] + 1;
                        change = true;
                     }
                }
               
            }
        }

        if(!change) {
            break;
        }
        change = false;
        no++;
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(arr[i][j] == 1) {
                return -1;
            }
        }
    }

    return no - 2;
}




/*
    Given an array of 0,1 and 2 where 0 denotes no oranges, 1 denotes fresh oranges and 2 denotes
    rotten oranges.We need to find what is the minimum number of iterations required to 
    convert each orange fresh fresh to rotten

    O(N3) soln ->> not optimized.
*/
int main() {

    inlineDebug();

    int v[R][C] = { { 2, 1, 0, 2, 1 },
                    { 1, 0, 1, 2, 1 },
                    { 1, 0, 0, 2, 1 } };
    cout << "Minimum time required " << rotOrange(v);
    return 0;
}
