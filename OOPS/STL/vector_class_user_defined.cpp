//Replica of the original vector class.

#include <iostream> 
using namespace std;

class Vector {
  //Data members
  int *arr;
  int currSize;
  int maxSize;

public:
  Vector(int defaultSize = 4) {
    maxSize = defaultSize;
    currSize = 0;
    arr = new int[maxSize];
  }

  void push_back(int data) {
    if(currSize == maxSize) {
      //Increase the size of vector.
      int* oldArr = arr;
      arr = new int[2*maxSize];
      maxSize *= 2;

      for(int i=0;i<currSize ;i++) {
        arr[i] = oldArr[i];
      }

      delete [] oldArr;
    }
    arr[currSize] = data;
    currSize++;
  }
  bool empty() {
    return currSize;
  }
  void pop_back() {
    if(!empty()) {
      currSize--;
    }
  }

  void print() {
    for(int i=0;i<currSize;i++) {
      cout << arr[i] << " ";
    }
  }

  int at(int i) {
    return arr[i];
  }

  //Operator overloading
  void operator()(string s) {
    cout << "() got overloaded";
  }

  int& operator[](int i) {
    return arr[i];
  }
};
int main() {

  Vector v;
  //Operator () all
  v("This is string"); //THis is not constructor .This is operatir overloading
  
  for(int i=0;i<=5;i++) {
    v.push_back(i*i);
  }
  v.print();

  for(int i=0;i<5;i++) {
    cout << v[i] <<endl;
  }

  v[2] = 8; //FOr = or /= or any other operator to be used with [] we must return the reference of the data type from the [] overloaded function.
  v[2] /= 6;
  return 0;
}
