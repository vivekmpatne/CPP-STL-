#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    mp[1] = 10;
    mp[2] = 20;

    auto it = mp.find(1);  // Valid iterator

    mp.rehash(100);        // All iterators invalidated

    cout << it->second << "\n"; // UB: invalid iterator use ho raha hai

    // Bhai, output 10 aaya, lekin correct answer B — Undefined Behaviour (UB) hai. Ye important OA trap hai!


    cout << "\n";

    return 0;
}