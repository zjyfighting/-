#pragma once
#include"Binary.h"
#include<cstring>
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int SeqList::CreatSeq(char Key[32][10])
{
//���ַ����鰴��string������
/*	char temp[10]="";
	for (int i = 0; i < 32; i++)//ִ������ѡ�񷨡�
		for (int j = i + 1; j<32; j++)
		{
			if (strcmp(Key[i],Key[j]) > 0)//�Ƚ�
			{
				strcpy(temp, Key[i]);
				strcpy(Key[i],Key[j]);
				strcpy(Key[j],temp);//������Ϊ������
			}
		}*/
	//==========================��ӽ�˳���
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Key[i][j]>='a'&&Key[i][j]<='z')
			{
				node[i].keyword[j]=Key[i][j];
			}
		}
	}
	return 1;
}
bool SeqList::isKeyword(char* word)
{
	for (int i = 0; i < 32; i++)
	{
		if (strcmp(word, KeyWords[i]) == 0)//����ǹؼ���
			return true;
	}
	return false;//������Ҳ����Ͳ��ǹؼ���
}
bool SeqList::isLetter(char ch)
{
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		return true;
	return false;
}
int SeqList::BiSearch(char* keyword)
{
	int low = 0;//��0��ʼ
	int high = 31;//��31Ϊֹһ��32��Keyword
	int mid;
	int s = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(KeyWords[mid],keyword)==0)
		{
			node[mid].count++;
			s++;
			node[mid].num = s;
			return 1;
		}
		else if (strcmp(KeyWords[mid], keyword)<0)
		{
			low = mid + 1;
			s++;
		}
		else
		{
			high = mid - 1;
			s++;
		}
	}
	return -1;
}
int SeqList::CalNum()
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
		sum = sum + node[i].count*node[i].num;
	return sum;
}
int SeqList::ReadFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	char text[1024];
	while (!feof(file))//ֱ���ļ��Ľ�β
	{
		int i = 0;
		char word[10] = { "" };
		char ch = fgetc(file);//����һ���ַ�
		while (!isLetter(ch) && feof(file) == 0)//���¶�ֱ������ĸ 
			ch = fgetc(file);
		while (isLetter(ch) && feof(file) == 0)//�����������ĸ
		{
			//�������10����ĸ˵���϶�����,����������һ������
			if (i == 10)
			{
				while (isLetter(ch) && feof(file) == 0)
				{
					ch = getc(file);
				}
				i = 0;
				break;
			}
			else//��������word����ɵ��ʽ����жϺ����
			{
				word[i] = ch;
				i++;
				ch = getc(file);
			}
		}
		word[i] = '\0';//������\0����
		if(isKeyword(word))
		   BiSearch(word);
	}
	fclose(file);
	return 1;
}
void SeqList::Show(int key)
{
	cout << "�ؼ���"<<node[key].keyword << "    ���ֵĴ���Ϊ��" << node[key].count<<"\n";
}