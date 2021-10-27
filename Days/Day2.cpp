#include "Day2.hpp"

void Day2::Solve() {

    std::string partOne;
    std::string partTwo;

    // Load the input instructions

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day2.txt");

    std::vector<std::vector<char>> instructions;

    while (!inputStream.eof()) {

        std::string line;

        inputStream >> line;

        std::vector<char> lineInstructions;

        for(char instruction : line) {
            lineInstructions.emplace_back(instruction);
        }

        instructions.emplace_back(lineInstructions);
    }

    // Define the shape of individual keypads and their starting points

    std::vector<std::vector<char>>keypad1 = {{'1','2','3'},
                                             {'4','5','6'},
                                             {'7','8','9'}};


    std::vector<std::vector<char>>keypad2 = {{'0','0','1','0','0'},
                                             {'0','2','3','4','0'},
                                             {'5','6','7','8','9'},
                                             {'0','A','B','C','0'},
                                             {'0','0','D','0','0'}};

    int firstX = 1;
    int firstY = 1;

    int secondX = 2;
    int secondY = 2;

    // Calculate the passcode

    for(auto& passDigit : instructions) {

        for(auto& step : passDigit) {

            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            // Move the cursor in said direction, with boundary checking
            // It might be quite messy, so let's clarify
            // (This is caused by the way of keypad initialization)
            //
            // The X axis -> increasing the X value moves us down, decreasing it moves the cursor upwards
            // The Y axis -> increasing the Y value moves up right, decreasing it moves the cursor left
            //
            // And thus ==> U -> --x
            //              D -> ++x
            //              R -> ++y
            //              L -> --y
            //
            // We perform the following boundary checks: For both keypads, when incrementing we check whether we're
            //                                           still in vector boundaries, when decrementing, we check if
            //                                           we are still in values above zero.
            //                                           For the second keypad, we also check if we're not in the
            //                                           "0" valued keys, we use those as placeholders of boundaries.
            //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////

            switch(step) {

                case 'R':
                    firstY+1 < keypad1.size() ? ++firstY : firstY;
                    secondY+1 < keypad2.size() && keypad2[secondX][secondY+1] != '0' ? ++secondY : secondY;
                    break;
                case 'L':
                    firstY-1 >= 0 ? --firstY : firstY;
                    secondY-1 >= 0 && keypad2[secondX][secondY-1] != '0' ? --secondY : secondY;
                    break;
                case 'D':
                    firstX+1 < keypad1.size() ? ++firstX : firstX;
                    secondX+1 < keypad2.size() && keypad2[secondX+1][secondY] != '0' ? ++secondX : secondX;
                    break;
                case 'U':
                    firstX-1 >= 0 ? --firstX : firstX;
                    secondX-1 >= 0 && keypad2[secondX-1][secondY] != '0' ? --secondX : secondX;
                    break;
            }
        }

        // Add the letter to the passcode

        partOne += keypad1[firstX][firstY];
        partTwo += keypad2[secondX][secondY];
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}