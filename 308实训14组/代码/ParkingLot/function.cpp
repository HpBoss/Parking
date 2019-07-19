#include <graphics.h>
#include "pch.h"
#include<cstdio>
#include <iomanip>

int totalnum = 0;
void InitStack(SeqStackCar *s) //初始化栈
{
	int i;
	s->top = 0;
	for (i = 0; i <= MAX; i++)
		s->stack[s->top] = NULL;
}
int InitQueue(LinkQueueCar *Q) //初始化便道
{
	Q->head = (QueueNode *)malloc(sizeof(QueueNode));
	if (Q->head != NULL)
	{
		Q->head->next = NULL;
		Q->rear = Q->head;
		return 1;
	}
	else
		return -1;
}
void changeT(char*T, int &h, int & m) {
	if (T[1] <= '9'&&T[1] >= '0') {
		h = (T[0] - '0') * 10 + T[1] - '0';
		m = (T[3] - '0') * 10 + T[4] - '0';
	}
	else {
		h =  T[0] - '0';
		m = (T[2] - '0') * 10 + T[3] - '0';
	}
}
void print(CarNode *p) //打印出站车的信息
{
	int A1, A2, B1, B2;
	char LeaveTime[100],money[10],time[5];
	float sum;
	char t[] = { ":" };
    char k[5];
    outtextrect(720,380,800,400,p->num);
    sprintf(time,"%d",p->leave.hour);
    if(p->leave.min==0){
        sprintf(k, "%d%d",0,0);
    }else{
    sprintf(k, "%d",p->leave.min);}
    strcat(time, t);
    strcat(time, k);
    outtextrect(820,380,900,400,time);
	A1 = p->reach.hour;
	A2 = p->reach.min;
	B1 = p->leave.hour;
	B2 = p->leave.min;
	if(A2<B2){
        sum=((B1-A1)*60+(B2-A2))*price;
	}else{
        sum=((B2-A2+60)+(B1-A1-1)*60)*price;
	}
	sprintf(money,"%2.1f",sum);
	outtextrect(920,380,1000,400,money);
	free(p);
	getch();
}
int arrivals(SeqStackCar *Enter, LinkQueueCar *W) //车辆到达
{
	CarNode *p;
	QueueNode *t;
    char ArrivalTime[100];
    static MUSIC music1,music2,music3;
    music1.SetVolume(1.0f);
    music2.SetVolume(1.0f);
    music3.SetVolume(1.0f);
	p = (CarNode *)malloc(sizeof(CarNode));
	music1.OpenFile("请输入你的车牌号.wma");
	music1.Play();
	inputbox_getline("请输入车牌号", "车牌号：",p->num,50);
	if (Enter->top < MAX)     //车场未满，车进车场
	{
		Enter->top++;
		music2.OpenFile("请输入你的入场时间.wma");
        music2.Play();
		inputbox_getline("请输入到达时间", "到达时间：",ArrivalTime,50);
        changeT(ArrivalTime,p->reach.hour,p->reach.min);
		totalnum++;
		Enter->stack[Enter->top] = p;
		return 1;
	}
	else     //车场已满，车进便道
	{
        music3.OpenFile("车位已满，请在便道等.wma");
        music3.Play();
		t = (QueueNode *)malloc(sizeof(QueueNode));
		t->data = p;
		t->next = NULL;
		W->rear->next = t;
		W->rear = t;
		return 1;
	}
}
void leaves(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *W)    //车辆离开
{
	int i, room;
	char LeaveTime[100],locate[1],ArrivalTime[100];
	CarNode *p, *t;
	QueueNode *q;
	static MUSIC music,music1,music2,music3;
	music1.SetVolume(1.0f);
	music2.SetVolume(1.0f);
	music3.SetVolume(1.0f);
	//判断车场内是否有车
	if (Enter->top > 0) //有车
	{
		while (1)//输入离开车辆的信息
		{
			music1.OpenFile("请输入离开车在车场的.wma");
            music1.Play();
			inputbox_getline("请输入离开车在车场的位置", "位置",locate,50);
			room=locate[0]-'0';
			if (room >= 1 && room <= Enter->top){
                break;
			}
		}
		while (Enter->top > room) //车辆离开
		{
			Temp->top++;
			Temp->stack[Temp->top] = Enter->stack[Enter->top];
			Enter->stack[Enter->top] = NULL;
			Enter->top--;
		}
		p = Enter->stack[Enter->top];
		Enter->stack[Enter->top] = NULL;
		Enter->top--;
		while (Temp->top >= 1)
		{
			Enter->top++;
			Enter->stack[Enter->top] = Temp->stack[Temp->top];
			Temp->stack[Temp->top] = NULL;
			Temp->top--;
		}
		music.SetVolume(1.0f);
        music.OpenFile("请输入车辆离开的时间.wma");
        music.Play();
        inputbox_getline("请输入离开时间", "离开时间：",LeaveTime,50);
        changeT(LeaveTime,p->leave.hour,p->leave.min);
		print(p);
		//判断通道上是否有车及车站是否已满
		if((W->head != W->rear) && Enter->top < MAX)//便道的车辆进入车场
		{
			q = W->head->next;
			t = q->data;
			Enter->top++;
			music2.OpenFile("请输入现在的时间.wma");
            music2.Play();
			inputbox_getline("请输入现在的时间","到达时间",ArrivalTime,50);
            changeT(ArrivalTime,t->reach.hour,t->reach.min);
			W->head->next = q->next;
			if (q == W->rear) W->rear = W->head;
			Enter->stack[Enter->top] = t;
			free(q);
		}
		else{
             music3.OpenFile("便道里没有车了.wma");
             music3.Play();
		}
	}
	else{
        music.OpenFile("停车场已经没有车辆了.wma");
        music.Play();
	}
}
void list1(SeqStackCar *S)     //列表显示车场信息
{
	int i,hour,min;
	char time[3];
	char timeh,timem;
	static MUSIC music;
	if (S->top > 0)    //判断车站内是否有车
	{
		for (i = 1; i <= S->top; i++)
		{
            char p[5];
            sprintf(p,"%d",S->stack[i]->reach.hour);
            char t[] = {":"};
            char k[5];
            if(S->stack[i]->reach.min==0){
                sprintf(k, "%d%d",0,0);
            }else{
            sprintf(k, "%d",S->stack[i]->reach.min);}
            strcat(p, t);
            strcat(p, k);

			outtextrect(770,110+(i-1)*40,870,140+(i-1)*40,S->stack[i]->num);//输出车牌号
			outtextrect(920,110+(i-1)*40,1000,140+(i-1)*40,p);//输出到达时间
		}
	}
	else{
        music.OpenFile("停车场已经没有车辆了.wma");
        music.Play();
	}
}
void list2(LinkQueueCar *W)   //列表显示便道信息
{
	QueueNode *p;
	int i=0;
	p = W->head->next;
    char t[] = {":"};
    char k[5];
    static MUSIC music;
	if (W->head != W->rear)   //判断通道上是否有车
	{
		while (p != NULL)
		{
		    i++;
			outtextrect(720,450+(i-1)*30,850,470+(i-1)*30,p->data->num);
			p = p->next;
		}
	}
	else{
        music.OpenFile("现在便道里没有车.wma");
        music.Play();
	}
}
void list(SeqStackCar S, LinkQueueCar W)
{
	list1(&S);
	list2(&W);
}




