#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

char mapa[200][200], jogada;
int coluna, linha, cont, i;
int fx, fy, f;
int posx[300], posy[300];
int final;;
int *tam, conf, opcao, matriz = 1, tf, sair, speed, velo = 2;
int gets();
int getch(void);
int kbhit(void);

//CADASTRO

FILE *arq;

typedef struct
{
  char nome[20];
  int pontuacao;
} CADASTRO;

CADASTRO ficha;

void Conf() {

  //CONFIGURAÇÕES INICIAIS DO JOGO
  tam = malloc(5 * sizeof(int));
  tam[0] = 30;
  tam[1] = 7;
  tam[2] = 29;
  tam[3] = 6;
  tam[4] = 28;
  tam[5] = 5;  
  tf = 10;
  speed = 150000;
}

void Menu() {

  arq = fopen("cadastro.bin","a+");

  system("clear");
  printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  printf("\n\t@@                                                         @@");
  printf("\n\t@@       @@@@@@@  @@   @@  @@@@@@@  @@   @@  @@@@@@@       @@");
  printf("\n\t@@       @@       @@@  @@  @@   @@  @@  @@   @@            @@");
  printf("\n\t@@       @@@@@@@  @@@@@@@  @@@@@@@  @@@@@    @@@@@@@       @@");
  printf("\n\t@@            @@  @@  @@@  @@   @@  @@  @@   @@            @@");
  printf("\n\t@@       @@@@@@@  @@   @@  @@   @@  @@   @@  @@@@@@@       @@");
  printf("\n\t@@                                                         @@");
  printf("\n\t@@                                                         @@");
  printf("\n\t@@                    1 - JOGAR                            @@");
  printf("\n\t@@                    2 - CONFIGURAÇÕES DE JOGO            @@");
  printf("\n\t@@                    3 - HISTÓRICO DE JOGO                @@");
  printf("\n\t@@                    4 - SAIR                             @@");
  printf("\n\t@@                                                         @@");
  printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  printf("\n");
  scanf("%i",&opcao);

  if (opcao == 2)
  {

    conf = 0;

    while (conf != 4)
    {

      system("clear");
      printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@                 CONFIGURAÇÕES DE JOGO                   @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@            1 - ALTERAR TAMANHO DA MATRIZ DE JOGO        @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@            2 - ALTERAR TAMANHO FINAL DA SKAKE           @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@            3 - ALTERAR VELOCIDADE DA SNAKE              @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@            4 - VOLTAR                                   @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@                                                         @@");
      printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
      printf("\n");
      scanf("%i",&conf);

      if (conf == 1) 
      {

        system("clear");
        printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                 CONFIGURAÇÕES DE JOGO                   @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@            1 - PEQUENO (3O X 7)                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@            2 - MÉDIO (60 x 15)                          @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@            3 - GRANDE (100 X 30)                        @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n");
        scanf("%i",&matriz);

        if (matriz == 1)
        {
          tam[0] = 30;  //COLUNAS AO TOTAL
          tam[1] = 7;   //LINHAS AO TOTAL
          tam[2] = 29;  //COLUNAS INTERNAS
          tam[3] = 6;   //LINHAS INTERNAS
          tam[4] = 28;  //FRUTAS DENTRO DO MAPA
          tam[5] = 5;   //FRUTAS DENTRO DO MAPA
          }

        else if (matriz == 2)
        {
          tam[0] = 60;
          tam[1] = 15;
          tam[2] = 59;
          tam[3] = 14;
          tam[4] = 58;
          tam[5] = 13;
        }

        else if (matriz == 3)
        {
          tam[0] = 100;
          tam[1] = 30;
          tam[2] = 99;
          tam[3] = 29;
          tam[4] = 98;
          tam[5] = 28;
        }
      } 

      else if (conf == 2) 
      {
        system("clear");
        printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                 CONFIGURAÇÕES DE JOGO                   @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@        DIGITE O TAMANHO FINAL DA SNAKE (10 - 300)       @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n");
        scanf("%i",&tf);
      }

      else if (conf == 3) 
      {
        system("clear");
        printf("\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                 CONFIGURAÇÕES DE JOGO                   @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                     1 - LENTO                           @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                     2 - NORMAL                          @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                     3 - RÁPIDO                          @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@                                                         @@");
        printf("\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n");
        scanf("%i",&velo);

        if (velo == 1)
        {
          speed = 250000;
        }

        else if (velo == 2)
        {
          speed = 150000;
        }

        else if (velo == 3)
        {
          speed = 50000;
        }
      }
    }  
  } 

  else if (opcao == 3)
  {

    system("clear");
    printf("\n\n\t\tHISTÓRICO DE JOGOS\n\n");

    while(fread(&ficha,sizeof(CADASTRO), 1, arq)) {
      printf("\tNome: %s \n\tPontuação: %i\n\n",ficha.nome,ficha.pontuacao);
    }

    printf("\n\tPRESSIONE ENTER PARA VOLTAR.");
    __fpurge(stdin);
    getchar();
  }

  else if (opcao == 4)
  {
    sair = 4;
  }
}  

