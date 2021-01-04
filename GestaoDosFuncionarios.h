#ifndef GestaoDosFuncionarios_H
#define GestaoDosFuncionarios_H

#define FILENAME "funcionarios.bin"

#define ERRO_LISTA_VAZIA        "A lista de funcionários está vazia."
#define ERRO_LISTA_CHEIA        "A lista de funcionários está cheia."

enum estadocivil  { Solteiro=1, Casado, Viuvo, Divorsiado };
enum cargonaempresa  { Empregado=1, Chefe, Administrador };
enum trabalhanaempresa  { TRUE=1, FALSE };

typedef struct {
    int dia, mes, ano;
}data;

typedef struct {
    int codigo;
    char nome[250];
    int telefone;
    enum estadocivil estado;
    int filhos;
    enum cargonaempresa cargo;
    int salariohora;
    int alimentacao;
    data nascimento;
    data entrada;
    data saida;
    enum trabalhanaempresa ativo;
}funcionario;

typedef struct {
    int contador;
    funcionario *funcionarios;
}vetor;

void menuFuncionarios();

#endif /* GestaoDosFuncionarios_H */

