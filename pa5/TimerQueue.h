#ifndef TIMERQUEUE_H
#define TIMERQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <Timer.h>




class TimerQueue {
public:

	TimerQueue();
	void addItem(Timer item);

	Timer getItem();

private:
	std::queue<Timer> queue_;
  	std::mutex queueMutex_;
  	std::condition_variable queueCV_;

};







// template<class T>
// class ConcurrentQueue {
//  public:
//   using ConcurrentQueue() = default;

//   /**
//    * Add an item to the queue.
//    */
//   void addItem(T item) {
//     // grab a lock on the queue mutex and add an item
//     {
//       std::lock_guard<std::mutex> guard(queueMutex_);
//       queue_.push_back(item);
//     }

//     // use the condition variable to indicate that the queue has been updated
//     // (see below)
//     queueCV_.notify_one();
//   }

//   /**
//    * Remove an item from the queue.
//    *
//    * TODO: Use condition variable to prevent hanging on getItem() on shutdown.
//    * Could use Optional or exception to escape from getItem() routine.
//    */
//   T getItem() {
//     // the queue might be empty, so we need to wait until it has an item in it
//     //
//     // we cannot hold a lock on the queue while we're waiting, otherwise
//     // nothing can be inserted into it (addItem() will hang waiting for lock)
//     //
//     // we use a condition_variable and wait() to solve this:
//     //   - every time addItem() is called, it uses the condition_variable to
//     //     signal that the queue has been updated (calls notify_one())
//     //   - each time queue_ is updated, we grab the lock check it its empty
//     //   - if the queue is NOT empty, we hold onto the lock and continue
//     //   - if the queue IS empty, we release the lock and keep waiting
//     std::unique_lock<std::mutex> lk(queueMutex_);
//     queueCV_.wait(lk, []{return not queue_.empty();});

//     // grab the item at the front of the queue, then pop it off
//     const T item = queue_.front();
//     queue_.pop();

//     return item;
//   }

//  private:
//   // queue and mutex for protection
//   std::queue<T> queue_;
//   std::mutex queueMutex_;
//   std::condition_variable queueCV_;
// };




















#endif_