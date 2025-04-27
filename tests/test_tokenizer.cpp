
#include "../tokenizer.h"
#include <cassert>
#include <iostream>

void loadTest(){
    Tokenizer t;
    t.loadFile("data/sample.txt");
    assert(t.getToken("hello") != -1);
    assert(t.getWord(t.getToken("world"))=="world");
}

void caseTest(){
    Tokenizer t;
    t.loadFile("data/sample.txt");
    assert(t.getToken("HELLO")==t.getToken("hello"));
}

int main(){
    loadTest();
    caseTest();
    std::cout<<"All unit tests passed!\n";
    return 0;
}
