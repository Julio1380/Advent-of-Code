#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int maxCals = 0, tempMax = 0;
    std::string currentVal;
    
    std::ifstream calories("input.txt");
    while(getline(calories, currentVal)){
        if(currentVal == ""){
            maxCals =std::max(maxCals, tempMax);
            tempMax = 0;
            continue;
        }
        tempMax += std::stoi(currentVal);
    }

    std::cout<< maxCals << std::endl;
}