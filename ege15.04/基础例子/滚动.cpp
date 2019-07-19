#include<graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640,480);//建立一个640*480的图像窗口
	//x,y为当前位置坐标，dx,dy为当前速度，r为圆半径长度
	int x=70,y = 50, dx = 2,dy=1, r = 30;
	//is_run检测图形化窗口继续运行
	for ( ; is_run(); delay_fps(30) )
	{
		// 当前位置 + 速度
		x = x+ dx;
		y = (y+ dy);
		if(x>470+r) {x=70;y=50;}
		//图形更新
		cleardevice();
		setcolor(YELLOW);//设置线条颜色
		setlinewidth(2);//设置线宽
		line(60,80,500,300);//画线
		setfillcolor(BLUE);//设置填充颜色
		fillellipse(x, y, r, r);//椭圆形填充函数
		
	}

	getch();
	closegraph();
	return 0;
}