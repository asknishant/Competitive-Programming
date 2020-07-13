//Finding bit at a particular position.Whether it is 0 or 1.

#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int i) {
  int mask = (1 << i);  //Adding i 0's after 1.
  int bit = (n&mask) > 0 ? 1 : 0;

  return bit;
}
int main() {
  //If n = 5 and i = 2.Find the bit at ith bit(here 2nd bit).
  int n;  cin >> n;
  int i;  cin >> i;

  cout << getBit(n,i);

  return 0;
}
