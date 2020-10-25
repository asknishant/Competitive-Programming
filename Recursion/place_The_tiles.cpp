//Place the tiles
//Given a wall of size N X 4 and tiles of size(1,4) and (4,1).In how man ways can you build the wall.

#include <bits/stdc++.h>
using namespace std;


int place_the_tiles(int n) {
    if(n <= 3) {
        return n;
    }
    
    return place_the_tiles(n-1) + place_the_tiles(n-4);
}
int main() {

   int n;
    cin >> n;

    cout << place_the_tiles(n);
    return 0;
}
