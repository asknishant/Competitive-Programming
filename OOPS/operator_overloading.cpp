#include <bits/stdc++.h>
using namespace std;

class Complex {

  int real;
  int img;
public:

  Complex() {

  }
  Complex(int r, int i) {
    real = r;
    img = i;
  }

  void setReal(const int r) {
    real = r;
  }
  void setImg(const int i) {
    img = i;
  }

  int getReal() const{
    return real;
  }
  int getImg() const{
    return img;
  }

  void print() {
    if(img>=0) {
      cout << real <<" + " << img <<"i";
    }
    if(img<0) {
      cout << real <<" - " << -img <<"i";
    }
  }
  
  //Passing object by reference here.We can also pass by value but that will take extra space.
  //But whenever we pass objects to constructors we must pass it by reference.
  void add(Complex &x) {
    real += x.real;
    img += x.img;
  }

  //Adddition using operator overloading.Whenever we will use + operator.
  void operator+(const Complex &x) {
    real += x.real;
    img += x.img;
  }

  void operator!() {
    img *= -1;
  }

  int operator[](string s) {
    if(s == "real") {
      return real;
    }else {
      return img;
    }
  }

};

//If we want to use operator overloading on two objects passing both of them inside a function then
//creating both of them outside of their respective classes is a good idea.
void operator>>(istream& cin, Complex& c) {
      int r1,i1;
      cin >> r1 >> i1;
      c.setReal(r1);
      c.setImg(i1);
      
      return cin;
}

void operator<<(ostream& os, Complex& c) {
  c.print();
}

int main() {

  Complex c1(5,3);
  Complex c2;
  c2.setImg(4);
  c2.setReal(1);

  c1.print();
  cout << endl;
  c2.print();
  cout << endl;

  c1.add(c2); //Value of c1 gets incremented.Value of c2 remains same.
              //Can be thought of as c1.+(c2)
  c1.print();
  cout << endl;
  !c1;
  c1.print();

  cout << c1["real"];

  //cin and cout are special classes of istream and ostream classes.
  // overloading  >>  and  << operator will not work as we cant change the existing classes.

  cout << endl << "Enter Real and imaginary part of Complex no.";
  Complex d;
  cin >> d;
  cout << d;

  return 0;
}
