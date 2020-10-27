//0-1 Knapsack problem.
#include <iostream>
using namespace std;


int profit(int N, int C, int *weights, int *prices) {
    if(N==0 or C==0) {
        return 0;
    }
    int inc = 0;
    int exc = 0;
    int ans;

    if(C >= weights[N-1]) {
        //Including the current item.
        inc = prices[N-1] + profit(N-1, C-weights[N-1], weights, prices);
    }

    //Excluding the current item.
    exc = 0 + profit(N-1,C, weights,prices);

    ans = max(inc,exc);
    return ans;

}
int main() {   

    int weights[] = {1,2,3,5};
    int prices[] = {40,20,30,100};

    int N = 4;
    int C = 7;
    cout << profit(N,C,weights,prices);

    return 0;
}
