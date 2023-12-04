#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

int STARTING_INDEX = 10, WINNING_DIGITS = 10, CARD_DIGITS = 25;

// Note: each card has 10 winning numbers and 25 regular numbers
int main(){
    int sum = 0, firstDigit, secondDigit, localPoints;
    std::string currentLine;
    std::ifstream nextline("input.txt");
    std::vector<int> winners = std::vector<int>(100, 0);
    std::queue<int> vals;

    while(getline(nextline, currentLine)){
        int temp;
        int index = STARTING_INDEX;
        for(int i = 0; i < WINNING_DIGITS; i++){
            temp = 0;
            firstDigit = currentLine[index] - '0';
            index++;
            secondDigit = currentLine[index] - '0';
            if(firstDigit >= 0){
                temp += firstDigit * 10;
            }
            temp += secondDigit;
            index +=2;
            vals.push(temp);
            winners[temp] = 1;
        }

        index +=2;
        localPoints = 0;

        //checks card values against winning numbers
        for(int i = 0; i < CARD_DIGITS; i++){
            temp = 0;
            firstDigit = currentLine[index] - '0';
            index++;
            secondDigit = currentLine[index] - '0';
            if(firstDigit >= 0){
                temp += firstDigit * 10;
            }
            temp += secondDigit;
            index +=2;
            if(winners[temp] == 1){
                localPoints++;
            }
        }

        //resets winning numbers
        while(!(vals.empty())){
            temp = vals.front();
            vals.pop();
            winners[temp] = 0;
        }
        if(localPoints > 0){
            sum += pow(2, localPoints-1);
        }
    }

    std::cout<< sum << std::endl;
}