#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>
#include<conio.h>
#include"Head.h"
#define ROW 20
#define COL 20
void GetPos(int i)
{
	for (int I = 0; I < ROW; I++)
		for (int J = 0; J < COL; J++)
			if (Map[i][I][J] == 4 || Map[i][I][J] == 6)
			{
				Pos.r = I, Pos.c = J;
				return;
			}
}
void InitMap(int i)
{
	{
		for (int I = 0; I < ROW; I++)
			for (int J = 0; J < COL; J++)
				Map[i][I][J] = Map_copy[i][I][J];
	}
}
void PrintMap(int i)
{
	for (int I = 0; I < ROW; I++)
	{
		for (int J = 0; J < COL; J++)
		{
			switch (Map[i][I][J])
			{
			case 0:putimage(J * 20, I * 20 , &blank); break;
			case 1:putimage(J * 20, I * 20 , &wall); break;
			case 2:putimage(J * 20, I * 20 , &destination); break;
			case 3:putimage(J * 20, I * 20 , &box); break;
			case 4:putimage(J * 20, I * 20 , &people); break;
			case 5:putimage(J * 20, I * 20 , &box_des); break;
			case 6:putimage(J * 20, I * 20 , &people); break;
			}
		}
	}
	outtextxy(130, 280, _T("按r回到起点"));
	switch (i)
	{
	case 0:outtextxy(150,320 , _T("Level 1")); break;
	case 1:outtextxy(150, 320, _T("Level 2")); break;
	case 2:outtextxy(150, 320, _T("Level 3")); break;
	case 3:outtextxy(150, 320, _T("Level 4")); break;
	case 4:outtextxy(150, 320, _T("Level 5")); break;
	}
}
void Up(int i)
{
	{
		if (Map[i][Pos.r][Pos.c] == 4)//当小人站在空地时
		{
			switch (Map[i][Pos.r - 1][Pos.c])//判断小人上方是什么
			{
			case 0:Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:break;
			case 2:Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			case 3:
			{
				switch (Map[i][Pos.r - 2][Pos.c])//判断小人上方的箱子上面是什么
				{
				case 0:Map[i][Pos.r - 2][Pos.c] = 3, Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
				case 1:case 3:case 5: break;//推不动
				case 2:Map[i][Pos.r - 2][Pos.c] = 5, Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
				}
			}
			case 5:
			{
				switch (Map[i][Pos.r - 2][Pos.c])//判断小人上方的已在目的地的箱子的上面是什么
				{
				case 0:Map[i][Pos.r - 2][Pos.c] = 3, Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
				case 1:case 3:case 5:break;
				case 2:Map[i][Pos.r - 2][Pos.c] = 5, Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
				}
			}
			}
		}
		else//小人在目的地
		{
			switch (Map[i][Pos.r - 1][Pos.c])//判断小人上方是什么
			{
			case 0:Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:break;
			case 2:Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			case 3:
			{
				switch (Map[i][Pos.r - 2][Pos.c])//判断小人上方的箱子上面是什么
				{
				case 0:Map[i][Pos.r - 2][Pos.c] = 3, Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
				case 1:case 3:case 5:break;//推不动
				case 2:Map[i][Pos.r - 2][Pos.c] = 5, Map[i][Pos.r - 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
				}
			}
			case 5:
			{
				switch (Map[i][Pos.r - 2][Pos.c])//判断小人上方的已在目的地的箱子的上面是什么
				{
				case 0:Map[i][Pos.r - 2][Pos.c] = 3, Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
				case 1:case 3:case 5:break;
				case 2:Map[i][Pos.r - 2][Pos.c] = 5, Map[i][Pos.r - 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
				}
			}
			}
		}
	}
}
void Down(int i)
{
	if (Map[i][Pos.r][Pos.c] == 4)//当小人站在空地时
	{
		switch (Map[i][Pos.r + 1][Pos.c])//判断小人下方是什么
		{
		case 0:Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
		case 1:break;
		case 2:Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
		case 3:
		{
			switch (Map[i][Pos.r + 2][Pos.c])//判断小人下方的箱子下面是什么
			{
			case 0:Map[i][Pos.r + 2][Pos.c] = 3, Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5: break;//推不动
			case 2:Map[i][Pos.r + 2][Pos.c] = 5, Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r + 2][Pos.c])//判断小人下方的已在目的地的箱子的下面是什么
			{
			case 0:Map[i][Pos.r + 2][Pos.c] = 3, Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r + 2][Pos.c] = 5, Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		}
	}
	else//小人在目的地
	{
		switch (Map[i][Pos.r + 1][Pos.c])//判断小人下方是什么
		{
		case 0:Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
		case 1:break;
		case 2:Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
		case 3:
		{
			switch (Map[i][Pos.r + 2][Pos.c])//判断小人下方的箱子上面是什么
			{
			case 0:Map[i][Pos.r + 2][Pos.c] = 3, Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;//推不动
			case 2:Map[i][Pos.r + 2][Pos.c] = 5, Map[i][Pos.r + 1][Pos.c] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r + 2][Pos.c])//判断小人下方的已在目的地的箱子的下面是什么
			{
			case 0:Map[i][Pos.r + 2][Pos.c] = 3, Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r + 2][Pos.c] = 5, Map[i][Pos.r + 1][Pos.c] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		}
	}
}
void Left(int i)
{
	if (Map[i][Pos.r][Pos.c] == 4)//当小人站在空地时
	{
		switch (Map[i][Pos.r][Pos.c - 1])//判断小人左方是什么
		{
		case 0:Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
		case 1:break;
		case 2:Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
		case 3:
		{
			switch (Map[i][Pos.r][Pos.c - 2])//判断小人左方的箱子左面是什么
			{
			case 0:Map[i][Pos.r][Pos.c - 2] = 3, Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5: break;//推不动
			case 2:Map[i][Pos.r][Pos.c - 2] = 5, Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r][Pos.c - 2])//判断小人左方的已在目的地的箱子的左面是什么
			{
			case 0:Map[i][Pos.r][Pos.c - 2] = 3, Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r][Pos.c - 2] = 5, Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		}
	}
	else//小人在目的地
	{
		switch (Map[i][Pos.r][Pos.c - 1])//判断小人左方是什么
		{
		case 0:Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
		case 1:break;
		case 2:Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
		case 3:
		{
			switch (Map[i][Pos.r][Pos.c - 2])//判断小人左方的箱子上面是什么
			{
			case 0:Map[i][Pos.r][Pos.c - 2] = 3, Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;//推不动
			case 2:Map[i][Pos.r][Pos.c - 2] = 5, Map[i][Pos.r][Pos.c - 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r][Pos.c - 2])//判断小人左方的已在目的地的箱子的上面是什么
			{
			case 0:Map[i][Pos.r][Pos.c - 2] = 3, Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r][Pos.c - 2] = 5, Map[i][Pos.r][Pos.c - 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		}
	}
}
void Right(int i)
{
	if (Map[i][Pos.r][Pos.c] == 4)//当小人站在空地时
	{
		switch (Map[i][Pos.r][Pos.c + 1])//判断小人右方是什么
		{
		case 0:Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
		case 1:break;
		case 2:Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
		case 3:
		{
			switch (Map[i][Pos.r][Pos.c + 2])//判断小人右方的箱子上面是什么
			{
			case 0:Map[i][Pos.r][Pos.c + 2] = 3, Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5: break;//推不动
			case 2:Map[i][Pos.r][Pos.c + 2] = 5, Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r][Pos.c + 2])//判断小人右方的已在目的地的箱子的上面是什么
			{
			case 0:Map[i][Pos.r][Pos.c + 2] = 3, Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r][Pos.c + 2] = 5, Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 0; break;
			}
		}
		}
	}
	else//小人在目的地
	{
		switch (Map[i][Pos.r][Pos.c + 1])//判断小人右方是什么
		{
		case 0:Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
		case 1:break;
		case 2:Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
		case 3:
		{
			switch (Map[i][Pos.r][Pos.c + 2])//判断小人右方的箱子上面是什么
			{
			case 0:Map[i][Pos.r][Pos.c + 2] = 3, Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;//推不动
			case 2:Map[i][Pos.r][Pos.c + 2] = 5, Map[i][Pos.r][Pos.c + 1] = 4, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		case 5:
		{
			switch (Map[i][Pos.r][Pos.c + 2])//判断小人右方的已在目的地的箱子的右面是什么
			{
			case 0:Map[i][Pos.r][Pos.c + 2] = 3, Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			case 1:case 3:case 5:break;
			case 2:Map[i][Pos.r][Pos.c + 2] = 5, Map[i][Pos.r][Pos.c + 1] = 6, Map[i][Pos.r][Pos.c] = 2; break;
			}
		}
		}
	}
}
bool Win(int i)
{
	int count = 0;
	for (int I = 0; I < ROW; I++)
		for (int J = 0; J < COL; J++)
			if (Map[i][I][J] == 5)
				count++;
	if (count == Numb_Des[i])
		return true;
	return false;
}
/*void PrintWin(int i)
{
	cleardevice();
	putimage(0, 0, &win);
}*/