#include <iostream>
#include <vector>

class Tile {
public:
    int a=5;

};
class Black: public Tile {
public:
    int a =10;
};

int main() {
    std::vector<Tile> vec = {Tile(), Black()};
    for(auto const &tile : vec){
        std::cout<< tile.a << "\n";
    }
    return 0;
}