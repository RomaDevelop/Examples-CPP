
//https://leetcode.com/problems/lru-cache/description/

// нужно оптимизировать, используя метод std::list::splice. 
// Он позволяет переместить узел в начало или конец списка без удаления и повторного выделения памяти (перепривязкой указателей), 
// что еще быстрее, чем связка erase + insert. 
// Least Recently Used (LRU) cache

#include <list>
#include <unordered_map>
using namespace std;

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
