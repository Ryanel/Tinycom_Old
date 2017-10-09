#pragma once
#include <vector>
#include <algorithm>
#include <cstdio>
template <class T>
class PriorityQueue {
private:
	// Layout in memory : high -> low
	std::vector<T> container;
public:
	void push(T value) {
		int insert_index = 0;
		for (int i = count() - 1; i >= 0; i--) {
			if (container[i] <= value) {
				if (container[i] == value) {
					return;
				}
				insert_index = i;
			}
		}
		if (count() == 0) { 
			container.emplace_back(value); 
			return; 
		}
		container.insert(container.begin() + insert_index, value);
	}

	T top() {
		if (container.size() == 0) {
			return T();
		}
		return container.back();
	}
	void pop() {
		if (container.size() > 0) {
			container.erase(container.end() - 1);
		}
	}

	size_t count() {
		return container.size();
	}
	bool empty() {
		return count() == 0;
	}
};