#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    int capacity;
    cin >> capacity;
    int k[n + 1][capacity + 1];
    int p[n + 1] = {0}, w[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the weight of object" << i << ":";
        cin >> w[i];
        cout << "Enter the value of object" << i << ":";
        cin >> p[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            k[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j < w[i])
            {
                k[i][j] = k[i - 1][j];
            }
            else
                k[i][j] = max(k[i - 1][j], p[i] + k[i - 1][j - w[i]]);
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= capacity; j++)
            {
                cout << k[i][j] << " ";
            }
            cout << endl;
        }
    }
}
