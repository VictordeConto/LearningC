#ifndef LISTATAREFAS_H_INCLUDED
#define LISTATAREFAS_H_INCLUDED

typedef struct noLista { // <---- Estrutura que armazena as informações de cada tarefa
    int id;
    char tarefa[20];
    char ativa[20];
    int tempConclusao;
    struct noLista *next;
    struct noLista *prev;
} listaTarefa;

typedef struct sent {  // <---- Estrutura que armazena cada lista de tarefas
    listaTarefa *head;
    listaTarefa *tail;
} sentinela;

typedef struct MenorValor{
    int menorTemp;
}menorTempo;

void iniciMenorTemp(menorTempo *m);

void criarLista(sentinela *s);

void inserirElemento(sentinela *s, int sid, char t[], int temp, menorTempo *m);

void inserirElemento2(sentinela *s, int sid, char t[], int temp, menorTempo *m);

void concluirTarefa(sentinela *s1, sentinela *s2, int sid, menorTempo *Menor2);

void removeTarefa(sentinela *s, int sid);

void imprimiLT(sentinela s);

int lerInteiro(int *valor);

void limparTela();


#endif // LISTATAREFAS_H_INCLUDED