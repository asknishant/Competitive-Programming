#include <iostream>
using namespace std;

bool isValid(int board[10][10],int i,int j,int n){
    //Checking the current column whether it has already a queen.If that is the case then return false otherwise reutrn true.

    for(int row=0;row<i;row++) {
        if(board[row][j] == 1) {
            return false;
        }
    }

    int x = i;//x coordinate
    int y = j;//y coordinate

    while(x>=0 and y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = i;
    y = j;

    while(x >= 0 and y <=n-1) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }
    //Now if this function does not return false it any of the above cases.
    return true;
}

bool solveNQueen(int board[10][10], int i, int n) { //i is the current row and n is the total number of queens needed to be placed.

    //Base case.When ith row is equal to number of queens.
    if(i==n) {
        for(int k=0;k<n;k++) {
            for(int j=0;j<n;j++) {
                cout << board[k][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    //Recursive case.
    for(int k=0;k<n;k++) {
        if(isValid(board,i,k,n)) {

            //Place the queen - Assuming i,j is the right position.  
            board[i][k] = 1;
            bool nextQueenRakhPaaye = solveNQueen(board,i+1,n);
            if(nextQueenRakhPaaye) {
                return true;
            }

            //If assumption gets wrong and further placing other queens in other rows fails.
            board[i][k] = 0;//Backtracking condition.
        }
    }

    //You have tried for all the positions in the current row but couldn't place a queen.Return false. 
    return false;
}

int main() {

    int n;  cin >> n;   //No of queens.
    int board[10][10] = {0};


    solveNQueen(board,0,n);


    return 0;
}
