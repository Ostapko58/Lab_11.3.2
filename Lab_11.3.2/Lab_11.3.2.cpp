#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<string>
using namespace std;


enum Specialnists
{
	computer_science,
	informatics,
	math_a_economics,
	physics_and_informatics,
	labor_education
};

struct Student
{
	char prizv[20];
	//string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};

};


void ToFile(Student& stud, const int N, char* filename);
void Create(Student& stud, const int N, char* filename)
{
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " �������: "; cin.getline(stud.prizv, 20);
		do
		{
			if (strpbrk(stud.prizv, "0 123456789") != NULL)
			{
				//stud.prizv.erase(0, -1);
				cout << "�� ����� ������ �������, ���������� �����: " << endl;
				cout << " �������: "; cin.getline(stud.prizv, 20);
			}
		} while (strpbrk(stud.prizv, "0 123456789") != NULL);
		cout << " ����: "; cin >> stud.kyrs;
		do
		{
			if (cin.fail() || stud.kyrs < 1 || stud.kyrs>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ ����, ���������� �����: " << endl;
				cout << " ����: "; cin >> stud.kyrs;
			}
		} while (cin.fail() || stud.kyrs < 1 || stud.kyrs>5);

		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialst;
		do
		{
			if (cin.fail() || specialst < 0 || specialst>4)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������������(0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������) : ";
				cin >> specialst;
			}
		} while (cin.fail() || specialst < 0 || specialst>4);
		stud.specialst = (Specialnists)specialst;
		cout << " ������ � ����������: "; cin >> stud.math_grade;
		do
		{
			if (cin.fail() || stud.math_grade < 1 || stud.math_grade>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ � ����������: "; cin >> stud.math_grade;
			}
		} while (cin.fail() || stud.math_grade < 1 || stud.math_grade>5);
		cout << " ������ � ������: "; cin >> stud.physics_grade;
		do
		{
			if (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5)
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ � ������: "; cin >> stud.physics_grade;
			}
		} while (cin.fail() || stud.physics_grade < 1 || stud.physics_grade>5);
		switch (stud.specialst)
		{
		case computer_science:
			cout << " ������ � ������������� : "; cin >> stud.programing_grade;
			do
			{
				if (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � �������������: "; cin >> stud.programing_grade;
				}
			} while (cin.fail() || stud.programing_grade < 1 || stud.programing_grade>5);
			break;
		case informatics:
			cout << " ������ � ��������� ������ : "; cin >> stud.chisel_metod_grade;
			do
			{
				if (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � ��������� ������: "; cin >> stud.chisel_metod_grade;
				}
			} while (cin.fail() || stud.chisel_metod_grade < 1 || stud.chisel_metod_grade>5);
			break;
		default:
			cout << " ������ � ��������� : "; cin >> stud.pedagogic_grade;
			do
			{
				if (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5)
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ � ���������: "; cin >> stud.pedagogic_grade;
				}
			} while (cin.fail() || stud.pedagogic_grade < 1 || stud.pedagogic_grade>5);
			break;
		}
		cout << endl;
		ToFile(stud, N, filename);
	}

}

void ToFile(Student& stud, const int N, char* filename)
{
	ofstream f(filename, ios::binary | ios::app);
	f.write((char*)&stud, sizeof(Student));
	f.close();
}

void PrintFromFile(Student& stud, const int N, string* List, char* filename)
{
	ifstream f(filename, ios::binary);
	int num = 1;
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| � |     �������     | ���� |      ������������      | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	while (f.read((char*)&stud, sizeof(Student)))
	{
		cout << "| " << setw(1) << right << num++ << " ";
		cout << "| " << setw(17) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(23) << left << List[stud.specialst] << " "
			<< "| " << setw(19) << right << stud.math_grade << " "
			<< "| " << setw(15) << right << stud.physics_grade << " ";
		switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud.chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
	}
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
}

