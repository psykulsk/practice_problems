#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <stack>

using std::vector;
using std::unordered_map;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    // Needed for the Point to be used in an unordered_map with Point as keys
    bool operator==(const Point &anotherPoint) const {
        return (x == anotherPoint.x && y == anotherPoint.y);
    }
};

namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point &k) const {
            // Compute individual hash values for two data members and combine them using XOR and bit shifting
            return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1);
        }
    };

}

// Possible neighbours' relative coordinates
std::array<Point, 8> neigh_modifiers = {
        Point(-1, -1),
        Point(-1, 0),
        Point(0, -1),
        Point(1, -1),
        Point(-1, 1),
        Point(0, 1),
        Point(1, 0),
        Point(1, 1)
};

// Border checking for finding neighbours
inline bool is_point_valid(const Point &point, int width, int height) {
    return point.x >= 0 && point.x < width && point.y >= 0 && point.y < height;
}

vector<Point> get_neighbours(const Point &point, int width, int height) {
    vector<Point> neighbours;
    for (Point modifier : neigh_modifiers) {
        Point neigh_candidate = Point(point.x + modifier.x, point.y + modifier.y);
        if (is_point_valid(neigh_candidate, width, height)) {
            neighbours.push_back(neigh_candidate);
        }
    }
    return neighbours;
}

void print_height_map(const unordered_map<Point, int> &map, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (map.find(Point(x, y)) != map.end()) {
                std::cout << map.at(Point(x, y));
            } else {
                std::cout << "-";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "----------------------\n";
}

int max_height(const vector<vector<int>> &map) {
    unsigned int width = map.at(0).size();
    unsigned int height = map.size();
    unordered_map<Point, int> max_height_map;
    std::queue<Point> to_process;
    int max_height = 0;

    // Find all 0's set their height in map and push their non 0 neighbours to the queue
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Point current = Point(x, y);
            if (map.at(current.y).at(current.x) == 0) {
                max_height_map[current] = 0;
                for (Point neigh: get_neighbours(current, width, height)) {
                    if (map.at(neigh.y).at(neigh.x) == 1)
                        to_process.push(neigh);
                }
            }
        }
    }

    //  Process non 0 fields in breadth-first order (switch queue to stack and see that
    //  depth first can give wrong results in some cases)
    while (!to_process.empty()) {
        Point current = to_process.front();
        to_process.pop();
        if (max_height_map.find(current) == max_height_map.end()) {
            int min_height = std::numeric_limits<int>::max();
            for (Point neigh : get_neighbours(current, width, height)) {
                if (max_height_map.find(neigh) != max_height_map.end())
                    min_height = std::min(min_height, max_height_map[neigh]);
                else {
                    to_process.push(neigh);
                }
            }
            max_height_map[current] = min_height + 1;
            max_height = std::max(max_height, min_height + 1);
        }
        print_height_map(max_height_map, width, height);
    }
    return max_height;
}


int main() {

    vector<vector<int>> map = {
            {0, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0}
    };
    int maximum = max_height(map);

    std::cout << "Max height: " << maximum << "\n";
    return 0;
}