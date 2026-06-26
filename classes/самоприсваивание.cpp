// Класс-поле, который логирует свое присваивание
class Field {
private:
	QString data;

public:
	Field(QString val) : data(val) {}

	// Кастомный оператор присваивания с выводом в cout
	Field& operator=(const Field& other) {
		qdbg << "[Logger] Вызван оператор= для значения: '" << other.data << "'\n";

		// Дополнительно проверяем, произошло ли самоприсваивание на его уровне
		if (this == &other) {
			qdbg << "[Logger] ВНИМАНИЕ: Произошло самоприсваивание внутри Logger!\n";
		}

		this->data = other.data;
		return *this;
	}
};

// Большой класс, который использует дефолтный оператор присваивания
class Class {
public:
	QString name;
	Field field; // Наше поле с логированием

	Class(QString n, QString logVal)
		: name(n), field(logVal) {}

	// Оператор присваивания НЕ пишем.
	// Компилятор сгенерирует дефолтный, который автоматически
	// вызовет оператор= для id, name и logField.
	// и самоприсваивание отработает!
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	auto w = new MyQTableWidget();
	w->show();

	Class myObject("Основной Объект", "Данные");
	auto &myObjectRef = myObject;

	qdbg << "--- Начало теста ---\n";
	qdbg << "Вызываем самоприсваивание: myObject = myObject;\n";

	// Вызываем присвоение самому себе
	myObject = myObjectRef;

	qdbg << "--- Конец теста ---\n";

	return app.exec();
}

--- Начало теста ---
Вызываем самоприсваивание: myObject = myObject;
[Logger] Вызван оператор= для значения: ' "Данные" '
[Logger] ВНИМАНИЕ: Произошло самоприсваивание внутри Logger!
--- Конец теста ---