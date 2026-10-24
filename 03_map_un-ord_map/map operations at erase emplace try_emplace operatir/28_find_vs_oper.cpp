#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    mp[1] = 10;
    mp[2] = 20;

    auto it = mp.find(3); // return mp.end if not found 

    if (it == mp.end()) {  // mp.end == mp.end so 
        cout << "Not found\n"; // o/p is Not Found
    }

    cout << mp.size() << "\n"; // size is 2. find(3) not insert value if not present 


    cout << "\n";

    return 0;
}