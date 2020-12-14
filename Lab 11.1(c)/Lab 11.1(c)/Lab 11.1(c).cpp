#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include < stdio.h >

using namespace std;

void CreateBIN(char* fname)
{
	FILE* f;
	f = fopen(fname, "wb");
	if ((f = fopen(fname, "wb")) == NULL)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		exit(1);
	}
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		for (unsigned i = 0; i < s.length(); i++)
			fwrite((char*)&s[i], sizeof(s[i]),1,f);
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fclose(f);

}
void PrintBIN(char* fname)
{
	FILE* f;
	f = fopen(fname, "rb");
	char c;
	while (fread((char*)&c, sizeof(c), 1, f))
	
	{
		cout << c;
	}
	cout << endl;
	fclose(f);

}
void ProcessBIN1(char* fname, char* gname)
{
	FILE* f;
	FILE* t;
	f = fopen(fname, "rb");
	t = fopen(gname, "wb");
	char c; // прочитаний символ
	while (!feof(f))
	{
		c = getc(f);
		if (!(c >= '0' && c <= '9'))
			putc(c, t);
	}
	fclose(f);
	fclose(t);

}

int main()
{
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname);
	PrintBIN(fname);
	char gname[100];
	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname);
}

