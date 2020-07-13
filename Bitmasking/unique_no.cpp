#include <bits/stdc++.h>
using namespace std;

///Finding unique no using xor operator.
int main(void) {
  
  int n;  cin >> n;
  int no;
  int ans = 0;
  //Bit wise operator to solve the unique number from array of numbers
  //This method uses less memory.

  while (n--)
  {
    cin >> no;
    ans = ans ^ no;
  }
  cout << ans;
 }
