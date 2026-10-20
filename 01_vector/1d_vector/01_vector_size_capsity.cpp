#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> v;
    v.reserve(5);
    v.push_back(10);
    v.push_back(20);

    cout<<v.size() << " "<<v.capacity()<< "\n ==== \n ";

    vector<int> v2 = {10, 20, 30};
    v2.reserve(10);
    v2.resize(5);

    cout<< v2.size() << " " << v2.capacity() << "\n";
    cout << v2[3] <<  " " << v2[4] << "\n";
    cout << v2[5] << " " << v2[7] <<"\n";

    // v.size or v.resize => related to size 
    // v.reserve ( its rekated to capacity allocation )

    return 0;
}