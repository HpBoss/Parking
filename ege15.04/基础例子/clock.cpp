//��ɫʱ��

/*����ʱ��Դ����*/
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<time.h>

#define PI 3.1415926 /*���峣��*/
//#define UP 0x4800   /*���ơ������޸�ʱ��*/
//#define DOWN 0x5000 /*���ơ������޸�ʱ��*/
//#define ESC 0x11b   /*ESC�� �� �˳�ϵͳ*/
//#define TAB 0xf09   /*TAB�� �� �ƶ����*/


/*��������*/
//int keyhandle(int,int); /*���̰����жϣ���������غ�������*/
//int timeupchange(int);  /*�������ư���*/
//int timedownchange(int); /*�������ư���*/
int digithour(double); /*��double�͵�Сʱ��ת����int��*/
int digitmin(double);  /*��double�͵ķ�����ת����int��*/
int digitsec(double);   /*��double�͵�������ת����int��*/
void digitclock(int,int,int ); /*��ָ��λ����ʾʱ�ӻ���ӻ�������*/
void drawcursor(int); /*����һ�����*/
void clearcursor(int);/*����ǰһ�����*/
void clockhandle(); /*ʱ�Ӵ���*/

double h,m,s; /*ȫ�ֱ���:Сʱ���֣���*/
double hh,mm,ss; /*ȫ�ֹ��ɱ���:Сʱ���֣���*/

double x,xx1,xx2,y,yy1,yy2; /*ȫ�ֱ���:����ֵ*/
double 	o_x,o_y,o_xx1,o_yy1,o_xx2,o_yy2;
struct tm *timeinfo;/*����һ��time�ṹ���͵�����*/
time_t rawtime;

int main()
{
	int mode=0,i,j;

	time(&rawtime);
	timeinfo = localtime ( &rawtime );///ȡ��ϵͳʱ��,������time�ṹ���͵����������


//	printf ( "\007The current date/time is: %s", asctime (timeinfo) );
	initgraph(640,480);
	// driver=DETECT; /*�Զ������ʾ�豸*/
	// initgraph(&driver, &mode, "");/*��ʼ��ͼ��ϵͳ*/
	setlinestyle(0,0,3); /*���õ�ǰ���߿�Ⱥ�����:���������ʵ��*/
	setbkcolor(BLACK);/*�õ�ɫ�����õ�ǰ������ɫ*/

	//******************************************************************************************************
	

	//���û�ͼ��ɫ��ʹ��RGB�꣬��������ֵ�ķ�Χ��Ϊ0 - 255 (0xFF)
	//�ֱ��ʾ��ɫ���ȣ���ɫ���ȣ���ɫ����
	//EGERGB(0xFF, 0x0, 0x0) (����ɫ) �ȼ���0xFF0000
// 	setcolor(EGERGB(0xFF, 0x0, 0x0));
//	circle(200, 200, 100);
//	setcolor(YELLOW);
//	line(100, 100, 200, 200);//���õ�ǰ������ɫ
	setcolor(GREEN);//�������ܵı�ֱ��
	line(82,430,558,430);
	line(70,62,70,418);
	line(82,50,558,50);
	line(570,62,570,418);
	line(70,62,570,62);
	line(76,56,297,56);
	line(340,56,564,56);

	//��Բ��arc(int x, int y, int stangle, int endangle, int radius)
	arc(82,62,90,180,12);
	arc(558,62,0,90,12);
	setlinestyle(0,0,3);
	arc(82,418,180,279,12);
	setlinestyle(0,0,3);
	arc(558,418,270,360,12);
	
	
	setcolor(15);
	outtextxy(300,53,"CLOCK"); //��ʾ����
	setcolor(LIGHTRED);
	rectangle(342,72,560,360); //��һ������,��Ϊʱ�ӵĿ��

	setwritemode(0); //�涨���ߵķ�ʽ��mode=0, ���ʾ����ʱ������λ�õ�ԭ����Ϣ����
	setcolor(YELLOW);
	outtextxy(433,75,"CLOCK");//ʱ�ӵı���
	setcolor(BROWN);
	line(392,310,510,310);
	line(392,330,510,330);
	arc(392,320,90,270,10);
	arc(510,320,270,90,10); //���Ƶ��Ӷ���ʱ���µ�����ʱ�ӵı߿��
	//��������ʱ�ӵ�ʱ����ķָ���
	setcolor(RED);
	for(i=431;i<=470;i+=39){
		for(j=317;j<=324;j+=7){
			setlinestyle(0,0,3);
			circle(i,j,1); //��(i, y)ΪԲ��,1Ϊ�뾶��Բ
		}
	}
	setfillcolor(BLUE);
	line(424,315,424,325); //�����е���ʱ��ǰ�Ȼ�һ�����
	//���Ʊ�ʾСʱ��Բ��
	for(i=0,m=0,h=0;i<=11;i++,h++){
		x=100*sin((h*60+m)/360*PI)+451;
		y=200-100*cos((h*60+m)/360*PI);
		setlinestyle(0,0,3);
		circlef(float(x),float(y),4);
	}
	//���Ʊ�ʾ���ӻ����ӵ�Բ��
	setfillcolor(LIGHTMAGENTA); 
	for(i=0,m=0;i<=59;m++,i++){
		x=100*sin(m/30*PI)+451;
		y=200-100*cos(m/30*PI);
		setlinestyle(0,0,1);
		circlef(float(x),float(y),2);
	}
	//�ڵ��ӱ����ߴ�ӡ������ʾ��Ϣ
	setcolor(CYAN);
	outtextxy(170,85,"���װ�ʱ��");
	setcolor(MAGENTA);

	outtextxy(140,145,"C ���Գ�����ƿγ�");
	outtextxy(140,185,"������ ");
	outtextxy(140,225,"�༶�� ");
	outtextxy(140,265,"ѧ�ţ� ");
	outtextxy(140,325,"Version : 1.0");
	setcolor(LIGHTCYAN);
	outtextxy(170,400,"Nothing is more important than time!");

	while(1){
		clockhandle();/*��ʼ����ʱ�Ӵ������*/
	}
	closegraph(); /*�ر�ͼ��ϵͳ*/
	return 0; /*��ʾ������������,�����ϵͳ����һ��0ֵ*/
	}
	//******************************************************************************************************



