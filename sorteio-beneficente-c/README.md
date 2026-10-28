# Sorteio Beneficente em C

Projeto de iniciante em linguagem C para praticar vetores, funções, estruturas de repetição, condicionais e ordenação.

## O que o programa faz

- Lê 12 números inteiros e mostra os valores informados.
- Conta as ocorrências de cada número distinto.
- Quando a quantidade de ocorrências é ímpar, cadastra exatamente essa quantidade de produtos, informando nome e preço unitário.
- Quando a quantidade de ocorrências é par, armazena o número uma única vez em um segundo vetor.
- Apresenta os produtos em ordem alfabética pelo nome.
- Apresenta os números com ocorrência par em ordem decrescente.

## Tecnologias e conceitos

- Linguagem C
- Vetores
- Funções
- Laços `for`
- Condicionais `if` e `else`
- Ordenação pelo método da bolha
- Biblioteca `string.h` para comparar e copiar nomes

## Como compilar

Com o GCC instalado, abra o terminal dentro da pasta do projeto e execute:

```bash
gcc main.c -o sorteio
```

## Como executar

No macOS ou Linux:

```bash
./sorteio
```

## Observação

A quantidade de produtos cadastrados para cada número com ocorrência ímpar corresponde à quantidade de vezes que esse número apareceu no vetor. O cadastro não depende do valor do número digitado.
