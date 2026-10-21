#include<bits/stdc++.h>
using namespace std;


// actual topic opr[], find(),  at()

int main(){

    unordered_map<int, int> mp;
    mp[5] = 50;   // key 5 ku value 50 

    cout << mp.size() << " "; // map ka size is 1
    cout << mp[5] << " ";     //predict :  key 5 not exist so o/p is one and 5 inseted to the map , now the map size + 1 

    // mp[5] finds the existing key and returns its value, 50. It does not insert another key. so the actual output is => 50

    cout << mp[8] << " "; // output is 0. not exist in map.
    cout << mp.size();  // now tthe map size is 2 ( 5 -> 50 & 8 -> 0 )

    // trap

    // the thing is ek key ka do value hosakata hai ( freq ) but ek value ku do key nahi hosakta hai
    // always key must be uniq... 
    // this mp of key 5 and same key again with diff value creates a collion (ye collition re-solve techniq use karna hoga , chaining ya hashing ya kuch maths ka ( sqr , kcuh function etc ))....



    // NOTE : mp[5] = 50; mp[5] = 70;  Yahan existing key 5 ki value 50 se 70 ho jaati hai. Map ka size 1 hi rehta hai.
    
    // Correction 3: Same value multiple keys ke paas ho sakti hai. For example, key 5 aur key 8, dono ki mapped value 100 ho sakti hai
    // ex its can be :   mp[5] = 100; and mp[8] = 100;

    cout << "\n";

    return 0;
}