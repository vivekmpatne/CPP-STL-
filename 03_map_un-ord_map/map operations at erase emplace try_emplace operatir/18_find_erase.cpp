#include<bits/stdc++.h>
using namespace std;

int main(){

    // concept: find() aur erase() ko combine karna
    unordered_map<int, int> mp = {
        {1, 100},
        {2, 200}
    };

    auto it = mp.find(2);

    if (it != mp.end()) {
        mp.erase(it);
    }

    cout << mp.size() << "\n";

    it = mp.find(2);

    if (it == mp.end()) {
        // Ab key 2 exist nahi karti, isliye find(2) mp.end() return karta hai.
        cout << "Not Found\n";
    }


    cout << "\n";

    return 0;
}