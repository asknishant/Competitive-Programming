#include<bits/stdc++.h>
using namespace std;

class Heap {
  vector<int> v;
  bool minHeap;
    bool compare(int a, int b, bool ) {
      if(minHeap) {
        return a > b;
      } else {
        return a < b;
      }
    }
  public:
    
    Heap(int default_size = 10, bool type = true) {
      v.reserve(default_size);
      v.push_back(-1);  //Root is reserved.
      minHeap = true;
    }

    void push(int d) {
      v.push_back(d);
      int idx = v.size()-1;
      int parent = idx/2;

      //Keep pushing to the top/root or stop int the mid way if v[idx] > v[parent].
      while(idx > 1 and compare(v[parent], v[idx])) {
        swap(v[parent],v[idx]);
        idx = parent;
        parent /= 2;
      }
    }
};


int main() {

  //TODO
  return 0;
}
