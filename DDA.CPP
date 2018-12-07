#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	int x,y,x1,y1,x2,y2,dx,dy,xinc,yinc,len;
	cin>>x1>>y1>>x2>>y2;
	dx = x2 - x1;
	dy = y2 - y1;
	if(abs(dx) > abs(dy))
		len = abs(dx);
	else
		len = abs(dy);
	x = x1;
	y = y1;
	xinc = dx / len;
	yinc = dy / len;
	while(len > 0)
	{
		putpixel(x,y,WHITE);
		x = xinc + x;
		y = yinc + y;
		len--;

	}
	getch();
	closegraph();
}