// /**/
   /*�������ܵı߽ǻ���*/

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

	x=50*sin((h*60+m)/360*PI)+451; /*ʱ���x����ֵ*/
	y=200-50*cos((h*60+m)/360*PI); /*ʱ���y����ֵ*/
	line_f(451,200,float(x),float(y));/*�ڵ��ӱ��л���ʱ��*/

	xx1=80*sin(m/30*PI)+451; /*�����x����ֵ*/
	yy1=200-80*cos(m/30*PI); /*�����y����ֵ*/
	line_f(451,200,float(xx1),float(yy1)); /*�ڵ��ӱ��л��Ʒ���*/

	digitclock(400,312,digithour(h)); /*������ʱ���У���ʾ��ǰ��Сʱֵ*/
	digitclock(444,312,digitmin(m)); /*������ʱ���У���ʾ��ǰ�ķ���ֵ*/
	digitclock(490,312,digitsec(s)); /*������ʱ���У���ʾ��ǰ����ֵ*/
	setwritemode(1);
 /*�涨���ߵķ�ʽ,���mode=1,���ʾ����ʱ���������Ե���
������֮��ԭ�е��߽������(XOR)����,ʵ���ϻ���������ԭ���������ڹ涨
���߽�������Ľ�������, ���ߵ����Բ���, �������λ��߲����൱��û�� 
���ߣ����ڵ�ǰλ�ô������ԭ���Ļ���*/

//		setcolor(YELLOW);/*����ɫ*/



		xx2=98*sin(s/30*PI)+451; /*�����x����ֵ*/
		yy2=200-98*cos(s/30*PI); /*�����y����ֵ*/
		line_f(451,200,float(xx2),float(yy2));

		o_xx2=xx2;
		o_yy2=yy2;
		/*��������*/
		delay(30);

		setcolor(BLACK); 
		xx2=98*sin(s/30*PI)+451;
		yy2=200-98*cos(s/30*PI);
		line_f(451,200,float(xx2),float(yy2));
		digitclock(490,312,digitsec(s));

  /*��ԭ������ɫ��ԭ��λ�ô��ٻ������룬�Դﵽ�����ǰ�����Ŀ��*/
		setcolor(WHITE);
		digitclock(490,312,digitsec(s)+1);/*����ʱ�����ӣ���*/



   /*���Ӵ���*/
		if(m!=mm){ /*�������б仯*/
         /*������ǰ����*/
			setcolor(BLACK); /*��ɫ15*/
			xx1=80*sin(m/30*PI)+451;
			yy1=200-80*cos(m/30*PI);
			line_f(451,200,float(o_xx1),float(o_yy1));
         /*�����µķ���*/
			m=timeinfo[0].tm_min;
			digitclock(444,312,digitmin(m)); /*������ʱ������ʾ�µķ���ֵ*/
			xx1=80*sin(m/30*PI)+451;
			yy1=200-80*cos(m/30*PI);
			line_f(451,200,float(xx1),float(yy1));
		}
