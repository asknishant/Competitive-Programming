#include <bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* left;
  node* right;

  node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

node* insertBST(int data, node* root) {

  if(root == NULL) {
    return new node(data);
  }

  if(data >= root->data) {
    root->right = insertBST(data,root->right);
  } else if(root->data > data) {
    root->left = insertBST(data, root->left);
  }
  return root;
}

node* build() {
  
  int d;
  cin >> d;
  node* root = NULL;
  while(d != -1) {
    root = insertBST(d,root);
    cin >> d;
  }
  return root;
}

class LinkedList {
  public:
  node* head;
  node* tail;
};

LinkedList flatten(node* root) {
  LinkedList l;
  
  //Base case.
  if(root == NULL) {
    l.tail = l.head = NULL;
    return l;
  }
  
  //Leaf node
  if(root->left == NULL and root->right == NULL) {
    l.head = root;
    l.tail = root;
    return l;
  }
  
  //Left node is not null.
  if(root->left != NULL and root->right == NULL) {
    LinkedList leftLL = flatten(root->left);
    leftLL.tail->right = root;

    l.head = leftLL.head;
    l.tail = root;

    return l;
  }

  //Right node is not null.
  if(root->left == NULL and root->right != NULL) {
    LinkedList rightLL = flatten(root->right);
    root->right = rightLL.head;

    l.head = root;
    l.tail = rightLL.tail;
    
    return l;
  }

  //Both the sides are not null

  LinkedList leftLL = flatten(root->left);
  LinkedList rightLL = flatten(root->right);

  leftLL.tail->right = root;
  root->right = rightLL.head;

  l.head = leftLL.head;
  l.tail = rightLL.tail;
  return l;
}
void bfs(node* root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    node* f = q.front();
    if(f == NULL) {
      cout << endl;
      q.pop();
      if(!q.empty()) {
        q.push(NULL);
      }
    }
    else {
      cout << f->data << " ";
      q.pop();
      if(f->left) {
        q.push(f->left);
      }
      if(f->right) {
        q.push(f->right);
      }
    }
  }
}
int main() {

  node* root = build();
  bfs(root);
  LinkedList l = flatten(root);
  node* temp = l.head;
  while(temp!=NULL) {
    cout << temp->data << "-->";
    temp = temp->right;
  } 
  cout << endl;

  return  0;
}
