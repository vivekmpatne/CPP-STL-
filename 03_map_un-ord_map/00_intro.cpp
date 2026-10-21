#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<int, int> a;            // balanced binary search tree
    unordered_map<int, int> b;  // hash table

    a[3] = 30;
    a[1] = 10;
    a[2] = 20;

    b[3] = 30;
    b[1] = 10;
    b[2] = 20;

    for (auto p : a) cout << p.first << " "; // 1 2 3 // Sorted by key
    cout << "\n";
    for (auto p : b) cout << p.first << " ";
    cout << "\n";
    // 3 1 2 // No guaranteed order.  yes true i got out put : 2 1 3

}