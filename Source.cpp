#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class warehouse
{
public:
	warehouse();
	warehouse(string category, string name, string maker, int price, int quantity, string date, int number);
	~warehouse();
	void print_menu();
	void set_data();
	void write_file(vector<warehouse>& arr, string path);
	void read_file(vector<warehouse>& arr, string path);

private:
	string category;//��������� ������
	string name;//������������ ������
	string maker;//������������
	int price;//���������
	int quantity;//����������
	string date;//���� �����������
	int number;//����� ������
};
int main()
{
	setlocale(LC_ALL, "rus");
	warehouse wh;
	vector<warehouse> arr;
	int var_switch = 0;
	string path = "data.txt";
	bool exit = false;
	while (!exit)
	{
		wh.print_menu();
		cout << "�������� ����� : " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			wh.set_data();
			arr.push_back(wh);
			cout << "������ ������� ������" << endl;
			cout << "===================================================" << endl;
			break;
		case 2:
			wh.write_file(arr, path);
			cout << "������ ������� ���������" << endl;
			cout << "===================================================" << endl;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			cout << "===================================================" << endl;
			cout << "��������� ���������" << endl;
			cout << "===================================================" << endl;
			exit = true;
			break;
		}
	}
	return 0;
}

warehouse::warehouse()
{
	this->category = "";
	this->name = "";
	this->maker = "";
	this->price = 0;
	this->quantity = 0;
	this->date = "";
	this->number = 0;
}

warehouse::warehouse(string category, string name, string maker, int price, int quantity, string date, int number)
{
	this->category = category;
	this->name = name;
	this->maker = maker;
	this->price = price;
	this->quantity = quantity;
	this->date = date;
	this->number = number;
}

warehouse::~warehouse()
{
	this->category = "";
	this->name = "";
	this->maker = "";
	this->price = 0;
	this->quantity = 0;
	this->date = "";
	this->number = 0;
}

void warehouse::print_menu()
{
	cout << "===================================================" << endl;
	cout << "��������� ������: " << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - ���������� ������ � ����" << endl;
	cout << "3 - ������ ������ �� �����" << endl;
	cout << "4 - �������� ������ �� �����" << endl;
	cout << "5 - ����� ������ �� �����" << endl;
	cout << "6 - ����� ������������ ��������" << endl;
	cout << "7 - ����� ������������� ��������" << endl;
	cout << "8 - ���������� �� ����" << endl;
	cout << "9 - ����� ������" << endl;
	cout << "10 - ����� �� ��������� " << endl;
	cout << "===================================================" << endl;
}

void warehouse::set_data()
{
	cout << "������� ��������� ������" << endl;
	cin >> this->category;
	cout << "������� ������������ ������" << endl;
	cin >> this->name;
	cout << "������� �������� �������������" << endl;
	cin >> this->maker;
	cout << "������� ��������� ������" << endl;
	cin >> this->price;
	cout << "������� ���������� ������" << endl;
	cin >> this->quantity;
	cout << "������� ���� �����������" << endl;
	cin >> this->date;
	cout << "������� ����� ������" << endl;
	cin >> this->number;
}

void warehouse::write_file(vector<warehouse>& arr, string path)
{
	fstream file;
	file.open(path, fstream::out);
	file.clear();
	if (file.is_open())
	{
		file << arr.size();
		for (auto& el : arr)
		{
			file << el.category;
			file << el.name;
			file << el.maker;
			file << el.price;
			file << el.quantity;
			file << el.date;
			file << el.number;
		}
		file.close();
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void warehouse::read_file(vector<warehouse>& arr, string path)
{
	string field;
	fstream file;
	int size = 0;
	warehouse w;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		getline(file, field);
		size = stoi(field);
		arr.clear();
		for (int i = 0;i < size;i++)
		{
			getline(file, w.category);
			getline(file, w.name);
			getline(file, w.maker);
			getline(file, field);
			w.price = stoi(field);
			getline(file, field);
			w.quantity = stoi(field);
			getline(file, w.date);
			getline(file, field);
			w.number = stoi(field);
			arr.push_back(w);
		}
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}
