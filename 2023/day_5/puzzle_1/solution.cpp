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
    std::string currentLine;
    std::ifstream nextline("input.txt");
    std::vector<long> seeds;

    getline(nextline,currentLine);
    int index = 7; 
    int forward;
    unsigned long multiplier, value;
    while(index < currentLine.size()){
        forward = index;
        multiplier = 1;
        value = 0;
        while(currentLine[forward] <= '9' && currentLine[forward] >= '0'){
            forward++;
        }
        for(int i = forward -1; i >= index; i--){
            value += multiplier * (currentLine[i] - '0');
            multiplier *= 10;
        }
        index = forward+1;
        seeds.push_back(value);
    }
    int size = seeds.size();
    std::vector<int> modified = std::vector<int>(size, 0);
    unsigned long source, destination, range, diff;
    while(getline(nextline, currentLine)){
        if(!(currentLine[0] <= '9' && currentLine[0] >= '0')){
            for(int i = 0; i < size; i++){
                modified[i] = 0;
            }
            continue;
        }
        // reads destination value
        index = 0;
        forward = 0;
        destination = 0;
        multiplier = 1;
        while(currentLine[forward] <= '9' && currentLine[forward] >= '0'){
            forward++;
        }
        for(int i = forward -1; i >= index; i--){
            destination += multiplier * (currentLine[i] - '0');
            multiplier *= 10;
        }
        index = forward+1;

        //reads source value
        source = 0;
        multiplier = 1;
        forward = index; 
        while(currentLine[forward] <= '9' && currentLine[forward] >= '0'){
            forward++;
        }
        for(int i = forward -1; i >= index; i--){
            source += multiplier * (currentLine[i] - '0');
            multiplier *= 10;
        }
        index = forward+1;

        //reads range value
        range = 0;
        multiplier = 1;
        forward = index; 
        while(currentLine[forward] <= '9' && currentLine[forward] >= '0'){
            forward++;
        }
        for(int i = forward -1; i >= index; i--){
            range += multiplier * (currentLine[i] - '0');
            multiplier *= 10;
        }
        //check if seed is in source range, convert if so.
        for(int i = 0; i < size; i++){
            if(seeds[i] >= source && seeds[i] <= source +range-1 && modified[i] == 0){
                modified[i] = 1;
                diff = seeds[i]-source;
                seeds[i] = destination+diff;
            }
        }
    }
    unsigned long least = INT_MAX;

    for(int i = 0; i < size; i++){
        if(least > seeds[i]){
            least = seeds[i];
        }
    }

    std::cout<< least << std::endl;
}