void TelaDeJogo() {

  //QUADRO DE JOGO

  for (linha = 0; linha < tam[1]; linha++)
  {
    mapa[linha][0] = '@';
    mapa[linha][tam[2]] = '@';
  }

  for (coluna = 1; coluna < tam[0]; coluna++)
  {
    mapa[0][coluna] = '@';
    mapa[tam[3]][coluna] = '@';
  }

  for (linha = 1; linha < tam[3]; linha++)
  {
    for (coluna = 1; coluna < tam[2]; coluna++)
    {
      mapa[linha][coluna] = ' ';
    }
  }
}

void Jogo() {

  srand(time(NULL));

  //POSIÇÃO INICIAL

  posx[0] = posy[0] = 2;      

  //TAMANHO INICIAL

  cont = 1;

  //VARIÁVEL DAS FRUTAS

  f = 0;

  //VARIÁVEL DE INÍCIO DE JOGO

  final = 1;

  while (final != 0)
  {
    //IMPRESSÃO DO QUADRO DE JOGO

    system("clear");

    for (linha = 0; linha < tam[1]; linha++)
    {
      printf("\n\t@");

      for (coluna = 0; coluna < tam[0]; coluna++)
      {
        if (linha == posx[0] && coluna == posy[0])
        {
          mapa[linha][coluna] = 'O';
          printf("%c",mapa[linha][coluna]);
        }

        else
        {
          printf("%c",mapa[linha][coluna]);
        }
      }

      printf("@");
    }

    //MOVIMENTO DA SNAKE DENTRO DO QUADRO DE JOGO

    /* SEMPRE QUE MINHA LINHA = POSX[0] E MINHA COLUNA = POSY[0] MEU MAPA[LINHA][COLUNA] VAI SER
    IGUAL A 'O', QUANDO NO LAÇO DE REPETIÇÃO ELE IRÁ FAZER UMA SEQUÊNCIA DE 'O'. PORÉM AÍ ENTRA MINHA
    POSX[CONT]/POSY[CONT] QUE SERÁ A POSIÇÃO QUE IRÁ APAGAR A SEQUÊNCIA DE 'O' CONFORME A SNAKE ANDAR.*/

    /*EX CONT = 4 ENTAO MEU POSX[CONT]/POSY[CONT] VAI SER IGUAL A POSX[3]/POSY[3], MINHA POSX[3]/POSY[3]
    VAI SER IGUAL A POSX[2]/POSY[2]... ASSIM ATÉ POSX[1]/POSY[1] SER IGUAL A POSX[0]/POSY[0] */

    if (kbhit()) 
    {
      jogada = getch();

      for (i = cont; i > 0; i--)
      {  
        posx[i]=posx[i-1];
        posy[i]=posy[i-1];
      }

      mapa[posx[cont]][posy[cont]] = ' ';

      switch (jogada)
      {
        case 'w': 
        posx[0]--;
        break;

        case 's': 
        posx[0]++;
        break;

        case 'd': 
        posy[0]++;
        break;

        case 'a': 
        posy[0]--;
        break;

        case 'o': 
        final = 0;
        break;
      }
    }

    else {

      for (i = cont; i > 0; i--)
      {   
        posx[i]=posx[i-1];
        posy[i]=posy[i-1];
      }

      mapa[posx[cont]][posy[cont]] = ' ';

      switch (jogada)
      {
        case 'w': 
        posx[0]--;
        break;

        case 's': 
        posx[0]++;
        break;

        case 'd': 
        posy[0]++;
        break;

        case 'a': 
        posy[0]--;
        break;
      }
    } 

    //CONDIÇÕES DO JOGO

    //SNAKE VS PAREDE

    if (posx[0] == 0|| posx[0] == tam[3])
    {
      final = 0;

      printf("\n\n\tGAME OVER!!!");
      __fpurge(stdin);
      printf("\n\n\tDIGITE O NOME DO JOGADOR: ");
      gets(ficha.nome);
      ficha.pontuacao = cont;
      fwrite(&ficha, sizeof(CADASTRO), 1,arq);
      fclose(arq);
    }

    if (posy[0] == 0|| posy[0] == tam[2])
    {
      final = 0;

      printf("\n\n\tGAME OVER!!!");
      __fpurge(stdin);
      printf("\n\n\tDIGITE O NOME DO JOGADOR: ");
      gets(ficha.nome);
      ficha.pontuacao = cont;
      fwrite(&ficha, sizeof(CADASTRO), 1, arq);
      fclose(arq);
    }

    //SNAKE VS ELA MESMA

    for (i = 1; i < cont; i++)
    {
      if (posx[0] == posx[i] && posy[0] == posy[i])
      {
        final = 0;

        printf("\n\n\tGAME OVER!!!");
        __fpurge(stdin);
        printf("\n\n\tDIGITE O NOME DO JOGADOR: ");
        gets(ficha.nome);
        ficha.pontuacao = cont;
        fwrite(&ficha, sizeof(CADASTRO), 1,arq);
        fclose(arq);
      }
    }

    //POTUAÇÃO FINAL *OBS: PODE SER ALTERADA NAS CONFIGURAÇÕES 

    if (cont == tf)
    {
        final = 0;

        printf("\n\n\tPARABÉNS!!! VOCÊ GANHOU!!!");
        __fpurge(stdin);
        printf("\n\n\tDIGITE O NOME DO JOGADOR: ");
        gets(ficha.nome);
        ficha.pontuacao = cont;
        fwrite(&ficha, sizeof(CADASTRO), 1,arq);
        fclose(arq);
    }

    //LOCALIZAÇÃO DAS FRUTAS

    if (f == 0)
    { 
      fx = (1 + (rand()%tam[4]));
      fy = (1 + (rand()%tam[5]));

      f = 1;
    } 

    for (linha = 1; linha < tam[3]; linha++)
    {
      for (coluna = 1; coluna < tam[2]; coluna++)
      {
        if (linha == fy && coluna == fx)
        {
          mapa[linha][coluna] = '6';
        }
      }
    }

    if (posx[0] == fy && posy[0] == fx)
    {
      cont = cont + 1;
      f = 0;
    }

    //PONTUAÇÃO EM TEMPO REAL 

    if (final != 0)
    {
      printf("\n\n\tPONTUAÇÃO: %i\tOBJETIVO: %i\t O = FRUTAS",cont,tf);
    }

    //VELOCIDADE 

    usleep(speed);
  }
}

int main() {


  Conf();

  while (sair != 4)
  { 
    Menu();

    if(opcao == 1)
    {
      TelaDeJogo();
      Jogo();
    }
  }

  printf("\n\n");
  return 0;
}

//CÓDIGO FONTE DE FUNÇÕES UTILIZADAS NO CÓDIGO

int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}

int kbhit(void) {

  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
} 
