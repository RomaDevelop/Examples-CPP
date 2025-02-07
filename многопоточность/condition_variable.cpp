
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

#include "MyQString.h"
#include "MyQShortings.h"
#include "MyCppDifferent.h"

#include "widget.h"

mutex mtx;
condition_variable cv;
bool flag = false;

void CreateWidget();

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	CreateWidget();

	std::thread t([](){
		QTextStream stream(stdout);
		stream << "started\n" << flush;
		while(true)
		{
			std::unique_lock<std::mutex> lock(mtx);
			cv.wait(lock, [&stream] {
				stream << "cv checking\n" << flush;
				return flag;
			});
			lock.unlock();
			flag = false;

			stream << "cv check passed\n" << flush;

			QTextStream stream(stdout);
			for(int i = 0; i<10; i++)
			{
				MyCppDifferent::sleep_ms(300);
				stream << "." << flush;
			}
			stream << endl << flush;
		}
	});
	t.detach();

	return app.exec();
}

void CreateWidget()
{
	QWidget *w = new QWidget;

	QVBoxLayout *vlo_main = new QVBoxLayout(w);
	QHBoxLayout *hlo1 = new QHBoxLayout;
	QHBoxLayout *hlo2 = new QHBoxLayout;
	vlo_main->addLayout(hlo1);
	vlo_main->addLayout(hlo2);

	QPushButton *btn1 = new QPushButton("flag");
	hlo1->addWidget(btn1);
	QObject::connect(btn1,&QPushButton::clicked,[](){
		flag = true;
	});

	QPushButton *btn2 = new QPushButton("cv");
	QObject::connect(btn2,&QPushButton::clicked,[](){
		cv.notify_one();
	});
	hlo1->addWidget(btn2);

	QPushButton *btn3 = new QPushButton("flag cv");
	QObject::connect(btn3,&QPushButton::clicked,[](){
		flag = true;
		cv.notify_one();
	});
	hlo1->addWidget(btn3);

	hlo1->addStretch();

	auto textEdit = new QTextEdit;
	hlo2->addWidget(textEdit);

	w->show();
}

