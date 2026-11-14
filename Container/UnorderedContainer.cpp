#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main()
{
    std::unordered_map<int, std::string> umap = {
        {1, "one"}, {3, "tree"}, {2, "two"}
    };

    std::map<int, std::string> ordered_map = {
        {1, "one"}, {3, "tree"}, {2, "two"}
    };


    std::cout << "Unordered Map:" << std::endl;
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Ordered Map:" << std::endl;
    for (const auto& pair : ordered_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}