#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "funcionarios.bin"
#include "GestaoDosFuncionarios.h"

void carregarVetor(vetor *x,int MAX_FUNCIONARIOS) {
    int i;

    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        printf("Erro a carregar Vetor !!!");
    } else{
        fwrite(&x->contador, sizeof (int), 1, fp);
        for(i=0; i<MAX_FUNCIONARIOS; i++){
            fwrite(&x->funcionarios[i], sizeof (funcionario), 1, fp);
            i++;
        }
    }
    fclose(fp);
}

void carregarFicheiro(funcionario *x,int MAX_FUNCIONARIOS,int c) {
    int i;
   
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("Erro a carregar Ficheiro !!!");
    } else{
        funcionario *tmp;
    
        tmp=x;
        fread(&c, sizeof (int), 1, fp);
        for(i=0; i<MAX_FUNCIONARIOS; i++){
            fread(&tmp, sizeof (funcionario), 1, fp);
            i++;
            tmp=x+i; 
        }
    }
    fclose(fp);
}

void lerdata(data*x){
    printf("\ndia: ");
    scanf("%d",&x->dia);
    printf("mes: ");
    scanf("%d",&x->mes);
    printf("ano: ");
    scanf("%d",&x->ano);
}

void imprimedata(data x){
    printf("%d-%d-%d", x.dia, x.mes, x.ano);
}

void imprimirFuncionario(funcionario x) {
    printf("Código: %d\n", x.codigo);
    printf("Nome: %s\n", x.nome);
    printf("Número de Telefone: %d\n", x.telefone);
    if(x.estado==1){
        printf("Estado Civil: Solteiro\n");
    }else if(x.estado==2){
        printf("Estado Civil: Casado\n");
    }else if(x.estado==3){
        printf("Estado Civil: Viúvo\n");
    }else if(x.estado==4){
        printf("Estado Civil: Divorsiado\n");
    }
    printf("Número de filhos: %d\n", x.filhos);
    if(x.cargo==1){
        printf("Cargo na empresa: Empregado\n");
    }else if(x.cargo==2){
        printf("Cargo na empresa: Chefe\n");
    }else if(x.cargo==3){
        printf("Cargo na empresa: Administrador\n");
    }
    printf("Ganho por hora: %d€\n", x.salariohora);
    printf("Subsídio de alimentação: %d€\n", x.alimentacao);
    printf("Data de Nascimento: ");
    imprimedata(x.nascimento);
    printf("\n");
    printf("Data de entrada na empresa: ");
    imprimedata(x.entrada);
    printf("\n");
    if (x.ativo==2){
        printf("Data de saida da empresa: ");
        imprimedata(x.saida);
        printf("\n");
        printf("Trabalhador inativo");
    } else{
        printf("Trabalhador ativo");
    }
    printf("\n");
    printf("\n");
}

int procurarFuncionario(vetor *x, int numero) {
    int i;
    for (i = 0; i < x->contador; i++) {
        if (x->funcionarios[i].codigo == numero) {
            return i;
        }
    }
    return -1;
}

void editarEstadoFuncionario(vetor *x) {
    int cod,num=-1;
    
    do{
        printf("Insira um código de funcionário existente: ");
        scanf("%d",&cod);
        num=procurarFuncionario(x,cod);
    }while (num==-1);
    
    if (x->funcionarios[num].ativo==1){
        x->funcionarios[num].ativo=2;
        printf("Data de saida da empresa: ");
        lerdata(&x->funcionarios[num].saida);
        printf("Trabalhador inativo");
        printf("\n");
    }else{
        x->funcionarios[num].ativo=1;
        printf("Trabalhador Ativo");
        printf("\n");
    }
}

