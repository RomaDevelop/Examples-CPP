/// если активировано Только длинные переносы - пропускать тех у кого не длинный перенос
/// а если не активировано - не пропускает никого
std::function<bool(Note*)> ContinueIfLongEnabledAndNotLong = [](Note*){ return false; };
if(widgetAlarms->LongPostponeOnly())
	ContinueIfLongEnabledAndNotLong = [](Note* note){
		return not Features::CheckFeature(note->Content(), Features::longPostpone);
	};

for(auto &note:notes)
{
	auto secsToAlarmCurrent = note->note->SecsToAlarm(currentDateTime);
	if(secsToAlarmCurrent <= 0)
	{
		if(ContinueIfLongEnabledAndNotLong(note->note.get())) continue;

		alarmedNotes.insert(note->note.get());
	}
	else
	{
		if(secsToAlarmCurrent <= secsToNextAlarmMax)
		{
			if(ContinueIfLongEnabledAndNotLong(note->note.get())) continue;

			nextAlarmsNotes[secsToAlarmCurrent].emplace_back(note->note.get());
		}

		if(secsToNextAlarmNote > secsToAlarmCurrent)
		{
			nextAlarmNote = note->note.get();
			secsToNextAlarmNote = secsToAlarmCurrent;
		}
	}
}