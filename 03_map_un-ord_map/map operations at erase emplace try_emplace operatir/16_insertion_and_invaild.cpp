#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, int> mp;
    mp[1] = 10;
    mp.reserve(2);

    auto it = mp.find(1);
    mp[2] = 20;

    cout << it->second;

    cout << "\n";

    /*
    what if remove mp.reserve(2); ? : 

    unordered_map<int, int> mp;
    mp[1] = 10;
    auto it = mp.find(1);
    mp[2] = 20;

    cout << it->second;
    it key 1 ko point karta hai.

    mp[2] = 20 doosri key insert karta hai.
    Agar insertion se rehash nahi hua, iterator valid rehta hai aur 10 print hota hai.
    Agar rehash hua hota, it invalidate ho jata. Uske baad it->second access karna undefined behavior hota. Program phir bhi 10 print kar sakta hai, isliye output akela proof nahi hai.
    
    */
    
    
    // next experiment 

    unordered_map<int, int> mp3;
    mp3[1] = 10;

    auto it3 = mp3.find(1);
    mp3.rehash(100);

    cout << it3->second;


    cout << "\n";

    /*
        Haan bhai, `10` aaya, lekin iska matlab ye nahi ki iterator valid tha. Ye C++ ka important trap hai.

        ```
        auto it = mp.find(1);
        mp.rehash(100);
        cout << it->second;  // Undefined behavior
        ```

        `rehash(100)` ke baad `it` invalid ho chuka hai. Invalid iterator ko dereference karna undefined behavior (UB) hai.

        UB ka matlab program:

                - `10` print kar sakta hai.
                - Crash kar sakta hai.
                - Koi unexpected result de sakta hai.

            Isliye output dekhkar iterator ki validity prove nahi kar sakte.

            ### Safe way

                    ```
                    mp.rehash(100);
                    auto it = mp.find(1);
                    cout << it->second;  // Safe, assuming key exists
                    ```

            Yaad rakho: `rehash()` ke baad fresh iterator lo. Purane iterator par depend mat karo.

            Agla important concept: `unordered_map` mein rehash vs `erase()` iterator invalidation. `erase()` ka behavior `rehash()` se different hai.
    */

    return 0;
}