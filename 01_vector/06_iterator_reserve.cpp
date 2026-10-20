#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<int> v = {10, 20, 30};

    auto it = v.begin();
    v.reserve(100); // Elements naye memory location par move/copy ho gaye.

    cout << *it <<"\n"; // o/p is garbage value not 10.

    // Reallocation hone par vector ke existing iterators, pointers aur references invalidate ho jaate hain. Isliye *it access karna undefined behavior (UB) hai.

    cout << "========================\n";

    // safely use : 
    
    vector<int> v2 = {10, 20, 30};
    v2.reserve(100);

    auto it2 = v2.begin();

    cout << *it2 << "\n"; // 10 

    cout << "========================\n"; 
    // push back and itr invalidation 

    vector<int> v3 = {10, 20 ,30}; // size = 3

    v3.reserve(5);                // capacity >= 5;
    auto it3 = v3.begin() + 1;    // ponits to 20
    v3.push_back(40);              // size = 4

    cout<< *it3 << "\n";            // 20 



    cout << "========================\n"; 

    // prediction 

    vector<int> v4 = {10 , 20, 30, 40}; // size = 4
    auto it4 = v4.begin() + 1;          // it points to 20
    v4.erase(it4);                      //  erase ( it4 ) => 20 ku erase kiya vector se 
                                        // so o/p => {10, 30, 40}

    cout<<v4[1]<<" "<< *it4 <<"\n";     // v4[1] => 30, and it4 ponting begin + 1 => 30

    // *it is undefined behavior because erase() invalidates iterators at or after the erased position.

    cout << "========================\n"; 

    // prediction 2

    vector<int> v5 = {10, 20, 30, 40};      // size => 4
    auto it5 = v5.begin() + 1;              // it ponits to 20
    it5 = v5.erase(it5);                    // it => erase 20 => {10, 30, 40};
    cout << *it5 <<"\n";                    // as it => begin + 1 => so o/p => 30

    // Before:  [10, 20, 30, 40]
    //          ↑ it

    //          erase(it) removes 20

    // After:   [10, 30, 40]
    //                ↑ returned iterator

    


    return 0;
}