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
		char text[] = { "�û���Ϣ�ռ�ϵͳ" };


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
		outtextxy((Width - textwidth("1.����û���Ϣ")) / 2 + 120, (Height - textheight("1.����û���Ϣ")) / 2 + 180, ("1.����û���Ϣ"));
		outtextxy((Width - textwidth("2.��ʾ�û���Ϣ")) / 2 + 120, (Height - textheight("2.��ʾ�û���Ϣ")) / 2 + 260, ("2.��ʾ�û���Ϣ"));
		outtextxy((Width - textwidth("3.ɾ���û���Ϣ")) / 2 + 120, (Height - textheight("3.ɾ���û���Ϣ")) / 2 + 340, ("3.ɾ���û���Ϣ"));
		outtextxy((Width - textwidth("4.�����û���Ϣ")) / 2 + 370, (Height - textheight("4.�����û���Ϣ")) / 2 + 180, ("4.�����û���Ϣ"));
		outtextxy((Width - textwidth("5.�޸��û���Ϣ")) / 2 + 370, (Height - textheight("5.�޸��û���Ϣ")) / 2 + 260, ("5.�޸��û���Ϣ"));
		outtextxy((Width - textwidth("6.�˳�ϵͳ")) / 2 + 370, (Height - textheight("6.�˳�ϵͳ")) / 2 + 340, ("6.�˳�ϵͳ"));
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
		cout << "ϵͳ���ܼ�¼�û��Ѵ�����";
	}
	else
	{
		cout << "�������û�����" << endl;
		cin >> (a + num)->name;
		cout << "����������" << endl;
		cin >> (a + num)->age;
		cout << "�������û��Ա��������������1��Ů������0��" << endl;
		cin >> (a + num)->sex;
		cout << "�Ƿ�Ϊ��Ƥ�����������1����������0" << endl;
		cin >> (a + num)->skin;
		cout << "��ӳɹ�"<<endl;
		num++;
	}
	system("pause");
	system("cls");
}
void showperson(person* a, int num)
{
	if (num == 0)
	{
		cout << "�û���ϢΪ��" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "������" << (a + i)->name << endl;
			cout << "���䣺" << (a + i)->age << endl;
			cout << "�Ա�(1Ϊ�У�0ΪŮ����" << (a + i)->sex << endl;
			cout << "Ƥ��(1Ϊ��Ƥ��0���ǣ���" << (a + i)->skin << endl;
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
	cout << "��������Ҫɾ�����û�����" << endl;
	string name;
	cin >> name;
	int x = isexist(a, name);
	if (x == -1)
	{
		cout << "���޴���" << endl;
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
		
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(person* a, int num)
{
	cout << "�����û�����" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < num; i++)
	{
		if ((a + i)->name == name)
		{
			cout << "������" << (a + i)->name << endl;
			cout << "���䣺" << (a + i)->age << endl;
			cout << "�Ա�(1Ϊ�У�0ΪŮ����" << (a + i)->sex << endl;
			cout << "Ƥ��(1Ϊ��Ƥ��0���ǣ���" << (a + i)->skin << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void changeperson(person* a, int num)
{
	cout << "�����û�����" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < num; i++)
	{
		if ((a + i)->name == name)
		{
			cout << "�������û�����" << endl;
			cin >> (a + i)->age;
			cout << "�������û��Ա�" << endl;
			cin >> (a + i)->sex;
			cout << "�������û�Ƥ��״��" << endl;
			cin >> (a + i)->skin;
		}
	}
	cout << "�޸����" << endl;
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
		case 6: cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0; break;
		default:break;
		}
	}
}