void inserirFuncionarios(vetor *x,int *MAX_FUNCIONARIOS) {
    if(x->contador==*MAX_FUNCIONARIOS){
        funcionario *Tmp;
 
        Tmp = (funcionario*)realloc(x->funcionarios, sizeof(funcionario) * (x->contador * 2));
        if (Tmp != NULL) {
        x->funcionarios = Tmp;
        *MAX_FUNCIONARIOS=x->contador * 2;
        
        x->funcionarios[x->contador].codigo = x->contador+1;
        printf("Código: %d",x->funcionarios[x->contador].codigo);
        printf("\n");
        printf("Nome: ");
        scanf("%s",&x->funcionarios[x->contador].nome);
        printf("\n");
        printf("Número de Telefone: ");
        scanf("%d",&x->funcionarios[x->contador].telefone);
        printf("\n");
        do{
            printf("Estado Civil\n1-Solteiro 2-Casado 3-Viuvo 4-Divorsiado\n");
            scanf("%d",&x->funcionarios[x->contador].estado);
        } while(x->funcionarios[x->contador].estado<1 || x->funcionarios[x->contador].estado>4);
        printf("\n");
        printf("Número de filhos: ");
        scanf("%d",&x->funcionarios[x->contador].filhos);
        printf("\n");
        do{
            printf("Cargo na empresa\n1-Empregado 2-Chefe 3-Admnistrador\n");
            scanf("%d",&x->funcionarios[x->contador].cargo);
        } while(x->funcionarios[x->contador].cargo<1 || x->funcionarios[x->contador].cargo>3);
        printf("\n");
        printf("Ganho por hora: ");
        scanf("%d",&x->funcionarios[x->contador].salariohora);
        printf("\n");
        printf("Subsídio de alimentação: ");
        scanf("%d",&x->funcionarios[x->contador].alimentacao);
        printf("\n");
        printf("Data de Nascimento: ");
        lerdata(&x->funcionarios[x->contador].nascimento);
        printf("\n");
        printf("Data de entrada na empresa: ");
        lerdata(&x->funcionarios[x->contador].entrada); 
        printf("\n");
        x->funcionarios[x->contador].ativo = 1;
        x->contador = x->contador+1;
        }
    }else{
        x->funcionarios[x->contador].codigo = x->contador+1;
        printf("Código: %d",x->funcionarios[x->contador].codigo);
        printf("\n");
        printf("Nome: ");
        scanf("%s",&x->funcionarios[x->contador].nome);
        printf("\n");
        printf("Número de Telefone: ");
        scanf("%d",&x->funcionarios[x->contador].telefone);
        printf("\n");
        do{
            printf("Estado Civil\n1-Solteiro 2-Casado 3-Viuvo 4-Divorsiado\n");
            scanf("%d",&x->funcionarios[x->contador].estado);
        } while(x->funcionarios[x->contador].estado<1 || x->funcionarios[x->contador].estado>4);
        printf("\n");
        printf("Número de filhos: ");
        scanf("%d",&x->funcionarios[x->contador].filhos);
        printf("\n");
        do{
            printf("Cargo na empresa\n1-Empregado 2-Chefe 3-Admnistrador\n");
            scanf("%d",&x->funcionarios[x->contador].cargo);
        } while(x->funcionarios[x->contador].cargo<1 || x->funcionarios[x->contador].cargo>3);
        printf("\n");
        printf("Ganho por hora: ");
        scanf("%d",&x->funcionarios[x->contador].salariohora);
        printf("\n");
        printf("Subsídio de alimentação: ");
        scanf("%d",&x->funcionarios[x->contador].alimentacao);
        printf("\n");
        printf("Data de Nascimento: ");
        lerdata(&x->funcionarios[x->contador].nascimento);
        printf("\n");
        printf("Data de entrada na empresa: ");
        lerdata(&x->funcionarios[x->contador].entrada); 
        printf("\n");
        x->funcionarios[x->contador].ativo = 1;
        x->contador = x->contador+1;
    }
}

void editarFuncionarios(vetor *x) {
    int cod,num=-1;
    
    do{
        printf("Insira um código de funcionário existente: ");
        scanf("%d",&cod);
        num=procurarFuncionario(x,cod);
    }while (num==-1);
    
    printf("Código: %d",x->funcionarios[num].codigo);
    printf("\n");
    printf("Nome: %s",x->funcionarios[num].nome);
    printf("\n");
    printf("Número de Telefone: %d\n",x->funcionarios[num].telefone);
    scanf("%d",&x->funcionarios[num].telefone);
    printf("\n");
    do{
        printf("Estado Civil - %d \n1-Solteiro 2-Casado 3-Viuvo 4-Divorsiado\n",x->funcionarios[num].estado);
        scanf("%d",&x->funcionarios[num].estado);
    } while(x->funcionarios[num].estado<1 || x->funcionarios[num].estado>4);
    printf("\n");
    printf("Número de filhos: %d\n",x->funcionarios[num].filhos);
    scanf("%d",&x->funcionarios[num].filhos);
    printf("\n");
    do{
        printf("Cargo na empresa - %d \n1-Empregado 2-Chefe 3-Admnistrador\n",x->funcionarios[num].cargo);
        scanf("%d",&x->funcionarios[num].cargo);
    } while(x->funcionarios[num].cargo<1 || x->funcionarios[num].cargo>3);
    printf("\n");
    printf("Ganho por hora: %d€\n",x->funcionarios[num].salariohora);
    scanf("%d",&x->funcionarios[num].salariohora);
    printf("\n");
    printf("Subsídio de alimentação: %d€\n",x->funcionarios[num].alimentacao);
    scanf("%d",&x->funcionarios[num].alimentacao);
    printf("\n");
}

