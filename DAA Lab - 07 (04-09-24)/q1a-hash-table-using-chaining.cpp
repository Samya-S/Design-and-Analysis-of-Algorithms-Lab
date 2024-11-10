#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashMap {
private:
    int numOfElements, capacity;
    Node** arr;

    int hashFunction(string key) {
        int sum = 0, factor = 31;
        for (int i = 0; i < key.length(); i++) {
            sum = ((sum % capacity) + (((int)key[i]) * factor) % capacity) % capacity;
            factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
        }
        return sum;
    }

public:
    HashMap(int cap = 5) {
        capacity = cap;
        numOfElements = 0;
        arr = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = nullptr;
        }
    }

    void insert(string key, string value) {
        int bucketIndex = hashFunction(key);
        Node* newNode = new Node(key, value);

        if (arr[bucketIndex] == nullptr) {
            arr[bucketIndex] = newNode;
        } else {
            newNode->next = arr[bucketIndex];
            arr[bucketIndex] = newNode;
        }
    }

    void deleteKey(string key) {
        int bucketIndex = hashFunction(key);
        Node* prevNode = nullptr;
        Node* currNode = arr[bucketIndex];

        while (currNode != nullptr) {
            if (key == currNode->key) {
                if (currNode == arr[bucketIndex]) {
                    arr[bucketIndex] = currNode->next;
                } else {
                    prevNode->next = currNode->next;
                }
                delete currNode;
                return;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
    }

    string search(string key) {
        int bucketIndex = hashFunction(key);
        Node* bucketHead = arr[bucketIndex];

        while (bucketHead != nullptr) {
            if (bucketHead->key == key) {
                return bucketHead->value;
            }
            bucketHead = bucketHead->next;
        }

        return "Oops! No data found.\n";
    }

    ~HashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* currNode = arr[i];
            while (currNode != nullptr) {
                Node* temp = currNode;
                currNode = currNode->next;
                delete temp;
            }
        }
        delete[] arr;
    }
};

int main() {
    HashMap mp;
    mp.insert((string) "key1", (string) "val1");
    mp.insert((string) "key2", (string) "val2");
    mp.insert((string) "key3", (string) "val3");
    mp.insert((string) "key4", (string) "val4");
    mp.insert((string) "key5", (string) "val5");

    cout << mp.search((string) "key3") << endl;
    cout << mp.search((string) "key1") << endl;
    cout << mp.search((string) "key2") << endl;
    cout << mp.search((string) "key5") << endl;
    cout << mp.search((string) "key4") << endl;

    cout << mp.search((string) "key6") << endl;

    mp.deleteKey((string) "key5");
    cout << "After deletion: \n";
    cout << mp.search((string) "key5") << endl;

    return 0;
}