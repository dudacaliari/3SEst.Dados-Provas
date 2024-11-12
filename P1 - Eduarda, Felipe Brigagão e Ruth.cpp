#include <iostream>

using namespace std;

/* fa�a uma sub-rotina que receba um valor inteiro e verifique se ele � positivo ou negativo
 Exerc�cio 5 da p�gina 298 do livro "Fundamentos da programa��o de computadores" */

void verificaNumero(int numero)
{
    if (numero > 0)
    {
        cout << "O numero " << numero << " eh positivo" << endl;
    }
    else if (numero == 0)
    {
        cout << "O numero " << numero << " eh neutro" << endl;
    }
    else
    {
        cout << "O numero " << numero << " eh negativo" << endl;
    }
}

int main()
{
    cout << "================================" << endl;
    cout << "||                            ||" << endl;
    cout << "||   Verificador de numeros   ||" << endl;
    cout << "||                            ||" << endl;
    cout << "================================" << endl;
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;
    verificaNumero(numero);
    return 0;
}

