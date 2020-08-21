#include <iostream>
#include <queue>

using namespace std;

int main() {

  priority_queue<int> pq; //this is by  default max heap.
  priority_queue<int, vector<int>, greater<int> > pq1;  //Getting the reversed vector.
  int n;  cin >> n;

  for(int i=0;i<n;i++){
    int no; cin >> no;
    pq1.push(no);  //O(logN)
  }

  for(int i=0;i<n;i++) {
    cout << pq1.top() << " ";  //O(1)
    pq1.pop(); //O(logN)
  }
  return 0;
}
