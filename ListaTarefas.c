#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaTarefas.h"

void iniciMenorTemp(menorTempo *m){
  m->menorTemp = -1;
}

void criarLista(sentinela *s) { // <---- Inicializador
  s->head = NULL;
  s->tail = NULL;
}


void inserirElemento(sentinela *s, int sid, char t[], int temp, menorTempo *m) {
  listaTarefa *aux2, *novo = malloc(sizeof(listaTarefa));
  if (!novo) {
      printf("Erro de alocação de memória.\n");
      return;
  }

  aux2 = s->head;

  while (aux2 != NULL) {
      if (aux2->id == sid) {
          printf("ID já existente\n");
          free(novo);
          return;
      }
      aux2 = aux2->next;
  }

  novo->id = sid;
  strcpy(novo->tarefa, t);
  strcpy(novo->ativa, "Ativa");
  novo->tempConclusao = temp;
  novo->next = NULL;
  novo->prev = NULL;

  if (s->head == NULL) {
      s->head = novo;
      s->tail = novo;
      m->menorTemp = novo->tempConclusao;
  } else {
      if (novo->tempConclusao < m->menorTemp) {
          novo->next = s->head;
          s->head->prev = novo;
          s->head = novo;
          m->menorTemp = novo->tempConclusao;
      } else {
          s->tail->next = novo;
          novo->prev = s->tail;
          s->tail = novo;
      }
  }
}

void inserirElemento2(sentinela *s, int sid, char t[], int temp, menorTempo *m) {
  listaTarefa *aux2, *novo = malloc(sizeof(listaTarefa));
  if (!novo) {
      printf("Erro de alocação de memória.\n");
      return;
  }

  aux2 = s->head;

  while (aux2 != NULL) {
      if (aux2->id == sid) {
          printf("ID já existente\n");
          free(novo);
          return;
      }
      aux2 = aux2->next;
  }

  novo->id = sid;
  strcpy(novo->tarefa, t);
  strcpy(novo->ativa, "Concluida");
  novo->tempConclusao = temp;
  novo->next = NULL;
  novo->prev = NULL;

  if (s->head == NULL) {
      s->head = novo;
      s->tail = novo;
      m->menorTemp = novo->tempConclusao;
  } else {
      if (novo->tempConclusao < m->menorTemp) {
          novo->next = s->head;
          s->head->prev = novo;
          s->head = novo;
          m->menorTemp = novo->tempConclusao;
      } else {
          s->tail->next = novo;
          novo->prev = s->tail;
          s->tail = novo;
      }
  }
}

void concluirTarefa(sentinela *s1, sentinela *s2, int sid, menorTempo *Menor2){
  listaTarefa *aux = s1->head;

  while (aux != NULL) {
      if (aux->id == sid) {


          if (aux == s1->head && aux == s1->tail) {
              s1->head = NULL;
              s1->tail = NULL;
          } else if (aux == s1->head) {
              s1->head = aux->next;
              s1->head->prev = NULL;
          } else if (aux == s1->tail) {
              s1->tail = aux->prev;
              s1->tail->next = NULL;
          } else {
              aux->prev->next = aux->next;
              aux->next->prev = aux->prev;
          }


          inserirElemento2(s2, aux->id, aux->tarefa, aux->tempConclusao, Menor2);

          free(aux);
          printf("A tarefa com ID %d foi concluída com sucesso!\n", sid);
          return;
      }
      aux = aux->next;
  }
  printf("Tarefa com ID %d não encontrada.\n", sid);
}

void removeTarefa(sentinela *s, int sid) {
  listaTarefa *aux = s->head;

  while (aux != NULL) {
      if (aux->id == sid) {
          if (aux == s->head && aux == s->tail) {
              s->head = NULL;
              s->tail = NULL;
          } else if (aux == s->head) {
              s->head = aux->next;
              s->head->prev = NULL;
          } else if (aux == s->tail) {
              s->tail = aux->prev;
              s->tail->next = NULL;
          } else {
              aux->prev->next = aux->next;
              aux->next->prev = aux->prev;
          }
          free(aux);
          printf("A tarefa com ID %d foi removida com sucesso!\n", sid);
          return;
      }
      aux = aux->next;
  }
  printf("Tarefa com ID %d não encontrada.\n", sid);
}

void imprimiLT(sentinela s) {
  listaTarefa *aux = s.head;
  printf("\nLISTA DE TAREFAS\n\n");
  while (aux) {
      printf("ID: %d\nDescrição: %s\nSituação: %s\nTempo limite: %d horas\n",
             aux->id, aux->tarefa, aux->ativa, aux->tempConclusao);
      aux = aux->next;
      printf("---------------------------\n");
  }
}

int lerInteiro(int *valor) {   // Função para verificar se é inteiro
  char buffer[100];
  char *endptr;
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      size_t len = strlen(buffer);
      if (len > 0 && buffer[len - 1] == '\n') {
          buffer[len - 1] = '\0';
      }
      *valor = strtol(buffer, &endptr, 10);
      if (endptr == buffer || *endptr != '\0') {
          return 0; 
      }
      return 1; 
  }
  return 0;
}

void limparTela() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}
