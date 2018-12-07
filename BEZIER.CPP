#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
int factorial(int n)
{
	if(n == 1 || n == 0)
		return 1;
	else
		return n*factorial(n-1);
}
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	int i,j,deg,x[5],y[5];
	float u,p1,p2;
	cout<<"Enter the degree"<<endl;
	cin>>deg;
	for(i = 0 ; i < deg+1 ; i++)
	{
		cout<<"Enter x and y"<<endl;
		cin>>x[i]>>y[i];
	}
	float b;
	for(u = 0.0001; u < 1 ; u+=0.0001)
	{
		p1 = 0;
		p2 = 0;
		for(j=0;j<deg+1;j++)
		{
			b=factorial(deg)*pow(u,j)*pow((1-u),(deg-j));
			b=b/(factorial(j)*factorial(deg-j));
			p1 = p1 + b * x[j];
			p2 = p2 + b * y[j];
		}
		putpixel((int)p1,(int)p2,WHITE);
	}
	getch();
	closegraph();
}