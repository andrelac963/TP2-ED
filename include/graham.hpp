//---------------------------------------------------------------------
// Arquivo      : graham.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include <iostream>
#include "stack.hpp"

using namespace std;

class Graham
{
private:
  Stack *stack;
  Stack *convexHull;

public:
  Graham(Stack *stack);
  ~Graham();
  void run();
  void print();
};

#endif