#include <graphics.h>
int main()
{
	int x=0,y=0,i=1;
	int x1=100,x2=450,y1=100;
	PIMAGE img; 
	initgraph(640, 480);
	setbkcolor(EGERGB(100,132,113)); //…Ë÷√±≥æ∞—’…´ 
	img = newimage();
	getimage(img,"yaoming.JPG",0,0);
	putimage(x1-50,y1-50,320,400,img,1,1,160,200);
	while(1)
	{
		
		cleardevice();
		putimage(x1-50,y1-50,320-8*i,400-10*i,img,1,1,160,200);
		delay_ms(200);
		i++;
		if(i==40){i=1;}
	}
	getch();
	closegraph();
	return 0;
}