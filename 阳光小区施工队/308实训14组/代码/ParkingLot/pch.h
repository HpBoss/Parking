#ifndef PCH_H
#define PCH_H
#include "cstdio"
#include "cstdlib"
#include "string"
#include <iostream>
using namespace std;
#define MAX 5    //��������
#define price 0.5    //ÿ��ÿ���ӷ���


typedef struct time  //ʱ����
{
	int hour;
	int min;
}Time;
typedef struct node //������Ϣ���
{
	char num[10];//���ƺ�
	Time reach;
	Time leave;
}CarNode;
typedef struct NODE   //ģ��ͣ����
{
	CarNode *stack[MAX + 1];
	int top=0;
}SeqStackCar;
typedef struct car
{
	CarNode *data;
	struct car *next;
}QueueNode;
typedef struct Node  //ģ����
{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;

extern void InitStack(SeqStackCar *); //��ʼ��ջ
extern int InitQueue(LinkQueueCar *); //��ʼ�����
extern int arrivals(SeqStackCar *Enter, LinkQueueCar *W); //��������
extern void leaves(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *);//�����뿪
extern void list(SeqStackCar, LinkQueueCar); //��ʾ�泵��Ϣ
extern void changeT(char*T, int &h, int & m);//�ַ�ת��Ϊ���ִ洢
extern void graph();
extern void Inaction(PIMAGE img,PIMAGE img2,int x1,int y1,int x2,int i,int y2);
extern void Outaction(PIMAGE img,PIMAGE img2s,int x1,int y1,int x3,int i,int y3);
extern void arrival(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int count);
extern void leave(PIMAGE img[],int x1,int y1,int x3,int i,int y3,int count);
extern void mouse(PIMAGE img[],int x1,int y1,int x2,int i,int y2,int x3,int y3,SeqStackCar Enter,SeqStackCar Temp,LinkQueueCar Wait);
#endif //PCH_H
