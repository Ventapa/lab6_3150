
@echo off
if "%CXX%"=="" (
  set CXX=g++
)
echo Compiling tokenizer_app...
%CXX% -std=c++17 -O2 tokenizer.cpp main.cpp -o tokenizer_app.exe
echo Compiling tokenizer_tests...
%CXX% -std=c++17 -O2 tokenizer.cpp tests\test_tokenizer.cpp -o tokenizer_tests.exe
echo Done.
