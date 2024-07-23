template<typename T>

class EasyData
{
public:
	template<typename T>
	void FromVect(const std::vector<T> &vectVals);
};

void EasyData::FromVect(const std::vector<T> &vectVals)
{
	static_assert(std::is_same<T,int>::value || std::is_same<T,bool>::value, "EasyData::FromVect wrong type (not int or bool)");
	// если передать в шаблон не int и не bool будет ошибка компиляции
	// typeid(myint).name()

	len = vectVals.size()/8 + 1;
	if(len > 8 || vectVals.size() > 64) Error("FromVect: to big size value" + QSn(vectVals.size()));
	for(uint i=0; i<vectVals.size(); i++)
	{
		if(vectVals[i] > 1 || vectVals[i] < 0) {
			data[i] = 0;
			Error("FromVect: to big value " + QSn(vectVals[i]));
		}
		else data[i] = vectVals[i];
	}
}