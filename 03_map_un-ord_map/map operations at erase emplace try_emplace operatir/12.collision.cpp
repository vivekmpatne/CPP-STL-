#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, string> mp;

    // mp[key] = valye;
    mp[27] = "Vivek";
    mp[47] = "Rahul";

    cout << mp.size() << " ";
    cout << mp[27] << " ";
    cout << mp[47] << " ";

    // Main concept: Collision ka matlab same bucket, not same key. Dono key-value pairs independently store hote hain. Collision se unordered_map ki correctness break nahi hoti, lekin bahut saare collisions performance ko slow kar sakte hain.

    /*
        Maan lo 1,000 keys hain aur sab ek hi bucket mein collide kar rahi hain. Search karte waqt unordered_map ko us bucket ke multiple elements check karne pad sakte hain. Worst case mein search O(n) ho sakta hai.

                        Situation  |  Search complexity
            --------------------------------------------
            Good hash distribution |  Average O(1)
            Bahut saare collisions |  Worst case O(n)
    */


    cout << "\n";
    printf("=====================\n");

    // Next prediction : 
    unordered_map<int, string> mp2;
    
    mp2[27] = "A";
    cout<<mp2[27]<<" \n";
    mp2[47] = "B";
    mp2[27] = "C";

    cout<<mp2.size() << " ";
    cout<<mp2[27]<<" ";
    cout<<mp2[47]<<" ";

    cout<<"\n";

    /* 

        Dry run:
            Operation	 |Key 27 | Key 47 |  Size
            -------------------------------------
            mp[27] = "A" |	A    |  --    |   1
            mp[47] = "B" |	A	 |   B	  |   2
            mp[27] = "C" |	C    |	B	  |   2


            Ek terminology correction: operator[] yahan reallocate nahi karta. Existing key milne par uski mapped value update hoti hai. Reallocation aur rehash alag concepts hain.

            concept: Hash collision vs duplicate key
                    Dono mein difference identify karo:
                - Collision: Different keys same bucket mein map hoti hain.
                - Duplicate key: Wahi key dobara insert ya access hoti hai.

    */

    // next prediction 

    unordered_map<int, int> mp3;

    printf("parallel behavior: \n");

    mp3[27] = 100;
    cout << "size: " << mp3.size() << " value : ";
    cout << mp3[27]<<" |";

    mp3[47] = 200;
    cout << "size: "<<  mp3.size()<< " value : ";
    cout << mp3[47]<<" |";


    mp3[27] = 300;
    cout << "size: " << mp3.size()<<" value :  ";
    cout << mp3[27]<<" |"; // updated one 300


    printf("after : \n");
    cout << mp3.size() << " ";
    cout << mp3[27]<<" "; // 300
    cout << mp3[47]<<" \n"; // 200

    // 27 aur 47 collision karte hain, aur final size 2 hai

    /* 
        Correct bhai! Option A bilkul sahi hai.

        Simplified hash rule: key % 10
            - 27 % 10 = 7
            - 47 % 10 = 7
        Dono same bucket mein jaati hain, isliye collision hota hai. Lekin keys different hain, isliye dono map mein independently stored rehti hain.

            Operation	  mp[27]	mp[47]	Size
            -------------------------------------
            mp[27] = 100	100	     —	     1
            mp[47] = 200	100	     200	 2
            mp[27] = 300	300	     200	 2

    */

    return 0;
}