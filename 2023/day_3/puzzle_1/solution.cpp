#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int getValue(std::vector<std::vector<char>> &table, std::vector<std::vector<int>> &visited, int i, int j){
    //doesn't need to check that is visited, guaranteed to not be visited.
    //two options: left or right.
    int front = j, back = j;
    // Starting from index, checks if left is digit and then repeats
    while(front > 0 && table[i][front-1] <= '9'&& table[i][front-1] >= '0'){
        front--;
    }
    while(back < (table[i].size()-1) && table[i][back+1] <= '9'&& table[i][back+1] >= '0'){
        back++;
    }
    int multiplier = 1;
    int sum = 0;
    for(int k = back; k >= front; k--){
        sum += ((table[i][k] -'0')* multiplier);
        multiplier = multiplier * 10;
        visited[i][k] = 1;
    }
    std::cout << sum << std::endl;
    return sum;
}

int main(){
    int sum = 0;
    std::string currentLine;
    std::ifstream nextline("input.txt");
    std::vector<std::vector<char>> engine;
    std::vector<char> temp;
    while(getline(nextline, currentLine)){
        temp.clear();
        for(int i = 0; i < currentLine.size(); i++){
            temp.push_back(currentLine[i]);
        }
        engine.push_back(temp);

    }
    std::vector<std::vector<int>> visited = std::vector<std::vector<int>>(engine.size(),std::vector<int>(engine[0].size(),0));

    // first iterate through matrix looking for symbols
    for(int i = 0; i < engine.size(); i++){
        for(int j = 0; j < engine[i].size(); j++){
            //finds symbol, searches around it.
            if(engine[i][j] != '.' && !(engine[i][j] <= '9' && engine[i][j] >= '0')){ 
                // Top Left               
                if(engine[i-1][j-1] <= '9' && engine[i-1][j-1] >= '0' && visited[i-1][j-1] == 0){
                    sum += getValue(engine, visited, i-1, j-1);
                }
                // Middle Left
                if(engine[i][j-1] <= '9' && engine[i][j-1] >= '0' && visited[i][j-1] == 0){
                    sum += getValue(engine, visited, i, j-1);
                }
                // Top Middle
                if(engine[i-1][j] <= '9' && engine[i-1][j] >= '0' && visited[i-1][j] == 0){
                    sum += getValue(engine, visited, i-1, j);
                }
                // Bottom Right
                if(engine[i+1][j+1] <= '9' && engine[i+1][j+1] >= '0' && visited[i+1][j+1] == 0){
                    sum += getValue(engine, visited, i+1, j+1);
                }
                // Bottom Left
                if(engine[i+1][j-1] <= '9' && engine[i+1][j-1] >= '0' && visited[i+1][j-1] == 0){
                    sum += getValue(engine, visited, i+1, j-1);
                }
                // Bottom Middle
                if(engine[i+1][j] <= '9' && engine[i+1][j] >= '0' && visited[i+1][j] == 0){
                    sum += getValue(engine, visited, i+1, j);
                }
                // Middle Right
                if(engine[i][j+1] <= '9' && engine[i][j+1] >= '0' && visited[i][j+1] == 0){
                    sum += getValue(engine, visited, i, j+1);
                }
                // Top Right
                if(engine[i-1][j+1] <= '9' && engine[i-1][j+1] >= '0' && visited[i-1][j+1] == 0){
                    sum += getValue(engine, visited, i-1, j+1);
                }

            }
        }
    }


    std::cout<< sum << std::endl;
}