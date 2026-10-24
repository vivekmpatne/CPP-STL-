#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {2, 7, 11, 15};
    int target = 9;

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


    cout << "\n";

    return 0;
}