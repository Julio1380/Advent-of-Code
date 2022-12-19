#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

int main(){
    int itemSum = 0;
    std::string items;
    std::unordered_map<int,int> sackOne, sackTwo;

    std::ifstream rucksack("input.txt");
    while(getline(rucksack, items)){
        for(int i = 0; i < items.size(); i++){
            sackOne[items[i]]++;
        }

        getline(rucksack, items);

        for(int i = 0; i < items.size(); i++){
            sackTwo[items[i]]++;
        }

        getline(rucksack, items);

        for(int i = 0; i < items.size(); i++){
            if(sackOne[items[i]] != 0 && sackTwo[items[i]] != 0){
                if(items[i] >= 'a'){
                    itemSum += (items[i]-'a')+1;
                }else{
                    itemSum += (items[i] - 'A')+27;
                }
                break;
            }
        }
        sackOne.clear();
        sackTwo.clear();
    }

    std::cout<< itemSum << std::endl;
}