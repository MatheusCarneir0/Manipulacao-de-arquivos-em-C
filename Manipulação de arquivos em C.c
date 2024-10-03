#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro {
    int id;
    char nome[50];
    float salario;
};

void adicionarRegistro(const char *nomeArquivo) {// Adicionar registros ao arquivo
    FILE *arquivo = fopen(nomeArquivo, "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    struct Registro novoRegistro;

    printf("Digite o ID: ");
    scanf("%d", &novoRegistro.id);
    printf("Digite o nome: ");
    scanf("%s", novoRegistro.nome);
    printf("Digite o salário: ");
    scanf("%f", &novoRegistro.salario);

    fwrite(&novoRegistro, sizeof(struct Registro), 1, arquivo);
    fclose(arquivo);

    printf("Registro adicionado com sucesso!\n");
}


void lerRegistros(const char *nomeArquivo) { // Ler e exibir os registros armazenados no arquivo
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    struct Registro registro;

    printf("\n**********************\n");
    printf("Registros armazenados:\n");
    printf("**********************\n");
    
    while (fread(&registro, sizeof(struct Registro), 1, arquivo)) {
        printf("ID: %d\n", registro.id);
        printf("Nome: %s\n", registro.nome);
        printf("Salário: %.2f\n", registro.salario);
        printf("------------------------\n");
    }

    fclose(arquivo);
}

int main() {
    int escolha;
    const char *nomeArquivo = "registros.dat";

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar novo registro\n");
        printf("2. Visualizar registros\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarRegistro(nomeArquivo);
                break;
            case 2:
                lerRegistros(nomeArquivo);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}
