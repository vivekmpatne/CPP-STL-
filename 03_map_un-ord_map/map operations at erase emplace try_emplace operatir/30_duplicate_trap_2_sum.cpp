#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {3, 3};
    int target = 6;

    unordered_map<int, int> mp;

    for(int x : v){
        int need = target - x;
        cout<<"need: "<<need<<" \n";

        if( mp.find(need) != mp.end() ){ // find returns mp.end().
            cout<< "Found \n";
            break; // dont run unnessary intaration 
            // if not break then map mai sab key value store honge
        }
        mp[x] = 1;
        cout<<"Key: "<<x<<" value: "<<mp[x]<<" : ";
        cout<<"size: "<<mp.size()<<" \n";
    }

    /*
        Important: Duplicate 3 hone par bhi algorithm kaam karta hai, kyunki pehle 3 ko map mein store kiya gaya tha aur doosre 3 par uska complement mil gaya.

        Aur haan, break unnecessary iterations ko rokta hai. Lekin agar break hata dein, toh loop aage chalta rahega; isse har case mein saari values map mein store hongi, ye zaroori nahi—kyunki if true hone par mp[x] = 1 phir bhi skip hoga.
    */


    cout << "\n";

    return 0;
}