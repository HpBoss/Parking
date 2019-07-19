#include<graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640,480);//建立一个640*480的图像窗口
	//x,y为当前位置坐标，dx,dy为当前速度，r为圆半径长度
	int x=70,y = 0, dx = 2,dy=1, r = 30;
	//is_run检测图形化窗口继续运行
	for ( ; is_run(); delay_fps(30) )
	{
		if(y<=50)
		{y=y+dy;}
		else if(y>50&&y<=(250+r))
		{// 当前位置 + 速度
			x = x+ dx;
			y = y+ dy;
		}
		else if(y>(250+r)&&y<=460+r) 
		{y=y+dy;}
		else if(y>460+r)
		{x=70;y=0;}
		
		//图形更新
		cleardevice();
		setcolor(YELLOW);
		setlinewidth(2);
		line(60,80,500,300);
		setfillcolor(BLUE);
		fillellipse(x, y, r, r);
		
	}

	getch();
	closegraph();
	return 0;
}