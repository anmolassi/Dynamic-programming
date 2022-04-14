#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of matrices you want to enter: ";
    cin>>n;
    int dimen[n+1];
    int mat[n+1][n+1]={0};
    int kv[n+1][n+1]={0};
    int j;
    cout<<"Enter the size of the matrices: ";
    for(int i=0;i<n+1;i++)
    {
        cin>>dimen[i];
    }
    for(int l=2;l<n+1;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            mat[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=mat[i][k]+mat[k+1][j]+dimen[i-1]*dimen[k]*dimen[j];
                if(q<mat[i][j])
                {
                    mat[i][j]=q;
                    kv[i][j]=k;
                }
            }
        }
    }
    cout<<"Number of steps required : ";
    cout<<mat[1][n]<<endl;
}