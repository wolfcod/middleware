#ifndef __HANDLER_CHAIN_H
#define __HANDLER_CHAIN_H

/// @brief represents the latest element of a chain.. invoked to avoid any overload of handler
struct return_handler_t
{
    template<typename... Args>
    bool operator()(Args&... args)
    {
        return true;
    }
};

/// @brief generic definition...
template<typename ...Handlers>
struct middleware_chain;

/// @brief handler_chain with a unique handler. Use as next functor ReturnHandler
template<typename T>
struct middleware_chain<T>
{
    T handle;
    template<typename... Args>
    bool operator()(Args&... args)
    {
        return_handler_t next;
        return handle(args..., next);
    }
};

template<typename T, typename... Handlers>
struct middleware_chain<T, Handlers...>
{
    T handle;
    template<typename... Args>
    bool operator()(Args&... args)
    {
        middleware_chain<Handlers...> next;

        return handle(args..., next);
    }
};

#endif
