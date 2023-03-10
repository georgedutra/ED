#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// Questão 1:
/*
int main()
{
    int iInicio, iFim;
    cin >> iInicio >> iFim;

    if (iInicio < iFim)
    {
        cout << "O JOGO DUROU " << iFim - iInicio << " HORA(S)" << endl;
    }
    else if (iInicio > iFim)
    {
        cout << "O JOGO DUROU " << 24 - iInicio + iFim << " HORA(S)" << endl;
    }
    else
    {
        cout << "O JOGO DUROU 24 HORA(S)" << endl;
    };

    return 0;
}
*/

// Questão 2
/*
int main()
{
    float fA, fB, fC;
    cin >> fA >> fB >> fC;

    float iDelta = pow(fB, 2) - (4 * fA * fC);

    if (iDelta < 0)
    {
        cout << "\nImpossível calcular" << endl;
    }
    else if (iDelta == 0)
    {
        cout << "Raiz = " << -fB / (2 * fA)  << endl;
    }
    else
    {
        cout << "Raiz 1 = " << ( -fB + sqrt(iDelta))/(2 * fA) << "\nRaiz 2 = " << ( - fB - sqrt(iDelta))/(2 * fA) << endl;
    };

    return 0;
}
*/

// Questão 3

int main()
{
    float fA, fB, fC;
    cin >> fA >> fB >> fC;

    float iDelta = pow(fB, 2) - (4 * fA * fC);

    if (iDelta < 0)
    {
        cout << "Raiz 1 = " << -fB / (2 * fA) << " + " << sqrt(abs(iDelta))/ (2*fA) << "i"
        << "\nRaiz 2 = " << -fB / (2 * fA) << " - " << sqrt(abs(iDelta))/ (2*fA) << "i" << endl;
    }
    else if (iDelta == 0)
    {
        cout << "Raiz = " << -fB / (2 * fA)  << endl;
    }
    else
    {
        cout << "Raiz 1 = " << ( -fB + sqrt(iDelta))/(2 * fA) << "\nRaiz 2 = " << ( - fB - sqrt(iDelta))/(2 * fA) << endl;
    };

    return 0;
}