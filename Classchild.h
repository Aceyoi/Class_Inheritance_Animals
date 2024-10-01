// Код создан Сапожниковым Ю.С.
// Создание классов наследования
// Используемые библиотеки

#include <iostream>
#include <string>


using namespace std;

// Абстрактный класс Animal
class Animal {
public:
	// Добавляем геттеры
	string getName() const { return name; }
	size_t getAge() const { return age; }
	string getBreed() const { return breed; }

	// Конструктор // todo:
	Animal(string n, size_t a, string b) : name(n), age(a), breed(b) {
		if (a < 0 || a > 20) { throw runtime_error("Ошибка: недопустимый возраст"); }
	}

	// Виртуальный метод делает класс абстрактным
	virtual void print() const = 0;

	// Виртуальный деструктор
	virtual ~Animal() {}

protected:
	string name;    // Кличка животного
	size_t age;     // Возраст животного
	string breed;   // Порода животного
}; /// get set

// Класс Cat наследуемый от Animal
class Cat: public Animal {
public:
	// Конструктор
	Cat(string name, size_t age, string breed, string furColor)
		: Animal{ name, age, breed }, furColor(furColor)
	{}

	//Методы
	void print() const override {
		cout << "Это кошка!" << endl;
		cout << "Кличка: " << name << endl
			<< "Возраст: " << age << endl
			<< "Порода: " << breed << endl
			<< "Цвет шерсти: " << furColor << endl;
	}

private:
	string furColor;
};

// Класс Dog наследуемый от Animal
class Dog: public Animal {
public:
	// Конструктор
	Dog(string name, size_t age, string breed, string favoriteToy)
		: Animal{ name, age, breed }, favoriteToy(favoriteToy)
	{}
	//Методы
	void print() const override{
		cout << "Это собака!" << endl;
		cout << "Кличка: " << name << endl
			<< "Возраст: " << age << endl
			<< "Порода: " << breed << endl
			<< "Любимая игрушка: " << favoriteToy << endl;
	}

private:
	string favoriteToy;
};

void printanimal(const Animal* animal) {
	animal->print();  // Здесь происходит полиморфный вызов метода print()
}