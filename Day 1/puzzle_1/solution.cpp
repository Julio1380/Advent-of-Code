#include <iostream>
#include <fstream>


int main(){
    int counter = 0;

    std::ifstream in("input");
    int num, prev;
    in>> prev;
    while(in >> num){
        if(num > prev)
            counter++;
        prev = num;
    }
    std::cout << counter << std::endl;

    return 0;
}