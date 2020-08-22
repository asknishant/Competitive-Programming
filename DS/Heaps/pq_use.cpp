#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
class Person {
  public:
    int age;
    string name;

    Person(int age,string name) {
    this->age = age;
    this->name = name;
    }
};

class PersonCompare {
  public:
    bool operator()(Person A, Person B) {
      //cout << "Comparing " << A.age << "" << B.age;
      return A.age > B.age;
    }
};

int main() {

  priority_queue<Person, vector<Person>, PersonCompare> pq;
  for(int i=0;i<5;i++) {
    int age;  cin >> age;
    string name; cin >> name;
    
    Person p(age, name);
    pq.push(p);
  }

  int k = 3;

  for(int i=0;i<5;i++) {
    Person p = pq.top();
    cout <<p.name <<" " << p.age<<endl;
    pq.pop();
  }
}
