#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int leftDigit, rightDigit, sum = 0;
    std::string currentLine;
    
    std::ifstream calibration("input.txt");
    while(getline(calibration, currentLine)){
        for(int i = 0; i < currentLine.size(); i++){
            if(currentLine[i] >= '0' && currentLine[i] <= '9'){
                leftDigit = currentLine[i] - '0';
                break;
            }
        }
        for(int i = currentLine.size()-1; i >= 0;i--){
            if(currentLine[i] >= '0' && currentLine[i] <= '9'){
                rightDigit = currentLine[i] - '0';
                break;
            }
        }
        sum += (leftDigit *10 + rightDigit);
    }

    std::cout<< sum << std::endl;
}