#include "Day1.hpp"

void Day1::Solve() {

    int partOne = 0;
    int partTwo = 0;

    // Parse input into a vector of pairs

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day1.txt");

    std::vector<std::pair<char,int>> instructions;

    while (!inputStream.eof()) {

        std::string instruction;

        inputStream >> instruction;

        instructions.emplace_back(instruction[0],
                                  std::stoi(instruction.substr(1,std::string::npos)));
    }

    // Resolve which direction to face and move in said direction

    std::vector<std::pair<int,int>> visited = {{0,0}};

    int xCurrent = 0;
    int yCurrent = 0;

    int xStep = 0;
    int yStep = 1;

    for(auto instruction : instructions) {

        // Rotate

        switch(instruction.first) {

            default:
                int temp;
            case 'R':
                temp = yStep;
                yStep = -xStep;
                xStep = temp;
                break;
            case 'L':
                temp = yStep;
                yStep = xStep;
                xStep = -temp;
                break;
        }

        // Move

        for(auto steps = 0; steps < instruction.second; ++steps) {

            xCurrent += xStep;
            yCurrent += yStep;

            auto currentPos = std::make_pair(xCurrent,yCurrent);

            if(partTwo == 0 && std::find(visited.begin(), visited.end(), currentPos) != visited.end())
                partTwo = std::abs(currentPos.first) + std::abs(currentPos.second);
            visited.emplace_back(currentPos);
        }
    }

    partOne = std::abs(xCurrent) + std::abs(yCurrent);

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}