//
  /*Сʱ����*/
		if((h*60+m)!=(hh*60+mm)){  /*��Сʱ���б仯*/
         /*������ǰʱ��*/
			setcolor(BLACK); /*��ɫ15*/
			x=50*sin((h*60+m)/360*PI)+451;/*50:ʱ�ӵĳ��ȣ���λ�����أ���451:Բ�ĵ�x����ֵ*/
			y=200-50*cos((h*60+m)/360*PI);
			line_f(451,200,float(o_x),float(o_y));
          /*�����µ�ʱ��*/
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
//int keyhandle(int key,int count)   /*���̿��� */
//{ 
//	switch(key)
//	{
//		case UP: timeupchange(count-1); /*��Ϊcount�ĳ�ʼֵΪ�������Դ˴�����*/
//			break;
//		case DOWN:timedownchange(count-1); /*��Ϊcount�ĳ�ʼֵΪ�������Դ˴�����*/
//			break;
//		case TAB:setcolor(WHITE);
//			clearcursor(count); /*���ԭ���Ĺ��*/
//			drawcursor(count);  /*��ʾһ���µĹ��*/
//			count++;
//			break;
//  }
//  return count;
// }
//
//int timeupchange(int count) /*���������Ƶİ���*/
//{
//     if(count==1){
//        timeinfo[0].tm_hour++;
//        if(timeinfo[0].tm_hour==24) timeinfo[0].tm_hour=0;
//        settime(timeinfo); /*�����µ�ϵͳʱ��*/
//        }
//
//     if(count==2){
//        timeinfo[0].tm_min++;
//        if(timeinfo[0].tm_min==60) timeinfo[0].tm_min=0;
//        settime(timeinfo); /*�����µ�ϵͳʱ��*/
//        }
//
//    if(count==3){
//        timeinfo[0].tm_sec++;
//        if(timeinfo[0].tm_sec==60) timeinfo[0].tm_sec=0;
//        settime(timeinfo); /*�����µ�ϵͳʱ��*/
//        }
// }
//
//int timedownchange(int count) /*���������Ƶİ���*/
//{
//   if(count==1) {
//        timeinfo[0].tm_hour--;
//        if(timeinfo[0].tm_hour==0) timeinfo[0].tm_hour=23;
//        settime(timeinfo);/*�����µ�ϵͳʱ��*/
//        }
//   if(count==2) {
//        timeinfo[0].tm_min--;
//        if(timeinfo[0].tm_min==0)timeinfo[0].tm_min=59;
//        settime(timeinfo);/*�����µ�ϵͳʱ��*/
//        }
//
//  if(count==3) {
//        timeinfo[0].tm_sec--;
//        if(timeinfo[0].tm_sec==0) timeinfo[0].tm_sec=59;
//        settime(timeinfo);/*�����µ�ϵͳʱ��*/
//        }
// }
//
//SetLocalTime()
 
int digithour(double h)/*��double�͵�Сʱ��ת����int��*/
{	
	int i;
	for(i=0;i<=23;i++)
	{
		if(h==i) 
			break;
	}
	return i;
}

int digitmin(double m)/*��double�͵ķ�����ת����int��*/
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
int digitsec(double s) /*��double�͵�������ת����int��*/
{
	int i;
	for(i=0;i<=59;i++)
		{	if(s==i) break;}
	return i;
}
//
//
void digitclock(int x,int y,int clock)/*��ָ��λ����ʾ����ʱ��:ʱ\��\��*/
{
	char buffer1[10];
	setfillstyle(0,2);
	bar(x,y,x+15,328);
	if(clock==60) {	clock=0;}
	sprintf(buffer1,"%d",clock);
	outtextxy(x,y,buffer1);
 }
////
//void drawcursor(int count)    /*����count��ֵ����һ�����*/
//{
//	switch(count)
//	{
//		case 1:line(424,315,424,325);break;
//		case 2:line(465,315,465,325);break;
//		case 3:line(505,315,505,325);break;
//	}
//}
//
//void clearcursor(int count)    /*����count��ֵ�����ǰһ�����*/
//{
//	switch(count)
//	{
//		case 2:line(424,315,424,325);break;
//		case 3:line(465,315,465,325);break;
//		case 1:line(505,315,505,325);break;
//	}
//}
//
