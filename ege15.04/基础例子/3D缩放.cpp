#include<graphics.h>
int main()
{
	initgraph(500,500);
	setcolor(YELLOW);
	//setfillstyle(1,GREEN);
	setfillcolor(EGERGB( 0xFF, 0xFF, 0x00 ));
	int i=0,j=0;
	for(;is_run;delay_fps(10))
	{
		if(j==0)
		{
			i++;
			cleardevice();
			bar3d(4*i+100,4*i+100,300,300,50-i,1);
			if(i==50){j=1;}
		}
		if(j==1)
		{
			i--;
			cleardevice();
			bar3d(100+4*i,100+4*i,300,300,50-i,1);
			if(i==0){j=0;}
		}
	}
	getch();
	closegraph();
	return 0;
}


