#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include<iostream>
#include<cstdlib>
#include<vector>
#define Max 1000
using namespace std;
ExMessage msg = { 0 };
bool inarea(int x, int y, int w, int h)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h)
	{
		return true;
	}
	return false;
}
bool button1(int x, int y, int w, int h)
{
	if (inarea(x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	else
	{
		setfillcolor(RGB(135, 206, 235));
	}
	fillroundrect(x, y, x + w, y + h, 5, 5);
	if (inarea(x, y, w, h) && msg.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}

int showpage(int &a)
{

	initgraph(640, 480, EX_SHOWCONSOLE | EX_DBLCLKS);
	setbkcolor(RGB(243, 152, 151));
	cleardevice();
	settextcolor(BLACK);
	int Width = 150, Height = 50;
	while (true)
	{
		BeginBatchDraw();

		setbkmode(TRANSPARENT);
		char text[] = { "用户信息收集系统" };


		outtextxy((640 - textwidth(text)) / 2, 90, text);
		if (peekmessage(&msg, EX_MOUSE)) {}

		if (button1(120, 180, Width, Height))
		{
			return a = 1;

		}
		else if (button1(120, 260, Width, Height))
		{
			return a = 2;
		}
		else if (button1(120, 340, Width, Height))
		{
			return a = 3;
		}
		else if (button1(370, 180, Width, Height))
		{
			return a = 4;
		}
		else if (button1(370, 260, Width, Height))
		{
			return a = 5;
		}
		else if (button1(370, 340, Width, Height))
		{
			return a = 6;
		}
		msg.message = 0;
		outtextxy((Width - textwidth("1.添加用户信息")) / 2 + 120, (Height - textheight("1.添加用户信息")) / 2 + 180, ("1.添加用户信息"));
		outtextxy((Width - textwidth("2.显示用户信息")) / 2 + 120, (Height - textheight("2.显示用户信息")) / 2 + 260, ("2.显示用户信息"));
		outtextxy((Width - textwidth("3.删除用户信息")) / 2 + 120, (Height - textheight("3.删除用户信息")) / 2 + 340, ("3.删除用户信息"));
		outtextxy((Width - textwidth("4.查找用户信息")) / 2 + 370, (Height - textheight("4.查找用户信息")) / 2 + 180, ("4.查找用户信息"));
		outtextxy((Width - textwidth("5.修改用户信息")) / 2 + 370, (Height - textheight("5.修改用户信息")) / 2 + 260, ("5.修改用户信息"));
		outtextxy((Width - textwidth("6.退出系统")) / 2 + 370, (Height - textheight("6.退出系统")) / 2 + 340, ("6.退出系统"));
		EndBatchDraw();
	}

	getchar();
}
class person {
public:
	string name;
	int age;
	bool sex;
	bool skin;
};
void addperson(person* a, int& num)
{
	if (num == Max)
	{
		cout << "系统所能记录用户已达上限";
	}
	else
	{
		cout << "请输入用户姓名" << endl;
		cin >> (a + num)->name;
		cout << "请输入年龄" << endl;
		cin >> (a + num)->age;
		cout << "请输入用户性别（如果是男性输入1，女性输入0）" << endl;
		cin >> (a + num)->sex;
		cout << "是否为油皮，如果是输入1，不是输入0" << endl;
		cin >> (a + num)->skin;
		cout << "添加成功"<<endl;
		num++;
	}
	system("pause");
	system("cls");
}
void showperson(person* a, int num)
{
	if (num == 0)
	{
		cout << "用户信息为空" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "姓名：" << (a + i)->name << endl;
			cout << "年龄：" << (a + i)->age << endl;
			cout << "性别(1为男，0为女）：" << (a + i)->sex << endl;
			cout << "皮肤(1为油皮，0则不是）：" << (a + i)->skin << endl;
		}
	}
	system("pause");
	system("cls");
}
int isexist(person* a, string name)
{
	for (int i = 0; i < 1000; i++)
	{
		if ((a + i)->name == name)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
	system("pause");
	system("cls");
}
void deleteperson(person* a, int& num)
{
	cout << "请输入想要删除的用户姓名" << endl;
	string name;
	cin >> name;
	int x = isexist(a, name);
	if (x == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = x; i < num; i++)
		{
			(a + i)->age = (a + i + 1)->age;
			(a + i)->name = (a + i + 1)->name;
			(a + i)->sex = (a + i + 1)->sex;
			(a + i)->skin = (a + i + 1)->skin;
		}
		num--;
		
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(person* a, int num)
{
	cout << "输入用户姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < num; i++)
	{
		if ((a + i)->name == name)
		{
			cout << "姓名：" << (a + i)->name << endl;
			cout << "年龄：" << (a + i)->age << endl;
			cout << "性别(1为男，0为女）：" << (a + i)->sex << endl;
			cout << "皮肤(1为油皮，0则不是）：" << (a + i)->skin << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void changeperson(person* a, int num)
{
	cout << "输入用户姓名" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < num; i++)
	{
		if ((a + i)->name == name)
		{
			cout << "请输入用户年龄" << endl;
			cin >> (a + i)->age;
			cout << "请输入用户性别" << endl;
			cin >> (a + i)->sex;
			cout << "请输入用户皮肤状况" << endl;
			cin >> (a + i)->skin;
		}
	}
	cout << "修改完毕" << endl;
	system("pause");
	system("cls");
	
}
int main()
{
	person a[Max];
	int num = 0;
	int j = 0;
	while (1)
	{
		showpage(j);
		switch (j)
		{
		case 1: addperson(a, num); break;
		case 2: showperson(a, num); break;
		case 3: deleteperson(a, num); break;
		case 4: findperson(a, num); break;
		case 5: changeperson(a, num); break;
		case 6: cout << "欢迎下次使用" << endl;
			system("pause");
			return 0; break;
		default:break;
		}
	}
}
