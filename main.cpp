#include <iostream>
using namespace std;


int LinhaAtaqueAlfanum(string linhaAtaqueAlfanum)
{
  int linhaAtaque;

  if(linhaAtaqueAlfanum == "A")
    linhaAtaque = 0;
  if(linhaAtaqueAlfanum == "B")
    linhaAtaque = 1;
  if(linhaAtaqueAlfanum == "C")
    linhaAtaque = 2;
  if(linhaAtaqueAlfanum == "D")
    linhaAtaque = 3;
  if(linhaAtaqueAlfanum == "E")
    linhaAtaque = 4;
  if(linhaAtaqueAlfanum == "F")
    linhaAtaque = 5;
  if(linhaAtaqueAlfanum == "G")
    linhaAtaque = 6;
  if(linhaAtaqueAlfanum == "H")
    linhaAtaque = 7;
  if(linhaAtaqueAlfanum == "I")
    linhaAtaque = 8;
  if(linhaAtaqueAlfanum == "J")
    linhaAtaque = 9;

  return linhaAtaque;
}



int main() 
{
  int linhaDefesa, colunaDefesa, linhaAtaque, colunaAtaque, navios = 0, tentativas = 70;
  int colunaAtaqueAlfanum;
  string linhaAtaqueAlfanum; 
  char indiceAtaque[10][10], indiceDefesa[10][10], indiceRestante[10][10]; 
  bool vitoria = 0;
  srand(time(0));

  for(int p = 0; p < 10; p++) //zerar tudo no início (tudo *)
  {
    for(int q = 0; q < 10; q++)
    {
      indiceAtaque[p][q] = '*';
      indiceRestante[p][q] = '*'; //será usado caso o usuário perca a partida, para mostrar onde estava o restante dos navios
    }
  }

  for(int n = 0; n < 5; n++) //adicionar as cooredenadas dos navios
  {
    linhaDefesa = rand() % 10;
    colunaDefesa = rand() % 10;
    indiceDefesa[linhaDefesa][colunaDefesa] = 'O';
    indiceRestante[linhaDefesa][colunaDefesa] = 'O'; //usado no final, caso o usuário perca
    navios++;
  }

  //CAMPO DE BATALHA NO INÍCIO
  cout << "\t";
  for(int p = 1; p <= 10; p++) //fazer o cabeçalho das colunas
  {
    cout << p << "\t";
  }
  cout << endl;

  for(int l = 0; l < 10; l++) //rodar o resultado inical (tudo *)
  {
    if(l == 0) //fazer o cabeçalho das linhas
    cout << "A\t";
    if(l == 1)
    cout << "B\t";
    if(l == 2)
    cout << "C\t";
    if(l == 3)
    cout << "D\t";
    if(l == 4)
    cout << "E\t";
    if(l == 5)
    cout << "F\t";
    if(l == 6)
    cout << "G\t";
    if(l == 7)
    cout << "H\t";
    if(l == 8)
    cout << "I\t";
    if(l == 9)
    cout << "J\t";

    for(int c = 0; c < 10; c++) //rodar o resultado inicial (tudo *)
    {
      cout << indiceAtaque[l][c] << "\t";
    }
    cout << endl;
  }
  cout << endl;

  //INTERAÇÃO COM O USUÁRIO
  while(tentativas != 0 && vitoria != 1)
  {
    cout << "Tentativas restantes: " << tentativas << endl;
    cout << "Navios Restantes: " << navios << endl;
    tentativas -= 1;

    cout << "\nEm qual coordenada será o ataque?? \n";
    cin >> linhaAtaqueAlfanum >> colunaAtaqueAlfanum;
    cout << endl;

    linhaAtaque = LinhaAtaqueAlfanum(linhaAtaqueAlfanum); //lê a linha do formato de letra (A e B) e retorna no formato de índice de uma matriz (0 e 1)
    colunaAtaque = colunaAtaqueAlfanum - 1; //diminui 1 do valor numérico da coluna correspondente para transformá-lo no formato de índice

    indiceAtaque[linhaAtaque][colunaAtaque] = 'O';

    if(indiceAtaque[linhaAtaque][colunaAtaque] == indiceDefesa[linhaAtaque][colunaAtaque])
    {
      indiceAtaque[linhaAtaque][colunaAtaque] = 'O';
      indiceRestante[linhaAtaque][colunaAtaque] = '*'; //usado no final, caso o usuário perca
      navios -= 1;
      if(navios == 0)
      {
        vitoria = 1;
      }
    }
    else if(indiceAtaque[linhaAtaque][colunaAtaque] != indiceDefesa[linhaAtaque][colunaAtaque])
    {
      indiceAtaque[linhaAtaque][colunaAtaque] = 'X';
    }

    cout << "\t";
    for(int p = 1; p <= 10; p++) //fazer o cabeçalho das colunas
    {
      cout << p << "\t";
    }
    cout << endl;

    for(int l = 0; l < 10; l++) //rodar os resultados
    {
      if(l == 0) //fazer o cabeçalho das linhas
        cout << "A\t";
      if(l == 1)
        cout << "B\t";
      if(l == 2)
        cout << "C\t";
      if(l == 3)
        cout << "D\t";
      if(l == 4)
        cout << "E\t";
      if(l == 5)
        cout << "F\t";
      if(l == 6)
        cout << "G\t";
      if(l == 7)
        cout << "H\t";
      if(l == 8)
        cout << "I\t";
      if(l == 9)
        cout << "J\t";
      /*
      if(l == 10)
        cout << "K\t";
      if(l == 11)
        cout << "L\t";
      if(l == 12)
        cout << "M\t";
      if(l == 13) 
        cout << "N\t";
      if(l == 14)
        cout << "O\t";
      if(l == 15)
        cout << "P\t";
      if(l == 16)
        cout << "Q\t";
      if(l == 17)
        cout << "R\t";
      if(l == 18)
        cout << "S\t";
      if(l == 19)
        cout << "T\t";
      */
      for(int c = 0; c < 10; c++) //rodar o resultado
      {
        cout << indiceAtaque[l][c] << "\t";
      }
      cout << endl;
    }
  }

  //FIM DO PROGRAMA E CONDIÇÕES FINAIS
  cout << endl;

  if(tentativas == 0)
  {
    cout << "Fim de jogo. Você perdeu!\n";
    cout << "Utilizou todas as alternativas, mas ainda faltou(aram) " << navios << " navio(s) adversário(s) em jogo!!\n\n";

    for(int p = 0; p < 10; p++) //zerar tudo no início (tudo *)
    {
      for(int q = 0; q < 10; q++)
      {
        indiceAtaque[p][q] = '*';
      }
    }

    cout << "\t";
    for(int p = 1; p <= 10; p++) //fazer o cabeçalho das colunas
    {
      cout << p << "\t";
    }
    cout << endl;
    
    for(int l = 0; l < 10; l++) //rodar o resultado inical (tudo *)
    {
      if(l == 0) //fazer o cabeçalho das linhas
        cout << "A\t";
      if(l == 1)
        cout << "B\t";
      if(l == 2)
        cout << "C\t";
      if(l == 3)
        cout << "D\t";
      if(l == 4)
        cout << "E\t";
      if(l == 5)
        cout << "F\t";
      if(l == 6)
        cout << "G\t";
      if(l == 7)
        cout << "H\t";
      if(l == 8)
        cout << "I\t";
      if(l == 9)
        cout << "J\t";

      for(int c = 0; c < 10; c++) //rodar o resultado inicial (tudo *)
      {
        if(indiceAtaque[l][c] != indiceRestante[l][c])
        {
          indiceAtaque[l][c] = 'O';
        }
        cout << indiceAtaque[l][c] << "\t";
      }
      cout << endl;
    }
  }
  else if(navios == 0)
  {
    cout << "Fim de jogo. Você Ganhou! Parabénss!!\n";
    cout << "Todos os navios foram afundados!!\n";
  }

  return 0;
}