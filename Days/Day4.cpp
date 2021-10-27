#include "Day4.hpp"

void Day4::Solve() {

    int partOne = 0;
    int partTwo = 0;

    // Load the input into several containers

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day4.txt");

    std::vector<std::string>rooms;
    std::vector<std::string>checksums;
    std::vector<int>roomNumbers;
    std::vector<std::map<char,int>>occurrences;

    while (!inputStream.eof()) {

        std::string input;

        inputStream >> input;

        input.erase(std::remove(input.begin(),input.end(),'-'),input.end());

        // Cheeky string manipulation to split our data into appropriate and mostly handy containers

        rooms.emplace_back(input.substr(0,input.length()-10));
        roomNumbers.emplace_back(std::stoi(input.substr(input.length()-10,3)));
        checksums.emplace_back(input.substr(input.length()-6,5));
    }

    // Store the occurrence of each letter in alphabetical order into a map

    for(int i = 0; i < rooms.size(); ++i) {

        occurrences.emplace_back();

        for(char letter : rooms[i]) {

            if(occurrences[i].find(letter) == occurrences[i].end()) {
                occurrences[i].emplace(letter,1);
            } else {
                ++occurrences[i].at(letter);
            }
        }
    }

    // Check the checksum

    for(int i = 0; i < checksums.size(); ++i) {

        bool valid = true;

        for(auto& character : checksums[i]) {

            int bigger = 0;
            int value;

            auto characterIter = occurrences[i].find(character);

            if(characterIter == occurrences[i].end()){
                valid = false;
                break;
            } else {
                value = characterIter->second;
            }

            for(auto curr = occurrences[i].begin(); curr != occurrences[i].end(); ++curr) {
                if(curr->second > value) {
                 ++bigger;
                }
                else if(curr->second == value) {
                    if (std::distance(curr, occurrences[i].end()) > std::distance(characterIter, occurrences[i].end())) {
                        ++bigger;
                    }
                }
            }

            if(bigger >= 5) {
                valid = false;
                break;
            }
        }

        if(valid)
            partOne += roomNumbers[i];
    }

    // Shift the names and find the correct room

    for(int i = 0; i < rooms.size(); ++i) {

        int shift = roomNumbers[i] % 26;

        for(auto& letter : rooms[i]) {

            if(letter + shift > 'z')
                letter -= 26;
            letter += shift;
        }
        if(rooms[i] == "northpoleobjectstorage")
            partTwo = roomNumbers[i];
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}
