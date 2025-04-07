#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer {
private:
    std::unordered_map<std::string, int> wordToToken;
    std::vector<std::string> tokenToWord;
    int nextTokenId = 0;

public:
    void readWordsFromString(const std::string& input) {
        std::istringstream stream(input);
        std::string word;
        while (stream >> word) {
            if (wordToToken.find(word) == wordToToken.end()) {
                wordToToken[word] = nextTokenId;
                tokenToWord.push_back(word);
                nextTokenId++;
            }
        }
    }

    int getToken(const std::string& word) const {
        auto it = wordToToken.find(word);
        if (it != wordToToken.end()) {
            return it->second;
        }
        return -1; // Token not found
    }

    std::string getWord(int token) const {
        if (token >= 0 && token < tokenToWord.size()) {
            return tokenToWord[token];
        }
        return ""; // Token not found
    }

    void printTokens() const {
        for (const auto& pair : wordToToken) {
            std::cout << "Word: " << pair.first << ", Token: " << pair.second << std::endl;
        }
    }
};

int main() {
    Tokenizer tokenizer;
    std::string input = "example test word example";
    tokenizer.readWordsFromString(input);
    tokenizer.printTokens();

    // Example usage
    std::string word = "example";
    int token = tokenizer.getToken(word);
    if (token != -1) {
        std::cout << "Token for word '" << word << "': " << token << std::endl;
    } else {
        std::cout << "Word '" << word << "' not found." << std::endl;
    }

    int exampleToken = 0;
    std::string exampleWord = tokenizer.getWord(exampleToken);
    if (!exampleWord.empty()) {
        std::cout << "Word for token " << exampleToken << ": " << exampleWord << std::endl;
    } else {
        std::cout << "Token " << exampleToken << " not found." << std::endl;
    }

    return 0;
}