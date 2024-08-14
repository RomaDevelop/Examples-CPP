//#include <windows.h>
MEMORYSTATUSEX statex;
statex.dwLength = sizeof (statex);
GlobalMemoryStatusEx(&statex);

if(sumSizez > statex.ullAvailPhys / 40000000)
{
	if(QMessageBox::question(this, "Большой объем данных", "В указали файлов суммарны объемом " + QSn(sumSizez / (1024*1024))
							 + " Mb.\nОперативной памяти свободно " + QSn(statex.ullAvailPhys / (1024*1024))
							 + " Mb.\nВозможно переполнение оперативной памяти. Продолжать?",
							 QMessageBox::Yes|QMessageBox::No) == QMessageBox::No)
		return;
}