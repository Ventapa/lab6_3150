
#include "tokenizer.h"
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {
    const char* f = (argc>1) ? argv[1] : "data/sample.txt";
    try {
        Tokenizer t;
        t.loadFile(f);
        std::cout<<"Tokens from "<<f<<":\n";
        for(const auto& [w,id]: t.dictionary())
            std::cout<<id<<" -> "<<w<<"\n";

        std::cout<<"Type word or id (CTRL+D to quit):\n";
        std::string inp;
        while(std::cin>>inp){
            if(std::all_of(inp.begin(), inp.end(), ::isdigit)) {
                int id = std::stoi(inp);
                try {
                    std::cout<<t.getWord(id)<<"\n";
                } catch(std::exception& e){ std::cout<<"(invalid)\n";}
            } else {
                int id = t.getToken(inp);
                std::cout<<(id==-1?"(unknown)":std::to_string(id))<<"\n";
            }
        }
    }catch(std::exception& e){
        std::cerr<<e.what()<<"\n";
        return 1;
    }
}
