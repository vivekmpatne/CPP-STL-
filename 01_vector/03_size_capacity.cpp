#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.reserve(4);
    v.push_back(7);
    v.push_back(9);
    cout << v.size() << " " << v.capacity() << "\n";
    v.reserve(2);
    cout << v.size() << " " << v.capacity() << "\n";

    cout<<"=======\n";

    // test 1 
    vector<int> v2 = {1, 2, 3};
    v2.resize(2);
    cout << v2.size() << " " << v2.capacity() << "\n"; // 2 and 3

    cout<<"=====\n";

    // test 2
    vector<int> v3;
    v3.resize(3);
    cout << v3.size() << " " << v3.capacity() << "\n"; // 3 and 3 
    cout << v3[0] << " " << v3[1] << " " << v3[2] << "\n"; // 0 0 0

}

// out put is 2, 4  & 2, 4.... 
// not 2 4 and 2, 2

// reserve(n) mein n total requested capacity hai, 
// -additional capacity nahi. Aur reserve() existing capacity ko reduce nahi karta.