#include "Day7.hpp"

void Day7::Solve() {

    int partOne = 0;
    int partTwo = 0;

    // Load the input into a weird container

    std::vector<std::vector<std::string>> IPs;

    char garbage[] = {']', '['};

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day7.txt");


    while (!inputStream.eof()) {

        std::string input;
        std::vector<std::string> codes = {"",""};

        int index = 0;

        inputStream >> input;

        // Switches buffer depending on the closing and opening brackets

        for (auto& c : input) {

            if(c == garbage[1])
                index = 1;
            if(c == garbage[0])
                index = 0;

            codes[index] += c;
        }

        IPs.emplace_back(codes);
    }

    for(auto & IP : IPs) {

        bool invalidated = false;
        bool passedOne = false;
        bool passedTwo = false;

        // Does some computations idk, you should understand it

        for (int r = 0; r <= 1; ++r ) {
            for (int i = r; i < IP[r].length() - 2; ++i) {
                if ( i < IP[r].length() -3 && IP[r][i] != IP[r][i + 1] && IP[r][i] == IP[r][i + 3] && IP[r][i + 1] == IP[r][i + 2]) {
                    if (IP[r][i] != garbage[r] && IP[r][i + 1] != garbage[r] && IP[r][i + 2] != garbage[r] && IP[r][i + 3] != garbage[r]) {
                        if(r == 0)
                            passedOne = true;
                        else
                            invalidated = true;
                    }
                }
                if(r == 0) {
                    if (IP[r][i] != IP[r][i + 1] && IP[r][i] == IP[r][i + 2]) {
                        if(IP[r+1].find(std::string() + IP[r][i+1] + IP[r][i] + IP[r][i+1]) != std::string::npos) {
                            passedTwo = true;
                        }
                    }
                }
            }
        }

        // Counts stuff if it's true

        if(passedOne && !invalidated)
            ++partOne;
        if(passedTwo)
            ++partTwo;
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}