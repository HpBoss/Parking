#include<graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640,480);//����һ��640*480��ͼ�񴰿�
	//x,yΪ��ǰλ�����꣬dx,dyΪ��ǰ�ٶȣ�rΪԲ�뾶����
	int x=70,y = 0, dx = 2,dy=1, r = 30;
	//is_run���ͼ�λ����ڼ�������
	for ( ; is_run(); delay_fps(30) )
	{
		if(y<=50)
		{y=y+dy;}
		else if(y>50&&y<=(250+r))
		{// ��ǰλ�� + �ٶ�
			x = x+ dx;
			y = y+ dy;
		}
		else if(y>(250+r)&&y<=460+r) 
		{y=y+dy;}
		else if(y>460+r)
		{x=70;y=0;}
		
		//ͼ�θ���
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