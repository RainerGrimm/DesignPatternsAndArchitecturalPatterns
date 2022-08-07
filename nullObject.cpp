#include <iostream>
#include <mutex>
#include <shared_mutex>


template <typename Lock>
class StrategizedLocking {
    Lock& lock;
public:
    StrategizedLocking(Lock& l): lock(l){
        lock.lock();
    }
    ~StrategizedLocking(){
        lock.unlock();
    }
};

struct NullObjectMutex {
    void lock(){}
    void unlock(){}
};

class NoLock{
public:
    void lock() const {
        std::cout << "NoLock::lock: " << '\n';
        nullObjectMutex.lock();
    }
    void unlock() const {
        std::cout << "NoLock::unlock: " << '\n';
         nullObjectMutex.lock();
    }
    mutable NullObjectMutex nullObjectMutex;
};

class ExclusiveLock {
public:
    void lock() const {
        std::cout << "    ExclusiveLock::lock: " << '\n';
        mutex.lock();
    }
    void unlock() const {
        std::cout << "    ExclusiveLock::unlock: " << '\n';
        mutex.unlock();
    }
    mutable std::mutex mutex;
};


int main() {

    std::cout << '\n';
    
    NoLock noLock;
    StrategizedLocking<NoLock> stratLock1{noLock};
    
    {
        ExclusiveLock exLock;
        StrategizedLocking<ExclusiveLock> stratLock2{exLock};
        {
            StrategizedLocking<NoLock> startLock3{noLock};
        }
    }
    
    std::cout << '\n';

}