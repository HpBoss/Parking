#include <stdio.h>
#include <windows.h>
#define LEN 25//进度条长度
int main()
{
int len,i;
system("title 进度条");//设置窗口标题
for(len = 0; len <= LEN; len++)
{ 
	system("cls");//清屏
	printf("╔═════════════════════════╗\n");
	printf(" ");
	for(i = 0; i < len+1; i++)
	{
		printf("█");
	}
printf("\n╚═════════════════════════╝");
printf("\n 已完成%d%%", 4 * len);//打印完成率
Sleep(100);//延时
}
return 0;
}
