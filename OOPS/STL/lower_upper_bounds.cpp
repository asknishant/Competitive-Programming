#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int a[] = {0,1,2,2,2,2,2,2,3,4};
  int n = sizeof(a)/sizeof(int);

  auto first = lower_bound(a,a+n,2)-a;
  auto last = upper_bound(a,a+n,2) - a - 1; //Upper bound gives index of element just after the req number.

  cout << first;
  cout << endl << last;
  return 0;
}
