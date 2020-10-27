//0-1 Knapsack problem.
#include <iostream>
using namespace std;

char keypad[][10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void generate_strings(char *in, char *out,int i, int j) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out <<endl;
        return;
    }
    int digit = in[i] - '0'; 
    if(digit == 0 or digit == 1) {
        //Ignore 1 and 0 and move to next digit.
        generate_strings(in,out,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++){
        out[j] = keypad[digit][k];
        //Fill the remaining part.
        generate_strings(in,out,i+1,j+1);
    }
    return;
}

int main() {   

   char in[100];
   char out[100];
   cin >> in;

    generate_strings(in,out,0,0);
    return 0;
}
