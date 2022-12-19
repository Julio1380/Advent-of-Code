#include <iostream>
#include <fstream>
#include <string>

int main(){
    int pos = 0, depth = 0, dist;
    
    std::ifstream in("input.txt");

    std::string cmd;
    while(in >> cmd >> dist){
        if(cmd == "forward"){
            pos +=dist;

        }else if(cmd == "up"){
            depth -= dist;
        }else if(cmd == "down"){
            depth +=dist;
        }
    }

    std::cout << pos * depth << std::endl;

    return 0;
}