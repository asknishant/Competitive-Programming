#include<bits/stdc++.h>
using namespace std;

class Heap {
  vector<int> v;
  bool minHeap;
    bool compare(int a, int b) {
      if(minHeap) {
        return a < b;
      } else {
        return a > b;
      }
    }

  void heapify(int idx) {
    int left = 2*idx;
    int right = 2*idx + 1;

    int min_idx = idx;
    int last_idx = v.size() - 1;
    
    if(left <= last_idx and compare(v[left],v[idx])) {
      min_idx = left;
    }
    if(right <= last_idx and compare(v[right], v[min_idx])) {
      min_idx = right; 
    }

    if(min_idx != idx) {
      swap( v[min_idx],v[idx]);
      heapify(min_idx);
    }
  }
  public:
    
    Heap(int default_size = 10, bool type = true) {
      v.reserve(default_size);
      v.push_back(-1);  //First index  is reserved.
      minHeap = type;
    }

    void push(int d) {
      v.push_back(d);
      int idx = v.size()-1;
      int parent = idx/2;

      //Keep pushing to the top/root or stop int the mid way if v[idx] > v[parent].
      while(idx > 1 and compare(v[idx],v[parent])) {
        swap(v[idx],v[parent]);
        idx = parent;
        parent = parent/2;
      }
    }

    int top() {
      return v[1];
    }

    void pop() {
      //swapping the v[1] at last with last index
      int last = v.size() - 1;
      swap(v[1], v[last]);
      v.pop_back();

      //After removal of the element the heap is no more a BT so convert BT to heap.
      //To restore heapify property.
      heapify(1); //Start heapification from root node or v[1].
    }

    //Heap is Empty or not.
   bool empty(){
     return v.size() == 1;
   }
};


int main() {

  Heap h;
  //Heap h(10,false);
  int n;  cin >> n;

  for(int i=0;i<n;i++) {
    int no;
    cin >> no;
    h.push(no);
  }

  //Remove elements
   while(!h.empty()) {
      cout << h.top() << " ";
      h.pop();
    }
  return 0;
}
