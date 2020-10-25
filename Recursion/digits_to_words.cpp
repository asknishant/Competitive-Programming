//digit to words problem using recursion

#include <bits/stdc++.h>
using namespace std;

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printWords(int n) {
    if(n==0)    return;

    //eg-: n == 2048 the sub problem will be 204 so solve for this then for 20 and 2.
    printWords(n/10);
    int x = n%10;
    cout << words[x] << " ";

}
int main() {

    int n;  cin >> n;
    printWords(n);

    return 0;
}
