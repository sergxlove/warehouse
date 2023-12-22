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
	bool exit = false;
	while (!exit)
	{
		
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
}
