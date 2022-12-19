#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

int main(){
    int tempMax = 0;
    std::priority_queue<int> mostCals; 
    std::string currentVal;
    
    std::ifstream calories("input.txt");

    while(getline(calories, currentVal)){
        if(currentVal == ""){
            mostCals.push(tempMax);
            tempMax = 0;
            continue;
        }
        tempMax += std::stoi(currentVal);
    }
    int maxCals = 0;
    for(int i = 0; i < 3; ++i){
        maxCals += mostCals.top();
        mostCals.pop();
    }

    std::cout<< maxCals << std::endl;
}