

// vecctor pass in funcation by value (copy) and by reference ( original )

#include<bits/stdc++.h>
using namespace std;

/*

Quick comparison
--------------------------------------------------------------
Function    parameter |	Copy created? |	Original vector modified?
------------------------------------------------------------------
vector<int> v         |   Yes	      |     No        | 
vector<int>& v        | 	No	      |     Yes        |
const vector<int>& v  |	    No	      |   No  function ke through modify nahi kar sakte


By value: Jab independent copy chahiye.

By reference: Jab original vector modify karna ho.

By const reference: Jab large vector read karna ho without copying or modifying it.

*/



void change(vector<int>& v){
    v[0] = 99;
}

void print(const vector<int>& v) {
    // original vector liya size print kiya orginal vector ka, with (&) => same size 10
    // whout this ( & ) => 10 ( size => same 10 )
    cout << v.size() << " ";
    // v[0] = 99; whiout const we can change here
    // but with const we cant change the elements
}

void f(vector<int> v) {
    v.push_back(40);
    cout << v.size() << " ";
}

int main(){

    vector<int> a = {10,20};
    change(a);
    cout<< a[0] <<"\n"; // 99

    cout<< "===========\n";

    vector<int> b = {10, 20, 30};
    print(b);
    cout << b[0] <<"\n"; // 10 

    cout<< "===========\n";

    vector<int> c = {10, 20, 30};
    f(c);
    cout << c.size() << "\n"; // 3

    return 0;
}