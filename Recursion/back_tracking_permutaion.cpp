#include<iostream>
using namespace std;

void permute(char *ch,int i) {
    if(ch[i] == '\0') {
        cout << ch << endl;
        return;
    }

    //Recursive case.
    for(int j=i;ch[j]!= '\0';j++) {
        //Swap
        swap(ch[i],ch[j]);
        permute(ch,i+1);
        //Backtrack
        swap(ch[i],ch[j]);
    }
}
int main() {

    char c[100];
    cin >> c;

    permute(c,0);

    return 0;
}
