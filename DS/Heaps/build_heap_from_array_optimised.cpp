//O(N)

#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b, bool minHeap) {
  if(!minHeap) {
    return a < b;
  }
  return a > b;
}
void heapify(vector<int> &v,int idx) {
    int left = 2*idx;
    int right = 2*idx + 1;

    int min_idx = idx;
    int last_idx = v.size() - 1;
    
    if(left <= last_idx and compare(v[left],v[idx],true)) {
      min_idx = left;
    }
    if(right <= last_idx and compare(v[right], v[min_idx],true)) {
      min_idx = right; 
    }

    if(min_idx != idx) {
      swap( v[min_idx],v[idx]);
      heapify(v,min_idx);
    }
  }
void build_heap_optimised(vector<int> &v) {
  //parent of the last leaf node is v.size()/2
  for(int i=v.size()-1/2;i>0;i--) {
    heapify(v,i);
  } 
}

void print(vector<int> v) {
  for(auto x:v) {
    cout << x << " ";
  }
}
int main() {

  vector<int> v{-1,10,20,5,6,1,8,9,4};
  build_heap_optimised(v);
  print(v);

  return 0;
}
