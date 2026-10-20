#include<bits/stdc++.h>
using namespace std;

int main(){

vector<int> v = {10, 20, 30}; 
v.reserve(3);

auto it = v.begin() + 1;
v.push_back(40);

cout << *it <<"\n"; // Reallocation ke baad it invalid ho jaata hai. so output is not the 20... its not fixed its like 6, 5, 5, 5 etc

return 0;
}

// size is 3 then reserved to 3 ( >= 3 ). and it poniting to 20. then 40 push back now size is 4 and it poniting to 20 and cout print the 20

