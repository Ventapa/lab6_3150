
#include "tokenizer.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

static std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return out;
}

void Tokenizer::addWord(const std::string& word) {
    auto lowered = toLower(word);
    if(lowered.empty()) return;
    if(word_to_token_.find(lowered)==word_to_token_.end()) {
        int id = static_cast<int>(token_to_word_.size());
        word_to_token_[lowered] = id;
        token_to_word_.push_back(lowered);
    }
}

void Tokenizer::loadFile(const std::string& filename) {
    std::ifstream in(filename);
    if(!in) throw std::runtime_error("Cannot open file: "+filename);
    std::string w;
    while(in >> w) addWord(w);
}

int Tokenizer::getToken(const std::string& word) const {
    auto lowered=toLower(word);
    auto it=word_to_token_.find(lowered);
    return it==word_to_token_.end() ? -1 : it->second;
}

const std::string& Tokenizer::getWord(int token) const {
    if(token<0 || token>=static_cast<int>(token_to_word_.size()))
        throw std::out_of_range("Invalid token");
    return token_to_word_[token];
}

void Tokenizer::clear() {
    word_to_token_.clear();
    token_to_word_.clear();
}
