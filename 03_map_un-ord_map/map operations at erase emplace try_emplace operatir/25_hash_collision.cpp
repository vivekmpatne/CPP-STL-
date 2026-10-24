#include<bits/stdc++.h>
using namespace std;

struct PairHash{
    size_t operator()(const pair<int, int> &p) const{
        return hash<int>{}(p.first) ^ ( hash<int>{} (p.second) << 1);
    }
};

int main(){

    unordered_map<pair<int,int>, int, PairHash> mp;

    mp[{2, 3}] = 10;
    mp[{4, 5}] = 20;

    cout << mp.size() << "\n"; // 2
    cout << mp[{2, 3}] << "\n"; // 10 

    /*
        Assume dono pairs ka hash same hai:
            - mp.size() → 2, kyunki dono keys alag hain.
            - mp[{2, 3}] → 10, kyunki us pair ki mapped value 10 hai.
        Important OA concept
        Same hash ≠ same key.

        Hash collision hone par unordered_map equality check karta hai taaki different keys ko distinguish kar sake.
        
    */


    cout << "\n";

    return 0;
}