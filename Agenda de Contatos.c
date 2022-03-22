#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 2
#define NAO_ENCONTRADO -3
#define ENCONTRADO -4

typedef struct
{
    char fixo[20];
    char pessoal[20];
    char empresa[20];
} Telefone;

typedef struct
{
    Telefone telefone;
    char nome[50];
    char email[50];
    char dataNasc[20];
    char endereco[300];
} Pessoa;

typedef struct
{
    int limite;
    int cont;
    Pessoa *pessoas;
} ArrayList;

//menu ();
//ArrayList* criarLista();
//int adicionar_Contato(ArrayList *list);
int imprimir(ArrayList *list);
ArrayList *criarLista()
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));

    if (list != NULL)
    {
        list->cont = 0;
        list->limite = 10;
        list->pessoas = (Pessoa *)malloc(list->limite * sizeof(Pessoa));

        if (list->pessoas == NULL)
            return NULL;

        return list;
    }
    else
        return NULL;
}

void troca(int x, int y, ArrayList *list)
{ // função que troca as posições
    char aux[80];
    Pessoa auxTelefone;
    strcpy(aux, list->pessoas[x].nome);
    strcpy(list->pessoas[x].nome, list->pessoas[y].nome);
    strcpy(list->pessoas[y].nome, aux);

    strcpy(aux, list->pessoas[x].email);
    strcpy(list->pessoas[x].email, list->pessoas[y].email);
    strcpy(list->pessoas[y].email, aux);

    strcpy(aux, list->pessoas[x].endereco);
    strcpy(list->pessoas[x].endereco, list->pessoas[y].endereco);
    strcpy(list->pessoas[y].endereco, aux);

    strcpy(aux, list->pessoas[x].dataNasc);
    strcpy(list->pessoas[x].dataNasc, list->pessoas[y].dataNasc);
    strcpy(list->pessoas[y].dataNasc, aux);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[x].telefone.empresa);
    strcpy(list->pessoas[x].telefone.empresa, list->pessoas[y].telefone.empresa);
    strcpy(list->pessoas[y].telefone.empresa, auxTelefone.telefone.empresa);

    strcpy(auxTelefone.telefone.fixo, list->pessoas[x].telefone.fixo);
    strcpy(list->pessoas[x].telefone.fixo, list->pessoas[y].telefone.fixo);
    strcpy(list->pessoas[y].telefone.fixo, auxTelefone.telefone.fixo);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[x].telefone.pessoal);
    strcpy(list->pessoas[x].telefone.pessoal, list->pessoas[y].telefone.pessoal);
    strcpy(list->pessoas[y].telefone.pessoal, auxTelefone.telefone.empresa);
}

