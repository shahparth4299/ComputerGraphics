#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void drawline(int x1,int y1,int x2,int y2)
{
	int xinc,yinc,dx,dy,x,y,d;
	if(x1 < x2)
		xinc = 1;
	else
		xinc = -1;
	if(y1 < y2)
		yinc = 1;
	else
		yinc = -1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	putpixel(x,y,WHITE);
	if(dx >= dy)
	{
		d = (2 * dy) - dx;
		while(x != x2)
		{
		if(d < 0)
			d += 2 * dy;
		else
		{
			d += 2 * (dy - dx);
			y += yinc;
		}
		x+=xinc;
		putpixel(x,y,WHITE);
		}

	}
	else
	{
		d = 2 * dx;
		while(y != y2)
		{
			if(d < 0)
				d += 2 * dx;
			else
			{
				d += 2 * (dx - dy);
				x += xinc;
			}
			y += yinc;
			putpixel(x,y,WHITE);
		}
	}

}
void floodcolor(int x,int y,int ncolor,int o)
{
	if(getpixel(x,y) == o)
	{
		putpixel(x,y,ncolor);
		floodcolor(x+1,y,ncolor,o);
		floodcolor(x-1,y,ncolor,o);
		floodcolor(x,y+1,ncolor,o);
		floodcolor(x,y-1,ncolor,o);
		floodcolor(x-1,y-1,ncolor,o);
		floodcolor(x-1,y+1,ncolor,o);
		floodcolor(x+1,y-1,ncolor,o);
		floodcolor(x+1,y+1,ncolor,o);
	}
}
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int x1,y1,x2,y2;
	//cin>>x1>>y1>>x2>>y2;
	//drawline(x1,y1,x2,y2);
	drawline(100,200,500,200);
	drawline(500,200,500,400);
	drawline(500,400,100,400);
	drawline(100,400,100,200);
	drawline(100,200,150,150);
	drawline(150,150,200,200);
	drawline(150,150,500,150);
	drawline(500,150,500,200);
	drawline(200,200,200,400);
	int n = getpixel(112,170);
	floodcolor(112,170,4,n);
	getch();
	closegraph();
}