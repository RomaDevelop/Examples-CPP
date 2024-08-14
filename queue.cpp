#include <queue>
using namespace std;

queue<QString> recieved;

recieved.push("some text");  
	
void MainWindow::on_Timer1()
{
	bool added = recieved.size();
	for(unsigned int i=0; i < recieved.size(); i++)
		// i < recieved.size(); оказывает положитьельное влияние на производительность, поскольку пока выполняется тело цикла
		// очередь пополняется и не осуществляется перевызов функции на вновь добавленные элементы
	{
		ui->textEditReceive->append(recieved.front());
		recieved.pop();
	}
	if(added) ui->textEditReceive->moveCursor(QTextCursor::End);
}

//==========================================================================================================
// сравнение производительности очисти очереди 
//==========================================================================================================
#include <string>
#include <iostream>
#include <chrono>
#include <queue>
using namespace std;

int main()
{
    
    queue<string> *messages = new queue<string>;
    for(int i=0; i<5000000; i++) messages->push("some text");
    
	auto start_time = std::chrono::steady_clock::now();
	// арена испытаний

    while (!messages->empty()) messages->pop();
    //delete messages;
    //messages = new queue<string>;

	// конец арены
	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	string nano = std::to_string(elapsed_ns.count());
	for(int i=nano.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) nano.insert(i," ");
	
	cout << nano;

	return 0;
}
// результат
while (!messages->empty()) messages->pop();
265 261 247 306 252

delete messages;
messages = new queue<string>;
218 241 219 215 212 196
//==========================================================================================================
