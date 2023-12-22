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
	string category;//категория товара
	string name;//наименование товара
	string maker;//произодитель
	int price;//стоимость
	int quantity;//количество
	string date;//дата поступления
	int number;//номер ячейки
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
		cout << "Выберите режим : " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			wh.set_data();
			arr.push_back(wh);
			cout << "Объект успешно создан" << endl;
			cout << "===================================================" << endl;
			break;
		case 2:
			wh.write_file(arr, path);
			cout << "Данные успешно сохранены" << endl;
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
			cout << "Программа завершена" << endl;
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
	cout << "Доступные режимы: " << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Сохранение данных в файл" << endl;
	cout << "3 - Чтение данных из файла" << endl;
	cout << "4 - Удаление данных из файла" << endl;
	cout << "5 - Поиск данных по полям" << endl;
	cout << "6 - Поиск минимального элемента" << endl;
	cout << "7 - Поиск максимального элемента" << endl;
	cout << "8 - Сортировка по полю" << endl;
	cout << "9 - Вывод данных" << endl;
	cout << "10 - Выход из программы " << endl;
	cout << "===================================================" << endl;
}

void warehouse::set_data()
{
	cout << "Введите категорию товара" << endl;
	cin >> this->category;
	cout << "Введите наименование товара" << endl;
	cin >> this->name;
	cout << "Введите название производителя" << endl;
	cin >> this->maker;
	cout << "Введите стоимость товара" << endl;
	cin >> this->price;
	cout << "Введите количество товара" << endl;
	cin >> this->quantity;
	cout << "Введите дату поступления" << endl;
	cin >> this->date;
	cout << "Введите номер ячейки" << endl;
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
		cout << "Ошибка открытия файла" << endl;
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
		cout << "Ошибка открытия файла" << endl;
	}
}
