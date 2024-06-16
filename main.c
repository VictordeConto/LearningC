//----------------------------------------------------------------------------------------
// UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - CAMPUS CHAPECÓ
// TRABALHO FINAL ESTRUTURA DE DADOS: LISTA DE TAREFAS EM C
// PROFESSOR: DENIO DUARTE
// ESTUDANTES: VICTOR NEYMAR DE CONTO (20230004269) E RAIEL VITOR BABINSKI (20230003539)
//----------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "ListaTarefas.h"


int main() {
    sentinela listaAtiva;
    sentinela listaConcluida;
    menorTempo Menor;
    menorTempo Menor2;
    int opcao;
    int idTarefa;
    char nomeTarefa[20];
    int tempTarefa;

    iniciMenorTemp(&Menor);
    iniciMenorTemp(&Menor2);
    criarLista(&listaAtiva); // Lista das tarefas que estão ativas
    criarLista(&listaConcluida); // Lista das tarefas que foram concluídas

    do {
        printf("\nMenu de opções:\n\n0- Sair do menu\n1- Adicionar nova tarefa\n2- Concluir tarefa\n3- Excluir tarefa\n4- Visualizar tarefas\n5- Limpar Terminal\n");
        if (!lerInteiro(&opcao)) {
            printf("Opção inválida. Por favor, digite um número inteiro.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite um ID para a tarefa:\n");
                if (!lerInteiro(&idTarefa)) {
                    printf("ID inválido. Por favor, digite um número inteiro.\n");
                    break;
                }

                printf("Digite a descrição da tarefa:\n");
                fgets(nomeTarefa, sizeof(nomeTarefa), stdin);
                size_t len = strlen(nomeTarefa);
                if (len > 0 && nomeTarefa[len - 1] == '\n') {
                    nomeTarefa[len - 1] = '\0';
                }

                printf("Digite o tempo para conclusão da tarefa:\n");
                if (!lerInteiro(&tempTarefa)) {
                    printf("Tempo para conclusão inválido. Por favor, digite um número inteiro.\n");
                    break;
                }

                inserirElemento(&listaAtiva, idTarefa, nomeTarefa, tempTarefa, &Menor);
                printf("A tarefa %s foi adicionada com sucesso!\n", nomeTarefa);
                break;
            case 2:
                printf("Digite o ID da tarefa a ser concluída:\n");
                if (!lerInteiro(&idTarefa)) {
                    printf("ID inválido. Por favor, digite um número inteiro.\n");
                    break;
                }
                concluirTarefa(&listaAtiva, &listaConcluida, idTarefa, &Menor2);
                break;
            case 3:
                printf("Digite o ID da tarefa a ser removida:\n");
                if (!lerInteiro(&idTarefa)) {
                    printf("ID inválido. Por favor, digite um número inteiro.\n");
                    break;
                }
                removeTarefa(&listaAtiva, idTarefa);
                removeTarefa(&listaConcluida, idTarefa);
                break;
            case 4:
                printf("\nOpções de visualização:\n\n0- Voltar ao menu principal\n1- Visualizar tarefas ativas\n2- Visualizar tarefas concluídas\n3- Visualizar todas as tarefas\n");
                int opcao2;
                if (!lerInteiro(&opcao2)){
                  printf("Opção inválida. Por favor, digite um número inteiro.\n");
                  break;
                }
                switch (opcao2) {
                    case 1:
                         printf("\nTAREFAS ATIVAS:\n");
                        if(listaAtiva.head == NULL){
                            printf("\nNenhuma tarefa ativa.\n");
                        }
                        else{
                        imprimiLT(listaAtiva);}
                        break;
                    case 2:
                        printf("\nTAREFAS CONCLUÍDAS:\n");
                        if(listaConcluida.head == NULL){
                            printf("\nNenhuma tarefa concluída.\n");
                        }
                        else{
                        imprimiLT(listaConcluida);}
                        break;
                    case 3:
                        printf("\nTAREFAS ATIVAS:\n");
                        imprimiLT(listaAtiva);
                        printf("\nTAREFAS CONCLUÍDAS:\n");
                        imprimiLT(listaConcluida);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opção Inválida\n");
                }
                break;
            case 5:
                limparTela();
                break;
            default:
                if (opcao != 0) {
                    printf("Opção Inválida\n");
                }
        }
    } while (opcao != 0);

    return 0;
}
