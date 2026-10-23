#include<bits/stdc++.h>
using namespace std;

int main(){

    
    // Next concept: reserve() and rehash in unordered_map 
    // Hashing deeply samajhne ke liye ab ek important concept: rehash.

    unordered_map<int, int> mp;

    mp.reserve(100);

    cout << mp.size() << " "; // pred : 0. reserve kiya value todi put kiya
    cout << mp.empty();       // pred : 0. map empty hoga , already empty hai 

    // actual : 0 and 1


    /* 
    
    1. mp.size() → 0 : 
        reserve(100) ka matlab 100 elements insert karna nahi hai. Ye hash table ko future insertions ke liye capacity prepare karne deta hai.
            - size() → currently kitne elements stored hain.
            - reserve(100) → approximately 100 elements accommodate karne ke liye bucket capacity arrange karta hai, current load factor ko dhyan mein rakhte hue.
        Isliye elements 0, size 0.
    
        
    2. mp.empty() → 1 :
        empty() check karta hai ki container mein koi element hai ya nahi.
            - Empty hai → true → print 1
            - Empty nahi hai → false → print 0

    
        Important distinction: empty() ka matlab hai “kya elements zero hain?”, na ki “kya memory ya buckets allocated hain?”
    
    */

    cout << "\n";

    return 0;
}