# создание
// через new
thread *tr = new thread([](){
	for(int i=0; i<5; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		qdbg << "new thread" << i;
	}
	qdbg << "new thread end";
});

// напрямую
thread tr2([](){
	for(int i=0; i<5; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		qdbg << "thread2" << i;
	}
	qdbg << "thread2 end";
});


# завершение
detach();	// отсоединение от основного потока. Если в потоке бесконечный цикл, поток будет работать, пока работает программа
				// после detach смело можно делать delete
				// так же если поток был создан не через new, он может быть уничтожен выходом из зоны видимости
				
join();		// ожидание завершения потока
				// если поток не завершится - поток из которого вызывано join - зависнет
				
// если поток будет уничтожен (delete или зоной видимости) 
// до того как было выполнено detach или join - программа критует

