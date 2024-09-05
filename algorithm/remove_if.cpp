// одним оператором
commands.erase(std::remove_if(commands.begin(), commands.end(),
	[](const QString& command){ return !command.contains(Import_ns::Policies::countPreviousElementsToCopy); }),
	commands.end());

// двумя операторами
auto removeRes = std::remove_if(words.begin(), words.end(), [](const QString &word){ return WidgetAddSettings::all.contains(word); });
words.erase(removeRes, words.end());