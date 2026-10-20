#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    v.reserve(8);
    cout << v.size() << "\n";
    v.resize(5);
    cout << v.size() << "\n";
    cout << v[3] << " " << v[4] << "\n";
}


/* 
Operation  |	size() par effect |	capacity() par effect
-----------------------------------------------------------
reserve(n) |	Change nahi hota  |	At least n ho jaati hai
resize(n)  |	n ho jaata hai	  | Zaroorat padne par badhti hai
Important correction: reserve(n) capacity ko at least n karta hai, exactly n hona guaranteed nahi hai. resize(n) naye int elements add kare, toh woh zero-initialize hote hain.

*/