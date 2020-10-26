//Awesome Brackets problem using recursion.


#include <iostream>
using namespace std;


void generate_brackets(int idx,char *out, int n, int open, int close) {
    if(idx == 2*n) {
        out[idx] = '\0';
        cout << out << endl;
    }
    if(open < n) {
        out[idx] = '(';
        generate_brackets(idx+1,out,n,open+1,close);
    }
    if(open > close) {
        out[idx] = ')';
        generate_brackets(idx+1, out, n, open,close+1);
    }
    return;
}
int main() {   

    int n;  cin >> n;
    char in[2*n];
    char out[100];
    generate_brackets(0,out,n,0,0);

    return 0;
}
