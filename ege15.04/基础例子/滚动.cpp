#include<graphics.h>
#include <stdio.h>
int main()
{
	initgraph(640,480);//����һ��640*480��ͼ�񴰿�
	//x,yΪ��ǰλ�����꣬dx,dyΪ��ǰ�ٶȣ�rΪԲ�뾶����
	int x=70,y = 50, dx = 2,dy=1, r = 30;
	//is_run���ͼ�λ����ڼ�������
	for ( ; is_run(); delay_fps(30) )
	{
		// ��ǰλ�� + �ٶ�
		x = x+ dx;
		y = (y+ dy);
		if(x>470+r) {x=70;y=50;}
		//ͼ�θ���
		cleardevice();
		setcolor(YELLOW);//����������ɫ
		setlinewidth(2);//�����߿�
		line(60,80,500,300);//����
		setfillcolor(BLUE);//���������ɫ
		fillellipse(x, y, r, r);//��Բ����亯��
		
	}

	getch();
	closegraph();
	return 0;
}