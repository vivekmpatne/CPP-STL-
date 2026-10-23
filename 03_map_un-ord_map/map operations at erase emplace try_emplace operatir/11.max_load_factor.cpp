#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
        concept: max_load_factor() :
            load_factor() current ratio batata hai, jabki max_load_factor() woh threshold batata hai jise container rehashing decide karne mein use karta hai.
    */

    unordered_map<int, int> mp;

    cout << mp.max_load_factor() << " "; // pred : 0
    // actul : Usually 1.0 in common C++ implementations => 1
 
    mp.max_load_factor(0.5); 
    mp.reserve(10);

    // LF => size / bkt...     size => LF*Bkt => 0.5*10 => 5 size 

    cout << mp.max_load_factor() << " "; // 0.5. right.

    cout << mp.size() << " ";  // pred : 5
    // act : 0, kyunki koi element insert hi nahi kiya

    cout << (mp.bucket_count() >= 20); // 0 ( false , its 10)
    // Guaranteed nahi; implementation ke bucket count par depend karta hai
    
    /*
    
    1. max_load_factor() size set nahi karta :
        mp.max_load_factor(0.5);
        mp.reserve(10);


    Yahan reserve(10) ka matlab hai ki map ko 10 elements accommodate karne ke liye prepare karo, maximum load factor 0.5 ke hisaab se.

        Approximate required bucket count:

                buckets >= (10/0.5) = 20
        


        Isliye reserve(10) ke baad bucket count at least 20 hona chahiye. Lekin size() phir bhi 0 rahega, kyunki abhi koi key-value pair insert nahi hua.

    2. Initial max_load_factor() usually 1.0 hota hai
    Common implementations mein default maximum load factor 1.0 hota hai. 
    
    Isliye tumhare code ka expected output roughly aisa hoga:
    1 0.5 0 1

    */


    cout << "\n";

    // newxt quick ques: 
    unordered_map<int, int> mp2;
    
    mp2.max_load_factor(0.5);
    mp2.reserve(10);
    mp2[1] = 100;
    mp2[2] = 200;

    cout << mp2.size() << " "; // 2
    cout << mp2.load_factor() <<" "; 

    // predict : LF => size / bkt_cnt =>  2/10 => 0.5

    // actual : 0.086  
    // bkt_cnt => 2/0.086 => 23.36 

    /*
        main formula : 
            
            load_factor = size / bkt_cnt

        Isko rearrange kar sakte ho:

            size = load_factor * buket_cnt

        Lekin max_load_factor() actual load_factor() ke equal hona zaroori nahi hai.
    */

    // relation 

    /*
        reserve(n) => bkt capacity approx >= ( n/max_load_factor )

        For example, reserve(10) aur max_load_factor(0.5) ke liye at least 20 buckets required hain.
    */


    return 0;
}