#include "../headers/test.hpp"

#include "../data_struct/position.hpp"

#include <iostream>
#include <unordered_set>

namespace data_struct_test {
    void pos_hash_test() {
        std::unordered_set<Pos> pos_set;

        pos_set.insert(Pos(1, 2));
        pos_set.insert(Pos(1, 2));
        std::cout << "Test 1 num of elements: " << pos_set.size() << "(supposed to be 1)" << std::endl;

        pos_set.insert(Pos(3, 4));
        pos_set.insert(Pos(5, 6));
        std::cout << "Test 2 num of elements: " << pos_set.size() << "(supposed to be 3)" << std::endl;

        const Pos p1(10, 20);
        const Pos p2(20, 10);
        const Pos p3(15, 15); 
        pos_set.insert(p1);
        pos_set.insert(p2);
        pos_set.insert(p3);
        std::cout << "Test 3 num of elements: " << pos_set.size() << "(supposed to be 6)" << std::endl;

        auto print_find = [&](const Pos& p) {
            auto it = pos_set.find(p);
            std::cout << "Test 4 find element" << (it != pos_set.end() ? " succeed" : " failed");
        };
        print_find(Pos(1, 2));
        std::cout << "(supposed to be succeed)" << std::endl;
        print_find(Pos(99,99));
        std::cout << "(supposed to be failed)" << std::endl;

        std::hash<Pos> pos_hasher;
        std::cout << "Elements' hash values: " << std::endl;
        for (const auto& p : pos_set) {
            std::cout << "(" << p.x() << "," << p.y() << ") -> " 
                    << pos_hasher(p) << std::endl;
        }
    }
}
