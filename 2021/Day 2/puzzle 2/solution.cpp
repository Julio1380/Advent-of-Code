#include <iostream>
#include <fstream>
#include <string>

int main(){
    int pos = 0, depth = 0, aim = 0, dist;
    
    std::ifstream in("input.txt");

    std::string cmd;
    while(in >> cmd >> dist){
        if(cmd == "forward"){
            pos +=dist;
            depth += (dist * aim);

        }else if(cmd == "up"){
            aim -= dist;
        }else if(cmd == "down"){
            aim +=dist;
        }
    }

    std::cout << pos * depth << std::endl;

    return 0;
}