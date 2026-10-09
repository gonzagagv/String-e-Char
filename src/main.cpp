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

  Serial.print("Tamanho da Variavel em bytes: ");
  Serial.println(tamanhoVariavel);

  Serial.print("Tamanho do Ponteiro: ");
  Serial.println(tamanhoPonteiro);
}

void textoTipoString()
{
}
