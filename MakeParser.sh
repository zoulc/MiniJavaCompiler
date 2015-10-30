flex -o lex.cpp lex.l
bison -v -d -o parser.cpp parser.y
g++ -o parser parser.cpp lex.cpp test.cpp
