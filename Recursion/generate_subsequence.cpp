#include <iostream>
using namespace std;

void generate_subsequence(char *in,char *out, int i, int j) {

    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    //Include the current character.
    out[j] = in[i];
    generate_subsequence(in,out,i+1,j+1);

    //Exclude the current char
    generate_subsequence(in, out,i+1,j);

}

int main() {

    char in[] = "abc";
    char out[3];

    generate_subsequence(in,out,0,0);
    return 0;
}
