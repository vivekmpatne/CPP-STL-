#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {10, 20, 30, 40}; // size 4
    auto it = v.begin() + 1;  // it 20
    v.resize(2);              // size is 2
    cout << *it <<"\n";       // o/p is 20

  

    return 0;
}