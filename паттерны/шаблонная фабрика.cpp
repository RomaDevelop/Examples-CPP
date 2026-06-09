class IWidget: public HaveClassName, public IWidgetNameValue
{
public:

	static std::unique_ptr<IWidget> CreateIWidget(const QString &creationField)
	{
		...
		for(auto &factory:widgetsFactories)
		{
			createResult = factory(creationField, widgetCreationCommand);
			if(createResult.widget or not createResult.tryCreateOther)
				break;
		}
		...
	}

	struct CreateResult
	{
		bool tryCreateOther = true;
		std::unique_ptr<IWidget> widget;
	};

	using WidgetFactory = std::function<CreateResult(const QString &, const QStringList &)>;
	inline static std::vector<WidgetFactory> widgetsFactories;
	/// для регистрации функции создания виджета в классе-реализации объявить в private:
	/// inline static bool isRegistred = []() { IWidget::widgetsFactories.push_back(&Class::TryCreate); return true; } ();
	
	...
};