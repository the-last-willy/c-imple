#include "logging_std_allocator.hpp"
#include "noisy.hpp"

#include <vector>

using namespace cimp;

int main()
{
    std::vector<noisy, logging_std_allocator<noisy>> vec;
    vec.resize(3);
    vec.resize(5);
}
