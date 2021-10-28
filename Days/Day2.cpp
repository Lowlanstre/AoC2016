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
    // They are rotated as such to comfort the X and Y axis of vectors

    std::vector<std::vector<char>>keypad1 = {{'7','4','1'},
                                             {'8','5','2'},
                                             {'9','6','3'}};


    std::vector<std::vector<char>>keypad2 = {{'0','0','5','0','0'},
                                             {'0','A','6','2','0'},
                                             {'D','B','7','3','1'},
                                             {'0','C','8','4','0'},
                                             {'0','0','9','0','0'}};

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
            //
            // The X axis -> increasing the X value moves us right, decreasing it moves the cursor left
            // The Y axis -> increasing the Y value moves us upwards, decreasing it moves the cursor downwards
            //
            // And thus ==> U -> ++y
            //              D -> --y
            //              R -> ++x
            //              L -> --x
            //
            // We perform the following boundary checks: For both keypads, when incrementing we check whether we're
            //                                           still in vector boundaries, when decrementing, we check if
            //                                           we are still in values above zero.
            //                                           For the second keypad, we also check if we're not in the
            //                                           "0" valued keys, we use those as placeholders of boundaries.
            //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////

            switch(step) {

                case 'U':
                    firstY+1 < keypad1.size() ? ++firstY : firstY;
                    secondY+1 < keypad2.size() && keypad2[secondX][secondY+1] != '0' ? ++secondY : secondY;
                    break;
                case 'D':
                    firstY-1 >= 0 ? --firstY : firstY;
                    secondY-1 >= 0 && keypad2[secondX][secondY-1] != '0' ? --secondY : secondY;
                    break;
                case 'R':
                    firstX+1 < keypad1.size() ? ++firstX : firstX;
                    secondX+1 < keypad2.size() && keypad2[secondX+1][secondY] != '0' ? ++secondX : secondX;
                    break;
                case 'L':
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
