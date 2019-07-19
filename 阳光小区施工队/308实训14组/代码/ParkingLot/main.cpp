#include <graphics.h>
#include <time.h>
#include <math.h>
#include "pch.h"
void graph(){
    setcolor(WHITE);
    char r[5];
    /////停车信息表////////
    setfont(18,0,"宋体");
    rectangle(700,50,1000,300);
    line(700,80,1000,80);
    line(700,100,1000,100);
    line(700,140,1000,140);
    line(700,180,1000,180);
    line(700,220,1000,220);
    line(700,260,1000,260);
    line(740,80,740,300);
    line(870,80,870,300);
    outtextrect(815,57,1000,300,"停车位信息");
    outtextrect(702,82,740,100,"车位");
    outtextrect(780,82,1000,80,"车牌号");
    outtextrect(910,82,1000,80,"到达时间");
    for(int i=1;i<=5;i++){
        sprintf(r,"%d",i);
        outtextrect(715,80+i*40,740,100+i*40,r);
    }
    ////////便道等候车牌号////////
    rectangle(700,410,880,530);
    line(700,440,880,440);
    line(700,470,880,470);
    line(700,500,880,500);
    outtextrect(720,420,880,440,"便道等候车牌号");
    //////控制菜单//////////
    line(40,50,0,20);
    line(130,50,170,20);
    line(0,20,170,20);
    outtextrect(60,25,90,25,"控制台");
    ////////控制台//////////
	rectangle(40,50,130,100);
	rectangle(40,100,130,150);
	rectangle(40,150,130,200);
	rectangle(40,200,130,250);
    outtextrect(50,70,120,100,"车辆到达");
    outtextrect(50,120,150,150,"车辆离开");
    outtextrect(65,170,150,200,"查询");
    outtextrect(65,220,150,250,"退出");
    ///////////离开信息表////////
    rectangle(700,310,1000,400);
    line(700,340,1000,340);
    line(700,370,1000,370);
    line(800,340,800,400);
    line(900,340,900,400);
    outtextrect(820,320,1000,340,"离开信息");
    outtextrect(720,350,800,350,"车牌号");
    outtextrect(820,350,900,350,"离开时间");
    outtextrect(930,350,1000,350,"费用");
}
void Inaction(PIMAGE img,PIMAGE img2,PIMAGE background,int x1,int y1,int x2,int i,int y2){
	while(1)
	{
		cleardevice();
        putimage(700,50,300,500,background,0,0,499,888);
		putimage(x1,y1,350,280,img,0,0,799,612);
		putimage(x2+=15,y2,70,50,img2,0,0,1052,762);
		graph();
		delay_ms(120);
		i++;
		if(i==21){
            i=0;
            x2-=315;
            break;
		}
	}
}
void Outaction(PIMAGE img,PIMAGE img2s,PIMAGE background,int x1,int y1,int x3,int i,int y3){
    while(1)
	{
		cleardevice();
        putimage(700,50,300,500,background,0,0,499,888);
		putimage(x1,y1,350,280,img,0,0,799,612);
		putimage(x3-=15,y3,70,50,img2s,0,0,1052,762);
		graph();
		delay_ms(120);
		i++;
		if(i==21){
            i=0;
            x3+=315;
            break;
		}
	}
}
void arrival(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int count){
   switch(count){
    case 1:
        Inaction(img[0],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[3],0,0,799,612);
        break;
    case 2:
        Inaction(img[3],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[4],0,0,799,612);
        break;
    case 3:
        Inaction(img[4],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[5],0,0,799,612);
        break;
    case 4:
        Inaction(img[5],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[6],0,0,799,612);
        break;
    case 5:
        Inaction(img[6],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[7],0,0,799,612);
        break;
    case 6:
        Inaction(img[7],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[8],0,0,799,612);
        break;
    case 7:
        Inaction(img[8],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[9],0,0,799,612);
        break;
    case 8:
        Inaction(img[9],img[1],img[12],x1,y1,x2,i,y2);
        putimage(x1,y1,350,280,img[10],0,0,799,612);
        break;
   }
}
void leave(PIMAGE img[],int x1,int y1,int x3,int i,int y3,int count){
    switch(count){
    case 0:
        putimage(x1,y1,350,280,img[0],0,0,799,612);
        Outaction(img[0],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 1:
        putimage(x1,y1,350,280,img[4],0,0,799,612);
        Outaction(img[3],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 2:
        putimage(x1,y1,350,280,img[5],0,0,799,612);
        Outaction(img[4],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 3:
        putimage(x1,y1,350,280,img[6],0,0,799,612);
        Outaction(img[5],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 4:
        putimage(x1,y1,350,280,img[7],0,0,799,612);
        Outaction(img[6],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 5:
        putimage(x1,y1,350,280,img[8],0,0,799,612);
        Outaction(img[7],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 6:
        putimage(x1,y1,350,280,img[9],0,0,799,612);
        Outaction(img[8],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    case 7:
        putimage(x1,y1,350,280,img[10],0,0,799,612);
        Outaction(img[9],img[2],img[12],x1,y1,x3,i,y3);
        putimage(x3-315,y3,70,50,img[1],0,0,1052,762);
        break;
    }
}
void mouse(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int x3,int y3,SeqStackCar Enter, LinkQueueCar Wait,SeqStackCar Temp){
   int count=0;
   char LeaveTime[100];
   mouse_msg msg;
   static MUSIC LeaveMusic,FullMusic;
   for(;is_run();delay_fps(60)){
      while (mousemsg())
      {
        msg = getmouse();
      }
      if(msg.x > 40 && msg.x < 120 && msg.y > 50 && msg.y < 100) {
        setcolor(GREEN);
        outtextrect(50,70,120,100,"车辆到达");
        setcolor(YELLOW);
        outtextrect(50,120,150,150,"车辆离开");
        outtextrect(65,170,150,200,"查询");
        outtextrect(65,220,150,250,"退出");
        if (msg.is_left()) {
            count++;
            arrivals(&Enter,&Wait);
            arrival(img,x1,y1,x2,i,y2,count);
        }
      }else if(msg.x > 40 && msg.x < 120 && msg.y>100 && msg.y<150){
            setcolor(GREEN);
            outtextrect(50,120,150,150,"车辆离开");
            setcolor(YELLOW);
            outtextrect(50,70,120,100,"车辆到达");
            outtextrect(65,170,150,200,"查询");
            outtextrect(65,220,150,250,"退出");
             if (msg.is_left()) {
                count--;
                if(count<0){
                    count=0;
                    FullMusic.OpenFile("现在停车场还没有车辆.wma");
                    FullMusic.Play();
                }else{
                    leaves(&Enter,&Temp,&Wait);
//                    LeaveMusic.OpenFile("一路平安，期待下次再.wma");
//                    LeaveMusic.Play();
                    leave(img,x1,y1,x3,i,y3,count);
                }
            }
       }else if(msg.x > 40 && msg.x < 120 && msg.y>150 && msg.y<200){
             setcolor(GREEN);
             outtextrect(65,170,150,200,"查询");
             setcolor(YELLOW);
             outtextrect(50,70,120,100,"车辆到达");
             outtextrect(50,120,150,150,"车辆离开");
             outtextrect(65,220,150,250,"退出");
              if (msg.is_left()) {
                list(Enter,Wait);
            }
       }else if(msg.x > 40 && msg.x < 120 && msg.y>200 && msg.y<250){
            setcolor(GREEN);
            outtextrect(65,220,150,250,"退出");
            setcolor(YELLOW);
            outtextrect(50,70,120,100,"车辆到达");
            outtextrect(50,120,150,150,"车辆离开");
            outtextrect(65,170,150,200,"查询");
             if (msg.is_left()) {
                    exit(0);
            }
       }else{
            setcolor(YELLOW);
            outtextrect(50,70,120,100,"车辆到达");
            outtextrect(50,120,150,150,"车辆离开");
            outtextrect(65,170,150,200,"查询");
            outtextrect(65,220,150,250,"退出");
       }
    }
}
int main(){
	int x1=300,x2=70,y1=100,y2=330,i=0,x3=385,y3=330;
	//////栈与队列////////
	SeqStackCar Enter, Temp;
	LinkQueueCar Wait;
	int ch;
	InitStack(&Enter);    //初始化车站
	InitStack(&Temp);     //初始化让路的临时栈
	InitQueue(&Wait);     //初始化通道
	////////////////////////
	static MUSIC music;
	music.SetVolume(1.0f);
	music.OpenFile("欢迎来到阳光小区停车.wma");
	///////播放欢迎音乐////////////
	initgraph(1030,560);
	//setbkcolor(WHITE);
    PIMAGE img1,img2,img2s,img3,img4,img5,img6,img7,img8,img9,img10,img11,background;
	PIMAGE img[20]={img1,img2,img2s,img3,img4,img5,img6,img7,img8,img9,img10,img11,background};
	/////////////////////////
	img[0]= newimage();
	img[1]= newimage();
	img[2]=newimage();
	img[3]= newimage();
	img[4]=newimage();
	img[5]=newimage();
	img[6]=newimage();
	img[7]=newimage();
	/////在便道上/////
	img[8]=newimage();
	img[9]=newimage();
	img[10]=newimage();
	/////在便道上动态驶入车位/////
	img[11]=newimage();
	img[12]=newimage();
	img[13]=newimage();
	img[14]=newimage();
	///////////////////
	getimage(img[12],"background8.jpg");
	//////背景图///////
	//////////车位停车///////////////
	getimage(img[0],"pk2.png");
	getimage(img[1],"e.gif");
	getimage(img[2],"el.gif");
	getimage(img[3],"pk2-1.png");
	getimage(img[4],"pk2-2.png");
	getimage(img[5],"pk2-3.png");
	getimage(img[6],"pk2-4.png");
	getimage(img[7],"pk2-5.png");
	///////////在便道上//////////////
	getimage(img[8],"queue1.png");
	getimage(img[9],"queue2.png");
	getimage(img[10],"queue3.png");
	/////在便道上动态驶入车位/////
	getimage(img[11],"in.gif");
	putimage(700,50,300,500,img[12],0,0,499,888);
	putimage(x2,y2,70,50,img[1],0,0,1052,762);
	putimage(x1,y1,350,280,img[0],0,0,799,612);
	graph();
	music.Play();
	//////////////////////////////
    mouse(img,x1,y1,x2,i,y2,x3,y3,Enter,Wait,Temp);
	getch();
	closegraph();
	return 0;
}

