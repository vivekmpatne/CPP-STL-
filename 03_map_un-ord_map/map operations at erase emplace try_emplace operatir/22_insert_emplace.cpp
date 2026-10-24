#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    auto a = mp.emplace(1, 10);  // emplace ka return type pair<iterator, bool>
    auto b = mp.emplace(1, 20);

    cout << a.second << "\n"; // 1 
    cout << b.second << "\n"; // 0 
    cout << b.first->second << "\n"; // 10 
    cout << mp.size() << "\n"; // 1

    // a.sec means -> pair<itr, bool> bool hai true ya false...  ye itr n itr ka sec mean value print hoga  

    /*
        | Expression       |       Meaning 
        --------------------------------------------------
        | `a.first`        | Iterator to the inserted element, ya duplicate key hone par existing element 
        | `a.second`       | `bool` — insertion successful hui ya nahi 
        | `a.first->first` | Element ki key 
        | `a.first->second`| Element ki mapped value 
    */

    // Next Question — Iterator + emplace() (Medium)
    printf("\n========================\n");

    unordered_map<int, int> mp2;

    mp2.emplace(2, 20); //Return value ignore kar di
    auto p = mp2.emplace(3, 30);  // // Return value p mein store ki
    auto q = mp2.emplace(3, 99); // // Return value q mein store ki

    cout << p.first->first << "\n"; // p.itr->key => 3 
    cout << p.first->second << "\n"; // p.itr->val => 30
    cout << q.second << "\n";  // q.bool => 0 (not inserted key exsist)
    cout << q.first->second << "\n"; // q.itr->vlaue => 30
    cout << mp2.size() << "\n"; // size is 2 ( p ka size + mp2.emplace inserted 2, 30 but didn't init with itr like how done for p and q)

    /*
        Yaad rakh:
            - emplace() map mein insertion attempt karta hai.
            - auto p = emplace(...) insertion ka result bhi store karta hai.
            - Iterator variable banana insertion ke liye compulsory nahi hai.
            - size() map mein present unique keys ki total count deta hai.
    */


    // Next Question — operator[] vs emplace() (Medium)
    // predict 3
    printf("\n==================\n");

    unordered_map<int, int> mp3;

    mp3[5] = 50; // 5->50 size 1 

    auto r = mp3.emplace(5, 100); 

    cout << r.second << "\n"; // 0. already exsist
    cout << r.first->second << "\n"; // r.itr->value => 50 (pointing to old value itself )

    mp3[5] = 200; // now 5 -> 200 ( updated value to key 5 )

    cout << r.first->second << "\n"; // 200 (not 50)
    cout << mp3[5] << "\n"; // 200
    cout << mp3.size() << "\n";  // 1

    cout << "\n";

    // Next Question — Iterator Invalidation
    printf("====== mp 4 =====\n");
    unordered_map<int, int> mp4;
    mp4[1] = 10;
    mp4[2] = 20;

    auto it4 = mp4.find(1); // Iterator points to key 1, value 10
    mp4[1] = 100; // Existing value updated to 100

    cout<< it4->second<<" \n"; // 100

    /*
        Important concept : 
            it4 element ki value ki copy store nahi karta. Woh unordered_map ke actual element ko point karta hai.

            Isliye mp4[1] = 100 se value update hone par it4->second bhi 100 return karta hai.

            Yaad rakh: unordered_map mein existing key ki value update karne se iterator invalidate nahi hota.
    */

    // Next Question — Iterator Invalidation (OA Level)
    printf("\n==== mp5 =====\n");
    unordered_map<int, int> mp5;

    mp5[1] = 10;
    mp5[2] = 20;

    auto it5 = mp5.find(1); // Iterator points to key 1

    mp5.erase(1); // key 1 deleted

    cout << it5->second << "\n"; // o/p -> i got garbage value 
    // undefined behavior , jo exsist nahi hai usku ponit kar raha ahi 

    /*
        erase(1) ke baad kya hota hai?
            1. find(1) key 1 ka iterator return karta hai.
            2. erase(1) key 1 ko map se remove kar deta hai.
            3. it5 ab erased element ka invalid iterator hai.
            4. it5->second access karna Undefined Behaviour hai.

        Important: UB ka matlab ye nahi ki program zaroor crash karega. Kabhi 10 print ho sakta hai, kabhi garbage value, kabhi crash. Inmein se kisi behaviour par bharosa nahi kar sakte.

        safe approch : 

            mp5.erase(1);

            auto it5 = mp5.find(1);

            if (it5 != mp5.end()) {
                cout << it5->second;
            } else {
                cout << "Key not found";
            } // o/p => key not found
    */

    // Next Question — erase(iterator) ka return value
    printf("\n====== mp 6 ========\n");
    unordered_map<int, int> mp6;

    mp6[1] = 10;
    mp6[2] = 20;
    mp6[3] = 30;

    auto it6 = mp6.find(2);

    it6 = mp6.erase(it6);

    if (it6 != mp6.end())
        cout << it6->first << " " << it6->second; // i got 1 10
    else
        cout << "end";

    // Hint: erase(iterator) erase kiye gaye element ke baad wale element ka iterator return karta hai, agar aisa element ho. unordered_map mein iteration order guaranteed nahi hota.

    //  Possible results:
    //  - 1 10
    //  - 3 30
    //  - end

    // Ye map ke iteration order par depend karta hai. Lekin Undefined Behaviour nahi hai, kyunki returned iterator ko correctly use kiya gaya hai.

    /*
        Interview/OA rule
            it = mp.erase(it);  // Safe: returned iterator use karo

        Lekin:
            mp.erase(it);
            cout << it->second;  // Undefined Behaviour: erased iterator use kiya

        Dono cases ka difference yaad rakhna.   
    */

    
    

    cout<<"\n";
    return 0;
}