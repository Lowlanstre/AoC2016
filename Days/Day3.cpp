#include "Day3.hpp"

// Function for determining whether three sides can form a triangle

bool Day3::isTriangle(int a, int b, int c) {
    return a+b > c && b+c > a && c+a > b;
}

void Day3::Solve() {

    int partOne = 0;
    int partTwo = 0;

    // Parse the input into triples

    std::ifstream inputStream;
    inputStream.open("..\\Input\\day3.txt");

    std::vector<std::vector<int>> triangles;

    while (!inputStream.eof()) {

        std::vector<int> sides = {0,0,0};

        inputStream >> sides[0] >> sides[1] >> sides[2];

        triangles.emplace_back(sides);
    }

    // Calculate part 1

    for(auto& triangle : triangles) {

        if(isTriangle(triangle[0],triangle[1],triangle[2]))
            ++partOne;
    }

    // Calculate part 2

    for(int i = 0; i < triangles.size(); i+=3) {

        for(int j = 0; j < 3; ++j) {

            if(isTriangle(triangles[i][j],triangles[i+1][j],triangles[i+2][j]))
                ++partTwo;
        }
    }

    std::cout << "The answer to part 1 is: " << partOne << "!\n";
    std::cout << "The answer to part 2 is: " << partTwo << "!\n";
}