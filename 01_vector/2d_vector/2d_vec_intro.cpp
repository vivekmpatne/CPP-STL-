#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> v(3, vector<int>(2, 0));

    v[1][0] = 7;
    v[2][1] = 9;

    cout << v.size() << " " << v[0].size() << "\n"; // 3 and 2
    cout << v[1][0] << " " << v[2][1] << "\n"; // 7 and 9

    cout<<"================\n";

    vector<vector<int>> v2(2);

    v2[0].push_back(10);
    v2[0].push_back(20);

    cout << v2.size() << " " << v2[0].size() << " "<<"\n"; // 2 and 2
    cout << v2[1].size() <<"\n";


    return 0;
}