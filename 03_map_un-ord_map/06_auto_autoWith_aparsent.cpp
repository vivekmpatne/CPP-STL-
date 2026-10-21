#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};

    for (auto p : mp) p.second = 99;   

    cout << mp[1] << " " << mp[2] <<"\n"; // 10 20

    printf("================================\n");
    
    /* Tumhari prediction thi ki output 99 99 hoga. Lekin actual output 10 20 hona chahiye.

    Kyun? auto p har iteration mein map ke element ki copy banata hai. Tum p.second change kar rahe ho, original mp ki value nahi. */

    for (auto p : mp) {
        cout<< "Before: " <<p.first << " "<< p.second<<" ";
        p.second = 99;
        cout<< "after: "  << p.first <<" "<<p.second<<" \n";        
    }

    cout << mp[1] << " " << mp[2] <<"\n"; // 10 20

    cout << "\n";

    // unordered_map ki iteration order guaranteed nahi hai, isliye tumhare output mein keys 4, 3, 2, 1 aayi hain. Ye normal hai. 
    // its can be any order ( not fixed order )


    printf("=======================\nNow Original\n");
    // auto p : mp =>>>>> auto& p =>> now orginal vlaue also changes

    unordered_map<int, int> mp2 = {{1, 10}, {2, 20}, {3, 30}, {4, 40}};

    for ( auto& p : mp2) {
        cout<< "Before: " <<p.first << " "<< p.second<<" ";
        p.second = 99;
        cout<< "after: "  << p.first <<" "<<p.second<<" \n";    
    }    

    cout << mp2[1] << " " << mp2[2] <<"\n";

    printf("===================================\n");
 /*
 Next prediction: const auto&
Ab copy, mutable reference, aur const reference ko compare karte hain. 
*/
    unordered_map<int, int> mp3 = {{1, 10}, {2, 20}};

    for (const auto& p : mp3) {
        cout << p.first << ":" << p.second << " ";
        //p.second = 99;
    }
    cout<<"\n";

    /*

    * auto p: Copy banata hai, so extra copying cost ho sakti hai.
    * auto& p: Original element ka reference, so modifications original  par apply hote hain.
    * const auto& p: Copy avoid karta hai aur modification prevent karta hai. Read-only iteration ke liye useful.
    
    One more detail: unordered_map mein iteration order guaranteed nahi hai. const auto& ke saath bhi key-value pairs kisi bhi order mein print ho sakte hain.
    
    */


    return 0;
}