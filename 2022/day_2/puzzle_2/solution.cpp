#include <fstream>
#include <iostream>
#include <string>

int main(){
    int totalPoints = 0, roundScore;
    std::string roundData;
    char opp, self;
    std::ifstream round("input.txt");

    while(std::getline(round, roundData)){
        opp = roundData[0];
        self = roundData[2];
        switch(self){
            case 'X':
                roundScore = 0;
                break;
            case 'Y':
                roundScore = 3;
                break;
            case 'Z':
                roundScore = 6;
                break;
        }
        if(opp == 'A' && self == 'X' || opp == 'C' && self == 'Y' || opp == 'B' && self == 'Z'){
            roundScore += 3;
        }else if(opp == 'A' && self == 'Y' || opp == 'B' && self == 'X' || opp == 'C' && self == 'Z'){
            roundScore += 1;
        }else{
            roundScore += 2;
        }
        totalPoints += roundScore;
    }    


    std::cout<< totalPoints << std::endl;
}