#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    cout << mp.count(7) << "\n"; // 0 (not present)
    // count => return 0 if missing 

    cout << mp.size() << "\n";   // 0 

    cout << mp[7] << "\n";       // not present , and now inserted 7->0, size of 1 
    cout << mp.size() << "\n"; // size if 1

    /*
        Operation	  |   Missing key par kya hota hai?
        ----------------------------------------------------
        mp.find(key)  |	mp.end() return karta hai
        mp.count(key) |	0 return karta hai
        mp.at(key)	  |  std::out_of_range exception throw karta hai
        mp[key]	      |  Key insert karta hai; value default-initialize hoti hai
        mp.insert({key, value})  |  Key insert karne ki koshish karta hai; existing key ko overwrite nahi karta
    */

    // next prediction 
    printf("\n======\n");
    // insert vs operator[]

    unordered_map<int, int> mp2;

    mp2.insert({5, 50});  // 5 -> 50
    mp2.insert({5, 100}); // 5 exsit so no overwrite

    cout << mp2.size() << "\n"; // size is one
    cout << mp2[5] << "\n"; // 50

    mp2[5] = 200;  // updated => 5 -> 200

    cout << mp2.size() << "\n"; // size if still one
    cout << mp2[5] << "\n";  // 200 (updated one)

    /*
        Ab tak tumne kya master kiya? : 

        Tum ab in operations ka difference correctly identify kar paa rahe ho:

        - insert() → existing key ko overwrite nahi karta.
        - mp[key] = value → existing key ki value overwrite karta hai.
        - count() → key ki presence check karta hai, insert nahi karta.
        - find() → missing key par end() return karta hai.
        - mp[key] → missing key par default-initialized value ke saath entry insert karta hai.

    */

    //next prediction(3)
    printf("\n=========\n");

    unordered_map<int, int> mp3;
    
    auto p1 = mp3.insert({5, 50});
    auto p2 = mp3.insert({5, 100});

    /*
        Ismein:
    - .first → iterator, jo inserted element ya already-existing element ko point karta hai.

    - .second → bool, jo batata hai ki insertion successful hua ya nahi.

    */

    cout<< p1.second<<"\n"; // 1 (inserted successfull)
    cout<< p2.second<<"\n"; // 0 (not able to insert, already exsit)
    cout<< p2.first->second<<"\n";  // Iterator existing entry {5, 50} ko point karta hai 50 (alreadu excist and insert don't update it) 
    
    // cout<< p1.first->first<<"\n"; // 5
    // cout<< p2.first->first<<"\n"; // 5

    // insert() kya return karta hai?
    // insert() ek pair return karta hai : pair<iterator, bool>



    cout << "\n";

    return 0;
}