#include <iostream>
using namespace std;
int main()
{
    string one = "#";
    string two = "^";
    cout << "Enter the first word: ";
    string temp = "";
    getline(cin, temp);
    one = one + temp;
    temp = "";
    cout << "Enter the second word: ";
    getline(cin, temp);
    two = two + temp;
    int m = one.length();
    int n = two.length();
    int length[m][n] = {0};
    char sign[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            length[i][j] = 0;
            sign[i][j] = 'X';
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (one[i] == two[j])
            {
                length[i][j] = 1 + length[i - 1][j - 1];
                sign[i][j] = 'D';
            }
            else
            {
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);

                if (length[i - 1][j] == length[i][j - 1])
                {
                    sign[i][j] = 'U';
                }
                else if (length[i][j] == length[i - 1][j])
                {
                    sign[i][j] = 'U';
                }
                else
                {
                    sign[i][j] = 'L';
                }
            }
        }
    }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << length[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << sign[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int i = m - 1;
    int j = n - 1;
    string ans="";
    while (true)
    {
        if (i == 0 || j == 0)
        {
            break;
        }
        if (sign[i][j] == 'L')
        {
            j = j - 1;
        }
        else if (sign[i][j] == 'U')
        {
            i = i - 1;
        }
        else if (sign[i][j] == 'D')
        {
            ans+=one[i];
            i = i - 1;
            j = j - 1;
            
        }
    }
    for(int i=0,j=ans.length()-1;i<j;i++,j--)
    {
        char z=ans[i];
        ans[i]=ans[j];
        ans[j]=z;
    }
    cout<<"Length of LCS is "<<ans.length();
    cout<<" and LCS is "<<ans;
}