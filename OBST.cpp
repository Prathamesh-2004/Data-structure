//Optimal Binary Search tree
#include<iostream>
using namespace std;

float key[10],p[10],q[10],w[10][10],c[10][10],r[10][10];
int n;

void preorder(int i,int j)
{
int root=r[i][j];
if(root==0)return;
cout<<key[root]<<" ";
preorder(i,root-1);
preorder(root,j);
}

int main()
{
    cout<<"\n Enter the size: ";
    cin>>n;
    cout<<"\nEnter the keys :"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>key[i];
    }

    cout<<"\nEnter the successful Probability :"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }

    cout<<"\nEnter the unsuccessful probability :"<<endl;
    for(int i=0;i<=n;i++)
    {
        cin>>q[i];
    }

    for(int i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=0;
        r[i][i]=0;
        cout<<"w["<<i<<"]["<<i<<"]= "<<w[i][i]<<endl;
        cout<<"c["<<i<<"]["<<i<<"]= "<<c[i][i]<<" , "<<"r["<<i<<"]["<<i<<"]= "<<r[i][i]<<endl;
    }

    for(int l=1;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            cout<<"w["<<i<<"]["<<j<<"]= "<<w[i][j]<<endl;

            c[i][j]=9999;
            for(int k=i+1;k<=j;k++)
            {
               float cost=c[i][k-1]+c[k][j]+w[i][j];
               if(cost<c[i][j])
               {
                c[i][j]=cost;
                r[i][j]=k;
               }
            }
            cout<<"c["<<i<<"]["<<j<<"]= "<<c[i][j]<<" , "<<"r["<<i<<"]["<<j<<"]= "<<r[i][j]<<endl;
        }
    }
    cout<<"\nMatrix of W[i][j] :"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i<=j){
            cout<<w[i][j]<<"\t";
            }
        }
        cout<<endl;
    }

    cout<<"\nMatrix of C[i][j] :"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i<=j){
            cout<<c[i][j]<<"\t";
            }
        }
        cout<<endl;
    }

    cout<<"\nMatrix of r[i][j] :"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i<=j){
            cout<<r[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<"\nPreorder display :"<<endl;
    preorder(0,n);
    cout<<endl;

    return 0;
}
