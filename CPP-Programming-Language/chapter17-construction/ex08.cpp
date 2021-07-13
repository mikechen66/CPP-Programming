#include <iostream>
#include <pthread.h>
#include <unistd.h>

// This is just a copy of ch14 ex11, since I already did this there.
// build with g++ -lpthread -o ex11 ex11.cpp
namespace construction {
    class Lock {
    private:
        pthread_mutex_t mutex;
        // Prevent copying
        Lock(const Lock& x);
        Lock& operator=(const Lock& x);

    public:
        class LockError2 {};
        class LockError : public std::exception {};
        Lock();
        ~Lock();
        void open();
        void close();
    };

    Lock::Lock() {
        if (pthread_mutex_init(&mutex, 0))
            throw LockError();
    }

    Lock::~Lock() {
        if (pthread_mutex_destroy(&mutex))
            throw LockError();
    }

    void Lock::open() {
        if (pthread_mutex_lock(&mutex))
            throw LockError();
    }

    void Lock::close() {
        if (pthread_mutex_unlock(&mutex))
            throw LockError();
    }

    class AutoLock {
    private:
        Lock* lock;
    public:
        AutoLock(Lock* lock) : lock(lock) { lock->open(); }
        ~AutoLock() { lock->close(); }
    };
}

extern "C" void* worker(void *p) {
    using namespace construction;
    AutoLock l(static_cast<Lock*>(p));

    std::cout << "worker thread acquired lock" << std::endl;
    sleep(5);
    std::cout << "worker thread releasing lock" << std::endl;
    return 0;
}

int main() {
    using namespace std;
    using namespace construction;

    Lock l;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_t thread;
    pthread_create(&thread, &attr, worker, (void*)&l);
    pthread_attr_destroy(&attr);
    sleep(1);

    cout << "main thread acquiring lock" << endl;
    l.open();
    cout << "main thread acquired lock" << endl;
    // Do some locked stuff here
    std::cout << "main thread releasing lock" << endl;
    l.close();
    pthread_join(thread, 0);
}



/* Output */

/* 
$g++ -o main *.cpp
main.cpp: In destructor ‘construction::Lock::~Lock()’:
main.cpp:31:29: warning: throw will always call terminate() [-Wterminate]
             throw LockError();
                             ^
main.cpp:31:29: note: in C++11 destructors default to noexcept
/tmp/ccpi5Mtv.o: In function `main':
main.cpp:(.text+0x24f): undefined reference to `pthread_create'
main.cpp:(.text+0x2e5): undefined reference to `pthread_join'
collect2: error: ld returned 1 exit status
 */