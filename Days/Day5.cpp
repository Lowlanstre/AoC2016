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

            if(foundOne < 8) {
                ++foundOne;
                partOne += x[5];
            }

            // Cheeky char comparison to make sure index is in 0-7 boundaries + said index is not filled yet
            // Short-circuit evaluation guarantees that it is safe behavior

            if(x[5] > 47 && x[5] < 56 && partTwo[int(x[5])-48] == '_') {
                partTwo[int(x[5])-48] = x[6];
                ++foundTwo;
            }
        }
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}
