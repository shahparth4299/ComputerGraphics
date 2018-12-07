#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3/BGI");
	circle(300,0,30);
	int j=0,k=0,i=0;
	while(!kbhit())
	{
		if(i < 400)
		{
			circle(300,0+j,30);
			j += 10;
		}
		else
		{
			circle(300,400-k,30);
			k += 10;
		}
		if(i == 780)
			i=j=k=0;
		i = i+10;
		delay(100);
		cleardevice();
	}
	getch();
	closegraph();
}