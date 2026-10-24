#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums = {1, 2, 3};
    int k = 3;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefixSum = 0;
    int cnt = 0;

    for(int x : nums){
        prefixSum += x;

        int need = prefixSum - k;
        
        if(mp.find(need) != mp.end()){
            cnt += mp[need];
            // need agar map mai hai then cnt mai add karo uska freq so number of subarray sum euqal to k ayega 
        }
        mp[prefixSum]++;
    }

    /*
        mp[0] = 1 array ke zero element ke liye nahi hai. Ye initial prefix sum 0 ko represent karta hai, jo array ke kisi bhi element ko include karne se pehle exist karta hai.

        Pehle element ko process karne par:
            - prefixSum = 3
            - need = 3 - 3 = 0 (matlab milgaya) so 0 se green signal

        Ab mp[0] = 1 ki wajah se humein ek matching prefix sum milta hai. Isliye [3] count hota hai.

        Agar mp[0] = 1 initialize nahi karte, toh ye subarray miss ho jaata.

        Golden rule: mp[0] = 1 empty prefix sum ko represent karta hai, taaki array ke starting index se shuru hone wale valid subarrays bhi count hon.
    */

    // link : https://chatgpt.com/s/t_6add221015dc8191b7b517528129f4b2
    

    cout<<cnt<<" \n";

    return 0;
}