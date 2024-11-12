#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX = 10000;

void cabecalho()
{
    cout << "\t------------------------" << endl;
    cout << "\t|      COMPARACAO      |" << endl;
    cout << "\t------------------------" << endl << endl;    
}

void bubbleSort(int vetor[], int max)
{
    int *ptrVetor = vetor;
    int i, j, aux;

    for(j=1; j<max-1; j++)
    {
        for(i=max-1; i >= j; i--)
        {
            if(ptrVetor[i] < ptrVetor[i-1])
            {
                aux = ptrVetor[i];
                ptrVetor[i] = ptrVetor[i-1];
                ptrVetor[i-1] = aux;
            }
        }
    }
}

void insertionSort(int vetor[], int max)
{
    int *ptrVetor = vetor;
    int i, j, aux;

    for(i=1; i<max-1; i++)
    {
        aux = ptrVetor[i];
        j = i-1;

        while(j >= 0 && ptrVetor[i] > aux)
        {
            ptrVetor[j+1] = ptrVetor[j];
            j--;
        }
        ptrVetor[j+1] = aux;
    }
}

void troca(int vetor[], int i, int j)
{
    int aux;
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int particao(int vetor[], int p, int r)
{
    int pivo, i, j;
    pivo = vetor[(p+r)/2];
    i = p-1;
    j = r+1;

    while(i < j)
    {
        do
        {
            j--;
        } while (vetor[j] > pivo);

        do
        {
            i++;
        } while (vetor[i] < pivo);
        
        if(i < j)
            troca(vetor, i, j);
    }

    return j;
}

void quickSort(int vetor[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = particao(vetor, p, r);
        quickSort(vetor, p, q);
        quickSort(vetor, q+1, r);
    }
}

void imprimirTempo(float tBubble, float tInsertion, float tQuick)
{
    cout << "Bubble Sort: " << tBubble << " segundos" << endl;
    cout << "Insertion Sort: " << tInsertion << " segundos" << endl;
    cout << "Quick Sort: " << tQuick << " segundos" << endl;
}

int main()
{
    int vet[MAX], i;
    int vetBubble[MAX], vetInsertion[MAX], vetQuick[MAX];
    float tempoBubble, tempoInsertion, tempoQuick;
    
    clock_t comeco, fim;
    cabecalho();
    srand(time(NULL));

    /*preenchimento do vetor de tamanho 1 até 10000
    com numeros aleatorios*/
    for(i=0; i<MAX; i++)
        vet[i] = rand() % MAX + 1;

    /*copiando os dados do vetor
    para tres vetores sem alterar o original*/
    for(i=0; i<MAX; i++)
    {
        vetBubble[i] = vet[i];
        vetInsertion[i] = vet[i];
        vetQuick[i] = vet[i];
    }

    comeco = clock();
    bubbleSort(vetBubble, MAX);
    fim = clock();
    tempoBubble = ((float) (fim - comeco)) / CLOCKS_PER_SEC;

    comeco = clock();
    insertionSort(vetInsertion, MAX);
    fim = clock();
    tempoInsertion = ((float) (fim - comeco)) / CLOCKS_PER_SEC;

    comeco = clock();
    quickSort(vetQuick, 0, MAX-1);
    fim = clock();
    tempoQuick = ((float) (fim - comeco)) / CLOCKS_PER_SEC;

    imprimirTempo(tempoBubble, tempoInsertion, tempoQuick);

    return 0;
}
