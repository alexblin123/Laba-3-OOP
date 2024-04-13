#include <iostream>

using namespace std;

class Pair {
	
private:

	int firstNum;
	double secondNum;

public:

	Pair();
	Pair(int first, double second);
	Pair(const Pair& num);

	int returnFirst();
	double returnSecond();

	void setFirst(int);
	void setSecond(double);
	void printNums();
	void addConst(int);
	void addConst(double);
	void operator+(int);
	void operator+(double);
	void operator=(const Pair&);
	void operator-(const Pair&);
	double difference();

	~Pair();

};

Pair::Pair() {

	cout << "\nКонструктор по умолчанию\n";
	firstNum = 12;
	secondNum = 3.5;
	
}

Pair::Pair(int firstOfNums, double secondOfNums) {

	cout << "\nКонструктор с параметрами\n";
	this->firstNum = firstOfNums;
	this->secondNum = secondOfNums;
}

Pair::Pair(const Pair& someNum) {

	cout << "\nКонструктор копирования\n";
	this->firstNum = someNum.firstNum;
	this->secondNum = someNum.secondNum;
}

Pair::~Pair() {
	cout << "\nЭто деструктор\n";
}

double Pair::difference() {
	cout << "\nПервое число - второе число: ";
	return (this->firstNum) - (this->secondNum);
}

void Pair::addConst(int num) {

	cout << "\nСложение первого числа с " << num << " : ";
	this->firstNum += num;
	cout << endl;
}

void Pair::addConst(double num) {
	cout << "\nСложение второго числа с " << num << " : ";
	this->secondNum += num;
	cout << endl;
}

void Pair::printNums() {

	cout << this->firstNum << " : " << this->secondNum;
}

void Pair::setFirst(int num) {
	this->firstNum = num;
}

void Pair::setSecond(double num) {
	this->secondNum = num;
}

void Pair::operator=(const Pair& number) {

	cout << "\nВызов оператора '='\n";
	this->firstNum = firstNum;
	this->secondNum = secondNum;
}

void Pair::operator+(int number) {

	cout << "\nВызов оператора '+' для первого числа\n";
	firstNum += number;
}

void Pair::operator+(double number) {

	cout << "\nВызов оператора '+' для второго числа\n";
	secondNum += number;
}

void Pair::operator-(const Pair& number) {

	firstNum -= number.firstNum;
	secondNum -= number.secondNum;
}

int Pair::returnFirst() {
	return firstNum;
}

double Pair::returnSecond() {
	return secondNum;
}

ostream& operator<<(ostream& outPut, Pair& num) { // перегружаем вывод

	cout << "\nПерегрузка оператора '<<'\n";
	outPut << num.returnFirst() << " : " << num.returnSecond() << endl;
	return outPut;
}

istream& operator>>(istream& inPut, Pair& num) {

	cout << "\nПерегрузка оператора '>>'\n";
	int firstNum;
	double secondNum;
	inPut >> firstNum >> secondNum;
	num.setFirst(firstNum);
	num.setSecond(secondNum);
	return inPut;
}

int main() {

	system("chcp 1251 > Null");

	Pair firstExample(7, 2.32);
	firstExample.printNums();
	cout << endl;

	cout << "\nРазность чисел: " << firstExample.difference() << endl;

	firstExample.addConst(6);
	firstExample.printNums();
	cout << endl;

	firstExample.addConst(3.75);
	firstExample.printNums();
	cout << endl;

	Pair secondExample;
	secondExample.printNums();
	cout << endl;

	Pair thirdExample(firstExample);
	thirdExample.printNums();
	cout << endl;

	Pair exampleFour;
	exampleFour = firstExample;
	exampleFour.printNums();
	cout << endl;

	cin >> firstExample;
	cout << firstExample << endl;

	secondExample - firstExample;
	cout << secondExample << endl;

	firstExample + 5;
	firstExample + 2.56;
	cout << firstExample << endl;
		

}