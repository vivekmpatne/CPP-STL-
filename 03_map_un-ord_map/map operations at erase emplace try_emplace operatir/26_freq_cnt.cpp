#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {2, 3, 2, 5, 3, 2};

    /* key -> freq 
        2 -> 3
        3 -> 2
        5 -> 1
    */

    unordered_map<int, int> freq;

    for( int x : v){
        freq[x]++;
    }

    cout<<freq[2] << "\n"; // 3
    cout<<freq[3] << "\n"; // 2
    cout<<freq.size() << "\n"; // 3


    cout << "\n";

    return 0;
}