#include<stdio.h>
#include "estudante.h"

void menu() {
    printf("Escolha uma opcao:\n");
    printf("1 - cadastar aluno\n");
    printf("2 - listar alunos\n");
    printf("3 - buscar aluno\n");
    printf("4 - quantidade de alunos\n");
    printf("5 - excluir um aluno\n");
    printf("6 - editar um aluno\n");
    printf("0 - sair\n");
    printf("===================\n");
}

int main() {
    int op;
    menu();
    scanf("%d", &op);
    while (op != 0) {
        if (op == 1) {
           cadastrar();
        } else if (op == 2) {
            listar();
        } else if (op == 3) {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            buscar(mat);
        } else if (op == 4) {
            int n = tamanho();
            printf("Quantidade alunos: %d\n", n);
        } else if (op == 5) {
            int mat;
            printf("Informe a matricula para exclusao:\n");
            scanf("%d", &mat);
            excluir(mat);
        } else if (op == 6) {
            int mat;
            printf("Informe a matricula do aluno para edicao:\n");
            scanf("%d", &mat);
            editar(mat);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}