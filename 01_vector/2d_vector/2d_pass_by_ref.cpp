#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<int>>& v) {
    v[0][0] = 99;
}

int main(){

    vector<vector<int>> v = {{1, 2}, {3, 4}}; // 2 x 2
    change(v);    // & hai so pass by refernce => original change hoga
    cout << v[0][0]; // v[0][0] 1 ta na 1 nahi ab 99 hai 


    cout << "\n";


    // Prediction 
    vector<vector<int>> v2 = {{1, 2}, {3, 4}};
    cout << v2[0][2]<< "\n"; 
    // 1st row ka 3rd elemnet but there is present 3rd element

    // [] vs .at()
    printf("=========================\n");

    vector<int> v3 = {10, 20};
    cout << v3.at(2) << "\n";


//    Access	|   Out-of-range behavior
//   --------------------------------------------
//      v[2]	|   Undefined behavior
//      v.at(2)	|   std::out_of_range exception

    return 0;
}