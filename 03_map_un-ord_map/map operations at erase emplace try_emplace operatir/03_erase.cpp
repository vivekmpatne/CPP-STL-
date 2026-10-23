#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp {{5, 50}, {8, 80}};

    cout<<mp.erase(5) <<" "; // 1 
    cout<<mp.erase(5) <<" "; // 0
    cout<<mp.size();         // 1
    
    cout << "\n";

    /*
    erase(key) return karta hai ki kitne elements remove hue. unordered_map mein keys unique hoti hain, isliye key-based erase() ka result 0 ya 1 hoga.
    */



    return 0;
}