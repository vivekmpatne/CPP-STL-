 #include<bits/stdc++.h>
using namespace std;

int main(){

    /* 
        Important correction: reserve(100) ka matlab exactly 100 buckets hona nahi hai. Iska matlab hai ki container ko kam se kam 100 elements accommodate karne layak bucket capacity arrange karni hai, current max_load_factor() ko dhyan mein rakhte hue. Actual bucket_count() implementation ke hisaab se 100 se zyada bhi ho sakta hai.

        Ab hashing ka next concept: load_factor()
        load_factor() batata hai ki average har bucket mein kitne elements hain.

        Formula:  load factor = size() / bucket_count()

    */

    unordered_map<int, int> mp;

    mp.reserve(100);  // bukt 
    mp[1] = 10;    // size 1
    mp[2] = 20;    // size 2

    cout << mp.size() << " ";          // size 2
    cout << mp.bucket_count() << " ";  // 100 
    cout << mp.load_factor();          // load_factor => 2/100 => 0.02

    // actial o/p => size : 2 . bkt_cnt => 103 LF => (2/103) => 0.019

    /*
        reserve(100) ka matlab hai ki map ko current max_load_factor() ke hisaab se kam se kam 100 elements accommodate karne ki capacity arrange karni hai.

        C++ standard exact bucket count specify nahi karta. Implementation apni internal bucket-sizing policy use karti hai. Tumhare compiler ki library ne 103 buckets choose kiye.

            - 100 → requested element capacity, buckets ki exact count nahi.
            - 103 → implementation ke choice ke according actual bucket count.
            - 2 → actual stored elements.
            - 0.0194... → 2 / 103, yani actual load factor.

        Kya har bucket mein ek element hota hai?
        Nahi. Bucket ka matlab element nahi hota. Multiple elements ek bucket mein aa sakte hain, agar unki keys hash hokar usi bucket mein map hon. Isi ko collision kehte hain.

        Aur koi special null bucket add karke count nahi kiya ja raha. bucket_count() sirf bucket count batata hai.
    */

    cout << "\n";

    return 0;
}