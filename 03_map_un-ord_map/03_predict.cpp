#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;
    mp[5] = 50;

    auto it = mp.find(8);   

    // key 8 ko search karta hai. Agar key missing hai, toh mp.end() return hota hai. Correct.

    cout << mp.size() << " ";   // 1


    // if ( mp.find(8) == mp.end() ) => mp.end() == mp.end() => so not found 

    if (it == mp.end())  cout << "not found";    // not found ( matlab 8 map mai nahi hai  )

    cout << " " << mp.size();   // 1  


    cout << "\n";


// Operation |	Missing key par behavior
//-------------------------------------------------------------------------------
// mp[8]	 |  Key insert karta hai, mapped value default-initialize hoti hai
//mp.find(8) |	mp.end() return karta hai, map unchanged rehta hai
//mp.at(8)	 |  std::out_of_range exception throw karta hai

// Yaad rakhna: Jab sirf check karna ho ki key present hai ya nahi, find() use karo. [] ko innocent read operation mat samajhna, kyunki missing key par ye container modify kar sakta hai.


    return 0;
}