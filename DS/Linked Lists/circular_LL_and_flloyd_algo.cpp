#include <bits/stdc++.h>
using namespace std;


class node {
  public:
  int data;
  node* next;

  node(int data) {
    this->data = data;
  }
};



void printList(node* head) {
  node* temp = head;
  while(head->next != temp) {
    cout << head->data <<"-->";
    head = head->next;
  }
  cout << head->data;
}



void push(node* &head, int data) {
  node* n = new node(data);
  node* temp = head;
  n->next = head;
  if(head==NULL) {
    n->next = n;
  } else {
    while(temp->next != head) {
      temp = temp->next;
    }
    temp->next = n;
  }
  head = n;
}


bool isCycle(node* head) {

  node* fast = head;
  node* slow = head;

  while(fast!=NULL or fast->next!=NULL) {
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow) {
      return true;
    }
  }
  return false;
}

//using Flloyd algo 
void remove_cycle(node* head) {
  node* fast = head;
  node* slow = head;
  node* prev;
  bool hasMeet = false;
  while(fast!=NULL or fast->next!=NULL) {
    if(!hasMeet) {
      fast = fast->next->next;
      slow = slow->next;
    } else {
      prev = fast;
      fast = fast->next;
      slow = slow->next;

      if(fast == slow) {
        prev->next = NULL;
        break;
      }
    }
    
    if(slow == fast) {
      slow = head;
      hasMeet = true;
    }
  } 
}

int main() {
  node* head = NULL;
 
  push(head, 10);
  push(head, 20);
  push(head, 30);
  push(head, 40);

  printList(head);
  cout << endl;
  if(isCycle(head)){
     cout << "Circular Linked list";
     remove_cycle(head);
  }

  if(!isCycle(head)) cout << "Cycle removed";
  return 0;
}
