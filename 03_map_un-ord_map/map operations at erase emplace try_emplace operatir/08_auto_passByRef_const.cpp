#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp  = {{1, 10}, {2, 20}};

    for(auto& p : mp ) p.second = 99;  
    //predict : p coming of mp and trying to change  1->99, 2->99 this chcnages inside the loop and print inside only

    for(auto& p : mp ) p.second += 1;
    //predict : ab pass by ref hai orginal cahnge hoga 1 -> 11, 2->21

    for(const auto& p : mp)
        cout<<p.first << " : " << p.second << " ";
    // predict : const orginal lega but change nahi karega
    // predict o/p => 1 -> 10 , 2 -> 20; 

    // actual o/p => what i got o/p : 2 : 21, and 1 : 11

    // =============================

    // auto p : Yahan p map ke har element ki copy hai. Isliye p.second = 99 sirf copy ko change karta hai, original map ko nahi

    // auto & p : Ab p original element ka reference hai. Values directly update hoti hain:  1-> 10 ( before ) -> after -> 11
    // 2-> 20 ( before ) -> after -> 21
    

    // const auto& p means read-only reference. Ye original values ko read karta hai, change nahi karta. Isliye values 11 aur 21 hi print hoti hain.

    // Iteration order: unordered_map keys ko sorted order mein print karne ki guarantee nahi deta. Isliye tumhare output mein key 2 pehle aayi, phir key 1.

    /*
    if we change 1st loop => for (auto& p : mp) p.second = 99;

    99, 99 value if onluy 1st loop done like this... if we keep 1st loop and 2nd loop p.second += 1 then its 100, 100

    */ 
   
    cout << "\n";

    return 0;
}