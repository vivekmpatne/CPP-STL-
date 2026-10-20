#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {10, 20, 30, 40}; //s => 4
    auto it = v.begin() + 1;     // it => 20
    it = v.erase(it);            // it removes 20, and 10, 30, 40 => size=3
    cout << *it << " " << v.size() << "\n"; // it is 30 and size is 3
    

    return 0;
}