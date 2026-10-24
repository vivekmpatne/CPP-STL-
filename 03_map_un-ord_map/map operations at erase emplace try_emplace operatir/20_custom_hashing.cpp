#include<bits/stdc++.h>
using namespace std;


// Custom hash ka basic example
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first)
             ^ (hash<int>{}(p.second) << 1);
    }
    // formula : Not this : H(a,b) = h(a)^h(b) <<1 same (2,3 and 3,2 same output) H(2, 3 or 3,2 here=> o/p => 2 )

    // formula is : H(a,b) = h(a) ^ ( h(b) << 1 )
    // so ( 2,3 and 3,2 give diff answers)
    // H(2, 3) = 4,  H(3, 2) = 7
};

/*
    Toh apne hash function mein hum:
        1. First integer ka hash nikalte hain.
        2. Second integer ka hash nikalte hain.
        3. Second hash ko ek bit left shift karte hain.
        4. Dono results ka XOR karte hain.
    
        hash(first) ^ (hash(second) << 1)

        left shift => <<, right shift =>  >>

        note: << 1 ka matlab hai bits ko ek position LEFT shift karna.

            Example:( left shift )
            3       = 0011
            3 << 1  = 0110 = 6

            Right shift hota:
            3 >> 1

            3       = 0011
            3 >> 1  = 0001 = 1

*/


int main(){

    /*

        Ye hamare hashing track ka ek important remaining topic hai.
        Abhi tak tumne aise maps use kiye hain:
            unordered_map<int, int> mp;

        Yahan key int hai, aur standard library uske liye hash function provide karti hai.
        Lekin maan lo tumhe pair<int, int> ko key banana hai:
            unordered_map<pair<int, int>, int> mp;
        
    */

    /*
        Question: Kya ye code standard C++17 mein bina custom hash function ke compile ho jayega?

            A) Haan, kyunki pair standard library ka part hai.
            B) Nahi, kyunki standard C++17 unordered_map ke liye pair<int,int> ka default hash function provide nahi karta.

                Apna option aur reasoning batao.

            Bhai, yahan correct answer B hai, A nahi. Koi baat nahi, custom hashing ka concept abhi seekh rahe hain.

    */

    // Custom hash ka basic example
    unordered_map<pair<int, int>, int, PairHash> mp;
    // pair<int, int> key hai.
    // int mapped value hai.
    // std::pair available hai, lekin standard library std::hash<pair<int,int>> provide nahi karti.

    mp[{2, 3}] = 100;
    mp[{4, 5}] = 200;

    cout << mp[{2, 3}] << "\n"; // output => 100

    // isme imp sytax : unordered_map<Key, Value, HashFunction> mp;

    /*
        Yahan PairHash third template argument hai. Ye map ko batata hai ki pair<int,int> keys ka hash kaise calculate karna hai.

        Hash collision hone par bhi unordered_map keys ki equality check karta hai; sirf hash same hone se keys equal nahi ho jaati.
    */

    cout << "=========\n";

    // next ques 
    unordered_map<pair<int, int>, int, PairHash> mp2;

    mp2[{2, 3}] = 100;
    mp2[{2, 3}] = 500;

    cout << mp2.size() << "\n";  // 1 
    cout << mp2[{2, 3}] << "\n"; // 500 may be

    /*
        Reason:
            - First assignment: key {2, 3} insert hoti hai, value 100.
            - Second assignment: same key {2, 3} already present hai, toh value 500 se overwrite ho jaati hai.
            - size() 1 hi rehta hai.

        Important: operator[] existing key ko update karta hai, lekin missing key ke liye naya element insert karta hai
    */

    // next predi tion
    printf("=========\n");

    // next check ( next predict )
    unordered_map<pair<int, int>, int, PairHash> mp3;

    mp3[{2, 3}] = 100; // key ka pair interchanged
    mp3[{3, 2}] = 200;

    cout << mp3.size() << "\n"; // size 2.. 


    /*
        Agar H(2,3) = 7 aur H(3,2) = 7, lekin pairs different hain, toh kya unordered_map unhe separate entries ke roop mein rakh sakta hai?

            A) Haan ( right answer)
            B) Nahi


        Yaad rako : 
        
        - Hash function: Key ko hash value mein convert karta hai.

        - Collision: Different keys ki hash values same aa jaati hain.

        - Equality comparison: Check karta hai ki keys actually equal hain ya nahi.

        more informaion :

        link 1 : https://chatgpt.com/s/t_6adcd16d28bc8191a01a3c055a6f0e2a 

        link 2 : https://chatgpt.com/s/t_6adcd1014bfc81918103b74ba891bb55

    
    */

    // next predict (4th one)
    printf("\n=================\n");

    unordered_map<int, int> mp4;

    mp4[5] = 50;

    auto it4 = mp4.find(10); // not there so returns mp.end

    if (it4 == mp4.end()) {  // not there, mp.end == mp.end 
        mp4[10] = 100;  // so now inssert 10->100
    }

    cout << mp4.size() << "\n"; // size is 2
    cout << mp4[5] << "\n";      // 50
    cout << mp4[10] << "\n";     // 100
    


    return 0;
}