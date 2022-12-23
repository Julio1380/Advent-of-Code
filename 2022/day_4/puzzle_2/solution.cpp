#include <fstream>
#include <iostream>
#include <string>

int main(){
    //needs to parse input string
    //needs to take in input
    std::string duo;

    std::ifstream partners("input.txt");
    int oneStart, oneEnd, twoStart, twoEnd, totalPairs = 0;

    while(getline(partners, duo)){
        int i, temp;
        
        i = duo.find('-');
        oneStart = std::stoi(duo.substr(0, i));
        temp = i+1;

        i = duo.find(',');
        oneEnd = std::stoi(duo.substr(temp, i-temp));
        temp = i+1;
        
        i = duo.find('-', i);
        twoStart = std::stoi(duo.substr(temp, i-temp));
        temp = i+1;

        twoEnd = std::stoi(duo.substr(temp, duo.size()-temp));

        if(!((oneStart > twoEnd)|| (twoStart > oneEnd))){
            totalPairs++;
        }
    }
    std::cout<<totalPairs<<std::endl;
    
    return 0;
}