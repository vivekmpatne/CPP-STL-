#include<bits/stdc++.h>
using namespace std;

int main(){


    vector<int> v = {10, 20, 30};
    auto it = v.begin();
    v.clear();
    cout << v.size() << " " << *it;

    // size is 3. then it pting to 10, v clear => all remove v size if zero due to all removed it will give 10 becuse its store the value after it store the clear was happend

    // NOTE : but its undefined behavior not alwary its give 10...
    

    cout << "\n";

    return 0;
}