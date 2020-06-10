#include <bits/stdc++.h>
using namespace std;

int paths(int x,int y) {
    if(x == 1 || y == 1)
        return 1;
    else return paths(x-1,y) + paths(x,y-1);
}

int main(void) {

    int x,y;
    cin>>x,y;
    cout<<paths(x,y);
    return 0;
}