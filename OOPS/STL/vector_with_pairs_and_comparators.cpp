#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<string,int> a, pair<string,int> b) {
  return a.first < b.first;
}

bool priceCompare(pair<string,int> a, pair<string,int> b) {
  return a.second < b.second; //In ascending order of price.
}

int main() {

  vector<pair<string,int> > v;
  int n;
  cin >> n; 

  for(int i=0;i<n;i++) {
    string s; cin >> s;
    int no; cin >> no;

    v.push_back(make_pair(s,no));
  } 

  //sort(v.begin(),v.end(),compare);
  sort(v.begin(),v.end(),priceCompare);

  for(auto x : v) {
    cout << x.first << " : " << x.second <<endl;
  }
  return 0;
}
