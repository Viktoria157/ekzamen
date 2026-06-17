#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cout << "Vvedit kilkist ryadkiv: ";
    cin >> n;

    cout << "Vvedit kilkist stovpciv: ";
    cin >> m;

    int a[100][100];

    cout << "\nVvedit elementy matrici:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "\nPochatkova matrica:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    long long product = 1;
    bool found = false;

    int minSize;

    if (n < m)
        minSize = n;
    else
        minSize = m;

    for (int i = 0; i < minSize; i++)
    {
        if (a[i][i] < 0)
        {
            product *= a[i][i];
            found = true;
        }
    }

    if (!found)
        product = 0;

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                if ((j + 1) % 2 == 0)
                {
                    if (a[i][j] < a[k][j])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
                else
                {
                    if (a[i][j] > a[k][j])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
    }

    cout << "\nVidsortovana matrica:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nDobutok vidyemnyh elementiv golovnoyi diagonali = "
        << product << endl;

    return 0;
}