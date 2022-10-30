#include <iostream>
#include <middleware.h>

struct GenericHandler
{
    template<typename Fn>
    bool operator()(int &i, Fn next)
    {
        std::cout << "GenericHandler " << i << std::endl;
        i += + 2 + next(i);
        std::cout << "GenericHandler " << i << std::endl;
        return true;
    }
};

struct FinalHandler
{
    template<typename Fn>
    bool operator()(int &i, Fn next)
    {
        std::cout << "FinalHandler " << i << std::endl;
        i += 1;
        next(i);

        std::cout << "FinalHandler " << i << std::endl;
        return true;
    }
};

int main() {
    int i = 0;
    middleware_chain<GenericHandler, FinalHandler> chain;

    chain(i);
    std::cout << "Return value of i " << i << std::endl;
    return 0;
}
