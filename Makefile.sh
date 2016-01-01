# Generate lexer and parser cpp file
flex -o lex.cpp lex.l
bison -v -d -o parser.cpp parser.y

# Compiler these cpp files into seperate objects
clang++-3.5 -g -O3 -c lex.cpp -o lex.o
clang++-3.5 -g -O3 -c parser.cpp `llvm-config --cxxflags` -o parser.o
clang++-3.5 -g -O3 -c toy.cpp `llvm-config --cxxflags` -o toy.o

# Link seperate objects to form our compiler
clang++-3.5 -g -O3 parser.o toy.o lex.o `llvm-config --ldflags --system-libs --libs core mcjit native` -o gava

