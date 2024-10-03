# 📄 Programa de Manipulação de Arquivos e Structs em C

Este programa permite realizar operações de **leitura** e **escrita** em arquivos utilizando `structs` para representar registros de dados. Você pode adicionar novos registros a um arquivo ou visualizar os registros já armazenados.

## 🚀 Funcionalidades

- 📝 **Adicionar novos registros**: O programa solicita ao usuário que informe o ID, nome e salário, e armazena esses dados em um arquivo binário.
- 📖 **Visualizar registros existentes**: O programa lê e exibe todos os registros armazenados no arquivo.

## 📂 Estrutura do Registro

Cada registro é representado por uma `struct` com os seguintes campos:

```c
struct Registro {
    int id;
    char nome[50];
    float salario;
};
```
📚 Exemplo de Uso
bash
Copiar código
Menu:
1. Adicionar novo registro
2. Visualizar registros
3. Sair
Escolha uma opção: 1

Digite o ID: 101
Digite o nome: João
Digite o salário: 2500.50

Registro adicionado com sucesso!
