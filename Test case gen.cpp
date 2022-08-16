#include <bits/stdc++.h>
#include<algorithm>
#include <cmath>

int lastopen(char str [100], int i)
{
    
    int last=-1, t1=0,t2=0; 
    for (int j = i-1; j >=0; j--)
    {
        if(str[j]==')')   t1++;
        if(str[j]=='}')   t2++;
        if(str[j]=='{')
        {
            if(t2==0)   {last=1;break;}
            else t2--;
        }
        if(str[j]=='(')
        {
            if(t1==0)   {last=0;break;}
            else t1--;
        }
    }
    return last;
}

void balanced (char str [100] , int n ,int m, int o , int c ,int oa , int ca , int i ){
    if (i==2*n+2*m){
        str[2*n+2*m]='\0';
        printf("%s\n",str);
        return ;
    }

    
    
    if (o < n ) {
        str[i]='(';
        balanced ( str , n ,m,  o+1 , c ,oa,ca, i+1);
    }
    if(c<o && lastopen(str,i)!=1){
        str[i]=')';
        balanced (str , n ,m, o , c+1 ,oa,ca, i+1);
    }
    if (oa < m ) {
        str[i]='{';
        balanced ( str , n ,m,  o , c ,oa+1,ca, i+1);
    }
    if(ca<oa && lastopen(str,i)!=0){
        str[i]='}';
        balanced (str , n ,m, o , c ,oa,ca+1, i+1);
    }



}

void ans (int n,int m )
{
    //  Insert your code here.
    int  i =0 ;
   // scanf("%d %d",&n,&m);
   printf("Test case \n");
    char str [2*n+2*m+1];
    balanced(str , n, m, 0, 0 ,0 ,0, i);
    //return 0;
}
int main (){
	int t;
	t=8;
	int a=0,b=0;
	for (int i =0 ; i<t;i++){
		if (i%2)a++;
		else b++;
		ans(a,b);
	}
}