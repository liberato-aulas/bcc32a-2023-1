#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int ddd;
    char numero[11];
} Celular;

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char rua[50];
    char cep[11];
    char cidade[30];
    char estado[3];
} Endereco;

typedef struct contato{
    char nome[100];
    Celular celular; 
    char email[50];
    Data nascimento;
    Endereco endereco;
}Contato;

void removeQuebraLinha(char* texto){
    int tam = strlen(texto);
    if(texto[tam-1] == '\n') texto[tam-1] = '\0';
}

int importarAgenda(Contato* agenda){
    int n;
    char dado[200];
    int ddd;
    int dia,mes,ano;

    scanf("%d\n", &n);    
    
    for(int i=0; i<n; i++){

        // Leitura do nome
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].nome, dado);

        // Leitura do telefone
        fscanf(stdin, "%d %s\n", &ddd, dado);
        agenda[i].celular.ddd = ddd;
        strcpy(agenda[i].celular.numero, dado);
        
        // Leitura do email
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].email, dado);

        // Leitura da data de nascimento
        fscanf(stdin, "%d/%d/%d\n", &dia, &mes, &ano);
        agenda[i].nascimento.dia = dia;
        agenda[i].nascimento.mes = mes;
        agenda[i].nascimento.ano = ano;
        
        // Leitura do nome da rua
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].endereco.rua, dado);

        // Leitura do cep
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].endereco.cep, dado);

        // Leitura da cidade
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].endereco.cidade, dado);

        // Leitura do estado
        fgets(dado, 200, stdin);
        removeQuebraLinha(dado);
        strcpy(agenda[i].endereco.estado, dado);

        // Leitura da linha em branco
        fgets(dado, 200, stdin);

    }

}

void procurarContato(Contato* agenda, int qtde, char* nome){

    for (int i=0; i < qtde; i++){
        char* encontrado = strstr(agenda[i].nome, nome);
        if(encontrado != NULL && encontrado == agenda[i].nome){
            imprimeContato(agenda + i);
        }
        
    }
}

void aniversariantesMes(Contato* agenda, int qtde, int mes){
    for (int i=0; i < qtde; i++){        
        if(mes == agenda[i].nascimento.mes){
            imprimeContato(agenda + i);
        }
        
    }
}

void imprimeContato(Contato* c){
    printf("Nome: %s\n", c->nome);
    printf("Celular: (%d) %s\n", c->celular.ddd, c->celular.numero);
    printf("Email: %s\n", c->email);
    printf("Nascimento: %d/%d/%d\n", c->nascimento.dia, c->nascimento.mes, c->nascimento.ano);
    printf("Endereco: %s, %s, %s, %s\n", c->endereco.rua, c->endereco.cep, c->endereco.cidade, c->endereco.estado);
    printf("\n\n");    
}

int main(){
    
    Contato agenda[100];
    int qtde = importarAgenda(agenda);

    procurarContato(agenda, qtde, "Ruan");

    aniversariantesMes(agenda, qtde, 10);

    // for (int i=0; i < qtde; i++){
    //     imprimeContato(agenda+i);
    // }

    return 0;
}