#include <stdio.h>
#include <windows.h>
#define LEN 25//����������
int main()
{
int len,i;
system("title ������");//���ô��ڱ���
for(len = 0; len <= LEN; len++)
{ 
	system("cls");//����
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf(" ");
	for(i = 0; i < len+1; i++)
	{
		printf("��");
	}
printf("\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
printf("\n �����%d%%", 4 * len);//��ӡ�����
Sleep(100);//��ʱ
}
return 0;
}
