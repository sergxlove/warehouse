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
	void print_data();
	void print_info();
	void print_mm();
	void set_data();
	void write_file(vector<warehouse>& arr, string path);
	void read_file(vector<warehouse>& arr, string path);
	void delete_object(vector<warehouse>& arr);
	void search_field(vector<warehouse>& arr);
	void search_min(vector<warehouse>& arr);
	void search_max(vector<warehouse>& arr);
	void sort_field(vector<warehouse>& arr);
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
	wh.read_file(arr, path);
	wh.print_menu();
	while (!exit)
	{
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
			wh.read_file(arr, path);
			cout << "������ ������� �������" << endl;
			cout << "===================================================" << endl;
			break;
		case 4:
			if (!arr.empty())
			{
				wh.delete_object(arr);
				wh.write_file(arr, path);
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
			cout << "===================================================" << endl;
			break;
		case 5:
			if(!arr.empty())
			{ 
				wh.search_field(arr);
				cout << "===================================================" << endl;
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
			break;
		case 6:
			if(!arr.empty())
			{ 
				wh.search_min(arr);
				cout << "===================================================" << endl;
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
			break;
		case 7:
			if(!arr.empty())
			{ 
				wh.search_max(arr);
				cout << "===================================================" << endl;
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
			break;
		case 8:
			if(!arr.empty())
			{
				wh.sort_field(arr);
				cout << "���������� ��������� �������" << endl;
				cout << "===================================================" << endl;
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
			break;
		case 9:
			if (!arr.empty())
			{
				for (auto& el : arr)
				{
					el.print_data();
				}
			}
			else
			{
				cout << "� ������� ��� ��������" << endl;
			}
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

void warehouse::print_data()
{
	cout << "������ ������ warehouse" << endl;
	cout << "��������� ������ : " << category << endl;
	cout << "������������ ������ : " << name << endl;
	cout << "�������� ������������� : " << maker << endl;
	cout << "��������� ������ : " << price << endl;
	cout << "���������� ������ : " << quantity << endl;
	cout << "���� ����������� : " << date << endl;
	cout << "����� ������ : " << number << endl;
	cout << "===================================================" << endl;
}

void warehouse::print_info()
{
	cout << "��������� ����" << endl;
	cout << "1 - ��������� ������" << endl;
	cout << "2 - ������������ ������" << endl;
	cout << "3 - �������� �������������" << endl;
	cout << "4 - ��������� ������" << endl;
	cout << "5 - ���������� ������" << endl;
	cout << "6 - ���� �����������" << endl;
	cout << "7 - ����� ������" << endl;
}

void warehouse::print_mm()
{
	cout << "��������� ����" << endl;
	cout << "1 - ��������� ������" << endl;
	cout << "2 - ���������� ������" << endl;
	cout << "3 - ����� ������" << endl;
}

void warehouse::set_data()
{
	cout << "������� ��������� ������" << endl;
	cin >> category;
	cout << "������� ������������ ������" << endl;
	cin >> name;
	cout << "������� �������� �������������" << endl;
	cin >> maker;
	cout << "������� ��������� ������" << endl;
	cin >> price;
	cout << "������� ���������� ������" << endl;
	cin >> quantity;
	cout << "������� ���� �����������" << endl;
	cin >> date;
	cout << "������� ����� ������" << endl;
	cin >> number;
}

void warehouse::write_file(vector<warehouse>& arr, string path)
{
	fstream file;
	file.open(path, fstream::out);
	file.clear();
	if (file.is_open())
	{
		file << arr.size() << endl;
		for (auto& el : arr)
		{
			file << el.category<<endl;
			file << el.name<<endl;
			file << el.maker << endl;
			file << el.price << endl;
			file << el.quantity << endl;
			file << el.date<<endl;
			file << el.number << endl;
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
		file.close();
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void warehouse::delete_object(vector<warehouse>& arr)
{
	int count = 0;
	int var = 0;
	cout << "��������� ������� ��� ��������" << endl;
	for (auto& el : arr)
	{
		cout << "������ " << count << endl;
		count++;
	}
	cout << "�������� ������ ��� ��������" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		arr.erase(arr.begin() + var);
		cout << "������ ������� ������" << endl;
	}
	else
	{
		cout << "���������� ���� " << endl;
	}
}

void warehouse::search_field(vector<warehouse>& arr)
{
	warehouse w;
	string field;
	int var = 0;
	bool check = false;
	w.print_info();
	cout << "�������� ����������� ����" << endl;
	cin >> var;
	cout << "������� ������ ��� ������ " << endl;
	cin >> field;
	for (auto& el : arr)
	{
		switch (var)
		{
		case 1:
			if (field == el.category)
			{
				el.print_data();
				check = true;
			}
			break;
		case 2:
			if (field == el.date)
			{
				el.print_data();
				check = true;
			}
			break;
		case 3:
			if (field == el.maker)
			{
				el.print_data();
				check = true;
			}
			break;
		case 4:
			if (stoi(field) == el.price)
			{
				el.print_data();
				check = true;
			}
			break;
		case 5:
			if (stoi(field) == el.quantity)
			{
				el.print_data();
				check = true;
			}
			break;
		case 6:
			if (field == el.date)
			{
				el.print_data();
				check = true;
			}
			break;
		case 7:
			if (stoi(field) == el.number)
			{
				el.print_data();
				check = true;
			}
			break;
		default:
			cout << "����������� ����" << endl;
			break;
		}
	}
	if (!check)
	{
		cout << "������ �� �������" << endl;
	}
}

void warehouse::search_min(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	int min = 10000000;
	w.print_mm();
	cout << "�������� ���� ��� ����������� ������������" << endl;
	cin >> var;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (el.price < min)
			{
				min = el.price;
			}
		}
		cout << "����������� ������� = " << min << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.quantity < min)
			{
				min = el.quantity;
			}
		}
		cout << "����������� ������� = " << min << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (el.number < min)
			{
				min = el.number;
			}
		}
		cout << "����������� ������� = " << min << endl;
		break;
	default:
		cout << "����������� ����" << endl;
		break;
	}
}

void warehouse::search_max(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	int max = 0;
	w.print_mm();
	cout << "�������� ���� ��� ����������� �������������" << endl;
	cin >> var;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (el.price > max)
			{
				max = el.price;
			}
		}
		cout << "������������ ������� = " << max << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.quantity > max)
			{
				max = el.quantity;
			}
		}
		cout << "������������ ������� = " << max << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (el.number > max)
			{
				max = el.number;
			}
		}
		cout << "������������ ������� = " << max << endl;
		break;
	default:
		cout << "����������� ����" << endl;
		break;
	}
}

void warehouse::sort_field(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	w.print_info();
	cout << "�������� ������ ����" << endl;
	cin >> var;
	switch (var)
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.category < w2.category;});
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.name < w2.name;});
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.maker < w2.maker;});
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.price < w2.price;});
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.quantity < w2.quantity;});
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.date < w2.date;});
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const warehouse& w1, const warehouse& w2) {return w1.number < w2.number;});
		break;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}
