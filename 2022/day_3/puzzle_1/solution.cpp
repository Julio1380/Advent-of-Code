#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int main(){
    int itemSum = 0;
    std::string items;
    std::unordered_map<int,int> pocketOne;

    std::ifstream rucksack("input.txt");
    while(getline(rucksack, items)){
        for(int i = 0; i < items.size()/2; i++){
            pocketOne[items[i]]++;
        }
        for(int i = items.size()/2; i < items.size(); i++){
            if(pocketOne[items[i]] != 0){
                if(items[i] >= 'a'){
                    itemSum += (items[i]-'a')+1;
                }else{
                    itemSum += (items[i] - 'A')+27;
                }
                break;
            }
        }
        pocketOne.clear();
    }

    std::cout<< itemSum << std::endl;
}