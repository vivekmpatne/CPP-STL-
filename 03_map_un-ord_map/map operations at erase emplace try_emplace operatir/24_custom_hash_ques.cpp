#include<bits/stdc++.h>
using namespace std;

struct PairHash{
    size_t operator()( const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ ( hash<int>{}(p.second) << 1 );
    }
};

int main(){

    unordered_map<pair<int,int>, int, PairHash> mp;

    mp[{2, 3}] = 10;
    mp[{3, 2}] = 20;

    cout << mp.size() << "\n"; // 2

    cout << "\n";

    return 0;
}