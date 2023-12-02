#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int sum = 0, id, numR = 12, numB = 14, numG = 13;
    std::string currentLine;
    
    std::ifstream balls("input.txt");
    while(getline(balls, currentLine)){
        // need to parse the string, get the id first, 100 total so need to account for digits
        int index = 5, firstDigit, secondDigit, temp;
        bool invalid = false;
        firstDigit = currentLine[index] - '0';
        index ++;
        if(currentLine[index] == ':'){
            id = firstDigit;
        }else{
            secondDigit = currentLine[index] - '0';
            index++;
            if(currentLine[index] == ':'){
                id = firstDigit * 10 + secondDigit;
            }else{
                id = firstDigit * 100 + secondDigit * 10 + currentLine[index] - '0';
                index ++;
            }
        }
        index +=2;
        //parse the string for game data;
        //delimiter is a semicolon, commas separate balls. 
        while(index < currentLine.size()){
            //every loop, check if value is digit or known letter. if digit, convert whole number to int.
            if(currentLine[index] <= '9' && currentLine[index] >= '0'){
                temp = currentLine[index]-'0';
                index++;
                if(currentLine[index] <= '9' && currentLine[index] >= '0'){
                    temp = temp * 10 + currentLine[index]-'0';
                    index++;
                }
            }else if(currentLine[index] == 'r'){
                if(temp > numR){
                    invalid = true; 
                    break; 
                }
                index += 3;
            }else if(currentLine[index] == 'g'){
                if(temp > numG){
                    invalid = true; 
                    break; 
                }
                index += 5;
            }else if(currentLine[index] == 'b'){
                if(temp > numB){
                    invalid = true; 
                    break; 
                }
                index += 4;
            }
            index++;
            


        }

        if(invalid == false){
            sum += id;
        }

    }

    std::cout<< sum << std::endl;
}