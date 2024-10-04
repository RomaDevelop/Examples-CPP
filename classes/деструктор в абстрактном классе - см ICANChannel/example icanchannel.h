

class ICANChannel
{
public:
	virtual ~ICANChannel() = default;  
	// если не определить деструктор в абстрактном и создать в наследнике вылезает варнинг
	// а иногда вообще не компилируется

	...

};

#endif // CANCHANNEL_H
