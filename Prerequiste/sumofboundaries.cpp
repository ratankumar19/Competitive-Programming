#include<bits/stdc++.h>
using namespace std;
int get_boundary(int m,int **a)
{
    int sum=0;
    
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<m;j++)
          {
              if(i==0)
                  sum+=a[i][j];
              else if(i==m-1)
                   sum+=a[i][j];
             else if(j==0)
                  sum+=a[i][j];
              else if(j==m-1)
                   sum+=a[i][j];
        
          }
     }
    int esum=sum-(a[0][0]+a[m-1][0]+a[0][m-1]+a[m-1][m-1]);
    return esum;
   
    
}
    int diagonal(int p,int **b)
    {
    int sum1=0;
    int sum2=0;
    int tsum;
       
        
     for(int i=0;i<p;i++)
     {
          for(int j=0;j<p;j++)
          {
              if(i==j)
		{
                 
		 sum1+=b[i][j];
		}
              if(i+j==(p-1))
              {
                 sum2+=b[i][j];
              }
          }
     }

	if(p%2!=0)
	{
           tsum=sum1+sum2-b[p/2][p/2];
	}	
        else
    {
		tsum=sum1+sum2;
    }
		
return tsum;
              
}
int main()
{
    int n;

    cin>>n;


    int **arr=new int *[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    
    for(int j=0;j<n;j++)
    {
    cin>>arr[i][j];
    }
   
    }
    int sum_boundary,sum_diagonal;
    sum_boundary=get_boundary(n,arr);
    
     sum_diagonal=diagonal(n,arr);
    
    cout<<sum_diagonal+sum_boundary<<endl;

    
    
	return 0;
}

