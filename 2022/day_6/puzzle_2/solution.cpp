#include <string>
#include <fstream>
#include <iostream>

int main(){
    std::ifstream code("input.txt");
    std::string letters;
    getline(code,letters);

    int back = 0, front = 1;

    while(front - back < 14){
        for(int i = back; i < front; i++){
            if(letters[i] == letters[front]){
                back = i+1;
                front = back; 
                break;
            }
        }
        front++;
    }
    std::cout<< front << std::endl;
    return 0;
}