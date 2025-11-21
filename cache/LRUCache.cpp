
https://leetcode.com/problems/lru-cache/description/

struct CacheItem
{
	int value;
	std::list<int>::iterator itInUsages;
};

class LRUCache {
	unordered_map<int, CacheItem> cache;
	list<int> keysUsages;
	int capacity;
public:
	LRUCache(int capacity) {
        this->capacity = capacity;
		cache.reserve(this->capacity);
	}

	int get(int key) {
		auto findRes = cache.find(key);
		if(findRes == cache.end()) return -1;

		CacheItem &item = findRes->second;
		keysUsages.erase(item.itInUsages);
		item.itInUsages = keysUsages.insert(keysUsages.end(), key);

		return item.value;
	}

	void put(int key, int value) {
		auto findRes = cache.find(key);
		if(findRes != cache.end()) // ключ уже есть в кеше
		{
			CacheItem &item = findRes->second;
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