#include <stdio.h>
#include <stdlib.h>
#include "estudante.h"

struct estudante {
    int mat;
    char nome[50];
    float media;
};

struct no {
    Estudante dado;
    struct no* prox;
};

struct lista{
    No* inicio;
};

void adicionaFim(Lista *lista, Estudante e) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = e;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    }
    else {
        No* pi;
        for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void mostrar(Lista lista) {
    No* pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        Estudante dado = pi->dado;
        printf("%d %s %f\n", dado.mat, dado.nome, dado.media);
    }
}

void editarMedia(Lista* lista, int mat, float media) {
  if (lista->inicio == NULL) {
    printf("Lista vazia\n");
  }
  else {
    No* pi;
    for (pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    if (pi == NULL) {
      printf("Aluno nao encontrado\n");
    }
    else {
      pi->dado.media = media;
    }
  }  
}

void deletar(Lista *lista, int mat) {
  if (lista->inicio == NULL) {
    printf("Lista vazia\n");
  }
  else {
      No* pa = NULL;
      No* pi;
      for (pi = lista->inicio; pi->prox != NULL && pi->dado.mat != mat; pi = pi->prox) {
        pa = pi;
      }
      if (pa == NULL) {
        if (pi->dado.mat == mat) {
          lista->inicio = pi->prox;
          free(pi);
        }
        else {
          printf("Elemento nao encontrado\n");
        }
      }
      else {
        if (pi->dado.mat == mat) {
          pa->prox = pi->prox;
          free(pi);
        }
        else {
          printf("Elemento nao encontrado\n");
        }
      }
  }
}


void ler(Estudante *e) {
    printf("Informe os dados do estudante:\n");
    scanf("%d %s %f", &e->mat, e->nome, &e->media);
}

void cadastrar() {
    FILE* file = fopen("aluno.b", "ab");
    Estudante a;
    printf("Informe os dados do aluno:\n");
    scanf("%d %s %f", &a.mat, a.nome, &a.media);
    fwrite(&a, sizeof(Estudante), 1, file);
    fclose(file);
}

void buscar (int mat) {
    FILE* file = fopen("aluno.b", "rb");
    Estudante a;
    int entrou = 0;
    while (fread(&a, sizeof(Estudante), 1, file)) {
        if (a.mat == mat) {
            printf("%d: %s %f\n", a.mat, a.nome, a.media);
            entrou = 1;
        }
    }
    if (entrou == 0) {
        printf("Aluno nao encontrado\n");
    }
    fclose(file);
}

void listar() {
    FILE* file = fopen("aluno.b", "rb");
    Estudante a;
    while (fread(&a, sizeof(Estudante), 1, file)) {
        printf("%d: %s %.2f\n", a.mat, a.nome, a.media);
    }
    fclose(file);
}

int tamanho() {
    FILE* file = fopen("aluno.b", "rb");
    Estudante a;
    int cont = 0;
    while (fread(&a, sizeof(Estudante), 1, file)) {
        cont++;
    }
    fclose(file);
    return cont;
}

void lerLista(Lista *lista) {
  FILE *file = fopen("aluno.b", "rb");
  Estudante e;
  while (fread(&e, sizeof(Estudante), 1, file)) {
      adicionaFim(lista, e);
  }
  fclose(file);
}

void salvaLista(Lista *lista) {
  FILE *file = fopen("aluno.b", "wb");
  No* pi;
  for (pi = lista->inicio; pi != NULL; pi = pi->prox) {
    fwrite(&pi->dado, sizeof(Estudante), 1, file);
  }
  fclose(file);
}

void excluir(int mat) {
    Lista lista;
    lista.inicio = NULL;
    lerLista(&lista);
    deletar(&lista, mat);
    salvaLista(&lista);
}

void editar(int mat) {
    Lista lista;
    lista.inicio = NULL;
    lerLista(&lista);
    float media;
    printf("Informe a nota nota:\n");
    scanf("%f", &media);
    editarMedia(&lista, mat, media);
    salvaLista(&lista);
}