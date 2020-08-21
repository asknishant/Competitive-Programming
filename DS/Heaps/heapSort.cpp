#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
  return a > b;
}

void heapify(vector<int> &v,int idx, int size) {
    int left = 2*idx;
    int right = 2*idx + 1;

    int min_idx = idx;
    int last_idx = size - 1;
    
    if(left <= last_idx and compare(v[left],v[idx])) {
      min_idx = left;
    }
    if(right <= last_idx and compare(v[right], v[min_idx])) {
      min_idx = right; 
    }

    if(min_idx != idx) {
      swap( v[min_idx],v[idx]);
      heapify(v,min_idx,size);
    }
  }
void buildHeap(vector<int> &v) {
  for(int i=(v.size()-1)/2;i>=1;i--) {
    heapify(v, i, v.size());
  }
}

void print(vector<int> v) {
  for(auto x: v) {
    cout << x << " ";
  }
}
void heapSort(vector<int> &v) {
  buildHeap(v);

  int n = v.size();

  //send n-1 elements at the end of vectors and heapify after every operation.
  while(n>1) {
    swap(v[1],v[n-1]);
    //shrink the space where heapify needs to be applied.
    n--;
    heapify(v, 1, n);
  }
}

int main() {

  vector<int> v;
  v.push_back(-1);

  int n;  cin >> n;

  int temp;
  for(int i=0;i<n;i++) {
    cin >> temp;
    v.push_back(temp);
  }
  print(v);
  cout << endl;
  heapSort(v);
  print(v);
  return 0;
}
