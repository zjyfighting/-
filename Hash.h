#pragma once
#include<iostream>
#include<string.h>
using namespace std;

struct H
{
	char keyword[10] = "";//��¼�ؼ���
	int count = 0;//��¼�ؼ��ʳ��ִ���
	int num = 0;//��¼�Ƚϴ���
};
class Hash//Hash���ģ��
{
public:
	H hash[42];
	bool isKeyWords(char *word);//�ж��Ƿ�Ϊ�ؼ���
	bool isLetter(char ch);
	int CalNum();
	int GetKey(char *keyword);//�ؼ�������Hash��λ��
	int Search(int key);//���ҿ�λ
	int CreatHash(char* keyword);//����Hash��,������һ����һ���ķ�ʽ
    int ReadFile(char* filename);
	void Show(int key);
	char KeyWords[32][10] = //�����ά����洢32���ؼ���/32���������10�����ʳ���
	{
		"auto","break","case","char","const","continue",
		"default","do","double","else","enum","extern",
		"float","for","goto","if","int","long","register",
		"return","short","signed","sizeof","static",
		"struct","switch","typedef","union","unsigned",
		"void","volatile","while",
	};
};