void trocaData(int n, int m, ArrayList *list)
{ // ordena em ordem de data do mais velho pro mais novo
    char aux[80];
    Pessoa auxTelefone;
    strcpy(aux, list->pessoas[n].nome);
    strcpy(list->pessoas[n].nome, list->pessoas[m].nome);
    strcpy(list->pessoas[m].nome, aux);

    strcpy(aux, list->pessoas[n].email);
    strcpy(list->pessoas[n].email, list->pessoas[m].email);
    strcpy(list->pessoas[m].email, aux);

    strcpy(aux, list->pessoas[n].endereco);
    strcpy(list->pessoas[n].endereco, list->pessoas[m].endereco);
    strcpy(list->pessoas[m].endereco, aux);

    strcpy(aux, list->pessoas[n].dataNasc);
    strcpy(list->pessoas[n].dataNasc, list->pessoas[m].dataNasc);
    strcpy(list->pessoas[m].dataNasc, aux);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[n].telefone.empresa);
    strcpy(list->pessoas[n].telefone.empresa, list->pessoas[m].telefone.empresa);
    strcpy(list->pessoas[m].telefone.empresa, auxTelefone.telefone.empresa);

    strcpy(auxTelefone.telefone.fixo, list->pessoas[n].telefone.fixo);
    strcpy(list->pessoas[n].telefone.fixo, list->pessoas[m].telefone.fixo);
    strcpy(list->pessoas[m].telefone.fixo, auxTelefone.telefone.fixo);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[n].telefone.pessoal);
    strcpy(list->pessoas[n].telefone.pessoal, list->pessoas[m].telefone.pessoal);
    strcpy(list->pessoas[m].telefone.pessoal, auxTelefone.telefone.empresa);
}
void trocaEmail(int a, int b, ArrayList *list)
{ // troca os e-mails em ordem alfabetica

    char aux[80];
    Pessoa auxTelefone;
    strcpy(aux, list->pessoas[a].nome);
    strcpy(list->pessoas[a].nome, list->pessoas[b].nome);
    strcpy(list->pessoas[b].nome, aux);

    strcpy(aux, list->pessoas[a].email);
    strcpy(list->pessoas[a].email, list->pessoas[b].email);
    strcpy(list->pessoas[b].email, aux);

    strcpy(aux, list->pessoas[a].endereco);
    strcpy(list->pessoas[a].endereco, list->pessoas[b].endereco);
    strcpy(list->pessoas[b].endereco, aux);

    strcpy(aux, list->pessoas[a].dataNasc);
    strcpy(list->pessoas[a].dataNasc, list->pessoas[b].dataNasc);
    strcpy(list->pessoas[b].dataNasc, aux);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[a].telefone.empresa);
    strcpy(list->pessoas[a].telefone.empresa, list->pessoas[b].telefone.empresa);
    strcpy(list->pessoas[b].telefone.empresa, auxTelefone.telefone.empresa);

    strcpy(auxTelefone.telefone.fixo, list->pessoas[a].telefone.fixo);
    strcpy(list->pessoas[a].telefone.fixo, list->pessoas[b].telefone.fixo);
    strcpy(list->pessoas[b].telefone.fixo, auxTelefone.telefone.fixo);

    strcpy(auxTelefone.telefone.empresa, list->pessoas[a].telefone.pessoal);
    strcpy(list->pessoas[a].telefone.pessoal, list->pessoas[b].telefone.pessoal);
    strcpy(list->pessoas[b].telefone.pessoal, auxTelefone.telefone.empresa);
}

int ordenar(ArrayList *list)
{ //função  ordena a lista  em ordem alfabetica

    int result;
    for (int i = 0; i < list->cont; i++)
    {
        for (int j = i + 1; j < list->cont; j++)
        {
            result = strcmp(list->pessoas[i].nome, list->pessoas[j].nome);
            if (result > 0)
            {
                troca(i, j, list);
            }
        }
    }
    return TRUE;
}
int ordenarDataNasc(ArrayList *list)
{ //ordena por data, do mais novo pro mais velho
    int result;
    for (int i = 0; i < list->cont; i++)
    {
        for (int j = i + 1; j < list->cont; j++)
        {
            result = strcmp(list->pessoas[i].dataNasc, list->pessoas[j].dataNasc);
            if (result < 0)
            {
                trocaData(i, j, list);
            }
        }
    }
    return TRUE;
}

int ordenar_Email(ArrayList *list)
{ //função  ordena a lista  em ordem alfabetica  pelo e-mail

    int result;
    for (int i = 0; i < list->cont; i++)
    {
        for (int j = i + 1; j < list->cont; j++)
        {
            result = strcmp(list->pessoas[i].email, list->pessoas[j].email);
            if (result > 0)
            {
                trocaEmail(i, j, list);
            }
        }
    }
    return TRUE;
}

int busca_binariaEmail(ArrayList *list, char *email)
{ // busca binaria por email
    ordenar_Email(list);
    int inicio = 0;
    int fim = list->cont - 1;
    int meio;

    while (inicio <= fim)
    {
       
        meio = (inicio + fim) / 2; 
        
        if (strcmp(email, list->pessoas[meio].email) > 0)
        {
            inicio = meio + 1;
        }
        else if (strcmp(email, list->pessoas[meio].email) < 0)
        {
            fim = meio - 1;
        }
        else if (strcmp(email, list->pessoas[meio].email) == 0)
        {
            return ENCONTRADO;
        }
       
    }
    return NAO_ENCONTRADO;
}

