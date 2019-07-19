//彩色时钟

/*电子时钟源代码*/
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<time.h>

#define PI 3.1415926 /*定义常量*/
//#define UP 0x4800   /*上移↑键：修改时间*/
//#define DOWN 0x5000 /*下移↓键：修改时间*/
//#define ESC 0x11b   /*ESC键 ： 退出系统*/
//#define TAB 0xf09   /*TAB键 ： 移动光标*/


/*函数声明*/
//int keyhandle(int,int); /*键盘按键判断，并调用相关函数处理*/
//int timeupchange(int);  /*处理上移按键*/
//int timedownchange(int); /*处理下移按键*/
int digithour(double); /*将double型的小时数转换成int型*/
int digitmin(double);  /*将double型的分钟数转换成int型*/
int digitsec(double);   /*将double型的秒钟数转换成int型*/
void digitclock(int,int,int ); /*在指定位置显示时钟或分钟或秒钟数*/
void drawcursor(int); /*绘制一个光标*/
void clearcursor(int);/*消除前一个光标*/
void clockhandle(); /*时钟处理*/

double h,m,s; /*全局变量:小时，分，秒*/
double hh,mm,ss; /*全局过渡变量:小时，分，秒*/

double x,xx1,xx2,y,yy1,yy2; /*全局变量:坐标值*/
double 	o_x,o_y,o_xx1,o_yy1,o_xx2,o_yy2;
struct tm *timeinfo;/*定义一个time结构类型的数组*/
time_t rawtime;

int main()
{
	int mode=0,i,j;

	time(&rawtime);
	timeinfo = localtime ( &rawtime );///取得系统时间,保存在time结构类型的数组变量中


//	printf ( "\007The current date/time is: %s", asctime (timeinfo) );
	initgraph(640,480);
	// driver=DETECT; /*自动检测显示设备*/
	// initgraph(&driver, &mode, "");/*初始化图形系统*/
	setlinestyle(0,0,3); /*设置当前画线宽度和类型:设置三点宽实线*/
	setbkcolor(BLACK);/*用调色板设置当前背景颜色*/

	//******************************************************************************************************
	

	//设置画图颜色，使用RGB宏，三个参数值的范围均为0 - 255 (0xFF)
	//分别表示红色亮度，绿色亮度，蓝色亮度
	//EGERGB(0xFF, 0x0, 0x0) (纯红色) 等价于0xFF0000
// 	setcolor(EGERGB(0xFF, 0x0, 0x0));
//	circle(200, 200, 100);
//	setcolor(YELLOW);
//	line(100, 100, 200, 200);//设置当前画线颜色
	setcolor(GREEN);//画主体框架的边直线
	line(82,430,558,430);
	line(70,62,70,418);
	line(82,50,558,50);
	line(570,62,570,418);
	line(70,62,570,62);
	line(76,56,297,56);
	line(340,56,564,56);

	//画圆弧arc(int x, int y, int stangle, int endangle, int radius)
	arc(82,62,90,180,12);
	arc(558,62,0,90,12);
	setlinestyle(0,0,3);
	arc(82,418,180,279,12);
	setlinestyle(0,0,3);
	arc(558,418,270,360,12);
	
	
	setcolor(15);
	outtextxy(300,53,"CLOCK"); //显示标题
	setcolor(LIGHTRED);
	rectangle(342,72,560,360); //画一个矩形,作为时钟的框架

	setwritemode(0); //规定画线的方式。mode=0, 则表示画线时将所画位置的原来信息覆盖
	setcolor(YELLOW);
	outtextxy(433,75,"CLOCK");//时钟的标题
	setcolor(BROWN);
	line(392,310,510,310);
	line(392,330,510,330);
	arc(392,320,90,270,10);
	arc(510,320,270,90,10); //绘制电子动画时钟下的数字时钟的边框架
	//绘制数字时钟的时分秒的分隔符
	setcolor(RED);
	for(i=431;i<=470;i+=39){
		for(j=317;j<=324;j+=7){
			setlinestyle(0,0,3);
			circle(i,j,1); //以(i, y)为圆心,1为半径画圆
		}
	}
	setfillcolor(BLUE);
	line(424,315,424,325); //在运行电子时钟前先画一个光标
	//绘制表示小时的圆点
	for(i=0,m=0,h=0;i<=11;i++,h++){
		x=100*sin((h*60+m)/360*PI)+451;
		y=200-100*cos((h*60+m)/360*PI);
		setlinestyle(0,0,3);
		circlef(float(x),float(y),4);
	}
	//绘制表示分钟或秒钟的圆点
	setfillcolor(LIGHTMAGENTA); 
	for(i=0,m=0;i<=59;m++,i++){
		x=100*sin(m/30*PI)+451;
		y=200-100*cos(m/30*PI);
		setlinestyle(0,0,1);
		circlef(float(x),float(y),2);
	}
	//在电子表的左边打印帮助提示信息
	setcolor(CYAN);
	outtextxy(170,85,"简易版时钟");
	setcolor(MAGENTA);

	outtextxy(140,145,"C 语言程序设计课程");
	outtextxy(140,185,"姓名： ");
	outtextxy(140,225,"班级： ");
	outtextxy(140,265,"学号： ");
	outtextxy(140,325,"Version : 1.0");
	setcolor(LIGHTCYAN);
	outtextxy(170,400,"Nothing is more important than time!");

	while(1){
		clockhandle();/*开始调用时钟处理程序*/
	}
	closegraph(); /*关闭图形系统*/
	return 0; /*表示程序正常结束,向操作系统返回一个0值*/
	}
	//******************************************************************************************************



