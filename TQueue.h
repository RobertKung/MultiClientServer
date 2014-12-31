#ifndef TQUEUE_H
#define TQUEUE_H
#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

template<class T>
class TQueue{

   private:
   	 std::queue<T> data;
   	 mutable std::mutex _mutex;
   	 std::condition_variable cons;
   public:
   	   TQueue(){}
      ~TQueue(){}
       void push(T n_value)
       {
       	std::lock_guard<std::mutex> lk(_mutex);
    	data.push(std::move(n_value));
    	cons.notify_one();
       }
       void pop(T& p_value)
       {
       	std::unique_lock<std::mutex> lk(_mutex);
		cons.wait(lk,[this]{return !data.empty();});
		p_value = std::move(data.front());
		data.pop();
       }
      
       bool empty()
       {
       	std::lock_guard<std::mutex> lk(_mutex);
		return data.empty();
       }

};



#endif