int adicionar_Contato(ArrayList *list)
{
    char token_end, token_telefoneFixo, token_email, token_data, token_telefoneEmpresa;
    if (list == NULL)
        return FALSE;

    printf("Digite o nome do contato: \n");
    scanf("%[^\n]s", list->pessoas[list->cont].nome);
    fflush(stdin);
    //***************************************************************************************
    printf("Digite o telefone pessoal: \n");
    scanf("%[^\n]s", list->pessoas[list->cont].telefone.pessoal);
    fflush(stdin);

    //***************************************************************************************
    do
    {
        printf("Deseja inserir telefone fixo? Se sim digite 'S', se nao digite 'N': \n");
        scanf(" %c", &token_telefoneFixo);
        fflush(stdin);
    } while (token_telefoneFixo != 'S' && token_telefoneFixo != 'N');

    if (token_telefoneFixo == 'S')
    {
        printf("Digite o telefone fixo: \n");
        scanf("%[^\n]s", list->pessoas[list->cont].telefone.fixo);
        fflush(stdin);
    }
    else
    {
        strcpy(list->pessoas[list->cont].telefone.fixo, "VAZIO");
    }
    //***************************************************************************************
    do
    {
        printf("Deseja inserir telefone empresarial? Se sim digite 'S', se nao digite 'N': \n");
        scanf(" %c", &token_telefoneEmpresa);
        fflush(stdin);
    } while (token_telefoneEmpresa != 'S' && token_telefoneEmpresa != 'N');

    if (token_telefoneEmpresa == 'S')
    {
        printf("Digite o telefone empresarial: \n");
        scanf("%[^\n]s", list->pessoas[list->cont].telefone.empresa);
        fflush(stdin);
    }
    else
    {
        strcpy(list->pessoas[list->cont].telefone.empresa, "VAZIO");
    }
    //***************************************************************************************
    do
    {
        printf("Deseja inserir endereco? Se sim digite 'S', se nao digite 'N': \n");
        scanf(" %c", &token_end);
        fflush(stdin);
    } while (token_end != 'S' && token_end != 'N');

    if (token_end == 'S')
    {
        printf("Digite o endereco (logadouro, numero, complemento, bairro, cidade, estado): \n");
        scanf("%[^\n]s", list->pessoas[list->cont].endereco);
        fflush(stdin);
    }
    else
    {
        strcpy(list->pessoas[list->cont].endereco, "VAZIO");
    }
    //***************************************************************************************
    do
    {
        printf("Deseja inserir e-mail? Se sim digite 'S', se nao digite 'N': \n");
        scanf(" %c", &token_email);
        fflush(stdin);
    } while (token_email != 'S' && token_email != 'N');

    if (token_email == 'S')
    {
        do
        {
            printf("Digite o e-mail: \n");
            fflush(stdin);
            scanf("%[^\n]s", list->pessoas[list->cont].email);

            if (busca_binariaEmail(list, list->pessoas[list->cont].email) == -4)
                printf("Esse e-mail ja foi cadastrado no sistema, digite outro: \n");

        } while (busca_binariaEmail(list, list->pessoas[list->cont].email) == -4);
    }
    else
    {
        strcpy(list->pessoas[list->cont].email, "VAZIO");
    }

    //***************************************************************************************
    do
    {
        printf("Deseja inserir data de nascimento ? Se sim digite 'S', se nao digite 'N': \n");
        scanf(" %c", &token_data);
        fflush(stdin);
    } while (token_data != 'S' && token_data != 'N');
    if (token_data == 'S')
    {
        printf("Digite a data  nesse formato YYYY/MM /DD: \n");
        scanf("%[^\n]s", list->pessoas[list->cont].dataNasc);
        fflush(stdin);
    }
    else
    {
        strcpy(list->pessoas[list->cont].dataNasc, "VAZIO");
    }

    list->cont++;

    return TRUE;
}
int busca_binaria(ArrayList *list, char *nome)
{ // busca binaria por nome
    ordenar(list);
    int inicio = 0;
    int fim = list->cont - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (strcmp(nome, list->pessoas[meio].nome) > 0)
        {
            inicio = meio + 1;
        }
        else if (strcmp(nome, list->pessoas[meio].nome) < 0)
        {
            fim = meio - 1;
        }
        else if (strcmp(nome, list->pessoas[meio].nome) == 0)
        {
            return meio;
        }
    }
    return NAO_ENCONTRADO;
}
int busca_binariaData(ArrayList *list, char *data)
{ // busca binaria por data
    ordenarDataNasc(list);
    int inicio = 0;
    int fim = list->cont - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (strcmp(list->pessoas[meio].dataNasc, data) > 0)
        {
            inicio = meio + 1;
        }
        else if (strcmp(list->pessoas[meio].dataNasc, data) < 0)
        {
            fim = meio - 1;
        }
        else if (strcmp(list->pessoas[meio].dataNasc, data) == 0)
        {
            return meio;
        }
    }
    return NAO_ENCONTRADO;
}