// /**/
   /*画主体框架的边角弧线*/

//
//
//

//
void clockhandle()
{
	int k=0;
	setcolor(YELLOW);

	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	h=timeinfo[0].tm_hour;
	m=timeinfo[0].tm_min;
	s=timeinfo[0].tm_sec;

	x=50*sin((h*60+m)/360*PI)+451; /*时针的x坐标值*/
	y=200-50*cos((h*60+m)/360*PI); /*时针的y坐标值*/
	line_f(451,200,float(x),float(y));/*在电子表中绘制时针*/

	xx1=80*sin(m/30*PI)+451; /*分针的x坐标值*/
	yy1=200-80*cos(m/30*PI); /*分针的y坐标值*/
	line_f(451,200,float(xx1),float(yy1)); /*在电子表中绘制分针*/

	digitclock(400,312,digithour(h)); /*在数字时钟中，显示当前的小时值*/
	digitclock(444,312,digitmin(m)); /*在数字时钟中，显示当前的分钟值*/
	digitclock(490,312,digitsec(s)); /*在数字时钟中，显示当前的秒值*/
	setwritemode(1);
 /*规定画线的方式,如果mode=1,则表示画线时用现在特性的线
与所画之处原有的线进行异或(XOR)操作,实际上画出的线是原有线与现在规定
的线进行异或后的结果。因此, 当线的特性不变, 进行两次画线操作相当于没有 
画线，即在当前位置处清除了原来的画线*/

//		setcolor(YELLOW);/*淡红色*/



		xx2=98*sin(s/30*PI)+451; /*秒针的x坐标值*/
		yy2=200-98*cos(s/30*PI); /*秒针的y坐标值*/
		line_f(451,200,float(xx2),float(yy2));

		o_xx2=xx2;
		o_yy2=yy2;
		/*绘制秒针*/
		delay(30);

		setcolor(BLACK); 
		xx2=98*sin(s/30*PI)+451;
		yy2=200-98*cos(s/30*PI);
		line_f(451,200,float(xx2),float(yy2));
		digitclock(490,312,digitsec(s));

  /*用原来的颜色在原来位置处再绘制秒针，以达到清除当前秒针的目的*/
		setcolor(WHITE);
		digitclock(490,312,digitsec(s)+1);/*数字时钟增加１秒*/



   /*分钟处理*/
		if(m!=mm){ /*若分钟有变化*/
         /*消除当前分针*/
			setcolor(BLACK); /*白色15*/
			xx1=80*sin(m/30*PI)+451;
			yy1=200-80*cos(m/30*PI);
			line_f(451,200,float(o_xx1),float(o_yy1));
         /*绘制新的分针*/
			m=timeinfo[0].tm_min;
			digitclock(444,312,digitmin(m)); /*在数字时钟中显示新的分钟值*/
			xx1=80*sin(m/30*PI)+451;
			yy1=200-80*cos(m/30*PI);
			line_f(451,200,float(xx1),float(yy1));
		}
//
  /*小时处理*/
		if((h*60+m)!=(hh*60+mm)){  /*若小时数有变化*/
         /*消除当前时针*/
			setcolor(BLACK); /*白色15*/
			x=50*sin((h*60+m)/360*PI)+451;/*50:时钟的长度（单位：像素），451:圆心的x坐标值*/
			y=200-50*cos((h*60+m)/360*PI);
			line_f(451,200,float(o_x),float(o_y));
          /*绘制新的时针*/
			h=timeinfo[0].tm_hour;
			digitclock(400,312,digithour(h));
			x=50*sin((h*60+m)/360*PI)+451;
			y=200-50*cos((h*60+m)/360*PI);
			line_f(451,200,float(x),float(y));
		}

		ss=s;
		mm=m;
		hh=h;
		o_x=x;
		o_y=y;
		o_xx1=xx1;
		o_yy1=yy1;
	

}



