// прямой цикл с удалением по условию
for(auto wIter = words.begin(); wIter!=words.end();)
{
	if(WidgetAddSettings::all.contains(*wIter))
	{
		AddAddSetting(*wIter);
		words.erase(wIter);
	}
	else ++wIter;
}