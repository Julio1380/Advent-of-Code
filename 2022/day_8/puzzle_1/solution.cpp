#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream row("input.txt");
    std::string reader;
    std::vector<std::vector<int>> grid;
    std::vector<int> temp;
    while(getline(row, reader)){
        for(int i = 0; i < reader.size(); i++){
            temp.push_back(reader[i]-'0');
        }
        grid.push_back(temp);
        temp.clear();
    }
    int maxWidth = grid[0].size(), maxHeight = grid.size(), total = 0;
    bool spotted;
    for(int i = 0; i < maxHeight; i++){
        for(int j = 0; j < maxWidth; j++){
            if(i == 0 || i == maxHeight-1 || j == 0 || j == maxWidth-1){
                total++;
                continue;
            }
            
            spotted = false;
            //up
            for(int k = i-1; k >=0; k--){
                if(grid[k][j] >= grid[i][j]){
                   break; 
                }
                if(k == 0){
                    spotted = true;
                }
            }

            //down
            for(int k = i+1; k < maxHeight; k++){
                if(grid[k][j] >= grid[i][j]){
                   break; 
                }
                if(k == maxHeight-1){
                    spotted = true;
                }
            }
            //left
            for(int k = j-1; k >= 0; k--){
                if(grid[i][k] >= grid[i][j]){
                   break; 
                }
                if(k == 0){
                    spotted = true;
                }
            }
            //right
            for(int k = j+1; k < maxWidth; k++){
                if(grid[i][k] >= grid[i][j]){
                   break; 
                }
                if(k == maxWidth-1){
                    spotted = true;
                }
            }
            if(spotted == true){
                total++;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}