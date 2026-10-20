#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> v(3, vector<int>(4, 5));

    v[1][2] = 9;

    cout << v.size() << " ";  // 3
    cout << v[0].size() << " "; // 4
    cout << v[1][2] << " ";   // 9 
    cout << v[2][3];        // 5


    cout << "\n";

    vector<vector<int>> v2(2, vector<int>(2, 0));

    v2[0][0] = 7;
    v2[1][0] = 9;

    cout << v2[0][0] << " ";
    cout << v2[1][0] << " ";
    cout << v2[0][1];

    cout << "\n";

    return 0;
}