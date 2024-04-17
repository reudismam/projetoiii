#ifndef H_ESTUDANTE
#define H_ESTUDANTE

typedef struct estudante Estudante;
typedef struct lista Lista;
typedef struct no No;

void adicionaFim(Lista *lista, Estudante e);

void mostrar(Lista lista);

void editarMedia(Lista* lista, int mat, float media);

void deletar(Lista *lista, int mat);

void ler(Estudante *e);

void cadastrar();

void buscar (int mat);

void listar();

int tamanho();

void lerLista(Lista *lista);

void salvaLista(Lista *lista);

void excluir(int mat);

void editar(int mat);

#endif