#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    mp[5] = 50;

    cout << mp.count(8) << " ";  // return 0. not present, count not insert the missing key. 
    cout << mp.size() << " "; // size 1 
    cout << mp.count(5);   // returns 1. its present

    // unordered_map mein keys unique hoti hain, isliye count() ka result sirf 0 ya 1 ho sakta hai.


    cout << "\n";

    printf("=======================================\n");

    // Ab ek important difference: insert() vs []

    unordered_map<int, int> mp2;

    mp2[5] = 50;

    mp2.insert({5, 99});    // insert not overwrite the existing values. so  5 -> 50
                            // Key 5 pehle se exist karti hai, isliye insertion fail hota hai. Existing value 50 unchanged rehti hai.

    mp2.insert({8, 80});    // insert 8 ->  80

    cout << mp2[5] << " ";  // o/p => 50
    cout << mp2[8] << " ";  // o/p => 80
    cout << mp2.size() << "\n";     // o/p => 2

//  Operation	            |   Existing key par behavior
//---------------------------------------------------------------------------------
//  mp[key] = value	        |   Mapped value overwrite karta hai
//  mp.insert({key, value}) |	Existing mapped value unchanged rakhta hai
//  mp.emplace(key, value)	|   Existing key ho toh new element insert nahi karta


// Interview trap: insert() ka return value pair<iterator, bool> hota hai. second batata hai insertion successful hua ya nahi.


printf("========================================\n");

 
// Next prediction: insert() ka return value

    unordered_map<int, int> mp3;
    mp3[5] = 50;

    auto result = mp3.insert({5, 99});  

    cout << result.second << " ";      //  Insertion successful hui?	false yani 0
    cout << result.first->second;      // res.sec => return value => 50
    cout<<"\n";

//    Expression	| Meaning	                            | Value
//-------------------------------------------------------------------------------------
//    result.second	| Insertion successful hui? 	        | false yani 0
//    result.first	| Existing element ka iterator	        |Key 5 wale element ka iterator
//    result.first->second |	Us element ki mapped value	|50

// Important: result.first->second mein second ka matlab pair ke second member se related hai, jo map ki mapped value hai. Ye 1 nahi hoga.

    return 0;
}