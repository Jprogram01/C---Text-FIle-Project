#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//function to sort through an map that has a string as a key and a int as the value
//and sort it by key that has the highest value
bool sortByCount(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {
    // load both files in
    std::ifstream inFile("kingfollet.txt");
    std::ofstream outFile("wordcount.txt");
    // Run check to see if file can be opened, if not return error message
    if (!inFile.is_open()) {
        std::cerr << "Unable to open the input file." << std::endl;
        return 1;
    }

    if (!outFile.is_open()) {
        std::cerr << "Unable to open the output file." << std::endl;
        return 1;
    }
    // Initialize string variable for each word in txt file
    std::string KingFolletTextWord;
    // Initialize map to hold each word in txt file.
    std::map<std::string, int> WordMap;
    // Loop each word in file
    while (inFile >> KingFolletTextWord) {
        // Remove non-alphabetic characters and convert to lowercase
        std::string WordWithoutSymbol;
        for (char c : KingFolletTextWord) {
            if (std::isalpha(c)) {
                WordWithoutSymbol += std::tolower(c);
            }
        }

        // Update the map
        if (!WordWithoutSymbol.empty()) {
            WordMap[WordWithoutSymbol]++;
        }
    }

    // Convert the map to a vector of pairs for sorting
    std::vector<std::pair<std::string, int>> sortedWordVector(WordMap.begin(), WordMap.end());
    
    // Sort the vector in descending order based on word count
    std::sort(sortedWordVector.begin(), sortedWordVector.end(), sortByCount);

    // Write word counts to the output file
    for (const auto& it : sortedWordVector) {
        outFile << it.first << " " << it.second << "\n";
    }
    // Write output message to console once process is done
    std::cout << "Word counts written to 'wordcount.txt' in descending order of usage." << std::endl;
    // Close files
    inFile.close();
    outFile.close();

    return 0;
}





