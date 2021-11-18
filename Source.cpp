#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include "stdio.h"
#include "ctype.h"
#include <string>
#include<iomanip>
#include<sstream>
using namespace std;
stringstream container;
int leng = 15;
struct Student
{
	string surname;
	string name;
	string direction;
	int number;
};
void pechat(string s)
{
	int i, p;
	p = leng - s.size();
	if (p <= 0) p = 1;
	for (i = 0; i < p; i++)
		cout << " ";
}

void pall(Student* A, int ch)
{
	int i;
	string s;
	cout << "Студент"; pechat("Студент");
	cout << "|Фамилия";  pechat("|Фамилия");
	cout << "|Имя"; pechat("|Имя");
	cout << "|Направление"; pechat("|Направление");
	cout << "|Номер группы"; pechat("|Номер группы"); cout << "|";
	cout << endl;
	for (i = 0; i < ch; i++)
	{
		cout << i + 1;
		container.clear();
		container << i + 1;
		container >> s;
		pechat(s);
		cout << "|" << A[i].surname; pechat("|" + A[i].surname);
		cout << "|" << A[i].name; pechat("|" + A[i].name);
		cout << "|" << A[i].direction; pechat("|" + A[i].direction);
		cout << "|" << A[i].number;
		container.clear();
		container << A[i].number;
		container >> s;
		pechat("|" + s); cout << "|";
		cout << endl;
	}
}
void napr(Student* A, int ch, string buff)
{
	int i, kolvo = 0, p = 1, k;
	string s;
	for (i = 0; i < ch; i++)
	{
		if (A[i].direction == buff) kolvo += 1;
	}
	int* B;
	B = new int[kolvo + 1];
	B[0] = kolvo;
	for (i = 0; i < ch; i++)
	{
		if (A[i].direction == buff)
		{
			B[p] = i;
			p += 1;
		}
	}
	if (B[0] == 0) cout << "Студентов на данном направлении подготовки нет" << endl;
	else
	{
		cout << "Студент"; pechat("Студент");
		cout << "|Фамилия";  pechat("|Фамилия");
		cout << "|Имя"; pechat("|Имя");
		cout << "|Направление"; pechat("|Направление");
		cout << "|Номер группы"; pechat("|Номер группы"); cout << "|";
		cout << endl;
		for (k = 1; k < B[0] + 1; k++)
		{
			i = B[k];
			cout << k;
			container.clear();
			container << k;
			container >> s;
			pechat(s);
			cout << "|" << A[i].surname; pechat("|" + A[i].surname);
			cout << "|" << A[i].name; pechat("|" + A[i].name);
			cout << "|" << A[i].direction; pechat("|" + A[i].direction);
			cout << "|" << A[i].number;
			container.clear();
			container << A[i].number;
			container >> s;
			pechat("|" + s); cout << "|";
			cout << endl;
		}
	}
}
int* gruppa(Student* A, int ch, string buff, int number)
{
	int i, kolvo = 0, p = 1, k;
	for (i = 0; i < ch; i++)
	{
		if ((A[i].direction == buff) && (A[i].number == number))  kolvo += 1;
	}
	int* B;
	B = new int[kolvo + 1];
	B[0] = kolvo;
	for (i = 0; i < ch; i++)
	{
		if ((A[i].direction == buff) && (A[i].number == number))
		{
			B[p] = i;
			p += 1;
		}
	}
	return B;
}
void gruppapechat(Student* A, int ch, int* B)
{
	int i, p = *B, k;
	string s;
	if (*B == 0) cout << "Студентов в данной группе нет" << endl;
	else
	{
		cout << "Студент"; pechat("Студент");
		cout << "|Фамилия";  pechat("|Фамилия");
		cout << "|Имя"; pechat("|Имя");
		cout << "|Направление"; pechat("|Направление");
		cout << "|Номер группы"; pechat("|Номер группы"); cout << "|";
		cout << endl;
		struct Student J;
		struct Student* C;
		C = new struct Student[*B];
		for (k = 0; k < p; k++)
		{
			B++;
			i = *B;
			C[k] = A[i];
		}
		for (k = 1; k < p; k++)
			for (i = 0; i < p - 1; i++)
			{
				if (C[i].surname > C[i + 1].surname)
				{
					J = C[i + 1];
					C[i + 1] = C[i];
					C[i] = J;
				}
				if (C[i].surname == C[i + 1].surname)
					if (C[i].name > C[i + 1].name)
					{
						J = C[i + 1];
						C[i + 1] = C[i];
						C[i] = J;
					}
			}
		for (i = 0; i < p; i++)
		{
			cout << i + 1;
			container.clear();
			container << i + 1;
			container >> s;
			pechat(s);
			cout << "|" << C[i].surname; pechat("|" + C[i].surname);
			cout << "|" << C[i].name; pechat("|" + C[i].name);
			cout << "|" << C[i].direction; pechat("|" + C[i].direction);
			cout << "|" << C[i].number;
			container.clear();
			container << C[i].number;
			container >> s;
			pechat("|" + s); cout << "|";
			cout << endl;
		}
	}
}
void init(Student& student)
{
	cout << "Введите фамилию студента " << endl;
	getline(cin, student.surname);
	if (student.surname.size() >= leng) leng = student.surname.size() + 2;
	cout << "Введите имя студента " << endl;
	getline(cin, student.name);
	if (student.name.size() >= leng) leng = student.name.size() + 2;
	cout << "Введите направление студента " << endl;
	getline(cin, student.direction);
	if (student.direction.size() >= leng) leng = student.direction.size() + 2;
	cout << "Введите номер группы студента " << endl;
	cin >> student.number;
	cin.get();
	cout << "________________________________" << endl;
}
void prin(Student student)
{
	cout << "Фамилия студента " << endl;
	cout << student.surname << endl;
	cout << "Имя студента " << endl;
	cout << student.name << endl;
	cout << "Направление студента " << endl;
	cout << student.direction << endl;
	cout << "Номер группы студента " << endl;
	cout << student.number << endl;
	cout << "________________________________" << endl;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "Russian");
	int i, n, p, ch = 0, number;
	n = 10;
	string buff;
	int* group;
	struct Student* A;
	A = new struct Student[n];
	struct Student* A1;
	A1 = new struct Student[n];
	while (1 > 0)
	{
		cout << "Меню" << endl;
		cout << "________________________________" << endl;
		cout << "Добавить новый элемент............................1" << endl;
		cout << "Распечатать базу студентов........................2" << endl;
		cout << "Определить студентов по направлению подготовки....3" << endl;
		cout << "Определить студентов по номеру группы.............4" << endl;
		cout << "Выход из программы................................5" << endl;
		cout << "Введите номер функции  "; cin >> p;
		while (p > 5)
		{
			cout << "Введите номер функции  "; cin >> p;
		}
		cin.get();
		cout << endl;
		cout << endl;
		if (p == 1)
		{
			init(A[ch]);
			ch += 1;
			for (i = 0; i < ch; i++)
			{
				A1[i] = A[i];
			}
			delete[] A;
			A = new struct Student[ch + 1];
			for (i = 0; i < ch; i++)
			{
				A[i] = A1[i];
			}
			delete[] A1;
			A1 = new struct Student[ch + 1];
		}
		if (p == 2)
		{
			pall(A, ch);
		}
		if (p == 3)
		{
			cout << "Введите направление: " << endl;
			getline(cin, buff);
			napr(A, ch, buff);
		}
		if (p == 4)
		{
			cout << "Введите направление: " << endl;
			getline(cin, buff);
			cout << "Введите номер группы: " << endl;
			cin >> number;
			cin.get();
			group = gruppa(A, ch, buff, number);
			gruppapechat(A, ch, group);
		}
		if (p == 5) break;
	}
	return 0;
}
