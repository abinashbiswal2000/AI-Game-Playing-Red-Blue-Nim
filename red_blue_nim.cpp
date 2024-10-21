#include <iostream>
#include <array>
#include <limits>
#include "standardFile.cpp"
#include "misereFile.cpp"

bool breakLoopCondition (int r , int b) {
    if (r == 0 || b == 0) {
        return 1;
    } else {
        return 0;
    }
}

void humanMovePrompt (int & r, int & b) {

    int humanNumber;
    std::string humanColor;
    
    std::cout << "Enter Your Move: ";
    std::cin >> humanColor >> humanNumber;
    

    if (humanColor == "red") {
        r = r - humanNumber;
    } else {
        b = b - humanNumber;
    }
}

void printGameStatus (int r , int b) {
    std::cout << "---------------------------------\n";
    std::cout << "Game Status -> Red: " << r << " , Blue: " << b << std::endl;
    std::cout << "---------------------------------\n";
}

void computerMoveFunction (int & r, int & b, std::string gameVersion) {
    int var = std::numeric_limits<int>::max();
    std::array<int,2> arr;
    if (gameVersion == "standard") {        
        arr = bestMove(r,b,1,var);
    } else {        
        arr = misereBestMove(r,b,1,var);
    }
    if (r - arr[0] == 0) {
        std::cout << "Computer Move: blue " << b - arr[1] << std::endl;
    } else {        
        std::cout << "Computer Move: red " << r - arr[0] << std::endl;
    }
    r = arr[0];
    b = arr[1];

}










int main (int argc, char *argv[]) {

    int startRed = std::stoi(argv[1]);
    int startBlue = std::stoi(argv[2]);
    std::string version = argv[3];
    std::string player = argv[4];

    if ((player != "human" && player != "computer") || (version != "standard" && version != "misere")) {
        std::cout << "\nInvalid Command!\nPlease restart game\n\n";
        return 0;
    }

    std::cout << "\nWelcome to the Red Blue Nim Game\n";
    while (1) {
        if (player == "human") {  
            printGameStatus(startRed, startBlue);
            if (breakLoopCondition(startRed , startBlue)) {
                std::cout << "Game Over" <<std::endl;
                if (version == "standard") {
                    std::cout << "Computer Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;
                } else {
                    std::cout << "Human Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;

                }
            }
            humanMovePrompt(startRed, startBlue);
            printGameStatus(startRed, startBlue);
            if (breakLoopCondition(startRed , startBlue)) {
                std::cout << "Game Over" <<std::endl;
                if (version == "standard") {
                    std::cout << "Human Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;
                } else {
                    std::cout << "Computer Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;

                }
            } 
            computerMoveFunction(startRed, startBlue, version);
        } else {
            printGameStatus(startRed, startBlue);
            if (breakLoopCondition(startRed , startBlue)) {
                std::cout << "Game Over" <<std::endl;
                if (version == "standard") {
                    std::cout << "Human Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;
                } else {
                    std::cout << "Computer Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;

                }
            }
            computerMoveFunction(startRed, startBlue, version);
            printGameStatus(startRed, startBlue);
            if (breakLoopCondition(startRed , startBlue)) {
                std::cout << "Game Over" <<std::endl;
                if (version == "standard") {
                    std::cout << "Computer Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;
                } else {
                    std::cout << "Human Wins by " << startRed*2 + startBlue*3 << " Points" << std::endl;
                    break;

                }
            }
            humanMovePrompt(startRed, startBlue);
        }
    }

    return 0;
}



