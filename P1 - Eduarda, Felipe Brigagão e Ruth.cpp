#include <iostream>

using namespace std;

/* faça uma sub-rotina que receba um valor inteiro e verifique se ele é positivo ou negativo
 Exercício 5 da página 298 do livro "Fundamentos da programação de computadores" */

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

