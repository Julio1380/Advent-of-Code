#include <fstream>
#include <iostream>
#include <string>
#include <stack>

int main(){
    std::ifstream instructions("input.txt");
    std::string mover, solution = "";
    int amount, first, second;
    std::stack<char> one, two, three, four, five, six, seven, eight, nine, holder;
    std::stack<char> * selectFirst, *selectSecond; 
    char temp;

    one.push('N');
    one.push('D');
    one.push('M');
    one.push('Q');
    one.push('B');
    one.push('P');
    one.push('Z');
    
    two.push('C');
    two.push('L');
    two.push('Z');
    two.push('Q');
    two.push('M');
    two.push('D');
    two.push('H');
    two.push('V');
    
    three.push('Q');
    three.push('H');
    three.push('R');
    three.push('D');
    three.push('V');
    three.push('F');
    three.push('Z');
    three.push('G');
    
    four.push('H');
    four.push('G');
    four.push('D');
    four.push('F');
    four.push('N');
    
    five.push('N');
    five.push('F');
    five.push('Q');
    
    six.push('D');
    six.push('Q');
    six.push('V');
    six.push('Z');
    six.push('F');
    six.push('B');
    six.push('T');

    seven.push('Q');
    seven.push('M');
    seven.push('T');
    seven.push('Z');
    seven.push('D');
    seven.push('V');
    seven.push('S');
    seven.push('H');

    eight.push('M');
    eight.push('G');
    eight.push('F');
    eight.push('P');
    eight.push('N');
    eight.push('Q');

    nine.push('B');
    nine.push('W');
    nine.push('R');
    nine.push('M');

    while(getline(instructions, mover)){
        amount = std::stoi(mover.substr(5,mover.find(' ', 5) - 5));
        
        first = mover.find('f')+5;
        first = std::stoi(mover.substr(first, mover.find(' ', first)-(first)));
        
        second = mover.find('t')+3;
        second = std::stoi(mover.substr(second, mover.size()-second));
        
        switch(first){
            case 1:
                selectFirst = &one;
                break;
            
            case 2:
                selectFirst = &two;
                break;

            case 3:
                selectFirst = &three;
                break;

            case 4:
                selectFirst = &four;
                break;

            case 5:
                selectFirst = &five;
                break;

            case 6:
                selectFirst = &six;
                break;

            case 7:
                selectFirst = &seven;
                break;

            case 8:
                selectFirst = &eight;
                break;

            case 9:
                selectFirst = &nine;
                break;
        }

        switch(second){
            case 1:
                selectSecond = &one;
                break;
            
            case 2:
                selectSecond = &two;
                break;

            case 3:
                selectSecond = &three;
                break;

            case 4:
                selectSecond = &four;
                break;

            case 5:
                selectSecond = &five;
                break;

            case 6:
                selectSecond = &six;
                break;

            case 7:
                selectSecond = &seven;
                break;

            case 8:
                selectSecond = &eight;
                break;

            case 9:
                selectSecond = &nine;
                break;
        }

        for(int i = 0; i < amount; i++){
            if((*selectFirst).empty()){
                break;
            }
            temp = (*selectFirst).top();
            (*selectFirst).pop();
            holder.push(temp);
        }
        while(!holder.empty()){
            temp = holder.top();
            holder.pop();
            (*selectSecond).push(temp);
        }

    }

    solution = solution + one.top();
    solution = solution + two.top();
    solution = solution + three.top();
    solution = solution + four.top();
    solution = solution + five.top();
    solution = solution + six.top();
    solution = solution + seven.top();
    solution = solution + eight.top();
    solution = solution + nine.top();

    std::cout << solution << std::endl;
    

    return 0;
}