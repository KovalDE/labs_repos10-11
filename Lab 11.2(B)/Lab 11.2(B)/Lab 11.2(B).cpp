#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h> 
using namespace std;

enum Spec { KN, INF, ME, FI, TN };
string SpecStr[] = { "Комп.наука", "Інформатика", "Математика та Економіка", "Фізика та Інформатика", "Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Spec spec;
	int physics;
	int math;
	union
	{
		int program;
		int metods;
		int pedag;
	};
};
void Create(Student* p, char* fname);
void Print(Student* p, char* fname);
double LineSearch(Student* p, char* fname);
double LineSearch1(Student* p, char* fname);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student* p = new Student[10000];
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	Create(p, fname);
	Print(p, fname);
	int cnt = LineSearch1(p, fname);
	cout << "Кількість студентів,які навчаються на відмінно та добре:" << endl;
	cout << cnt << endl;
	int proc = LineSearch(p, fname);
	cout << "Процент студентів, у яких середній бал менший 4:" << endl;
	cout << proc << '%' << endl;
	return 0;
}
void Create(Student* p, char* fname)
{
	ofstream fout(fname, ios::binary);
	int spec;
	char ch;
	int i = 0;
	do{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " Спеціальність: (0 - Комп.науки, 1 -Інформатика , 2 - Математика та економіка, 3 - Фізика та Інформатика,4 - Трудове навчання): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " Оцінка по фізиці: ";cin >> p[i].physics;
		cout << " Оцінка по математиці: ";cin >> p[i].math;
		switch (p[i].spec)
		{
		case KN:
			cout << " Оцінка по програмуванню : "; cin >> p[i].program;
			break;
		case INF:
			cout << " Оцінка по чисельним методам : "; cin >> p[i].metods;
			break;
		case ME:
		case FI:
		case TN:
			cout << " Оцінка з педагогіки: "; cin >> p[i].pedag;
			break;
		}
		cout << endl;
		if (!fout.write((char*)&p, sizeof(Student)))
		{
			cerr << "Error writing file." << endl;
		}
		cout << "continue? (y/n): "; cin >> ch;
		i++;
	} while (ch == 'y' || ch == 'Y');
}
void Print(Student* p, char* fname)
{
	ifstream fin(fname, ios::binary);
	int i = 0;
	cout << "=============================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Предмет по фаху |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	while (fin.read((char*)&p, sizeof(Student)))
	{
		cout << "|" << setw(3) << right << i + 1 << " ";
		cout << "|  " << setw(6) << left << p[i].prizv << "| " << setw(4) << right << p[i].kurs << "  "
			<< "| " << setw(6) << left << SpecStr[p[i].spec] << setw(4);
		cout << "   |" << setw(4) << right << p[i].physics << setw(4) << right << "| ";
		cout << setw(4) << right << p[i].math << setw(4) << right << "    | ";
		switch (p[i].spec)
		{
		case KN:
			cout << setw(4) << right << p[i].program << setw(8) << right << "    | " << endl;
			break;
		case INF:
			cout << setw(4) << right << p[i].metods << setw(8) << right << "    | " << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << setw(4) << right << p[i].pedag << setw(8) << right << "| " << endl;
			break;
		}
		i++;
	}
	cout << "==============================================================================" << endl;
}
double LineSearch(Student* p, char* fname) {
	int n = 0, k = 0;
	ifstream fin(fname, ios::binary);
	int i = 0;
	while (fin.read((char*)&p, sizeof(Student)))
	{
		n++;
		switch (p[i].spec)
		{
		case KN:
			if (((p[i].program + p[i].physics + p[i].math) / 3) < 4)
				k++;
			break;
		case INF:
			if (((p[i].metods + p[i].physics + p[i].math) / 3) < 4)
				k++;
			break;
		case ME:
		case FI:
		case TN:
			if (((p[i].pedag + p[i].physics + p[i].math) / 3) < 4)
				k++;
			break;
		}
		i++;
	}
	return 100 * k / n;
}
double LineSearch1(Student* p, char* fname) {
	int n = 0;
	ifstream fin(fname, ios::binary);
	int i = 0;
	while (fin.read((char*)&p, sizeof(Student)))
	{
		switch (p[i].spec)
		{
		case KN:
			if ((p[i].program > 3) && (p[i].physics > 3) && (p[i].math > 3))
				n++;
			break;
		case INF:
			if ((p[i].metods > 3) && (p[i].physics > 3) && (p[i].math > 3))
				n++;
			break;
		case ME:
		case FI:
		case TN:
			if ((p[i].pedag > 3) && (p[i].physics > 3) && (p[i].math > 3))
				n++;
			break;
		}
	}
	return n;
}