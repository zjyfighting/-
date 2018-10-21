#pragma once
#include"Hash.h"
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//�ж�
bool Hash::isKeyWords(char *word)
{
	for (int i = 0; i < 32; i++)
	{
		if (strcmp(word, KeyWords[i]) == 0)//����ǹؼ���
			return true;
	}
	return false;//������Ҳ����Ͳ��ǹؼ���
}
//���ҹؼ���λ��
int Hash::GetKey(char* keyword)
{
	return (keyword[0] * 100 + keyword[strlen(keyword) - 1]) %41;
}
//�ҿ�λ
int Hash::Search(int key)
{
	if (key<0 || key >= 41) return -1;
	for (int i = key + 1; i < 41; i++)
	{
		if (strlen(hash[i].keyword) == 0)//���Ϊ��
		{
			hash[i].num = hash[key].num + (i - key);
			return i;
		}
	}
	for (int j = 0; j < key; j++)
	{
		if (strlen(hash[j].keyword) == 0)//���Ϊ��
		{
			hash[j].num = hash[key].num + j + (42 - key);
			return j;
		}
	}
	return -1;
}
//����Hash��
int Hash::CreatHash(char* keyword)
{
	
	//���ж�
	if (!isKeyWords(keyword))
		return -1;
	//�ж�Hashλ��
	int key = GetKey(keyword);
	//���Ϊ��ǰλ��Ϊ��,�����
	if (strlen(hash[key].keyword) == 0)
	{
		strcpy(hash[key].keyword, keyword);
		hash[key].count++;
		hash[key].num++;
		return 1;
	}
	else
	{
		//�����Ϊ�գ�����ͬ
		if (strcmp(hash[key].keyword, keyword) == 0)
		{
			hash[key].count++;
			return 1;
		}
		//�����Ϊ�գ��Ҳ���ͬ
		else
		{
			int emptyseat=Search(key);//Ѱ�ҿյ�λ��
			strcpy(hash[key].keyword, keyword);//�ڿյ�λ�ò���ؼ���
			hash[emptyseat].count++;
			return 1;
		}
	}
	cout << "over";
}
bool Hash::isLetter(char ch)
{
	if ((ch >= 'a'&&ch <= 'z')|| (ch >= 'A'&&ch <= 'Z'))
		return true;
	return false;
}
int Hash::CalNum()
{
	int sum=0;
	for (int j = 0; j < 41; j++)
	{
		sum = sum + (hash[j].count*hash[j].num);
	}
	return sum;
}
int Hash::ReadFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	char text[1024];
	while (!feof(file))//ֱ���ļ��Ľ�β
	{
		int i = 0;
		char word[10] = { "" };
		char ch = fgetc(file);//����һ���ַ�
		while (!isLetter(ch)&& feof(file) == 0)//���¶�ֱ������ĸ 
			ch = fgetc(file);
		while (isLetter(ch) && feof(file) == 0)//�����������ĸ����Ҫ��ʼ�ŵ�Hash������
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
					   //�����ж�
		if (isKeyWords(word))
			CreatHash(word);
	}
	fclose(file);
	return 1;
}
//=========================================�������
void Hash::Show(int key)
{
	if (strlen(hash[key].keyword) == 0)
	{
		cout << "��ϣ���λ��:" << key << "     ���ִ���Ϊ0" << '\n';
		return;
	}
	cout << "��ϣ���λ��:" << key << "     �ؼ���:" << hash[key].keyword << "     ���ִ���:" << hash[key].count << "\n";
}
