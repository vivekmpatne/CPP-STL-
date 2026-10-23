#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;
    mp[1] = 10;

    auto it = mp.find(1);
    mp.rehash(100);

    cout << it->second;

    /*
        auto it = mp.find(1);
        mp.rehash(100);
        cout << it->second;  // Invalid iterator!
    */ 

    // safe approch 
    //above one is give o/p but unsafe and invalid may occure , right approch bellow 
    printf(" \n-----\n");

    unordered_map<int, int> mp2;
    mp2[1] = 10;

    mp2.rehash(100);

    auto it2 = mp2.find(1);  // Rehash ke baad fresh iterator
    cout << it2->second;    // 10

    cout << "\n";

    // rehadh first then it => safe
    // 1st it then re-hash => un-safe


    // next prediction 
    printf("------\n");
    unordered_map<int, int> mp3;
    mp3[1] = 10;
    
    int& ref = mp3[1];
    mp3.rehash(100);

    ref = 99;
    cout<< mp3[1];

    cout<<"\n";

    return 0;
}