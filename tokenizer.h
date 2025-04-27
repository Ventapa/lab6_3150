
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer {
public:
    explicit Tokenizer(char delimiter=' ') : delimiter_(delimiter) {}

    void loadFile(const std::string& filename);
    int  getToken(const std::string& word) const;
    const std::string& getWord(int token) const;
    void clear();

    const std::unordered_map<std::string,int>& dictionary() const { return word_to_token_; }

private:
    void addWord(const std::string& word);

    std::unordered_map<std::string,int> word_to_token_;
    std::vector<std::string> token_to_word_;
    char delimiter_;
};

#endif
