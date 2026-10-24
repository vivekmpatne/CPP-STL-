#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1, -1, 1};
    int sum = 0;

    unordered_map<int, int> freq;
    freq[0] = 1; // edge case handel 0->1

    for(int x : v){
        cout<<"x : "<<x<<" sum previous: "<<sum<<" | ";
        sum += x; 
        cout<<"sum after add: "<<sum<<" \n";
        freq[sum]++;

        cout<<"mp of sum: "<<freq[sum]<<" \n";
    }

    cout<<freq[0]<<"\n";
    cout<<freq[1]<<"\n";
    cout<<freq.size()<<"\n";

    /*
        | Step    | `x` |sum after addition | Updated entry |
       -------------------------------------------------------
        | Initial | —   |       0       | `freq[0] = 1` |
        | 1       | 1   |       1       | `freq[1] = 1` |
        | 2       | -1  |       0       | `freq[0] = 2` |
        | 3       | 1   |       1       | `freq[1] = 2` |

    */

    // link : https://chatgpt.com/s/t_6add1e443d048191bb9d74d3cd854bdf

    



    return 0;
}