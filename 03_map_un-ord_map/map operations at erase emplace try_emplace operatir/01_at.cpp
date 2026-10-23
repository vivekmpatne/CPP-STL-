#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;
    mp[5] = 50;       

    cout << mp.at(5) << " ";  // 50
    // cout << mp.at(8);  // out of range

    //cout<< mp.find(8)->second; // o/p => Segmentation falut

    // mp.find(8) key 8 ko search karta hai. Key exist nahi karti, toh mp.end() return hota hai.

    // mp.find(8)->second invalid hai, kyunki end() kisi valid element ko point nahi karta.

    // Ek aur correction: find(8)->second se 8 print nahi hota. find() key ko search karta hai, aur successful hone par key-value element ka iterator return karta hai.

/*
2. Ye three operations yaad rakho
------------------------------------------
Expression	|  Key missing ho toh
---------------------------------------------------
mp[8]	    |  Key insert hoti hai, mapped value default-initialize hoti hai
mp.at(8)	| std::out_of_range exception
mp.find(8)	| mp.end() return hota hai, map unchanged rehta hai


*/

    cout << "\n";

    //  3. Safe way to use find()

    auto it = mp.find(8);

    if (it != mp.end()) { 
        // it is mp.end (becuse is not present) so its returns the mp.end then  mp.end != mp.end stmt fails so else will ecicute 
        cout << it->second; 
    } else {
        cout << "not found"; 
    }

    cout << "\n";

    
    printf("===============================\n");
    
    // Next prediction: at() vs []

    // try catch

    unordered_map<int, int> mp3;
    mp3[5] = 50;

    try {
        cout << mp3.at(8);
    } catch (const out_of_range&) {
        cout << "not found";
    }

    cout << "\n " << mp3.size();

    cout << "\n";

    


    return 0;
}