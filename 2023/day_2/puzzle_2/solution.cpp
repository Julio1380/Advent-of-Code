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
        int index = 8, firstDigit, secondDigit, temp, r = 0, g = 0, b = 0;
        bool invalid = false;
        
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
                r = std::max(r, temp);
                index += 3;
            }else if(currentLine[index] == 'g'){
                g = std::max(g, temp);
                index += 5;
            }else if(currentLine[index] == 'b'){
                b = std::max(b, temp);
                index += 4;
            }
            index++;
            


        }

        sum += (r*g*b);

    }

    std::cout<< sum << std::endl;
}