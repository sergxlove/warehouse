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
	wh.read_file(arr, path);
	wh.print_menu();
	while (!exit)
	{
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
			wh.read_file(arr, path);
			cout << "Данные успешно считаны" << endl;
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
				cout << "В векторе нет объектов" << endl;
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
				cout << "В векторе нет объектов" << endl;
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
				cout << "В векторе нет объектов" << endl;
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
				cout << "В векторе нет объектов" << endl;
			}
			break;
		case 8:
			if(!arr.empty())
			{
				wh.sort_field(arr);
				cout << "Сортировка проведена успешна" << endl;
				cout << "===================================================" << endl;
			}
			else
			{
				cout << "В векторе нет объектов" << endl;
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
				cout << "В векторе нет объектов" << endl;
			}
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

void warehouse::print_data()
{
	cout << "Объект класса warehouse" << endl;
	cout << "Категория товара : " << category << endl;
	cout << "Наименование товара : " << name << endl;
	cout << "Название производителя : " << maker << endl;
	cout << "Стоимость товара : " << price << endl;
	cout << "Количество товара : " << quantity << endl;
	cout << "Дата поступления : " << date << endl;
	cout << "Номер ячейки : " << number << endl;
	cout << "===================================================" << endl;
}

void warehouse::print_info()
{
	cout << "Доступные поля" << endl;
	cout << "1 - Категория товара" << endl;
	cout << "2 - Наименование товара" << endl;
	cout << "3 - Название производителя" << endl;
	cout << "4 - Стоимость товара" << endl;
	cout << "5 - Количество товара" << endl;
	cout << "6 - Дата поступления" << endl;
	cout << "7 - Номер ячейки" << endl;
}

void warehouse::print_mm()
{
	cout << "Доступные поля" << endl;
	cout << "1 - Стоимость товара" << endl;
	cout << "2 - Количество товара" << endl;
	cout << "3 - Номер ячейка" << endl;
}

void warehouse::set_data()
{
	cout << "Введите категорию товара" << endl;
	cin >> category;
	cout << "Введите наименование товара" << endl;
	cin >> name;
	cout << "Введите название производителя" << endl;
	cin >> maker;
	cout << "Введите стоимость товара" << endl;
	cin >> price;
	cout << "Введите количество товара" << endl;
	cin >> quantity;
	cout << "Введите дату поступления" << endl;
	cin >> date;
	cout << "Введите номер ячейки" << endl;
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
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void warehouse::delete_object(vector<warehouse>& arr)
{
	int count = 0;
	int var = 0;
	cout << "Доступные объекты для удаления" << endl;
	for (auto& el : arr)
	{
		cout << "Объект " << count << endl;
		count++;
	}
	cout << "Выберите объект для удаления" << endl;
	cin >> var;
	if (var >= 0 && var < arr.size())
	{
		arr.erase(arr.begin() + var);
		cout << "Объект успешно удален" << endl;
	}
	else
	{
		cout << "Некорктный ввод " << endl;
	}
}

void warehouse::search_field(vector<warehouse>& arr)
{
	warehouse w;
	string field;
	int var = 0;
	bool check = false;
	w.print_info();
	cout << "Выберите необходимое поле" << endl;
	cin >> var;
	cout << "Введите данные для поиска " << endl;
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
			cout << "Некоректный ввод" << endl;
			break;
		}
	}
	if (!check)
	{
		cout << "Ничего не найдено" << endl;
	}
}

void warehouse::search_min(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	int min = 10000000;
	w.print_mm();
	cout << "Выберите поле для определения минимального" << endl;
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
		cout << "Минимальный элемент = " << min << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.quantity < min)
			{
				min = el.quantity;
			}
		}
		cout << "Минимальный элемент = " << min << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (el.number < min)
			{
				min = el.number;
			}
		}
		cout << "Минимальный элемент = " << min << endl;
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
}

void warehouse::search_max(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	int max = 0;
	w.print_mm();
	cout << "Выберите поле для определения максимального" << endl;
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
		cout << "Максимальный элемент = " << max << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (el.quantity > max)
			{
				max = el.quantity;
			}
		}
		cout << "Максимальный элемент = " << max << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (el.number > max)
			{
				max = el.number;
			}
		}
		cout << "Максимальный элемент = " << max << endl;
		break;
	default:
		cout << "Некоректный ввод" << endl;
		break;
	}
}

void warehouse::sort_field(vector<warehouse>& arr)
{
	warehouse w;
	int var = 0;
	w.print_info();
	cout << "Выберите нужное поле" << endl;
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
		cout << "Некорректный ввод" << endl;
		break;
	}
}
