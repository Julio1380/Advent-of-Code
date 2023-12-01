#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

bool checkWord(std::string&, int, int&);


int main(){
    int leftDigit, rightDigit, sum = 0;
    std::string currentLine;
    
    std::ifstream calibration("input.txt");
    while(getline(calibration, currentLine)){
        for(int i = 0; i < currentLine.size(); i++){
            if(currentLine[i] >= '0' && currentLine[i] <= '9'){
                leftDigit = currentLine[i] - '0';
                break;
            }else if(checkWord(currentLine, i, leftDigit)){
                break;
            }
        }
        for(int i = currentLine.size()-1; i >= 0;i--){
            if(currentLine[i] >= '0' && currentLine[i] <= '9'){
                rightDigit = currentLine[i] - '0';
                break;
            }else if(checkWord(currentLine, i, rightDigit)){
                break;
            }
        }
        sum += (leftDigit *10 + rightDigit);
    }

    std::cout<< sum << std::endl;

    return 0;
}


//Checks if next characters are a valid number. If it is a valid number, set the value of the digit and return True.
bool checkWord(std::string& line, int index, int& val){
    int amtLeft = line.size() - index;
    std::string sub;
    if(amtLeft >= 3){
        sub = line.substr(index, 3);
        if(!(sub.compare("one"))){
            val = 1;
            return true;
        }
        if(!(sub.compare("two"))){
            val = 2;
            return true;
        }
        if(!(sub.compare("six"))){
            val = 6;
            return true;
        }
    }
    if(amtLeft >= 4){
        sub = line.substr(index, 4);
        if(!(sub.compare("four"))){
            val = 4;
            return true;
        }
        if(!(sub.compare("five"))){
            val = 5;
            return true;
        }
        if(!(sub.compare("nine"))){
            val = 9;
            return true;
        }
        if(!(sub.compare("zero"))){
            val = 0;
            return true;
        }
    }
    if(amtLeft >= 5){
        sub = line.substr(index, 5);
        if(!(sub.compare("three"))){
            val = 3;
            return true;
        }
        if(!(sub.compare("seven"))){
            val = 7;
            return true;
        }
        if(!(sub.compare("eight"))){
            val = 8;
            return true;
        }
    }
    return false;
}
