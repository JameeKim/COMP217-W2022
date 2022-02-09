/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #5 (Wed. Feb. 09, 2022)
 * File IO (fstream)
 *
 * 301058465 Dohyun Kim
 */

#include <fstream>
#include <iostream>
#include <string>

constexpr char USER_INFO_FILE[] = "userInfo.json";
constexpr char GAME_DATA_FILE[] = "gameData.txt";

/**
 * Print the file (ifstream) to the console output
 */
void printFile(std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}

void fileIO()
{
    // write to a file
    std::ofstream outputFile;
    outputFile.open(USER_INFO_FILE, std::ios::out);
    outputFile << "{\n";
    outputFile << "  \"players\": [\n";
    outputFile << "    {\n";
    outputFile << "      \"id\": 112233,\n";
    outputFile << "      \"username\": \"jamee\",\n";
    outputFile << "      \"country\": \"Canada\"\n";
    outputFile << "    }\n";
    outputFile << "  ]\n";
    outputFile << "}\n";
    outputFile.close();

    // read from a file
    std::ifstream inputFile;
    inputFile.open(USER_INFO_FILE);
    printFile(inputFile);
    inputFile.close();
}

void fileCursor()
{
    std::ifstream inputFile;
    inputFile.open(USER_INFO_FILE, std::ios::binary);

    // position1: the cursor position to the beginning
    const std::streampos begin = inputFile.tellg();

    // position2: the cursor position to the end
    inputFile.seekg(0, std::ios::end);
    const std::streampos end = inputFile.tellg();

    // position2 - position1 = length of the file
    std::cout << "Number of characters in the file: " << end - begin << std::endl;
}

void writeBlock()
{
    std::ofstream outputFile;
    outputFile.open(GAME_DATA_FILE, std::ios::binary);

    // block of memory to write to the file
    const char* memoryBlock = "BlahBlahYaddiYadda\n";

    outputFile.write(memoryBlock, 19);
    outputFile.close();

    std::ifstream inputFile;
    inputFile.open(GAME_DATA_FILE);
    printFile(inputFile);
    inputFile.close();
}
