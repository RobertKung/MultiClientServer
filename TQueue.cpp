/*#include "TQueue.h"

template<class T>
TQueue<T>::TQueue()
{

}
template<class T>
TQueue<T>::~TQueue()
{

}

template<class T>
void TQueue<T>::push(T n_value)
{
    std::lock_guard<std::mutex> lk(_mutex);
    data.push(std::move(n_value));
    cons.notify_one();
}

template<class T>
void TQueue<T>::pop(T& p_value)
{
	std::unique_lock<std::mutex> lk(_mutex);
	cons.wait(lk,[this]{return !data.empty();});
	p_value = std::move(data.front());
	data.pop();
}

template<class T>
bool TQueue<T>::empty()
{
	std::lock_guard<std::mutex> lk(_mutex);
	return data.empty();
}*/