#include <iostream>
#include <unordered_map>
#include <string>

// Your custom type
struct Point {
    int x;
    int y;

    // 1. Must define equality operator so the map can handle collisions
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 2. Define the Custom Hasher
struct PointHasher {
    std::size_t operator()(const Point& p) const noexcept {
        // Combine the hashes of individual members (using XOR and bit-shifting)
        return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 1);
    }
};

int main() {
    // 3. Pass the Custom Hasher as the 3rd template parameter
    std::unordered_map<Point, std::string, PointHasher> pointMap;
    
    pointMap[{1, 2}] = "Starting Location";
    
    std::cout << pointMap[{1, 2}] << std::endl; // Outputs: Starting Location
    return 0;
}
