//https://medium.com/@baeddavid/taking-the-first-recursive-leap-of-faith-ea5cd9582d94
//For reference.

#include <bits/stdc++.h>
using namespace std;


int makingChange(int arr[] , int c) {

  if(c == 0)  return 0;
  int number_of_coins = 0;

  for(int i=0;i<3;i++) {
    if(c-arr[i] >=0)
       number_of_coins = makingChange(arr,c-arr[i]);    ///Each call leads to looping from 0 to 2.subtracting all possible cases till c-arr[i]>=0.
  }
  return number_of_coins+1;
}
int main(void) {

  int arr[] = {1,2,5};
  int c;  cin >> c;

  cout << "Number of change coins are" << makingChange(arr,c);
  return 0;
}
