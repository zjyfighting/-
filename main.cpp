#include"Hash.h"
#include"Binary.h"
#include<iostream>
using namespace std;
char KeyWords[32][10] = //�����ά����洢32���ؼ���/32���������10�����ʳ���
{
	"auto","break","case","char","const","continue",
	"default","do","double","else","enum","extern",
	"float","for","goto","if","int","long","register",
	"return","short","signed","sizeof","static",
	"struct","switch","typedef","union","unsigned",
	"void","volatile","while",
};
void menu()
{
	cout << "\t===========��ѡ����\n";
	cout << "\t===========1.����Hash����\n";
	cout << "\t===========2.����˳�����\n";
	cout << "\t===========3.�˳�\n";
}

int main()
{
	while(1)
	{
	Hash hx;
	SeqList seq;
	int sr;
	menu();
	cin >> sr;
	switch (sr)
	{
	case 1:
	{
		hx.ReadFile("Binary.cpp");
		for (int i = 0; i < 41; i++)
		{
			hx.Show(i);
		}
		int s = hx.CalNum();
		cout << "�ؼ��ʲ����ܴ���Ϊ��" << s << "\n\n\n";
		break;
	}


	case 2:
	{
		seq.CreatSeq(KeyWords);
		seq.ReadFile("Binary.cpp");
		for(int i=0;i<32;i++)
		{
			seq.Show(i);
		}
		int s = seq.CalNum();
		cout << "�ؼ��ʲ����ܴ���Ϊ��" << s << "\n\n\n";
		break;
	}
	case 3:
	{
		return 0;
	}
	default: 
	{
		cout << "��������ȷ��ֵ\n";
		break;
	}
	}
	}
}