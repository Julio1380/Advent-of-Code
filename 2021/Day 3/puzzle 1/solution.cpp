#include <iostream>
#include <fstream>
#include <vector>

int main(){

    std::vector<int> values;
    std::ifstream in("input");
    int length = 12;
    long current;
    in >> current;
    /*for(int i = 0; i < length; i++){
        values.push_back(0);
    }
    while(in >> current){
        std::cout << current << std::endl;
        for(int i = 0; i < length; i++){
            if()
        }
    }*/
    std::cout << current << std::endl;
    std::cout << "test";
    return 0;
}