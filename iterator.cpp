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

// !!! нельзя использовать base() обратных итераторов для удаления !!!

// обратный цикл с прямыми итераторами, можно удалять
auto it = prev(v.end());
while(true)
{
    bool first (it == v.begin());
    cout << *it << " ";
    if(first) break;
    --it;
}

for(auto it = prev(v.end()); true; --it)
{
    bool first (it == v.begin());
    cout << *it << " ";
    if(first) break;
}