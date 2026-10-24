#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums     = {1, -1,  1};

    // dry run           |     tabel
    //-----------------------------------------
    //         x            = {1, -1,  1}
    //    prefix sum        = {1,  0,  1}
    //  need(preFSum - k)   = {0, -1,  0}  
    //      mp[need]       = {1, 0(ab), 1}
    //        cnt           = {1,  1,  2} 
    
    // init cnt, prefixSum = 0.
    // prefixSum += x, need = prefixSum - k, cnt += mp[need].


    int k = 1;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefixSum = 0;
    int cnt = 0;

    for (int x : nums) {
        prefixSum += x;
        int need = prefixSum - k;

        if (mp.find(need) != mp.end()) {
            cnt += mp[need];
        }

        mp[prefixSum]++;
    }

    cout << cnt << "\n";
    

    cout << "\n";

    // link : https://chatgpt.com/s/t_6add221015dc8191b7b517528129f4b2


    return 0;
}