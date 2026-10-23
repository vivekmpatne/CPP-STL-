#include<bits/stdc++.h>
using namespace std;

int main(){

    // Next question: count() vs find()

    unordered_map<int, int> mp;

    mp[5] = 50;

    cout << mp.count(5) << " "; // 1
    cout << mp.count(9) << " "; // 0
    cout << mp.size();   // 1

    // Yaad rakhne wali baat: unordered_map mein keys unique hoti hain, isliye count(key) ka result sirf 0 ya 1 hota hai.

    

    cout << "\n";

    return 0;
}