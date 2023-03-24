#include <iostream>
using namespace std;

// Абстрактный класс стола
class Table {
public:
	// Метод, который вызывается, когда на столе едят
	virtual void eatFood() = 0;
};

// Абстрактный класс стула
class Chair {
public:
	// Метод, который вызывается, когда на стуле сидят
	virtual void sit() = 0;
};

// Абстрактный класс шкафа
class Cupboard {
public:
	// Метод, который вызывается, когда используют шкаф
	virtual void use() = 0;
};

///////////////////////////////////////////////////////

// Конкретный класс стола деревянной мебели
class WoodenTable : public Table {
public:
	void eatFood() override {
		cout << "Eating food on a wooden table\n";
	}
};

// Конкретный класс стула деревянной мебели
class WoodenChair : public Chair {
public:
	void sit() override {
		cout << "Sitting on a wooden chair\n";
	}
};

// Конкретный класс шкафа деревянной мебели
class WoodenCupboard : public Cupboard {
public:
	void use() override {
		cout << "Using a wooden cupboard\n";
	}
};

// Конкретный класс стола пластиковой мебели
class PlasticTable : public Table {
public:
	void eatFood() override {
		cout << "Eating food on a plastic table\n";
	}
};

// Конкретный класс стула пластиковой мебели
class PlasticChair : public Chair {
public:
	void sit() override {
		cout << "Sitting on a plastic chair\n";
	}
};

// Конкретный класс шкафа пластиковой мебели
class PlasticCupboard : public Cupboard {
public:
	void use() override {
		cout << "Using a plastic cupboard\n";
	}
};

// Конкретный класс стола металлической мебели
class MetalTable : public Table {
public:
	void eatFood() override {
		cout << "Eating food on a metal table\n";
	}
};

// Конкретный класс стула металлической мебели
class MetalChair : public Chair {
public:
	void sit() override {
		cout << "Sitting on a metal chair\n";
	}
};

// Конкретный класс шкафа металлической мебели
class MetalCupboard : public Cupboard {
public:
	void use() override {
		cout << "Using a metal cupboard\n";
	}
};

///////////////////////////////////////////////////////

// Абстрактный класс для производства мебели
class FurnitureFactory {
public:
	// Создает объект стола
	virtual class Table* createTable() = 0;

	// Создает объект стула
	virtual class Chair* createChair() = 0;

	// Создает объект шкафа
	virtual class Cupboard* createCupboard() = 0;
};

///////////////////////////////////////////////////////

// Класс для производства деревянной мебели
class WoodenFurnitureFactory : public FurnitureFactory {
public:
	// Создает объект стола деревянной мебели
	Table* createTable() override {
		return new WoodenTable();
	}

	// Создает объект стула деревянной мебели
	Chair* createChair() override {
		return new WoodenChair();
	}

	// Создает объект шкафа деревянной мебели
	Cupboard* createCupboard() override {
		return new WoodenCupboard();
	}
};

// Класс для производства пластиковой мебели
class PlasticFurnitureFactory : public FurnitureFactory {
public:
	// Создает объект стола пластиковой мебели
	Table* createTable() override {
		return new PlasticTable();
	}

	// Создает объект стула пластиковой мебели
	Chair* createChair() override {
		return new PlasticChair();
	}

	// Создает объект шкафа пластиковой мебели
	Cupboard* createCupboard() override {
		return new PlasticCupboard();
	}
};

// Класс для производства металлической мебели
class MetalFurnitureFactory : public FurnitureFactory {
public:
	// Создает объект стола металлической мебели
	Table* createTable() override {
		return new MetalTable();
	}

	// Создает объект стула металлической мебели
	Chair* createChair() override {
		return new MetalChair();
	}

	// Создает объект шкафа металлической мебели
	Cupboard* createCupboard() override {
		return new MetalCupboard();
	}
};

void test(FurnitureFactory* factory) {
	Table* table = factory->createTable();
	Chair* chair = factory->createChair();
	Cupboard* cupboard = factory->createCupboard();

	// Используем мебель
	table->eatFood();
	chair->sit();
	cupboard->use();

	// Освобождаем память
	delete table;
	delete chair;
	delete cupboard;
}

// Пример использования фабрик мебели
int main() {

	FurnitureFactory* factory = new WoodenFurnitureFactory();
	// Создаем деревянную фабрику мебели
	test(factory);

	// Освобождаем память
	delete factory;

	factory = new PlasticFurnitureFactory();
	// Создаем пластиковую фабрику мебели
	test(factory);

	// Освобождаем память
	delete factory;
}

/*
Код включает в себя определение абстрактных классов
Table, Chair и Cupboard, а также конкретных классов
WoodenTable, WoodenChair, WoodenCupboard, PlasticTable,
PlasticChair, PlasticCupboard, MetalTable, MetalChair
и MetalCupboard, которые наследуют абстрактные классы.

Также определен абстрактный класс FurnitureFactory и его
конкретные реализации WoodenFurnitureFactory,
PlasticFurnitureFactory и MetalFurnitureFactory,
которые создают объекты Table, Chair и Cupboard
соответствующих типов мебели.

Функция test использует экземпляр FurnitureFactory для
создания объектов Table, Chair и Cupboard, а затем
вызывает их методы eatFood(), sit() и use()
соответственно.

Этот код использует принцип проектирования "Абстрактная
фабрика", который позволяет создавать объекты семейства
связанных продуктов без указания их конкретных классов.
Вместо этого код работает с абстрактными классами и
интерфейсами, которые определяют общие методы для
семейства продуктов.
*/

// https://refactoring.guru/ru/design-patterns/abstract-factory

/* 
Паттерн Абстрактная Фабрика(Abstract Factory) -
это паттерн проектирования, который позволяет создавать
семейства связанных объектов, не указывая их конкретные
классы.

Плюсы:

+ Обеспечивает высокий уровень абстракции и гибкость
проектирования.
+ Позволяет создавать объекты, не зависящие от конкретных
классов, что облегчает их замену.
+ Упрощает добавление новых семейств объектов в приложение.

Минусы :

- Усложняет код программы из-за необходимости создания
большого количества классов и интерфейсов.
- Увеличивает сложность программы, если в приложении нет
необходимости в использовании семейств объектов или
семейств объектов редко меняются.
- Необходимо тщательно проектировать и документировать
интерфейсы и классы, чтобы предотвратить ошибки
при работе с различными семействами объектов.

*/