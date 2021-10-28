#include "Day6.hpp"

void Day6::Solve() {

    std::string partOne;
    std::string partTwo;

    // Load the input into a container

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day6.txt");

    std::vector<std::string> messages;
    std::vector<std::unordered_map<char,int>> occurrences;

    while (!inputStream.eof()) {

        std::string input;

        inputStream >> input;

        messages.emplace_back(input);
    }

    // Initialize vector with empty maps

    for(int i = 0; i < messages.back().length(); ++i) {
        occurrences.emplace_back();
    }

    // Paste letter occurrences to appropriate maps

    for(auto& message : messages) {

        for (int i = 0; i < message.length(); ++i) {

            if(occurrences[i].find(message[i]) == occurrences[i].end()) {

                occurrences[i].emplace(message[i],1);

            } else {
                ++occurrences[i].at(message[i]);
            }
        }
    }

    // Find the least and most occurring number

    for(auto& letterMap : occurrences) {

        int biggest = 0;
        int smallest = INT32_MAX;

        // 1st iteration -> find the biggest and smallest number

        for(auto& pair : letterMap) {
            if(pair.second > biggest)
                biggest = pair.second;
            if(pair.second < smallest)
                smallest = pair.second;
        }

        // 2nd iteration -> locate the letter with the biggest and smallest number and add them to the answer

        for(auto& pair : letterMap) {
            if(pair.second == biggest)
                partOne += pair.first;
            if(pair.second == smallest)
                partTwo += pair.first;
        }

    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}
