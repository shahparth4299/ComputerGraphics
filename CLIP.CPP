#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
int x,y,x3,y3,x1,x2,y1,y2,xmin,xmax,ymin,ymax,p1code[4],p2code[4],fx1,fy1,fx2,fy2;
void getLine()
{
	cout<<"Enter xmin,xmax,ymin,ymax"<<endl;
	cin>>xmin>>xmax>>ymin>>ymax;
	cout<<"Enter x1,y1,x2,y2"<<endl;
	cin>>x1>>y1>>x2>>y2;
}
void setCode()
{
	for(int i=0;i<4;i++)
	{
		p1code[i] = 0;
		p2code[i] = 0;
	}
	if(y1 > ymax)//above
		p1code[0] = 1;
	if(y1 < ymin)//bottom
		p1code[1] = 1;
	if(x1 > xmax)//Right
		p1code[2] = 1;
	if(x1 < xmin)
		p1code[3] = 1;

	if(y2 > ymax)//above
		p2code[0] = 1;
	if(y2 < ymin)//bottom
		p2code[1] = 1;
	if(x2 > xmax)//Right
		p2code[2] = 1;
	if(x2 < xmin)
		p2code[3] = 1;

}
int checkVisibility()
{
	int flag = 0;
	for(int i=0;i<4;i++)
	{
		if((p1code[i]&p2code[i]) == 0)
		{
			flag++;
		}
		else
		{
			return 0;
		}
	}
	return flag;
}
void intersect_p1()
{
	if(p1code[0] == 1)
	{
		x = x1 + (y2 - y1)*(ymax - y1)/(y2 - y1);
		y = ymax;
	}
	else if(p1code[1] == 1)
	{
		x = x1 + (y2 - y1)*(ymin - y1)/(y2 - y1);
		y = ymin;
	}
	else if(p1code[2] == 1)
	{
		y = y1 + (y2 - y1)*(xmax - x1)/(x2 - x1);
		x = xmax;
	}
	else if(p1code[3] == 1)
	{
		x = xmin;
		y = y1 + (y2 - y1)*(xmin-x1)/(x2-x1);
	}
}
void intersect_p2()
{
	if(p2code[0] == 1)
	{
		x3 = x1 + (y2 - y1)*(ymax - y1)/(y2 - y1);
		y3 = ymax;
	}
	else if(p2code[1] == 1)
	{
		x3 = x1 + (y2 - y1)*(ymin - y1)/(y2 - y1);
		y3 = ymin;
	}
	else if(p2code[2] == 1)
	{
		y3 = y1 + (y2 - y1)*(xmax - x1)/(x2 - x1);
		x3 = xmax;
	}
	else if(p2code[3] == 1)
	{
		x3 = xmin;
		y3 = y1 + (y2 - y1)*(xmin-x1)/(x2-x1);
	}
}
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	getLine();
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	setCode();
	//display code
	int a;
	cout<<"Press 1 to continu"<<endl;
	cin>>a;
	cleardevice();
	int intersection = 0;
	int flag = checkVisibility();
	if(flag == 0)
	{
		cout<<"NOT VISIBLE"<<endl;
	}
	else
	{
		cout<<"PARTIALLY VISIBLE"<<endl;
		rectangle(xmin,ymin,xmax,ymax);
		intersection = 0;
		for(int i=0;i<4;i++)
		{
			if(p1code[i] == 1)
			{
				intersection = 1;
				break;
			}
		}
		if(intersection == 1)
		{
			intersect_p1();
			fx1 = x;
			fy1 = y;
		}
		else
		{
			fx1 = x1;
			fy1 = y1;
		}
		intersection = 0;
		for(i=0;i<4;i++)
		{
			if(p1code[i] == 1)
			{
				intersection = 1;
				break;
			}
		}
		if(intersection == 1)
		{
			intersect_p2();
			fx2 = x3;
			fy2 = y3;
		}
		else
		{
			fx2 = x2;
			fy2 = y2;
		}
	}
	line(fx1,fy1,fx2,fy2);
	getch();
	closegraph();
}