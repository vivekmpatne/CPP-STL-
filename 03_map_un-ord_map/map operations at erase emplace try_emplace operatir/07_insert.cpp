#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp;  // res is it poniting to 5->50
    auto result = mp.insert({5, 50});
    // insert() ek pair return karta hai, jismein do different cheezein hoti hain:
   
    
    cout<< result.second<<" ";   // null or zero. actul o/p => 1.
    cout<< result.first->first << " "; // 1st key-value ka key in map o/p 5
    cout<< result.first->second; // 5 key ka value 50 is the o/p

    /*
    result.first :
    Iterator hai. Inserted element ko point karta hai, jahan se key aur value access kar sakte ho.
        result.first->first → 5
        result.first->second → 50


    result.second :
    Boolean (bool) hai. Batata hai ki insertion successful hua ya nahi.
        true → insertion successful, prints 1
        false → insertion failed, prints 0

    
    Important: result.second ka matlab “result present hai” nahi, balki “insertion successful hua” ha

    */

    cout << "\n";

    printf("================================\n");

    unordered_map<int,int> mp2;
    mp2.insert({5, 50});

    auto result2 = mp2.insert({5, 99});

    cout<<result2.second << " ";  // 0 ( failted to insert becuade already exist )
    cout<<result2.first->second; // 50 ( 1st key-value pari ka value)

    cout<<"\n";

    return 0;
}