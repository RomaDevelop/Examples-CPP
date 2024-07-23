// преобразование указателей в строку

	static QString PtrToStr(HaveClassName* ptr) 
	{ 
		quint64 ptrVal = (quint64)ptr;
		return QString::number(ptrVal,16); 
	}
	static HaveClassName* PtrFromStr(QString strPtr)
	{
		bool ok;
		quint64 ptrVal = strPtr.toULongLong(&ok,16);
		if(!ok) Logs::ErrorSt("PtrFromStr: wrong strPtr ["+strPtr+"]");
		return (HaveClassName*)ptrVal;
	}