//https://www.hackerrank.com/challenges/tree-top-view/problem

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
         queue<pair<int,Node*>> q;
        map<int,Node*> mp;
        
        q.push(make_pair(0,root));
        while(!q.empty()) {
            
            Node* currNode = q.front().second;
            auto i = q.front(); //auto is required to access the q.front().If you write 
                                // i instead of q.front it will give you segmentation                                     
                                //fault.auto keyword helps the pair object to be                                         
                                //inserted to map object at runtime.
            q.pop();
            if(i.second == NULL) {
                continue;    
            }
            mp.insert(i);
            q.push(make_pair(i.first + 1,i.second->right));
            q.push(make_pair(i.first - 1,i.second->left));
        }
        
         for(auto x : mp)    cout << x.second->data<< " ";
    }

}; //End of Solution
