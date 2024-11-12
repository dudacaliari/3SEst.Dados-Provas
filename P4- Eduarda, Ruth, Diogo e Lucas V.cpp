/*2. Faca um programa que cadastre 8 funcionarios. Para cada funcionario devem ser 
cadastrados nome e salario. Os dados devem ser armazenados em uma lista 
simplesmente encadeada e ordenada, de forma decrescente, pelo salario do 
funcionário. Posteriormente, o programa de mostrar:
a. O nome do funcionario que tem o maior salario (em caso de empate mostrar 
todos);
b. A media salarial de todos os funcionarios juntos;
c. A quantidade de funcionarios com salario superior a um valor fornecido pelo 
usuario. Caso nenhum funcionario satisfaca essa condicao, mostrar 
mensagem.*/

#include <iostream>
#include <string>

using namespace std;

const int MAX = 3;

typedef struct Funcionario{
    string nome;
    float salario;
    Funcionario *proximo;
}Funcionario;

typedef struct Lista{
    Funcionario *inicio;
    int tamanho;
} Lista;

void cabecalho()
{
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "+ CADASTRO DE FUNCIONARIOS  +" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl << endl;
}


void inserir(Lista *lst, string nome, float salario)
{
    Funcionario *novo = new Funcionario(); //criando caixinha
    novo->nome = nome;
    novo->salario = salario;

    Funcionario *ptrAnterior =NULL;
    Funcionario *ptrAux = lst->inicio;
    
    while (ptrAux != NULL && novo->salario < ptrAux->salario)
    {
        ptrAnterior = ptrAux;
        ptrAux = ptrAux->proximo;
    }

    if(ptrAnterior == NULL)
    {
        novo->proximo = lst->inicio;
        lst->inicio = novo;
    }
    
    else
    {
        ptrAnterior->proximo = novo;
        novo->proximo = ptrAux;
    }   
}

void imprime(Lista *lst)
{
    Funcionario *ptrAux = lst->inicio;

    while(ptrAux != NULL)
    {
        cout << "|+| Nome: " << ptrAux->nome << " - ";
        cout << "|+| Salario: R$" << ptrAux->salario << " " << endl;
        ptrAux = ptrAux->proximo;
    }

    cout << endl;
    
}

void maiorSalario(Lista *lst)
{
    Funcionario *ptrAux = lst->inicio;
    float maiorSalario = 0;

    while(ptrAux != NULL)
    {
        if(ptrAux->salario > maiorSalario) 
            maiorSalario = ptrAux->salario;
        
        ptrAux = ptrAux->proximo;
    }

    ptrAux = lst->inicio;

    cout << "|+| Funcionario(s) com maior salario: " << endl;
    while(ptrAux != NULL)
    {
        if(ptrAux->salario == maiorSalario) 
            cout << ptrAux->nome << endl;
        
        ptrAux = ptrAux->proximo;
    }
    cout << endl;
}

void calcularMedia(Lista *lst)
{
    Funcionario *ptrAux = lst->inicio;
    float somaSalarios = 0, media;
    
    while(ptrAux != NULL)
    {
        somaSalarios += ptrAux->salario;
        ptrAux = ptrAux->proximo;
    }

    media = somaSalarios / MAX;
    
    cout << "|+| Media total dos salarios: " << endl << media << endl << endl;
}

void buscarSalario(Lista *lst, float salarioBuscado)
{
    Funcionario *ptrAux = lst->inicio;
    int contador = 0;

    while(ptrAux != NULL)
    {
        if(ptrAux->salario > salarioBuscado)
            contador++;

        ptrAux = ptrAux->proximo;
    }
    if (contador == 0)
        cout << "|!| Nao ha funcionarios com salario superior a " << salarioBuscado << "." << endl;
    else
    {
        cout << "|+| Quantidade de funcionarios com salario superior a " << salarioBuscado << ":" << endl;
        cout << contador << endl;
    }
}

int main()
{
    Lista lista;
    string nome;
    float salario, salarioProcurado;

    lista.inicio = NULL;
    lista.tamanho = MAX;

    cabecalho();
    
    for(int i=0; i<MAX; i++)
    {
        cout << "> Digite o nome do funcionario " << i+1 << ": " << endl;
        cout << "\t";
        getline(cin, nome);
        
        cout << "> Digite o salario do funcionario " << i+1 << ": " << endl;
        cout << "\t";
        cin >> salario;
        
        cin.ignore();
        inserir(&lista, nome, salario);
    }
    
    cout << endl;
    imprime(&lista);

    maiorSalario(&lista);

    calcularMedia(&lista);

    cout << "> Digite um valor para mostrar a quantidade de salarios superiores: " << endl;
    cin >> salarioProcurado;
    
    buscarSalario(&lista, salarioProcurado);

    
    return 0;
}
