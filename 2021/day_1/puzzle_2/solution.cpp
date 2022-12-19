#include <iostream>
#include <fstream>


int main(){
    int counter = 0;

    std::ifstream in("input");
    int first, second, third, previous, current;
    in>> first;
    in>> second;
    in>> third;
    previous = first + second+ third;
    while(true){
        first = second;
        second = third;
        if(in>>third){
            current = first +second + third;
            if(current > previous)
                counter++;
            previous = current;
        }else{
            break;
        }
        
    }
    std::cout << counter << std::endl;

    return 0;
}