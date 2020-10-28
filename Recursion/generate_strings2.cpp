

//Generate all possible strings using numbers from 1-6,1-A,2-B...
#include <iostream>
using namespace std;

void generate_strings(char *in, char *out, int i,int j) {
    //base case.
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    //Taking ine digit at a time.
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generate_strings(in,out,i+1,j+1);

    //Taking two digti at a time.
    if(in[i+1]!='\0') {
        int digit2 = in[i+1] - '0';
        int tot = digit*10 + digit2;
        if(tot<=26) {
            char ch2 = tot + 'A' - 1;
            out[j] = ch2;
             generate_strings(in,out,i+2,j+1);
        }
       
    }
}

int main() {   

   char in[100];
   char out[100];
   cin >> in;

    generate_strings(in,out,0,0);
    return 0;
}
