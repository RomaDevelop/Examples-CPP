мат.часть

Примитивы синхронизации:
Взаимное исключение потоков - с критической областью работает только один поток
Синхронизация потоков - отслеживать наступление тех или иных конкретных событий, то есть поток не будет работать, пока не наступило какое-то событие
	Другой поток в таком случае должен гарантировать наступление данного события
	
Объкты синхронизации
critical section - критическая секция - EnterCriticalSection - LeaveCriticalSection - внутри одного процесса
mutex - взаимоисключение - пока mutex заблокирован, с ним нельзя работать из друого потока - возможно межпроцессная блокировка (в winapi - точно)
event - событие - для уведомления ожидающих нитей о наступлении какого-либо события
semaphore - семафор - взаимоисключение со счетчиком, т.е. к семафор(5) получат доступ не более 5 потоков, 
atomic  - работа с глобальными переменными из всех нитей, не заботясь о синхронизации, т.к. эти функции сами за ней следят – их выполнение атомарно

Прочитал
Многопоточность в C++. Основные понятия (поверхностный обзор STL)
https://radioprog.ru/post/1402#:~:text=Многопоточность%20(multithreading)%20–%20свойство%20платформы,без%20предписанного%20порядка%20во%20времени.

изучить позже
задача об обедающих философах;
проблема спящего парикмахера;
задача о курильщиках;
задача о читателях-писателях;
другие задачи.
Раздел deadlock

Прочитал
Синхронизация процессов и потоков (WinAPI)
http://www.codenet.ru/progr/cpp/process-threads-sync.php




https://habr.com/ru/articles/738250/
https://habr.com/ru/companies/otus/articles/549814/






