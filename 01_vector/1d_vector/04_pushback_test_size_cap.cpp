
#include <iostream>
#include <vector>

using namespace std;

int main(){

std::vector<int> v;
v.reserve(3);

v.push_back(10);
v.push_back(20);
v.push_back(30);

std::cout << v.size() << " " << v.capacity() << "\n"; // 3 & 4

v.push_back(40);

std::cout << v.size() << " " << v.capacity() << "\n"; // 4 & 6

// Capacity ka exactly 6 hona C++17 mein guaranteed nahi hai. Ye tumhare standard library ki growth strategy hai.


cout<< "=========\n";

// more clearity 

    vector<int> v3(5);
    v3.reserve(5);

    for(int i=1; i<=5; i++){
        v3.push_back(i);
        cout<< v3.size() << " : " << v3.capacity() << " " <<"\n";
    }

    // o/p => 1 : 5,  2 : 5 ............  5 : 5
    // not 6 : 5,  7 : 5 ................. 10 : 5
    // v3.reserve(5); => storage prepare karta hai, elements create nahi karta.

    // 6 : 5,  7 : 5 ................. 10 : 5 => 6:10, 7:10, 8:10, 9:10, 10:10 when ->
    //currect version when we declare size  in vector<int> v3(5)

    cout<<"======== \n";

    // more clear

vector<int> a;
a.reserve(4);

vector<int> b;
b.resize(4);

cout << a.size() << " " << a.capacity() << "\n";
cout << b.size() << " " << b.capacity() << "\n";

//a.reserve(4) creates zero elements. size() = 0, capacity() = 4.
//b.resize(4) creates four valid elements. size() = 4, capacity() = 4 on your implementation.
//Since b contains int elements added by resize(4), they are zero-initialized.




return 0;
}

