//ʹ��IMAGE����ץͼ���滭��IMAGE��IMAGE����Ļ
//IMAGE�����൱��һ����ͼ�壬��ͬʱҲ������ΪͼƬ��������IMAGE��
//����һ���ǳ����Ķ��󣬸��ӵĻ�ͼ��Ҫ����IMAGE���Ա���õر�������ͼ��
#include <graphics.h>
int main()
{ 
int x=0;
int y=0,x1=-16,x2=450,y1=350;
//����һ��imgͼƬ����, ָ������. point image. 
PIMAGE img,img2; 
initgraph(640, 480);
setbkcolor(EGERGB(205,132,213)); //���ñ�����ɫ 
img = newimage();
img2= newimage();
getimage(img,"MARIO.JPG",0,0); 
getimage(img2,"d.png",0,0); 
//�õ�һ��ͼƬ������ִ��exe�ļ�ͬһ��λ��. Ҳ����ָ����(c://MARIO.BMP) 
while(1)
{
	putimage(x1+= 10,y1,31,32,img,x+=(33+2),1,31,32);
//putimage(dst x, dst y, dst with, dst high, img, 
// src x, src y, src with, src high);
//dst = destination(Ŀ��) ��Ӧ�ڴ�������
//src=source(Ŀ��Դ) ��Ӧ��ͼƬ����,��(MARIO.BMP) 
//getch(); //���Բ������� 
	delay_ms(100);
	y++; //��¼ͼƬ֡�ĸ��� 
	if(5 == y)
	{
		x=-33; //�ص�ͼƬ��ʼλ�� 
		y=0; 
	} 
	if(x1>=x2-100)
	{
		putimage(x2,260,144,196,img2,0,1,144,196);
		putimage(x1,y1,31,32,img,0,1,31,32);
		delay_ms(500);
		for(;x1<=x2+50;x1+=5)
		{
			cleardevice();
			putimage(x2,260,144,196,img2,0,1,144,196);
			putimage(x1,(350-x1)*1.2+y1,31,32,img,213,1,31,32);
			delay_ms(100);
		}
		for(;x1<=640;x1+=5)
		{
			cleardevice();
			putimage(x2,260,144,196,img2,0,1,144,196);
			putimage(x1,(x1-680)+y1,31,32,img,213,1,31,32);
			delay_ms(100);
		}
		 
		x1=-16;//�ص���Ļ��ʼλ�� 
	}
	
	// getch();
	cleardevice(); //�򵥵�����ʵ�ֲ��� 
}
getch();
delimage(img); //�ͷ��ڴ�ָ�� 
closegraph(); //�ر�ͼ�� 
return 0;
}