int pesquisaNome(ArrayList *list, char *nomeBusca)
{ // printa o contato pelo nome
    ordenar(list);
    int pos = busca_binaria(list, nomeBusca);
    printf("--------------------Contato-------------------");
    printf("\n");
    if (strcmp(list->pessoas[pos].nome, "VAZIO") != 0)
    {
        printf("O nome eh: %s", list->pessoas[pos].nome);
        printf("\n");
    }

    if (strcmp(list->pessoas[pos].endereco, "VAZIO") != 0)
    {
        printf("O endereco eh: %s", list->pessoas[pos].endereco);
        printf("\n");
    }

    if (strcmp(list->pessoas[pos].email, "VAZIO") != 0)
    {
        printf("O e-mail eh: %s", list->pessoas[pos].email);
        printf("\n");
    }
    if (strcmp(list->pessoas[pos].dataNasc, "VAZIO") != 0)
    {
        printf("A data de nascimento eh: %s", list->pessoas[pos].dataNasc);
        printf("\n");
    }
    if (strcmp(list->pessoas[pos].telefone.empresa, "VAZIO") != 0)
    {
        printf("O telefone empresarial eh: %s", list->pessoas[pos].telefone.empresa);
        printf("\n");
    }
    if (strcmp(list->pessoas[pos].telefone.fixo, "VAZIO") != 0)
    {
        printf("O telefone fixo eh: %s", list->pessoas[pos].telefone.fixo);
        printf("\n");
    }
    if (strcmp(list->pessoas[pos].telefone.pessoal, "VAZIO") != 0)
    {
        printf("O telefone pessoal eh: %s", list->pessoas[pos].telefone.pessoal);
        printf("\n");
    }

    printf("----------------------------------------------\n");

    return TRUE;
}
int pesquisaData(ArrayList *list, char *DataBusca)
{ // printa o contato pela data de nascimento
    ordenarDataNasc(list);

    int pos = busca_binariaData(list, DataBusca);
    if (strcmp(DataBusca, "\0") != 0)
    {
        printf("--------------------Contato-------------------");
        printf("\n");
        if (strcmp(list->pessoas[pos].nome, "VAZIO") != 0)
        {
            printf("O nome eh: %s", list->pessoas[pos].nome);
            printf("\n");
        }

        if (strcmp(list->pessoas[pos].endereco, "VAZIO") != 0)
        {
            printf("O endereco eh: %s", list->pessoas[pos].endereco);
            printf("\n");
        }

        if (strcmp(list->pessoas[pos].email, "VAZIO") != 0)
        {
            printf("O e-mail eh: %s", list->pessoas[pos].email);
            printf("\n");
        }
        if (strcmp(list->pessoas[pos].dataNasc, "VAZIO") != 0)
        {
            printf("A data de nascimento eh: %s", list->pessoas[pos].dataNasc);
            printf("\n");
        }
        if (strcmp(list->pessoas[pos].telefone.empresa, "VAZIO") != 0)
        {
            printf("O telefone empresarial eh: %s", list->pessoas[pos].telefone.empresa);
            printf("\n");
        }
        if (strcmp(list->pessoas[pos].telefone.fixo, "VAZIO") != 0)
        {
            printf("O telefone fixo eh: %s", list->pessoas[pos].telefone.fixo);
            printf("\n");
        }
        if (strcmp(list->pessoas[pos].telefone.pessoal, "VAZIO") != 0)
        {
            printf("O telefone pessoal eh: %s", list->pessoas[pos].telefone.pessoal);
            printf("\n");
        }

        printf("----------------------------------------------\n");
    }
    return TRUE;
}

