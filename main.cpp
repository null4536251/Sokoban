#define _CRT_SECURE_NO_WARNINGS 1
//运行环境：Visual Studio 2019
//唐郑翔
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<conio.h>
#include<graphics.h>
#include<easyx.h>
#include<mmstream.h>
#pragma comment(lib,"winmm.lib");
#include"Function.cpp"
#include"Head.h"
#define ROW 20
#define COL 20
//0:空地 1：墙壁 2:目的地 3：箱子在空地 4：人在空地 5：箱子在目的地 6：人在目的地
int main(void)
{
	blank, people, destination, wall, box,box_des,begin,win,end;
	initgraph(400, 400);
	loadimage(&blank, L"C:\\Users\\86150\\source\\repos\\推箱子\\blank.jpg",20,20);
	loadimage(&people, L"C:\\Users\\86150\\source\\repos\\推箱子\\people.jpg", 20, 20);
	loadimage(&destination, L"C:\\Users\\86150\\source\\repos\\推箱子\\destination.jpg", 20, 20);
	loadimage(&wall, L"C:\\Users\\86150\\source\\repos\\推箱子\\wall.jpg", 20, 20);
	loadimage(&box, L"C:\\Users\\86150\\source\\repos\\推箱子\\box.jpg", 20, 20);
	loadimage(&box_des, L"C:\\Users\\86150\\source\\repos\\推箱子\\box_des.jpg", 20, 20);
	loadimage(&begin, L"C:\\Users\\86150\\source\\repos\\推箱子\\begin.jpg", 400, 400);
	loadimage(&win, L"C:\\Users\\86150\\source\\repos\\推箱子\\win.jpg", 400, 400);
	loadimage(&end, L"C:\\Users\\86150\\source\\repos\\推箱子\\end.jpg", 400, 400);
	mciSendString(TEXT("open Doraemon.mp3"), NULL, 0, NULL);
	mciSendString(TEXT("play Doraemon.mp3 repeat"), NULL, 0, NULL);
	while (1)
	{
		//outtextxy(0,0,_T("欢迎来到推箱子小游戏"));
		//outtextxy(0, 20, _T("按任意键继续"));
		putimage(0, 0, &begin);
		Init_level = _getch();
		while (Init_level > '5' || Init_level < '1')
		{
			Init_level = _getch();
		}
		/*do
		{
			cleardevice();
			outtextxy(0,0,_T("请选择起始关卡（1—5）"));
			Init_level = _getch();
			if (Init_level > '5' || Init_level < '1')
			{
				cleardevice();
				outtextxy(0, 0, _T("只有五关！"));
				outtextxy(0, 20, _T("按任意键继续"));
				_getch();
			}
		} while (Init_level > '5' || Init_level < '1');*/
		for (int i = Init_level - '0' - 1; i < MAXSIZE; i++)
		{
			count = 0;
			cleardevice();
			PrintMap(i);
			while (1)
			{
				GetPos(i);
				ch = _getch();
				switch (ch)
				{
				case 'w':case 'W':case 72:Up(i); break;
				case 's':case 'S':case 80:Down(i); break;
				case 'a':case 'A':case 75:Left(i); break;
				case 'd':case 'D':case 77:Right(i); break;
				case 'r':case 'R':
				{
					count++;
					InitMap(i);
					PrintMap(i);
					break;
				}
				}
				if (Win(i))
				{
					if (i == MAXSIZE - 1)
					{
						cleardevice();
						putimage(0, 0, &end);
						if(_getch())
						return 0;
					}
					else
					{
						cleardevice();
						putimage(0, 0, &win);
						_getch();
						break;
					}
				}
				else
				{
					PrintMap(i);
				}
			}
		}
	}
	return 0;
}