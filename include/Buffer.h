#ifndef CTRADEROPENAPI__BUFFER_H
#define CTRADEROPENAPI__BUFFER_H

#include <deque>
#include <mutex>
#include <condition_variable>

template<class T, int size>
class Buffer
{
public:
    void add(T item)
    {
        while (true)
        {
            std::unique_lock<std::mutex> locker(mu_);
            cond_.wait(
                    locker, [this]()
                    { return buffer_.size() < size_; }
                      );
            buffer_.push_back(item);
            locker.unlock();
            cond_.notify_all();
            return;
        }
    }

    T remove()
    {
        while (true)
        {
            std::unique_lock<std::mutex> locker(mu_);
            cond_.wait(
                    locker, [this]()
                    { return buffer_.size() > 0; }
                      );
            T back = buffer_.back();
            buffer_.pop_back();
            locker.unlock();
            cond_.notify_all();
            return back;
        }
    }

private:
    std::mutex mu_;
    std::condition_variable cond_;
    std::deque<T> buffer_;
    const unsigned int size_ = size;
};

#endif //CTRADEROPENAPI__BUFFER_H