int remover(ArrayList *list, char *nomeUsuario)
{
    int pos = busca_binaria(list, nomeUsuario);

    for (int i = 1, j = 0; i <= list->cont - 1; i++, j++)
    {
        strcpy(list->pessoas[pos + j].nome, list->pessoas[pos + i].nome);
        strcpy(list->pessoas[pos + j].endereco, list->pessoas[pos + i].endereco);
        strcpy(list->pessoas[pos + j].email, list->pessoas[pos + i].email);
        strcpy(list->pessoas[pos + j].dataNasc, list->pessoas[pos + i].dataNasc);
        strcpy(list->pessoas[pos + j].telefone.pessoal, list->pessoas[pos + i].telefone.pessoal);
        strcpy(list->pessoas[pos + j].telefone.fixo, list->pessoas[pos + i].telefone.fixo);
        strcpy(list->pessoas[pos + j].telefone.empresa, list->pessoas[pos + i].telefone.empresa);
    }

    list->cont--;
    return TRUE;
}
int editar(ArrayList *list, char *nomeUsuario)
{
    char email[50];
    char token_end, token_telefoneFixo, token_email, token_data, token_telefoneEmpresa, token_telefonePessoal, token_nome;
    int pos = busca_binaria(list, nomeUsuario);
    
    do
        {
            printf("Deseja modificar o nome desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_nome);
            fflush(stdin);
        }while(token_nome != 'S' && token_nome != 'N');
    
    if (token_nome == 'S')
    {
        printf("Digite o novo nome: \n");
        scanf("%[^\n]s", list->pessoas[pos].nome);
        fflush(stdin);
    }
    //*********************************************************************************************************
    do
        {
            printf("Deseja modificar o endereco(logadouro, numero, complemento, bairro, cidade, estado) desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_end);
            fflush(stdin);
        }while(token_end != 'S' && token_end != 'N');
    if (token_end == 'S')
    {
        printf("Digite o novo endereco (logadouro, numero, complemento, bairro, cidade, estado): \n");
        scanf("%[^\n]s", list->pessoas[pos].endereco);
        fflush(stdin);
    }
    //*********************************************************************************************************
    do
        {
            printf("Deseja modificar a data de nascimento desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_data);
            fflush(stdin);
        }while(token_data != 'S' && token_data != 'N');
    if (token_data == 'S')
    {
        printf("Digite a nova data de nascimento nesse formato YYY/MM/DD: \n");
        scanf("%[^\n]s", list->pessoas[pos].dataNasc);
        fflush(stdin);
    }
    //*********************************************************************************************************
    do
        {
            printf("Deseja modificar o telefone pessoal desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_telefonePessoal);
            fflush(stdin);
        }while(token_telefonePessoal != 'S' && token_telefonePessoal != 'N');

    if (token_telefonePessoal == 'S')
    {
        printf("Digite o novo telefone pessoal: \n");
        scanf("%[^\n]s", list->pessoas[pos].telefone.pessoal);
        fflush(stdin);
    }
    //*********************************************************************************************************
    do
        {
            printf("Deseja modificar o telefone empresarial desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_telefoneEmpresa);
            fflush(stdin);
        }while(token_telefoneEmpresa!= 'S' && token_telefoneEmpresa != 'N');
    if (token_telefoneEmpresa == 'S')
    {
        printf("Digite o novo telefone empresarial: \n");
        scanf("%[^\n]s", list->pessoas[pos].telefone.empresa);
        fflush(stdin);
    }
    //*********************************************************************************************************
    do
        {
            printf("Deseja modificar o telefone fixo desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_telefoneFixo);
            fflush(stdin);
        }while(token_telefoneFixo != 'S' && token_telefoneFixo != 'N');
    if (token_telefoneFixo == 'S')
    {
        printf("Digite o novo telefone fixo: \n");
        scanf("%[^\n]s", list->pessoas[pos].telefone.fixo);
        fflush(stdin);
    }
    //*********************************************************************************************************
   do
        {
            printf("Deseja modificar o e-mail desse contato? Se sim digite S, se nao digite N \n");
            scanf(" %c", &token_email);
            fflush(stdin);
        }while(token_email != 'S' && token_email != 'N');

    if (token_email == 'S')
    {
        do
        {
            printf("Digite o novo e-mail: \n");
            fflush(stdin);
            scanf("%[^\n]s", email);
            if (busca_binariaEmail(list, email) == -4)
                printf("Esse e-mail ja foi cadastrado no sistema, digite outro: \n");
            else
            {
                strcpy(list->pessoas[pos].email, email);
                break;
            }
        } while (busca_binariaEmail(list, email) == -4);
    }
    return TRUE;  

}
void salvar(ArrayList *list)
{
    FILE *fp;
    int desbugador = -5;
    fp = fopen("agenda.txt", "w");
    if (fp == NULL)
        printf("Erro na abertura do arquivo\n");
    else
    {
        for (int i = 0; i < list->cont; i++)
        {
            fprintf(fp, "%s\n", list->pessoas[i].nome);
            fprintf(fp, "%s\n", list->pessoas[i].telefone.pessoal);
            fprintf(fp, "%s\n", list->pessoas[i].telefone.fixo);
            fprintf(fp, "%s\n", list->pessoas[i].telefone.empresa);
            fprintf(fp, "%s\n", list->pessoas[i].email);
            fprintf(fp, "%s\n", list->pessoas[i].endereco);
            fprintf(fp, "%s\n", list->pessoas[i].dataNasc);
            fprintf(fp,"%d", desbugador);
        }
        fclose(fp);
        printf("Dados Gravados!\n");
    }
}
void string(ArrayList *list){                 // coloca \0 no final da string 
    for(int i = 0; i < list->cont; i++){ 
       
        list->pessoas[i].nome[strlen(list->pessoas[i].nome) - 1]= '\0';
        list->pessoas[i].telefone.pessoal[strlen(list->pessoas[i].telefone.pessoal) - 1]= '\0';
        list->pessoas[i].telefone.empresa[strlen(list->pessoas[i].telefone.empresa) - 1]= '\0';
        list->pessoas[i].telefone.fixo[strlen(list->pessoas[i].telefone.fixo) - 1]= '\0';
        list->pessoas[i].email[strlen(list->pessoas[i].email) - 1]= '\0';
        list->pessoas[i].endereco[strlen(list->pessoas[i].endereco) - 1]= '\0';
        list->pessoas[i].dataNasc[strlen(list->pessoas[i].dataNasc) - 1]= '\0';
        
    }   
}

void carregarDados(ArrayList *list)
{
    FILE *fp;
    int desbugador;
    fp = fopen("agenda.txt", "r");
    list->cont = 0;
    if (fp == NULL)
        printf("Arquivo nao foi encontrado!\n");
    else
    {
        
        while (!feof(fp))
        {
            fgets(list->pessoas[list->cont].nome, 50, fp);
            fgets(list->pessoas[list->cont].telefone.pessoal, 20, fp);
            fgets(list->pessoas[list->cont].telefone.fixo, 20, fp);
            fgets(list->pessoas[list->cont].telefone.empresa, 20, fp);
            fgets(list->pessoas[list->cont].email, 50, fp);
            fgets(list->pessoas[list->cont].endereco, 300, fp);
            fgets(list->pessoas[list->cont].dataNasc, 20, fp);
            fscanf(fp,"%d",&desbugador);
            list->cont++;
        }
        fclose(fp);
        string(list);
        printf("Dados Carregados!\n");
    }
}

int imprimir(ArrayList *list)
{
    printf("--------------Agenda de Contatos--------------- \n");
    for (int i = 0; i < list->cont; i++)
    {

        if (strcmp(list->pessoas[i].nome, "VAZIO") != 0)
        {
            printf("O nome eh:  %s", list->pessoas[i].nome);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].telefone.pessoal, "VAZIO") != 0)
        {
            printf("O telefone pessoal eh:  %s", list->pessoas[i].telefone.pessoal);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].telefone.fixo, "VAZIO") != 0)
        {
            printf("O telefone fixo eh:  %s", list->pessoas[i].telefone.fixo);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].telefone.empresa, "VAZIO") != 0)
        {
            printf("O telefone empresarial eh:  %s", list->pessoas[i].telefone.empresa);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].email, "VAZIO") != 0)
        {
            printf("O e-mail eh:  %s", list->pessoas[i].email);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].endereco, "VAZIO") != 0)
        {
            printf("O endereco eh:  %s", list->pessoas[i].endereco);
            printf("\n");
        }

        if (strcmp(list->pessoas[i].dataNasc, "VAZIO") != 0)
        {
            printf("A data de nascimento eh:  %s", list->pessoas[i].dataNasc);
            printf("\n");
        }

        printf("----------------------------------------------\n");
    }

    return TRUE;
}
void menu()
{
    int num, pesquisa;
    char nomeUsuario[80], dataUsuario[13];
    ArrayList *list = criarLista();

    do
    {
        printf("*.*.*.* MENU *.*.*.*\n");
        printf("0. Sair\n");
        printf("1. Novo Contato\n");
        printf("2. Pesquisar\n");
        printf("3. Atualizar\n");
        printf("4. Excluir\n");
        printf("5. Imprimir \n");
        printf("6. Salvar\n");
        printf("7. Carregar Dados\n");
        printf("*.*.*.*.*.*.*.*.*.*\n");

        printf("Opcao: ");
        scanf("%d", &num);
        fflush(stdin);

        switch (num)
        {
        case 0:
            printf("Saindo...... \n");
            break;
        case 1:
            adicionar_Contato(list);
            break;
        case 2:
            if (list->cont == 0)
            {
                printf("A agenda estah vazia \n");
                break;
            }
            printf("Como deseja pesquisar? \n");
            printf("1. Por nome\n");
            printf("2. Por data de nascimento\n");
            scanf("%d", &pesquisa);
            fflush(stdin);
            if (pesquisa == 1)
            {
                printf("Qual o nome do contato a ser pesquisado? \n");
                scanf("%[^\n]s", nomeUsuario);
                fflush(stdin);
                if (busca_binaria(list, nomeUsuario) == -3)
                {
                    printf("O nome inserido nao esta cadastrado na agenda! \n");
                }
                else
                {
                    pesquisaNome(list, nomeUsuario);
                }
            }
            else if (pesquisa == 2)
            {
                printf("Qual a data de nascimento  do contato a ser pesquisado? Escreva no formato YYYY/MM/DD \n");
                scanf("%[^\n]s", dataUsuario);
                fflush(stdin);
                if (busca_binariaData(list, dataUsuario) == -3)
                {
                    printf("A data  inserida nao esta cadastrado na agenda! \n");
                }
                else
                {
                    pesquisaData(list, dataUsuario);
                }
            }
            else
                printf("Opcao invalida! \n");
            break;
        case 3:
            if (list->cont == 0)
            {
                printf("A agenda estah vazia \n");
            }
            else
            {
                printf("Qual o nome do contato que deseja editar?  \n");
                scanf("%[^\n]s", nomeUsuario);
                fflush(stdin);
                if (busca_binaria(list, nomeUsuario) == -3)
                {
                    printf("O nome inserido nao esta cadastrado na agenda!\n");
                }
                else
                {
                    editar(list, nomeUsuario);
                }
            }
            break;
        case 4:
            if (list->cont == 0)
            {
                printf("A agenda estah vazia! \n");
            }
            else
            {
                printf("Qual o nome do contato para ser excluido?  \n");
                scanf("%[^\n]s", nomeUsuario);
                fflush(stdin);
                if (busca_binaria(list, nomeUsuario) == -3)
                {
                    printf("O nome inserido nao esta cadastrado na agenda! \n");
                }

                else
                {
                    remover(list, nomeUsuario);
                }
            }
            break;

        case 5:
            if (list->cont == 0)
                printf("A agenda estah vazia! \n");
            else
            {
                ordenar(list);
                imprimir(list);
            }
            break;
        case 6:
            if (list->cont == 0)
                printf("A agenda estah vazia! \n");
            else
            {
                ordenar(list);
                salvar(list);
            }
            break;
        case 7:
            carregarDados(list);
            break;
        default:
            printf("Opcao invalida, digite novamente: \n");
            break;
        }
    } while (num != 0);
}
int main()
{

    menu();
    return 0;
}