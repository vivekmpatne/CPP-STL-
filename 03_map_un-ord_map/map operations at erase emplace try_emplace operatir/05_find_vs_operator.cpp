#include<bits/stdc++.h>
using namespace std;

int main(){

    // Next prediction: find() vs operator[]

    unordered_map<int, int> mp;
    auto it = mp.find(7);  // false nahi hai key mai and not insert also 

    cout<< (it == mp.end()) << " "; // return mp.end() == mp.end() o/p if   end == end => 1
    cout<< mp.size();  // size is 0. 


    /*
     mp empty hai, toh key 7 nahi milti.
find(7) returns mp.end().
Isliye it == mp.end() evaluates to true, jo 1 print karta hai.    
*/
      
    // find() missing key ko insert nahi karta. Map empty hi rehta hai, isliye size 0 hai.


    cout << "\n";

    printf("========================\n");
    unordered_map<int, int> mp2;
    auto it = mp2.find(7); // false 0. returns end()

    if( it != mp2.end()){   // end != end() => false so else block 
        cout<< it->second;  
    } else{
        cout<< "Not Found"; // not found 
    }

    return 0;
}