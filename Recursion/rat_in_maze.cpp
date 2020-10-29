#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[][10], int i, int j, int m, int n) {

    //Base case
    if(i==m and j==n) {
        soln[i][j] = 1;
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //If rat goes out of the maze
    if(i>m or j>n) {
        return false;
    }
    //If rat gets an X
    if(maze[i][j] == 'X') {
        return false;
    }

    //Assume Soln exists
    soln[i][j] = 1;

    //Recursive case.//Reducing in sub problems   
    bool rightgrid = ratInMaze(maze,soln,i,j+1,m,n);
    bool lowergrid = ratInMaze(maze,soln,i+1,j,m,n);

    //Backtracking case
    soln[i][j] = 0;

    if(lowergrid or rightgrid) {
        return true;
    }

    return false;
}

int main() {

    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };

    int soln[10][10] = {0};
    int m=4,n=4;

    bool ans = ratInMaze(maze,soln,0,0,m-1,n-1);

    if(!ans) cout << "No path exists";
    return 0;
}
