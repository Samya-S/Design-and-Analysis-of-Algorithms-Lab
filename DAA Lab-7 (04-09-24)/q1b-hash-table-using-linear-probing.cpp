#include <bits/stdc++.h>
using namespace std;

class HashMap {
private:
    struct Entry {
        char* key;
        char* value;
        bool isOccupied;
        bool isDeleted;

        Entry() : key(nullptr), value(nullptr), isOccupied(false), isDeleted(false) {}
    };

    Entry* arr;
    int capacity;
    int numOfElements;

    int hashFunction(char* key) {
        int sum = 0, factor = 31;
        for (int i = 0; i < strlen(key); i++) {
            sum = (sum + key[i] * factor) % capacity;
            factor = (factor * 31) % capacity;
        }
        return sum % capacity;
    }

    int probe(int bucketIndex) {
        // Linear probing: find the next available index
        int originalIndex = bucketIndex;
        while (arr[bucketIndex].isOccupied && !arr[bucketIndex].isDeleted) {
            bucketIndex = (bucketIndex + 1) % capacity;
            if (bucketIndex == originalIndex) {
                return -1;  // Table is full
            }
        }
        return bucketIndex;
    }

public:
    HashMap(int cap = 5) {
        capacity = cap;
        numOfElements = 0;
        arr = new Entry[capacity];
    }

    void insert(char* key, char* value) {
        if (numOfElements == capacity) {
            cout << "HashMap is full!" << endl;
            return;
        }

        int bucketIndex = hashFunction(key);
        bucketIndex = probe(bucketIndex);

        if (bucketIndex == -1) {
            cout << "Unable to insert: HashMap is full." << endl;
            return;
        }

        arr[bucketIndex].key = key;
        arr[bucketIndex].value = value;
        arr[bucketIndex].isOccupied = true;
        arr[bucketIndex].isDeleted = false;
        numOfElements++;
    }

    void deleteKey(char* key) {
        int bucketIndex = hashFunction(key);
        int originalIndex = bucketIndex;

        while (arr[bucketIndex].isOccupied) {
            if (!arr[bucketIndex].isDeleted && strcmp(arr[bucketIndex].key, key) == 0) {
                arr[bucketIndex].isDeleted = true;
                arr[bucketIndex].isOccupied = false;
                numOfElements--;
                return;
            }
            bucketIndex = (bucketIndex + 1) % capacity;
            if (bucketIndex == originalIndex) {
                break;  // Back to the original index, key not found
            }
        }

        cout << "Key not found." << endl;
    }

    char* search(char* key) {
        int bucketIndex = hashFunction(key);
        int originalIndex = bucketIndex;

        while (arr[bucketIndex].isOccupied) {
            if (!arr[bucketIndex].isDeleted && strcmp(arr[bucketIndex].key, key) == 0) {
                return arr[bucketIndex].value;
            }
            bucketIndex = (bucketIndex + 1) % capacity;
            if (bucketIndex == originalIndex) {
                break;  // Back to the original index, key not found
            }
        }

        return (char*)"Oops! No data found.\n";
    }

    ~HashMap() {
        delete[] arr;
    }
};

int main() {
    HashMap mp;
    mp.insert((char*)"key1", (char*)"val1");
    mp.insert((char*)"key2", (char*)"val2");
    mp.insert((char*)"key3", (char*)"val3");
    mp.insert((char*)"key4", (char*)"val4");
    mp.insert((char*)"key5", (char*)"val5");

    cout << mp.search((char*)"key3") << endl;
    cout << mp.search((char*)"key1") << endl;
    cout << mp.search((char*)"key2") << endl;
    cout << mp.search((char*)"key5") << endl;
    cout << mp.search((char*)"key4") << endl;

    cout << mp.search((char*)"key6") << endl;

    mp.deleteKey((char*)"key5");
    cout << "After deletion: \n";
    cout << mp.search((char*)"key5") << endl;

    return 0;
}