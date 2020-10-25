//Place the tiles-VVVI
//Given a group of people tell how many n of ways are there for going to a party when each of them can go alone or in pairs.
//let f(n) be the total number of ways then f(n) = 1.f(n-1) + (n-1)C(1).f(n-2).

#include <bits/stdc++.h>
using namespace std;


int no_of_ways(int n) {
    if(n<=1)    return 1;

    return no_of_ways(n-1) + (n-1)*no_of_ways(n-2);
}
int main() {

    int n;
    cin >> n;

    cout << no_of_ways(n);

    return 0;
}
