#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1, 2, 1};

    unordered_map<int, int> freq;

    for (int x : v) {
        freq[x]++;
    }

    cout << freq[3] << "\n"; // not exsist key 3. so now its insert 3 -> 0
    cout << freq.size() << "\n"; // size is 3 ( 1 -> 2, 2-> 1, 3-> 0)

    // Important trap: freq[3] sirf value read nahi karta; missing key ko insert bhi karta hai!
    

    cout << "\n";

    return 0;
}