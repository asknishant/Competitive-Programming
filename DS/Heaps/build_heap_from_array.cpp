#include <iostream>
#include <vector>
using namespace std;

void buildHeap(vector<int> &v) {
  for(int i=1;i<v.size();i++) {
    int idx = i;
    int parent = idx/2;

    while(idx > 0 and v[idx] > v[parent]) {
      swap(v[idx],v[parent]);
      idx = parent;
      parent = parent/2;
    }
  }
}

void print(vector<int> v) {
  for(auto x:v) {
    cout << x << " ";
  }
}
int main() {
  vector<int> v{10,20,5,6,1,8,9,4};
  print(v);
  buildHeap(v);
  cout << endl;
  print(v);
}
