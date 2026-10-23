#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    mp[27] = 100;
    mp[47] = 200;

    mp.rehash(50);

    cout << mp.size() << " ";  // size is 2 
    cout << (mp.bucket_count() >= 50) << " "; // 1 (true)
    cout << mp[27] << " " << mp[47];  // 100, 200


    cout << "\n";

    /* 
        rehash() : 
            Ab samjhenge ki bucket count change hone par hashing ka behavior kaise badalta hai.
        
        Hint: rehash() bucket structure ko change kar sakta hai, lekin existing key-value pairs ko delete nahi karta.
        
    */

    return 0;
}