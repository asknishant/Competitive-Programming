//Very immportant.

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node {

public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T val) {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

template<typename T>
class HashTable {
    int table_size;
    int current_size;
    Node<T> **table; 

    int hashFn(string key) {
        int idx = 0;
        int p=1;
        for(int i=0;i<key.length();i++) {
            idx = idx + (key[i]*p)%table_size;
            idx %= table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
public:
    HashTable(int ts = 7) {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, T value) {
        int idx = hashFn(key);

        Node<T> * n = new Node<T>(key, value);
        n->next = table[idx];
        table[idx] = n;;
        current_size++;
    }

    void print() {

        for(int i=0;i<table_size;i++) {
            cout << "Bucket" << i << "-->";
            Node<T> * temp = table[i];
            while(temp != NULL) {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T search(string key) {

    }

    void erase(string key) {

    }
};
int main() {
    HashTable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi",20);
    price_menu.insert("BurgerPizza",150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print();
}
