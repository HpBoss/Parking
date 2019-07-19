#ifndef PCH_H
#define PCH_H
#include "cstdio"
#include "cstdlib"
#include "string"
#include <iostream>
using namespace std;
#define MAX 5    //车库容量
#define price 0.5    //每车每分钟费用


typedef struct time  //时间结点
{
	int hour;
	int min;
}Time;
typedef struct node //车辆信息结点
{
	char num[10];//车牌号
	Time reach;
	Time leave;
}CarNode;
typedef struct NODE   //模拟停车场
{
	CarNode *stack[MAX + 1];
	int top=0;
}SeqStackCar;
typedef struct car
{
	CarNode *data;
	struct car *next;
}QueueNode;
typedef struct Node  //模拟便道
{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;

extern void InitStack(SeqStackCar *); //初始化栈
extern int InitQueue(LinkQueueCar *); //初始化便道
extern int arrivals(SeqStackCar *Enter, LinkQueueCar *W); //车辆到达
extern void leaves(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *);//车辆离开
extern void list(SeqStackCar, LinkQueueCar); //显示存车信息
extern void changeT(char*T, int &h, int & m);//字符转化为数字存储
extern void graph();
extern void Inaction(PIMAGE img,PIMAGE img2,int x1,int y1,int x2,int i,int y2);
extern void Outaction(PIMAGE img,PIMAGE img2s,int x1,int y1,int x3,int i,int y3);
extern void arrival(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int count);
extern void leave(PIMAGE img[],int x1,int y1,int x3,int i,int y3,int count);
extern void mouse(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int x3,int y3,SeqStackCar Enter,SeqStackCar Temp,LinkQueueCar Wait);
#endif //PCH_H
