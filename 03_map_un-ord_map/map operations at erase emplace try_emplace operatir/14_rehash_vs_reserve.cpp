#include<bits/stdc++.h>
using namespace std;

/*

    concept: rehash() vs reserve()

        Dono similar lagte hain, lekin purpose alag hai:
        Function  |	Kya specify karte ho?
        --------------------------------------------------
        rehash(n) |	Minimum bucket count ki requirement
        reserve(n)|	Elements accommodate karne ki capacity

*/

int main(){

    
    unordered_map<int, int> mp;
    mp.max_load_factor(0.5);

    mp.rehash(20);
    cout << mp.bucket_count() << " "; // 20 or 23 ( depend on internal)

    mp.reserve(20);
    cout << (mp.bucket_count() >= 40) << " "; // 1
    cout<< mp.bucket_count() << " "; // 41 
    cout << mp.size() << " "; // 0 ( no elements (key, val) in hashmap)

    cout << "\n";

    /*
        Tumhare answers check karte hain : 
        Expression	                         |  Tumhara prediction |Result
        -----------------------------------------------------------------
        mp.rehash(20) ke baad bucket_count() |	20 ya 23	Exact count implementation-dependent hai, lekin 20 se kam nahi hona chahiye

        mp.reserve(20) ke baad bucket_count() >= 40 | 	1 | 	Correct, because max_load_factor = 0.5

        mp.bucket_count()  |	41	       |  Tumhare g++ run ka actual result
        mp.size()	       |    0	       | Correct, koi elements insert nahi hue

    Formula:
        
        req buckets >= ( req elements/maxLoadFactor )

         20 / 0.5 => 40 

    Isliye reserve(20) ke baad bucket count at least 40 hona chahiye. Tumhare implementation ne 41 choose kiye.

    Yaad rakho: rehash(20) bucket count ke baare mein hai, jabki reserve(20) 20 elements accommodate karne ki capacity ke baare mein hai.
    */

    return 0;
}