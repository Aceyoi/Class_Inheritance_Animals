// ��� ������ ������������ �.�.
// �������� ������� ������������
// ������������ ����������

#include <iostream>
#include <string>


using namespace std;

// ����������� ����� Animal
class Animal {
public:
	// ��������� �������
	string getName() const { return name; }
	size_t getAge() const { return age; }
	string getBreed() const { return breed; }

	// ����������� // todo:
	Animal(string n, size_t a, string b) : name(n), age(a), breed(b) {
		if (a < 0 || a > 20) { throw runtime_error("������: ������������ �������"); }
	}

	// ����������� ����� ������ ����� �����������
	virtual void print() const = 0;

	// ����������� ����������
	virtual ~Animal() {}

protected:
	string name;    // ������ ���������
	size_t age;     // ������� ���������
	string breed;   // ������ ���������
}; /// get set

// ����� Cat ����������� �� Animal
class Cat: public Animal {
public:
	// �����������
	Cat(string name, size_t age, string breed, string furColor)
		: Animal{ name, age, breed }, furColor(furColor)
	{}

	//������
	void print() const override {
		cout << "��� �����!" << endl;
		cout << "������: " << name << endl
			<< "�������: " << age << endl
			<< "������: " << breed << endl
			<< "���� ������: " << furColor << endl;
	}

private:
	string furColor;
};

// ����� Dog ����������� �� Animal
class Dog: public Animal {
public:
	// �����������
	Dog(string name, size_t age, string breed, string favoriteToy)
		: Animal{ name, age, breed }, favoriteToy(favoriteToy)
	{}
	//������
	void print() const override{
		cout << "��� ������!" << endl;
		cout << "������: " << name << endl
			<< "�������: " << age << endl
			<< "������: " << breed << endl
			<< "������� �������: " << favoriteToy << endl;
	}

private:
	string favoriteToy;
};

void printanimal(const Animal* animal) {
	animal->print();  // ����� ���������� ����������� ����� ������ print()
}