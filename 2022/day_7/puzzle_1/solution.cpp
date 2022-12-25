//find sum of all files/directories smaller than size 100000, might just have to construct a tree
#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main(){
    std::vector<std::string> directories;
    int total = 0;
    std::ifstream cmd("input.txt");
    std::unordered_map<std::string,int> sizes;
    std::string line, holder;
    while(std::getline(cmd, line)){
        holder = "";
        for(int i = 0; i < directories.size(); i++){
            holder = holder + directories[i] + " ";
        }

        if(line == "$ cd .."){
            directories.pop_back();
            continue;
        }
        if(line == "$ ls"){
            continue;
        }
        if(line.substr(0,3) == "dir"){
            sizes[holder + line.substr(4, line.size()-4) + " "] = 0;
            continue;
        }
        if(line.substr(0,4) == "$ cd"){
            directories.push_back(line.substr(5, line.size()-5));
            continue;
        }
        int temp = std::stoi(line.substr(0, line.find(" ")));
        holder = "";
        for(int i = 0; i < directories.size(); i++){
            holder = holder + directories[i] + " ";
            sizes[holder] += temp;
        }
    }

    for(auto i : sizes){
        if(i.second <= 100000){
            total += i.second;
        }
    }

    std::cout<< total << std::endl;

    return 0;
}
