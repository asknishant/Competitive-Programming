#include <iostream>
#include <bitset>

using namespace std;

int main() {

  bitset<30> b; //Each block is of 1 bit.Total 30 bits.
  b[3] = b[5] = 1;
  cout << b << endl; //Starts from left.
}
