//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include "pointcollection.hpp"

using namespace std;

int main(int argc, char **argv)
{

  try
  {
    PointCollection *pointCollection = new PointCollection();

    pointCollection->readFile("pontos.txt");

    pointCollection->print();

    pointCollection->~PointCollection();

    delete pointCollection;
  }
  catch (FailedToOpenFile e)
  {
    cout << "Erro ao abrir o arquivo " << e.filename << endl
         << endl;
  }
  catch (exception e)
  {
    cout << "Erro desconhecido: " << e.what() << endl
         << endl;
  }

  return 0;
}