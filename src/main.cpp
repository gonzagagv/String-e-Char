#include <Arduino.h>
#include <string.h> //strlen, strcpy, strcat,strcpm
#include <stdlib.h>

void textoTipoString();
void textoTipoC();
void setup()
{
  Serial.begin(9600);
  Serial.println();
  textoTipoString();
  textoTipoC();
}

void loop()
{
}

void textoTipoC()
{
  //* Texto Literal
  //* Use const char * quando o texto nao sera alterado
  const char *cidade = "Sao Paulo";
  const char outraCidade[] = "Sao Caetano";
  Serial.println(cidade);
  Serial.println(outraCidade);

  //* Descobrindo o tamanho do texto
  //* strlen conta quantas caracteres antes do \0
  int tamanhoCidade = strlen(cidade);
  int tamanhoOutraCidade = strlen(outraCidade);

  Serial.println("Comprimento do texto em caracteres: ");
  Serial.println(tamanhoOutraCidade);

  Serial.print("Tamanho do conteudo do ponteiro: ");
  Serial.println(tamanhoCidade);

  //* Descobrindo o tamanho ocupado
  int tamanhoVariavel = sizeof(outraCidade);
  int tamanhoPonteiro = sizeof(cidade);

  //* Quando usando o sizeof em uma string sempre retornara
  //* um byte a mais do que a quantidade de caracteres
  //* causa do '\0' que finaliza o texto
  Serial.print("Tamanho da Variavel em bytes: ");
  Serial.println(tamanhoVariavel);

  //* Quando usando o sizeof em ponteiros retorna sempre bytes
  //* pois o conteudo dele e um endereco de memoria como 0xFF00C246
  Serial.print("Tamanho do Ponteiro: ");
  Serial.println(tamanhoPonteiro);

  //* O caractere '\0' e colocado automaticamente quando escrevemos
  //* um texto entre aspas duplas "  "
  const char vetorTexto[6] = {'C', 'A', 'R', 'L', 'O', 'S'};
  Serial.println(vetorTexto);

  //* Comparar texto
  const char *cidadeI = "Porto Alegre";
  const char *cidadeII = "Porto Alegre";

  if (strcmp(cidadeI, cidadeII) == 0)

    Serial.println("As strings sao iguais");

  else
    Serial.println("As strings sao diferentes");

  //* strcmp analize a ordem lexica das palavras, se a primeira palavra vem antes
  //* que a segunda o valor retornado sera menor que zero, se a primeira vem apos
  //* a segunda o retorno sera maior q zero

  //*==============================
  //*TEXTO EDITAVEL
  //*==============================

  char nomeAluno[7] = "Carlos";

  nomeAluno[5] = 'o';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! Cuidado o vetor precisa ter espaco o suficiente

  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  //* Concatenando texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo Cruel!");
  Serial.println(frase);

  //* procurando um caractere no texto
  char *posicaoLetra = strchr(frase, 'M');

  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.println(posicaoLetra);
  }
  else
    Serial.println("Letra nao encontrada");

  //* Convertendo texto numerico para inteiro 
  char idadeTexto[] = "39"; //* [0x33, 0x57, 0x00]
  int idadeTexto = atoi(idadeTexto);
  
  //* Montando Texto
  char buffer[100];
  char* local = "Sala de aula";
  float temperatura = 26.4;
  int unidade = 72;

  //*Ela joga o texto para o buffer 
  snprintf(buffer, sizeof(buffer), "%s | Temp: %f C | Unid: %d %% \n\r", local, temperatura, unidade);

  Serial.print(buffer);

  //*snprintf monta o texto dentro de um vetor de char
  //* Isso e muito util quando depois voce quer:
  //* -enviar por MOTT
  //* -salvar em variavel
  //* -mandar para o diplay
  //* -imprimir na Serial

  //*ESPECIFICADOES
  //*  %d ou %1    -init
  //* %u           -unsigned int
  //* %ld       -long 
  //* %lu      -unsigned long 
  //* %f     -float
  //* %e     -notacao cientifica 
  //* %g     -float, formato mais curto 
  //* %c    -char 
  //* %s    -char*
  //* %x ou %X     -hexadecimal minuscolo/maiusculo
  //* %o     -octal
  //* %p     -ponteiro 
  //* %%     -o proprio

  //* Flags, largurae precisao

  //* %5d    -imprime com largura minima de 5, alinhado a direita
  //* %-2d   -imprime com largura minima de 2, alinhado a esquerda
  //* %04d   -completa com zeros ex: 0022
  //* %+d    -sempre mostra o sinal ex: +5
  //* %.2f   -2 casas decimais 
  //* %4.2f  -largura de 4 com 2 casas 
  //* %02x   -hexadecimalccom 2 digitos
  //* %#x    -prefixo 0x
  //* %.3s   -so os primeiros 3 caracteres de string
 //*     %*d         - largura passada como argumento ex. snprintf(buffer, sizeof(buffer), "%*d", 5, 42 [   42]
}

void textoTipoString()
{
}
