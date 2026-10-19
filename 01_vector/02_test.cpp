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