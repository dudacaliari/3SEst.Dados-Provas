#include <iostream>

using namespace std;

const int MAX = 5;

typedef struct Noh
{
    int numero;
    struct Noh *proximo;
} Noh;

typedef struct Fila
{
    Noh *inicio;
    Noh *fim;
} Fila;

typedef struct Pilha
{
    Noh *topo;
} Pilha;

void cabecalho()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "|            CADASTRO DE NUMEROS             |" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void inserirFila(Fila *fila, int numero)
{
    Noh *novo = new Noh();

    novo->numero = numero;
    novo->proximo = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

void inserirPilha(Pilha *pilha, int numero)
{
    Noh *novo = new Noh();

    novo->numero = numero;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void relatorio1(Fila *fila, Pilha *pilha)
{
    cout << "|+| Relatorio 1: Numeros que estao nas duas estruturas:" << endl;
    Noh *ptrFila = fila->inicio;
    bool encontrado = false;

    while (ptrFila != NULL)
    {
        Noh *ptrPilha = pilha->topo;

        while (ptrPilha != NULL)
        {
            if (ptrFila->numero == ptrPilha->numero)
            {
                encontrado = true;
                cout << ptrFila->numero << " ";
                break;
            }
            ptrPilha = ptrPilha->proximo;
        }

        ptrFila = ptrFila->proximo;
    }

    if (!encontrado)
    {
        cout << "|!| Nao existe numeros iguais nas duas estruturas." << endl;
    }
    cout << endl;
}

void relatorio2(Fila *fila, Pilha *pilha)
{
    cout << "|+| Relatorio 2: Numeros que estao apenas na fila:" << endl;
    Noh *ptrFila = fila->inicio;
    bool encontrado = false;

    while (ptrFila != NULL)
    {
        Noh *ptrPilha = pilha->topo;

        while (ptrPilha != NULL)
        {
            if (ptrFila->numero == ptrPilha->numero)
            {
                encontrado = true;
                break;
            }
            ptrPilha = ptrPilha->proximo;
        }

        if (!encontrado)
        {
            cout << ptrFila->numero << " ";
        }

        ptrFila = ptrFila->proximo;
    }
    
    cout << endl;
}

void relatorio3(Fila *fila, Pilha *pilha)
{
    cout << "|+| Relatorio 3: Numeros que estao apenas na pilha:" << endl;
    Noh *ptrPilha = pilha->topo;
    bool encontrado = false;

    while (ptrPilha != NULL)
    {
        Noh *ptrFila = fila->inicio;

        while (ptrFila != NULL)
        {
            if (ptrFila->numero == ptrPilha->numero)
            {
                encontrado = true;
                break;
            }
            ptrFila = ptrFila->proximo;
        }

        if (!encontrado)
        {
            cout << ptrPilha->numero << " ";
        }

        ptrPilha = ptrPilha->proximo;
    }

    cout << endl;
}

int main()
{
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    Pilha pilha;
    pilha.topo = NULL;

    int numero;

    cout << "> Digite 5 numeros para inserir na fila:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\t";
        cin >> numero;
        inserirFila(&fila, numero);
    }

    cout << "> Digite 5 numeros para inserir na pilha:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\t";
        cin >> numero;
        inserirPilha(&pilha, numero);
    }

    cout << endl;

    relatorio1(&fila, &pilha);
    relatorio2(&fila, &pilha);
    relatorio3(&fila, &pilha);

    return 0;
}
