#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, string> mp;

    cout<< mp.size() <<"\n";     // 0
    cout<< mp[10] <<"\n";        // Not 0.  empty space 
    // why ? => unordered_map<int, string> mein mapped value string type ki hai. Default-constructed string empty hoti hai, yani "".
    cout<< mp.size() <<"\n";     // 1
    

    // Important trap: unordered_map<int, int> mein missing key ko [] se access karoge, toh inserted int ki value 0 hogi. Lekin unordered_map<int, string> mein inserted value empty string hoti hai. Default value mapped type par depend karti hai.


    cout << "\n";

    return 0;
}