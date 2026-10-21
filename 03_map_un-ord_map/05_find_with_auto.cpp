#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;
    mp[5] = 50;

    auto it = mp.find(5);
    
    // mp.find(key) if we try to find then its give Segmentation fault (core dumped)

    cout << it->first << " ";   // 5 
    cout << it->second;         // 50

    cout << "\n";

    // auto it = mp.find(5); key 5 ko search karta hai aur iterator return karta hai.



/*  it->first mapped element ki key deta hai, yani 5.
    it->second us key ki mapped value deta hai, yani 50.
    it ek iterator hai, actual key-value pair nahi.

Ek important detail: Agar key exist nahi karti, toh find() mp.end() return karta hai. Us case mein it->first ya it->second access karna valid nahi hoga. */



    printf("===============================\n");



    return 0;
}