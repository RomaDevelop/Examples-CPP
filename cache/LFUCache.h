I solved this problem in two hours without google or gpt. Week ago i solved LRUCache problem, so I moved next. But I also haven't encountered LFUCache theme before, it has been reinvented anew ) But my solution doesn't matches all conditions. Therefore it beats only 25-40%.

Approach
We use unordered_map to save key and value. Than we shoud save keys of different frequensies, and we need the lowest freq to remove, when cache is full. So I used map (bin-ordered). Also we need to remove lowest freq with oldest usage, so value of freq map can be LRUCache. I used my realisation LRUCache from that problem withot any modification. It is not O(1), but I could'nt quickly understand how to use unordered_map for freq map instead map, so I submitted this solution.

Than I start think about optimisation, and realized that we can use unordered_map+list+iterator for remove like in LRUCache. I started reading about it, and my hunch was confirmed. We also need to store and update the minimum frequency value. I couldn't figure out how to use it or what would happen if there was a gap in the frequencies, but it's actually fine; it works. Maybe I'll add optimiztion to this solution someday.

Code

struct LRUCacheItem
{
	int value;
	std::list<int>::iterator itInUsages;
};

class LRUCache {
	unordered_map<int, LRUCacheItem> cache;
	list<int> keysUsages;
	int capacity;
public:
	inline static int capacity_for_default_constructor = 100;
	LRUCache() {
		this->capacity = capacity_for_default_constructor;
		cache.reserve(this->capacity);
	}
	LRUCache(int capacity) {
        this->capacity = capacity;
		cache.reserve(this->capacity);
	}

	void erase(int key)
	{
		auto findRes = cache.find(key);
		if(findRes == cache.end()) return;

		LRUCacheItem &item = findRes->second;
		keysUsages.erase(item.itInUsages); // удаляем из очереди
		cache.erase(key);
	}

	bool empty() { return cache.empty(); }

	int get_oldest() { return keysUsages.front(); }

	int get(int key) {
		auto findRes = cache.find(key);
		if(findRes == cache.end()) return -1;

		LRUCacheItem &item = findRes->second;
		keysUsages.erase(item.itInUsages);
		item.itInUsages = keysUsages.insert(keysUsages.end(), key);

		return item.value;
	}

	void put(int key, int value) {
		auto findRes = cache.find(key);
		if(findRes != cache.end()) // ключ уже есть в кеше
		{
			LRUCacheItem &item = findRes->second;
			item.value = value;												// обновляем значение
			keysUsages.erase(item.itInUsages);								// удаляем из очереди
			item.itInUsages = keysUsages.insert(keysUsages.end(), key);		// добавляем в конец очереди
		}
		else // findRes == cache.end() : ключа нет в кеше
		{
			if(cache.size() < capacity)	// кеш не заполнен, просто добавляем
			{
				auto itInUsages = keysUsages.insert(keysUsages.end(), key);
				cache[key] = {value, itInUsages};
			}
			else // кеш заполнен
			{
				int removingKey = keysUsages.front();  // удаляем первый из очереди
				keysUsages.pop_front();
				cache.erase(removingKey);

				auto itInUsages = keysUsages.insert(keysUsages.end(), key); // добавляем новый в конец очереди
				cache[key] = {value, itInUsages};
			}
		}
	}
};


struct LFUCacheItem
{
	int value;
	int freq = 1;
	//itFreq_t itFreq;
};

class LFUCache {
	unordered_map<int, LFUCacheItem> cacheByKey;
	map<int, LRUCache> keysByFreq;
	uint capacity;

public:
	LFUCache(int capacity) {
        LRUCache::capacity_for_default_constructor = capacity;
		if(capacity < 0)
		{
			cerr << "LFUCache created with capacity " << capacity << "; capacity seted 100";
			capacity = 100;
		}
		this->capacity = capacity;
		cacheByKey.reserve(this->capacity);
	}

	int get(int key) {
		auto findRes = cacheByKey.find(key);
		if(findRes == cacheByKey.end()) return -1;

		LFUCacheItem &item = findRes->second;

		auto &keysWithCurrFreq = keysByFreq[item.freq];
		keysWithCurrFreq.erase(key);
		if(keysWithCurrFreq.empty())
			keysByFreq.erase(item.freq);

		item.freq++;

		auto &keysWithNewFreq = keysByFreq[item.freq];
		keysWithNewFreq.put(key, 0);

		return item.value;
	}

	void put(int key, int value) {
		auto findRes = cacheByKey.find(key);
		if(findRes == cacheByKey.end()) // ключа нет в кеше
		{
			if(cacheByKey.size() < capacity)	// кеш не заполнен, просто добавляем
			{
				auto &item = cacheByKey[key];
				item.value = value;

				auto &keysWithNewFreq = keysByFreq[item.freq];
				keysWithNewFreq.put(key, 0);
			}
			else // кеш заполнен
			{
				// нужно удалить минимально используемую запись
					// пока удаляю первую попавшуюся из минимальных
					// а потом добавлю что бы не первую а самую старую
				auto &keysWithMinFreq = keysByFreq.begin()->second;
				if(keysWithMinFreq.empty()) cout << "keysWithMinFreq!!!!";
				int keyWithMinFreq = keysWithMinFreq.get_oldest();
				//qdbg << MyQString::JoinSep(" ", "put key:value =", key, value, "erase", keyWithMinFreq);
				//QString s;
				//for(auto k:keysWithMinFreq) s+=QSn(k)+" ";
				//qdbg << "keysWithMinFreq("+QSn(keysWithMinFreq.size())+")" << s;
				keysWithMinFreq.erase(keyWithMinFreq);
				if(keysWithMinFreq.empty())
					keysByFreq.erase(keysByFreq.begin());

				cacheByKey.erase(keyWithMinFreq);

				auto &item = cacheByKey[key];
				item.value = value;

				auto &keysWithNewFreq = keysByFreq[item.freq];
				keysWithNewFreq.put(key, 0);
			}
		}
		else // ключ уже есть в кеше
		{
			LFUCacheItem &item = findRes->second;
			item.value = value;

			auto &keysWithCurrFreq = keysByFreq[item.freq];
			keysWithCurrFreq.erase(key);
			if(keysWithCurrFreq.empty())
				keysByFreq.erase(item.freq);

			item.freq++;

			auto &keysWithNewFreq = keysByFreq[item.freq];
			keysWithNewFreq.put(key, 0);
		}
	}
};