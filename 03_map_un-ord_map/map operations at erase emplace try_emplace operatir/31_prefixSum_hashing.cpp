#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1, 2, 3};
    int sum = 0;

    unordered_map<int, int> mp;
    mp[0] = 1; // edge case handel 0->1

    for(int x : v){
        cout<<"x : "<<x<<" sum previous: "<<sum<<" | ";
        sum += x; 
        cout<<"sum after add: "<<sum<<" \n";
        mp[sum]++;

        cout<<"key: "<<x<<" value: "<<mp[x]<<" | "; // if x is not there in map then this line will insert so size may increse of hashmap 

        cout<<"mp of sum: "<<mp[sum]<<" \n";
    }

    cout<<mp[3]<<"\n";
    cout<<mp[6]<<"\n";
    cout<<mp.size()<<"\n";

    /*
    
        Golden rule : 
            Debugging ke waqt bhi mp[key] carefully use karna, kyunki missing key access karne se woh insert ho sakti hai.

            Agar sirf check karna hai ki key exist karti hai ya nahi, toh find() use kar.

    */

    // link : https://chatgpt.com/s/t_6add1642d4a08191ba85dd1eca09d86c 



    return 0;
}