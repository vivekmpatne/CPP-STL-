#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;

    cout << mp.size() << "\n"; // 0

    cout << mp[5] << "\n";    // 0

    cout << mp.size() << "\n"; // size is 1, 5->0 insert in above 

    auto it = mp.find(10); // not found => it.end hoga
 
    cout << mp.size() << "\n"; // mp size : 1

    /*
        Ek important correction: mp[5] ka matlab 5 → 0 insert hota hai, kyunki int ka default-initialized value 0 hai.

        Aur find(10) return karta hai mp.end(), it.end() nahi. it ek iterator variable hai, jabki end() map ka member function hai.

        Tumne ye bhi correctly identify kiya ki find(10) se map ka size change nahi hota.
        
    */
    

    cout << "\n";

    return 0;
}