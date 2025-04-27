
# Lab Tokenizer 

## Build on Windows (MinGW‑w64)

```
# Open "Developer PowerShell" or MinGW shell
build.bat           # or: powershell -ExecutionPolicy Bypass -File build.ps1
tokenizer_tests.exe  # run unit tests
tokenizer_app.exe data\sample.txt
```

Set the `CXX` environment variable to choose a different compiler:
```
set CXX=clang++
build.bat
```

## Build on Linux / macOS

```
g++ -std=c++17 -O2 tokenizer.cpp main.cpp -o tokenizer_app
g++ -std=c++17 -O2 tokenizer.cpp tests/test_tokenizer.cpp -o tokenizer_tests
./tokenizer_tests
./tokenizer_app data/sample.txt
```

## Project Structure
```
tokenizer.h / tokenizer.cpp   # core library
main.cpp                      # demo
tests/test_tokenizer.cpp      # unit tests (assert-based)
build.bat / build.ps1         # simple build scripts
data/sample.txt               # sample corpus
docs/...                      # one-page architecture doc
```

