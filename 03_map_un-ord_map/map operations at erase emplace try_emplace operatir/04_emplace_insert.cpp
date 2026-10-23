#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
    emplace() ek pair return karta hai:

    - result.first → iterator, jo existing ya newly inserted element ko point karta hai.

    - result.second → bool, jo batata hai ki naya element insert hua ya nahi.

    Expression	           | Meaning
    ----------------------------------------------------------
    result.second == true  | Naya key insert hua
    result.second == false | Key pehle se exist karta tha, insertion nahi hua
    
    */

    // emplace() vs insert()

    unordered_map<int, int> mp;
    mp.emplace(5, 50);  // mp = { {5, 50} }, size = 1

    auto result = mp.emplace(5, 99); // Key 5 already present hai. unordered_map mein duplicate key allowed nahi hai. Insertion failed.  result.second = false, aur existing value 50 hi rahegi.

    cout<<result.second << " "; // predict : 1  => actual : 0
    cout<<mp[5] << " ";  // pre: 99  =>   act : 50
    cout<<mp.size();    //  pre : 1 => act :  1

    cout<<"\n";

    unordered_map<int, int> mp2;
    mp2[5] = 50;
    mp2[5] = 99;  // update the value of mapped key.
    cout << mp2[5] <<"\n"; // 99 value changed.

    // mp.emplace(5, 99); → key 5 already hai toh existing value ko update nahi karta.

    // Next Prediction 

    printf("======================\n");

    unordered_map<int, int> mp3;

    auto a = mp3.emplace(5, 50);  // insert 5, 50 size 1
    auto b = mp3.emplace(5, 99);  // not insert size 1
    auto c = mp3.emplace(8, 80);  // insert 8, 80 size 2

    cout << a.second << " ";     // 1
    cout << b.second << " ";     // 0
    cout << c.second << " ";     // 1
    cout << mp3.size();          // 2

    /*
        Operation	Key exists?	Result
        mp.emplace(5, 99)	Yes	Value unchanged, insertion status false
        mp[5] = 99	Yes	Existing value becomes 99
        mp.emplace(8, 80)	No	New key inserted, insertion status true
    */
    
    cout << "\n";                    

    printf("================\n");
    // insert() vs emplace()

    unordered_map<int, int> mp4;
    mp4.insert({5, 50});               
    auto result4 = mp4.insert({5, 99});  // already exist so un-success to insert. or failed to unsert.

    cout << result4.second << " ";  // 0.
    cout << mp4[5];  // 50

    cout<<"\n";

    printf("=========================\n");

    /*

    Ab ek subtle difference check karte hain : 

    insert() aur emplace() dono duplicate key ko overwrite nahi karte. Lekin operator[] missing key ke case mein kya karta hai, ye important hai.

    */

    unordered_map<int, int> mp5;

    cout << mp5[7] << " "; // 0 ,  key 7 insert ho gayi
    cout << mp5.size();   // 1

    // Output 0 1 aata hai because mp[7] missing key ko automatically insert karta hai, with default int value 0.

    cout<<"\n";

    



    return 0;
}