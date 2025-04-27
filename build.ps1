
param(
  [string]$Compiler = "g++"
)
Write-Host "Compiling tokenizer_app..."
& $Compiler -std=c++17 -O2 tokenizer.cpp main.cpp -o tokenizer_app.exe
Write-Host "Compiling tokenizer_tests..."
& $Compiler -std=c++17 -O2 tokenizer.cpp tests/test_tokenizer.cpp -o tokenizer_tests.exe
Write-Host "Done."
