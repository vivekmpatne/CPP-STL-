#include<bits/stdc++.h>
using namespace std;

int main(){

    
    vector<vector<int>> v = {
        {1, 2},
        {3, 4, 5},
        {6}
    };

    cout << v.size() << " ";   // 3
    cout << v[1].size() << " "; // 2nd row ka 3 elements
    cout << v[2][0]; // 3rd row and 1st elem ka number => 6


    cout << "\n";

    return 0;
}