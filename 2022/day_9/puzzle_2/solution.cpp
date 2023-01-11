#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>



int main(){
    //visited matrix

    std::vector<std::vector<int>> visited(10000, std::vector<int>(10000,0));
    std::vector<std::pair<int,int>> nodes(10,std::pair<int,int>(5000,5000));
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
                nodes[0].second--;
            }else if(direction == "D"){
                nodes[0].second++;
            }else if(direction == "R"){
                nodes[0].first++;
            }else if(direction == "L"){
                nodes[0].first--;
            }
            for(int j = 1; j < 10; j++){
                //tail movement
                bool 
                sameRow = nodes[j].second == nodes[j-1].second,
                sameCol = nodes[j].first == nodes[j-1].first,
                headIsRight = (nodes[j-1].first-nodes[j].first) > 1,
                headIsLeft = (nodes[j-1].first-nodes[j].first) < -1,
                headIsUp = (nodes[j-1].second-nodes[j].second) < -1,
                headIsDown = (nodes[j-1].second-nodes[j].second) > 1;
            

                //same row, diff col
                if(sameRow && headIsRight){
                    nodes[j].first++;
                }else if(sameRow && headIsLeft){
                    nodes[j].first--;
                }else //diff row, same col
                if(sameCol && headIsUp){
                    nodes[j].second--;
                }else if(sameCol && headIsDown){
                    nodes[j].second++;
                }else //diagonal cases
                if((headIsRight && headIsDown) || (headIsRight && (nodes[j-1].second-nodes[j].second == 1)) || (headIsDown && (nodes[j-1].first-nodes[j].first == 1))){
                    nodes[j].first++;
                    nodes[j].second++;    
                }else if((headIsRight && headIsUp) || (headIsRight && (nodes[j-1].second-nodes[j].second == -1)) || (headIsUp && (nodes[j-1].first-nodes[j].first == 1))){
                    nodes[j].first++;
                    nodes[j].second--;
                }else if((headIsLeft && headIsDown) || (headIsLeft && (nodes[j-1].second-nodes[j].second == 1)) || (headIsDown && (nodes[j-1].first-nodes[j].first == -1))){
                    nodes[j].first--;
                    nodes[j].second++;
                }else if((headIsLeft && headIsUp) || (headIsLeft && (nodes[j-1].second-nodes[j].second == -1)) || (headIsUp && (nodes[j-1].first-nodes[j].first == -1))){
                    nodes[j].first--;
                    nodes[j].second--;
                }
            }
            visited[nodes[9].first][nodes[9].second] = 1;
            
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