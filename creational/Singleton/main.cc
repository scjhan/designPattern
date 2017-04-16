#include "Singleton.h"
#include "SingletonWithThreadSafe.h"
#include <iostream>
#include <string>

class Print
{
public:
    void print(const std::string &msg)
    {
        std::cout << msg << std::endl;
    }
};

int main()
{
    Singleton<Print>::instance().print("Normal singleton");

    Singleton<Print>::instance().print("Singleton with thread safe");

    return 0;
}
