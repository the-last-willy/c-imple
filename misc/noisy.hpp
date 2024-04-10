#pragma once

#include <iostream>

namespace cimp {

    class noisy
    {
    public:
        noisy()
        {
            std::cout << "default ctor " << this << std::endl;
        }

        template<typename... Args>
        noisy(Args&&... args)
        {
            std::cout << "value ctor " << this << std::endl;
        }

        noisy(const noisy& other)
        {
            std::cout << "copy ctor " << this << " from " << &other << std::endl;
        }

        noisy(noisy&& other) noexcept
        {
            std::cout << "move ctor " << this << " from " << &other << std::endl;
        }

        noisy& operator=(const noisy& other)
        {
            std::cout << "copy assign " << this << " from " << &other << std::endl;
            return *this;
        }

        noisy& operator=(noisy&& other) noexcept
        {
            std::cout << "move assign " << this << " from " << &other << std::endl;
            return *this;
        }

        ~noisy() noexcept
        {
            std::cout << "dtor " << this << std::endl;
        }
    };
}