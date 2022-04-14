#include "iostream"
#include "fstream"
#include "string"
#include <vector>

using namespace std;

ifstream f("LAB9.txt");
struct student
{
	string fname, sname, lname;
	string sex;
	string faculty, group;
	int mas[5], curse;
	void print();
};

void student::print()
{
	cout << fname << " " << sname << " " << lname << endl;
}

student tip;
bool checkmass(student a, vector<string>& m)
{
	if (m.empty())
		return true;
	for (int i = 0;i<m.size(); i++)
	{
		if (m[i] == a.group)
			return false;
	}
	return true;
}

void out(vector<student>& vec)
{
	system("chcp 1251");
	student check;
	cout << "Ввекдите факультет" << endl;
	getline(cin, check.faculty);
	vector <string> mas;
	string b;
	for (int i = 0; i < vec.size(); i++)
	{

		if (vec[i].faculty == check.faculty && checkmass(vec[i], mas))
		{
			mas.push_back(vec[i].group);

		}
	}
	for (int i = 0; i < mas.size(); i++)
	{
		cout << "Группа" << mas[i]<<endl;
		for (int j = 0; j < vec.size(); j++)
		{
			if (mas[i] == vec[j].group)
			{
				vec[j].print();
			}
		}
	}
	/*
	cout << "Ввекдите номер группы" << endl;
	cin >> check.group;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].faculty == check.faculty && vec[i].group == check.group)
		{
			vec[i].print();
		}
	}*/


}
int main()
{
	//system("chcp 1251");



	int n = 0;
	string s, l;

	vector<student> spisok;

	while (f.peek() != EOF)
	{
		spisok.push_back(tip);
		getline(f, l);
		spisok[n].fname = l;
		getline(f, l);
		spisok[n].sname = l;
		getline(f, l);
		spisok[n].lname = l;
		getline(f, l);
		spisok[n].sex = l;
		getline(f, l);
	    spisok[n].faculty = l;
		getline(f, l);
		spisok[n].curse =stoi(l);
		getline(f, l);
		spisok[n].group = l;
		for (int i = 0; i < 5; i++)
		{
			getline(f, s);
			spisok[n].mas[i] = stoi(s);
		}
		n++;
		getline(f, l);
	}

	out(spisok);


	system("Pause");
}