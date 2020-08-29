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

    void rehash() {
       
        Node<T> ** oldTable = table;
        int oldTableSize = table_size; 

        table_size = 2*table_size;
        table = new Node<T>*[table_size];

        for(int i=0;i<table_size;i++){
            table[i] = NULL;
        }

        current_size = 0;

        for(int i=0;i<oldTableSize;i++) {
            Node<T> *temp = oldTable[i];
            while(temp!=NULL) {
                insert(temp->key,temp->value);
                current_size++;
                temp = temp->next;
            }
            //delete oldtable
            if(oldTable[i] != NULL) {
                delete oldTable[i];//Here delete keyword invokes the first pointer of the row then destructor of the node is being recursively called.
            }
        }
        delete [] oldTable;
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

        //Rehashing
        float load_factor = current_size/(1.0*table_size);

        if(load_factor > 0.7) {
            rehash();
        }
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

    T* search(string key) {
        
        int idx = hashFn(key);
       
        Node<T> *temp = table[idx]; //idx gives the row at which key and value are present which are required.
        while(temp!=NULL) {
            if(temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }
        
        //If the key is not present we will return a null pointer as T is of unknown type.
        return NULL;
    }

    void erase(string key) {
        int idx = hashFn(key);
    
        Node<T> *temp = table[idx]; //idx gives the particular row
        Node<T> * prev = temp;
        while(temp!=NULL) {
            
            
            if(temp->key == key) {
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
           
        }
        
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

    int *price = price_menu.search("Noodles");
    if(price == NULL) {
        cout << "Not Found";
    } else {
        cout << "Price is" << *price;//As we are getting pointer to the price.
    }
    price_menu.erase("Burger");
    price_menu.print();
}
