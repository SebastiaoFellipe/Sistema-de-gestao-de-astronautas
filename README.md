# Sistema-de-gestão-de-astronautas

Este projeto foi desenvolvido como parte da disciplina Linguagem de Programação I do curso de Bacharelado em Tecnologia da Informação da UFRN. O objetivo do projeto é aplicar conceitos de programação em C++ aprendidos durante a disciplina.

## Requisitos
Para compilar e executar este projeto, você precisa do compilador g++. Você pode instalá-lo através do seu gerenciador de pacotes.

### Linux
```bash
sudo apt-get update
sudo apt-get install g++
```

### macOS
Você pode instalar o Xcode Command Line Tools, que inclui o g++:

```bash
xcode-select --install
```

### Windows
No Windows, você pode instalar o MinGW para obter o g++:

1. Baixe o MinGW.
2. Siga as instruções de instalação e selecione o pacote g++.

Certifique-se de que o g++ está disponível no PATH do sistema.

## Clonando o Repositório
Primeiro, clone o repositório para sua máquina local:

```bash
git clone https://github.com/SebastiaoFellipe/Sistema-de-gestao-de-astronautas.git
cd Sistema-de-gestao-de-astronautas
```

## Compilação
Para compilar o projeto, você pode usar o Makefile incluído no repositório. Execute o seguinte comando na raiz do projeto para gerar o executável:

```bash
make
```

## Execução
Depois de compilar o projeto, você pode rodar o executável gerado com o seguinte comando:

```bash
./saida
```

## Limpeza
Para limpar os arquivos gerados pela compilação, você pode usar o comando:

```bash
make clean
```