////
//int keyhandle(int key,int count)   /*键盘控制 */
//{ 
//	switch(key)
//	{
//		case UP: timeupchange(count-1); /*因为count的初始值为２，所以此处减１*/
//			break;
//		case DOWN:timedownchange(count-1); /*因为count的初始值为２，所以此处减１*/
//			break;
//		case TAB:setcolor(WHITE);
//			clearcursor(count); /*清除原来的光标*/
//			drawcursor(count);  /*显示一个新的光标*/
//			count++;
//			break;
//  }
//  return count;
// }
//
//int timeupchange(int count) /*处理光标上移的按键*/
//{
//     if(count==1){
//        timeinfo[0].tm_hour++;
//        if(timeinfo[0].tm_hour==24) timeinfo[0].tm_hour=0;
//        settime(timeinfo); /*设置新的系统时间*/
//        }
//
//     if(count==2){
//        timeinfo[0].tm_min++;
//        if(timeinfo[0].tm_min==60) timeinfo[0].tm_min=0;
//        settime(timeinfo); /*设置新的系统时间*/
//        }
//
//    if(count==3){
//        timeinfo[0].tm_sec++;
//        if(timeinfo[0].tm_sec==60) timeinfo[0].tm_sec=0;
//        settime(timeinfo); /*设置新的系统时间*/
//        }
// }
//
//int timedownchange(int count) /*处理光标下移的按键*/
//{
//   if(count==1) {
//        timeinfo[0].tm_hour--;
//        if(timeinfo[0].tm_hour==0) timeinfo[0].tm_hour=23;
//        settime(timeinfo);/*设置新的系统时间*/
//        }
//   if(count==2) {
//        timeinfo[0].tm_min--;
//        if(timeinfo[0].tm_min==0)timeinfo[0].tm_min=59;
//        settime(timeinfo);/*设置新的系统时间*/
//        }
//
//  if(count==3) {
//        timeinfo[0].tm_sec--;
//        if(timeinfo[0].tm_sec==0) timeinfo[0].tm_sec=59;
//        settime(timeinfo);/*设置新的系统时间*/
//        }
// }
//
//SetLocalTime()
 
int digithour(double h)/*将double型的小时数转换成int型*/
{	
	int i;
	for(i=0;i<=23;i++)
	{
		if(h==i) 
			break;
	}
	return i;
}

int digitmin(double m)/*将double型的分钟数转换成int型*/
{
	int i;
	for(i=0;i<=59;i++)
	{	
		if(m==i) 
			break;	
	}
	return i;
}
//
int digitsec(double s) /*将double型的秒钟数转换成int型*/
{
	int i;
	for(i=0;i<=59;i++)
		{	if(s==i) break;}
	return i;
}
//
//
void digitclock(int x,int y,int clock)/*在指定位置显示数字时钟:时\分\秒*/
{
	char buffer1[10];
	setfillstyle(0,2);
	bar(x,y,x+15,328);
	if(clock==60) {	clock=0;}
	sprintf(buffer1,"%d",clock);
	outtextxy(x,y,buffer1);
 }
////
//void drawcursor(int count)    /*根据count的值，画一个光标*/
//{
//	switch(count)
//	{
//		case 1:line(424,315,424,325);break;
//		case 2:line(465,315,465,325);break;
//		case 3:line(505,315,505,325);break;
//	}
//}
//
//void clearcursor(int count)    /*根据count的值，清除前一个光标*/
//{
//	switch(count)
//	{
//		case 2:line(424,315,424,325);break;
//		case 3:line(465,315,465,325);break;
//		case 1:line(505,315,505,325);break;
//	}
//}
//
