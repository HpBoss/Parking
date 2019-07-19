//使用IMAGE——抓图，绘画到IMAGE，IMAGE到屏幕
//IMAGE对象相当于一个绘图板，而同时也可以作为图片画到其它IMAGE上
//它是一个非常灵活的对象，复杂的绘图都要借助IMAGE，以便更好地保存和输出图像
#include <graphics.h>
int main()
{ 
int x=0;
int y=0,x1=-16,x2=450,y1=350;
//声明一个img图片对象, 指针类型. point image. 
PIMAGE img,img2; 
initgraph(640, 480);
setbkcolor(EGERGB(205,132,213)); //设置背景颜色 
img = newimage();
img2= newimage();
getimage(img,"MARIO.JPG",0,0); 
getimage(img2,"d.png",0,0); 
//得到一个图片，放在执行exe文件同一个位置. 也可以指定如(c://MARIO.BMP) 
while(1)
{
	putimage(x1+= 10,y1,31,32,img,x+=(33+2),1,31,32);
//putimage(dst x, dst y, dst with, dst high, img, 
// src x, src y, src with, src high);
//dst = destination(目标) 对应于窗口坐标
//src=source(目标源) 对应于图片坐标,如(MARIO.BMP) 
//getch(); //可以步进调试 
	delay_ms(100);
	y++; //记录图片帧的个数 
	if(5 == y)
	{
		x=-33; //回到图片起始位置 
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
		 
		x1=-16;//回到屏幕起始位置 
	}
	
	// getch();
	cleardevice(); //简单的清屏实现擦除 
}
getch();
delimage(img); //释放内存指针 
closegraph(); //关闭图形 
return 0;
}