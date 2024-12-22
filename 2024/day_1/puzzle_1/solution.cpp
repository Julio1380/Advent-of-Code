#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<int> getVals(std::string);
int calcLine(std::string);
void skipSpaces(std::string, int&);
int extractNumber(std::string, int&);
int ctoi(char);

int main(){
    std::string line;
    int sum = 0;    
    std::ifstream inputLine("sample.txt");

    while(getline(inputLine, line)){
        sum += calcLine(line);
    }

    std::cout << sum << std::endl;
}

int calcLine(std::string line){
    std::vector<int> vals = getVals(line);

    int diff = vals[0] - vals[1];
    std::cout << diff << std::endl;

    if (diff < 0){
        return -diff;
    }
    else
    {
        return diff;
    }
    
}

std::vector<int> getVals(std::string line){
    std::vector<int> vals;
    
    int index = 0;

    int val1 = extractNumber(line, index);

    skipSpaces(line, index);

    int val2 = extractNumber(line, index);



    vals.push_back(val1);
    vals.push_back(val2);
    return vals;
}

void skipSpaces(std::string line, int& index){
    
    while (index < line.length())
    {
        if (line[index] == ' '){
            index++;
        }
        else
        {
            break;
        }
    }
}

int extractNumber(std::string line, int& index){
    int multiplier = 10;
    int value = 0;

    while(index < line.length() && line[index] != ' '){
        value *= multiplier;
        value += ctoi(line[index]);
        index++;
    }
    
    return value;
}

int ctoi(char letter){
    return letter - '0';
}