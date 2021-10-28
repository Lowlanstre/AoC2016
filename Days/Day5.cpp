#include "Day5.hpp"

#include "../External/md5.hpp"

void Day5::Solve() {

    std::string partOne;
    std::string partTwo = "________";

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day5.txt");

    std::string doorID;
    inputStream >> doorID;

    int foundOne = 0;
    int foundTwo = 0;

    // The second answer is guaranteed to take longer to compute than the first , so we can use it as an exit condition
    // The whole mechanism just brute-forces MD5 hashes, so it's doomed to be slow

    for(int i = 0; foundTwo < 8; ++i) {

        std::string x = MD5(doorID + std::to_string(i)).hexdigest();

        if(x.substr(0,5) == "00000") {

            char sixth = x[5];
            char seventh = x[6];

            if(foundOne < 8) {
                ++foundOne;
                partOne += sixth;
            }

            // Cheeky char comparison to make sure index is in 0-7 boundaries + said index is not filled yet
            // Short-circuit evaluation guarantees that it is safe behavior

            int charBelowZero = 47;
            int charAboveseven = 56;

            int charToIntOffset = 48;

            if(sixth > charBelowZero && sixth < charAboveseven && partTwo[int(sixth)-charToIntOffset] == '_') {
                partTwo[int(sixth)-charToIntOffset] = seventh;
                ++foundTwo;
            }
        }
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}