Student fRead(ifstream& f, const int i)
{
	Student tmp;
	f.seekg(i * (long)sizeof(Student)); // ���������� ��������
	f.read((char*)&tmp, sizeof(Student)); // ��������� ��������
	return tmp;
}

void IndexSort(Student& stud, const int N, char* gname, char* fname)
{
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);
	int* I = new int[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		I[i] = i; // ��������� ���� ����������� ������
	int i0, i1, value,i,j; // �������� ��������� ����� �������
	//for (i0 = 1; i0 < N; i0++)
	//{
	//	value = I[i0];
	//	for (i1 = 10-1; i1 >=0; i1--)
	//	{
	//		Student a = fRead(f, I[i1]);
	//		Student b = fRead(f, value);
	//		if ((a.specialst > b.specialst)
	//			||
	//			(a.specialst == b.specialst &&
	//				a.math_grade < b.math_grade)
	//			||
	//			(a.specialst == b.specialst &&
	//				a.math_grade == b.math_grade &&
	//				a.prizv > b.prizv))
	//		{
	//			//fChange(f, i1, i1 + 1);
	//			I[i1 + 1] = I[i1];
	//		}
	//	}
	//	I[i1 + 1] = value;
	//	
	//}
	for (i = 1; i < N; i++)
	{
		value = I[i];
		Student b = fRead(f, value);
		for (j = i - 1; j >= 0; j--)
		{
			Student a = fRead(f, I[j]);
			if ((a.specialst > b.specialst)
				||
				(a.specialst == b.specialst &&
					a.math_grade < b.math_grade)
				||
				(a.specialst == b.specialst &&
					a.math_grade == b.math_grade &&
					a.prizv[0] > b.prizv[0])
				||
				(a.specialst == b.specialst &&
					a.math_grade == b.math_grade &&
					a.prizv[0] == b.prizv[0]&&
					a.prizv[1] > b.prizv[1]))
			{
				I[j + 1] = I[j];
			}
			else
			{
				break;
			}
		}
		I[j + 1] = value;
	}
	for (int i = 0; i < N; i++)
	{
		g.write((char*)&I[i], sizeof(int));
	}
	g.close();
	delete[] I;
}


void IndexPrint(Student& stud, const int N, char* gname, char* fname, string* List)
{ 
	int* I = new int[N];
	ifstream f(fname, ios::binary);
	ifstream g(gname, ios::binary);
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		g.read((char*)&I[i], sizeof(int));
	}
	cout << endl;
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| � |     �������     | ���� |      ������������      | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		f.seekg(I[i] * (long)sizeof(Student)); // ���������� ��������
		f.read((char*)&stud, sizeof(Student));
		cout << "| " << setw(1) << right << i+1 << " ";
		cout << "| " << setw(17) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(23) << left << List[stud.specialst] << " "
			<< "| " << setw(19) << right << stud.math_grade << " "
			<< "| " << setw(15) << right << stud.physics_grade << " ";
		switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud.chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
	}
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
	delete[] I;
	f.close();
	g.close();
	
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string List[] = {
	"��������� �����",
	"�����������",
	"���������� �� ��������",
	"Գ���� �� �����������",
	"������� ��������"
	};
	char fname[60];
	cout << "������ ��'� ����� ��� ������: "; cin.getline(fname, 60);
	char gname[60];
	cout << "������ ��'� ����� ��� ������ �������: "; cin.getline(gname, 60);
	int N;
	cout << "������ N: "; cin >> N;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "�� ����� ����� ���, ���������� �����: " << endl;
			cout << "������ N: "; cin >> N;
		}
	} while (cin.fail());
	Student stud;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - �������������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(stud, N, fname);
			break;
		case 2:
			PrintFromFile(stud, N, List, fname);
			break;
		case 3:
			IndexSort(stud, N, gname, fname);
			IndexPrint(stud, N, gname, fname, List);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ������ ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}