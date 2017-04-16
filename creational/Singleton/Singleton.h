#ifndef DP_SINGLETON_H__
#define DP_SINGLETON_H__

template<typename T>
class Singleton
{
public:
    static T& instance()
    {
        if (m_value == nullptr)
            m_value = new T();
        return *m_value;
    }
private:
    ~Singleton()
    {
        if (m_value)
            delete m_value;
    }
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
private:
    static T *m_value;
};

template<typename T>
T* Singleton<T>::m_value = nullptr;

#endif
