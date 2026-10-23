#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> mp = {{5, 50}};

    try {
        cout << mp.at(5) << " "; // 50
        cout << mp.at(8) << " "; // expection throw (out_of_range)
        cout << "after";         // after print nahi hoga
    } catch (const out_of_range&) {  // exception jo throw kiya na co idar catch karliya ( afar expection hai toh ye block ke under ka exicute hoga )
        cout << "caught";   // caught print hoga
    } 

    cout << " " << mp.size() <<"\n"; // size is one
}