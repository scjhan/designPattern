#ifndef DP_SINGLETON_WITH_THREAD_SAFE_H__
#define DP_SINGLETON_WITH_THREAD_SAFE_H__

#include <pthread.h>

template<typename T>
class SingletonWithThreadSafe
{
public:
    static T &instance()
    {
        pthread_once(&m_once, SingletonWithThreadSafe<T>::init());
        return *m_value;
    }
private:
    SingletonWithThreadSafe() = default;
    SingletonWithThreadSafe(const SingletonWithThreadSafe&) = delete;
    SingletonWithThreadSafe& operator=(const SingletonWithThreadSafe&) = delete;

    ~SingletonWithThreadSafe()
    {
        if (m_value)
            delete m_value;
    }

    void init()
    {
        m_value = new T();
    }
private:
    static T *m_value;
    static pthread_once_t m_once;
};

template<typename T>
T* SingletonWithThreadSafe<T>::m_value = nullptr;

template<typename T>
pthread_once_t SingletonWithThreadSafe<T>::m_once = PTHREAD_ONCE_INIT;

#endif
