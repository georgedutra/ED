#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int find1sDivisor(int n)
{
    bool achei = false;
    long long int lliMult = 1; 
    int iNum = 1;

    while (achei == false)
    {
        lliMult = lliMult + (pow(10,iNum));
        iNum++;
        if (lliMult % n == 0) achei = true;
        else if (iNum >= 20) 
        {
            cout << "\nO múltiplo tem mais de [20] 1's :O\n";
            break;
        }
    } 
    return iNum;
}
/*
int main()
{
    int iValue;
    cout << "De qual número você quer um múltiplo só de uns?" << endl;
    cin >> iValue;
     cout << "Seu número tem um múltiplo com " << find1sDivisor(iValue) << " 1's" << endl;

    return 0;
}
*/