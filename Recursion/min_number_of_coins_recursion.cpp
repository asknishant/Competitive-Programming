//https://medium.com/@baeddavid/taking-the-first-recursive-leap-of-faith-ea5cd9582d94
//For reference.
//though this is just for understanding the recursion algo.Althogh this process is very slow as it is performing calls inside loops inside calls ......
#include <bits/stdc++.h>
using namespace std;


int makingChange(int arr[] , int c) {

  if(c == 0)  return 0;
  int min_coin = INFINITY;
  int curr_min_coins = 0;
  for(int i=0;i<3;i++) {
    if(c-arr[i] >=0)
       curr_min_coins = makingChange(arr,c-arr[i]);    ///Each call leads to looping from 0 to 2.subtracting all possible cases till c-arr[i]>=0.
      if(curr_min_coins < min_coin)
         min_coin = curr_min_coins;
  }
  return min_coin+1;
}
int main(void) {

  int arr[] = {1,2,5};
  int c;  cin >> c;

  cout << "Number of change coins are" << makingChange(arr,c);
  return 0;
}
