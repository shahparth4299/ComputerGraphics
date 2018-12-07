#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
	clrscr();
	int j=0,gd=DETECT,gm,n,i,shape[10][10];
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	cout<<"How many points you want to enter?"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter x"<<i<<" y"<<i<<":";
		cin>>shape[i][j]>>shape[i][j+1];
	}
	int tx,ty;
	//shape
	int k,m;
	i=j=k=m=0;
	for(i=0;i<n;i++)
	{
		if(i != n-1)
		{
			line(shape[i][j],shape[i][j+1],shape[i+1][j],shape[i+1][j+1]);
		}
		else
			line(shape[i][j],shape[i][j+1],shape[k][m],shape[k][m+1]);
	}
	cout<<"Enter tx and ty"<<endl;
	cin>>tx>>ty;
	if(n > 2)
	{
	int trans[10][10],sum=0,mul[10][10];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j  > 1)
			{
				shape[i][j] = 1;
			}
			if(i != j)
				trans[i][j] =  0;
			else
				trans[i][j] = 1;
			cout<<trans[i][j]<<" ";
		}
		cout<<endl;
	}
	trans[n-1][0] = tx;
	trans[n-1][1] = ty;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<n;k++)
			{
				sum += shape[i][k] * trans[k][j];
			}
			mul[i][j] = sum;
			cout<<mul[i][j]<<" ";
		}
		cout<<endl;
	}
	i=j=k=m=0;
	for(i=0;i<n;i++)
	{
		if(i != n-1)
		{
			line(mul[i][j],mul[i][j+1],mul[i+1][j],mul[i+1][j+1]);
		}
		else
			line(mul[i][j],mul[i][j+1],mul[k][m],mul[k][m+1]);
	}
	}
	else
		cout<<"Select more than 3 points"<<endl;
	getch();
	cleardevice();
}