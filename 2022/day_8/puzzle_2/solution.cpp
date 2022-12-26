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
    int maxWidth = grid[0].size(), maxHeight = grid.size(), maxScenic = 0, localScenic;
    for(int i = 0; i < maxHeight; i++){
        for(int j = 0; j < maxWidth; j++){
            int up = 0, down = 0, right = 0, left = 0;
            //up
            for(int k = i-1; k >=0; k--){
                up++;
                if(grid[k][j] >= grid[i][j]){
                   break; 
                }
            }

            //down
            for(int k = i+1; k < maxHeight; k++){
                down++;
                if(grid[k][j] >= grid[i][j]){
                   break; 
                }
                
            }
            //left
            for(int k = j-1; k >= 0; k--){
                left++;
                if(grid[i][k] >= grid[i][j]){
                   break; 
                }
            }
            //right
            for(int k = j+1; k < maxWidth; k++){
                right++;
                if(grid[i][k] >= grid[i][j]){
                   break; 
                }
            
            }
            localScenic = up * left * right * down;
            maxScenic = std::max(maxScenic,localScenic);
            
        }
    }

    std::cout << maxScenic << std::endl;

    return 0;
}