void listarFuncionarios(vetor x,int op) {
    if (x.contador > 0) {
        if(op==1){
            int i;
            for (i = 0; i < x.contador; i++) {
                imprimirFuncionario(x.funcionarios[i]);
            }
        }else if(op==2){
            int i,cont=0;
            for (i = 0; i < x.contador; i++) {
                if(x.funcionarios[i].ativo==1){
                    imprimirFuncionario(x.funcionarios[i]);
                    cont++;
                }
            }
            if(cont==0){
                puts(ERRO_LISTA_VAZIA);
            }
        } else{
            int i,cont=0;
            for (i = 0; i < x.contador; i++) {
                if(x.funcionarios[i].ativo==2){
                    imprimirFuncionario(x.funcionarios[i]);
                    cont++;
                }
            }
            if(cont==0){
                puts(ERRO_LISTA_VAZIA);
            }
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void menuFuncionarios() {
    int opcao,i=0,MAX_FUNCIONARIOS=1;
    
    vetor funcionarios = {.contador = 0};
    
    funcionarios.funcionarios=calloc(MAX_FUNCIONARIOS,sizeof(funcionario));
    
    carregarVetor(&funcionarios,MAX_FUNCIONARIOS);
    do {
        printf("         -------------------------------------\n");
        printf("        |                                     |\n");
        printf("        |                 Menu                |\n");
        printf("        |         Gestão dos Funcionários     |\n");
        printf("        |                                     |\n");
        printf("        |   1- Listar Funcionários            |\n");
        printf("        |   2- Listar Funcionários Ativos     |\n");
        printf("        |   3- Listar Funcionários Inativos   |\n");
        printf("        |   4- Inserir Funcionário            |\n");
        printf("        |   5- Editar Funcionário             |\n");
        printf("        |   6- Demitir/Admitir Funcionário    |\n");
        printf("        |                                     |\n");
        printf("        |   11- Save changes                  |\n");
        printf("        |   22- Delete changes                |\n");
        printf("        |   0- Exit                           |\n");
        printf("        |                                     |\n");
        printf("         -------------------------------------\n");
        printf("\nFuncionários: %d/%d", funcionarios.contador, MAX_FUNCIONARIOS);

        printf("\nOpção: ");
        scanf("%d", &opcao);
        printf("\n");
        printf("\n");

        switch (opcao) {
            case 0:
                carregarFicheiro(&funcionarios.funcionarios[0],MAX_FUNCIONARIOS,funcionarios.contador);
                free(funcionarios.funcionarios);
                break;
            case 1:
                listarFuncionarios(funcionarios,1);
                //system("clear");
                break;
            case 2:
                listarFuncionarios(funcionarios,2);
                //system("clear");
                break;
            case 3:
                listarFuncionarios(funcionarios,3);
                //system("clear");
                break;    
            case 4:
                inserirFuncionarios(&funcionarios,&MAX_FUNCIONARIOS);
                //system("clear");
                break;
            case 5:
                editarFuncionarios(&funcionarios);
                //system("clear");
                break;
            case 6:
                editarEstadoFuncionario(&funcionarios);
                //system("clear");
                break;
            case 11:
                carregarFicheiro(&funcionarios.funcionarios[0],MAX_FUNCIONARIOS,funcionarios.contador);
                break;
            case 22:
                carregarVetor(&funcionarios,MAX_FUNCIONARIOS);
                break;
            default:
                printf("\nOpção invalida!");
        }

    } while (opcao != 0);
}