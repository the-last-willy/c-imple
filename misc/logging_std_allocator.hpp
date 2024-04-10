#pragma once

#include <iostream>
#include <memory>

namespace cimp
{
    template<typename Ty>
    class logging_std_allocator {
    public:
        using value_type = Ty;

        Ty* allocate(std::size_t n)
        {
            auto mem = internal.allocate(n);
            std::cout << "allocate " << n << " '" << typeid(Ty).name() << "' at " << mem << std::endl;
            return mem;
        }

        void deallocate(Ty* first, std::size_t count)
        {
            std::cout << "deallocate " << count << " '" << typeid(Ty).name() << "' at " << first << std::endl;
            return internal.deallocate(first, count);
        }

        std::allocator<Ty> internal;
    };
}