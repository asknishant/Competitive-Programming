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

void insertAtHead(node* &head, int data) {
  node* n = new node(data);
  n->next = head;
  head = n;
}

void insertNodeAtEnd(node* &head, int data) {

  if(head == NULL) {
    insertAtHead(head, data);
    return;
  }
  node* tail = head;
  while(tail->next!=NULL) {
    tail = tail->next;
  }
  node* n = new node(data);
  n->next = NULL;
  tail->next = n;
}

void insertAtMiddle(node* head, int data,int pos) {
  node* n = new node(data);
  int jumps = 0;
  while(jumps < pos-2) {
    head = head->next;
    jumps++;
  }
  n->next = head->next;
  head->next = n;
  
}

void print(node* head) {
  while(head!=NULL) {
    cout << head->data <<"-->";
    head = head->next;
  }
}

node* findMiddle(node* head) {
 
  if(head == NULL or head->next == NULL) {
    return head;
  }
  node* fast = head->next;  //Always point fast to head->next other wise mergeSort will give infinite loop.Dry run with two nodes to check.
  node* slow = head;

  while(fast != NULL and fast->next !=NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}

void buildList(node* &head) {
  int data;
  cin >> data;
  while(data != -1){
    insertNodeAtEnd(head,data);
    cin >> data;
  }
}
istream& operator>>(istream &is, node* &head) {
  buildList(head);
  return is;
}

// ostream& operator<<(ostream& os, node* &head) {
//   print(head);
//   return os;
// }

node* merge(node* a, node* b) {
  if(a == NULL) {
    return b;
  }
  if(b == NULL) {
    return a;
  }
  node* c;
  if(a->data < b->data) {
    c = a;
    c->next = merge(a->next, b);
  }  
  if(a->data >= b->data){
    c = b;
    c->next = merge(a, b->next);   
  }
  return c;
}

node* mergeSort(node* head) {
    //Base Case.
    if(head == NULL || head->next == NULL) {
      return head;
    }
    //Rec Case.
    //Mid point.
    node* mid = findMiddle(head);

    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    //Recursively sort.
    a = mergeSort(a);
    b = mergeSort(b);

    node* c = merge(a, b);
    return c;

}
int main() {
  node* head = NULL;
 
  // insertNodeAtEnd(head, 4);
  // insertNodeAtEnd(head, 3);
  // insertNodeAtEnd(head, 2);
  // insertNodeAtEnd(head, 9);
  // insertNodeAtEnd(head, 7);

  // print(head);

   cin >> head; 
   print(head); //Not using cout << head; as this will print every element after middle element.
   cout << endl;
   head = mergeSort(head);
   print(head);

  


  return 0;
}
