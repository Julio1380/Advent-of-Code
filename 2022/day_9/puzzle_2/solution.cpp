#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>



int main(){
    //visited matrix

    std::vector<std::vector<int>> visited(10000, std::vector<int>(10000,0));
    int tailX = 5000, tailY = 5000, headX = 5000, headY = 5000;
    visited [5000][5000] = 1;
    int totalVisited = 0;
    std::ifstream reader("input.txt");
    std::string mover, direction;
    int moves;
     
    while(getline(reader, mover)){
        direction = mover.substr(0,1);
        moves = stoi(mover.substr(2,mover.size()-2));
        for(int i = 0; i < moves; i++){
            //head movement
            if(direction == "U"){
                headY--;
            }else if(direction == "D"){
                headY++;
            }else if(direction == "R"){
                headX++;
            }else if(direction == "L"){
                headX--;
            }

            //tail movement
            bool 
            sameRow = tailY == headY,
            sameCol = tailX == headX,
            headIsRight = (headX-tailX) > 1,
            headIsLeft = (headX-tailX) < -1,
            headIsUp = (headY-tailY) < -1,
            headIsDown = (headY-tailY) > 1;
        

            //same row, diff col
            if(sameRow && headIsRight){
                tailX++;
            }else if(sameRow && headIsLeft){
                tailX--;
            }else //diff row, same col
            if(sameCol && headIsUp){
                tailY--;
            }else if(sameCol && headIsDown){
                tailY++;
            }else //diagonal cases
            if((headIsRight && (headY-tailY == 1)) || (headIsDown && (headX-tailX == 1))){
                tailX++;
                tailY++;    
            }else if((headIsRight && (headY-tailY == -1)) || (headIsUp && (headX-tailX == 1))){
                tailX++;
                tailY--;
            }else if((headIsLeft && (headY-tailY == 1)) || (headIsDown && (headX-tailX == -1))){
                tailX--;
                tailY++;
            }else if((headIsLeft && (headY-tailY == -1)) || (headIsUp && (headX-tailX == -1))){
                tailX--;
                tailY--;
            }
            
            visited[tailX][tailY] = 1;
        }
    }   

    //visited checker
    for(int i = 0 ; i < visited.size(); i++){
        for(int j = 0; j < visited[0].size(); j++){
            totalVisited += visited[i][j];
        }
    }

    std::cout << totalVisited << std::endl;

    return 0;
}