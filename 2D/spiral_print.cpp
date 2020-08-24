/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int r,c;
        cin >> r >> c;
    int arr[r][c];

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            int x;  cin >> x;
            arr[i][j] = x;
        }
    }

    int start_row = 0;
    int end_row = r-1;
    int start_col = 0;
    int end_col = c-1;

    while(start_row<=end_row and start_col<=end_col) {
        for(int i=start_col;i<=end_col;i++) {
            cout << arr[start_row][i];
        }
        start_row++;
        for(int i=start_row;i<=end_row;i++) {
            cout << arr[i][end_col];
        }
        end_col--;
        for(int i=end_col;i>=start_col;i--) {
            cout << arr[end_row][i];
        }
        end_row--;
        for(int i=end_row;i>=start_row;i--) {
            cout << arr[i][start_col];
        }
        start_col++;
    }
    return 0;
}
