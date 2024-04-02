add_library(cimple-misc)
target_sources(cimple-misc
        PUBLIC
        special_members_decorator.hpp
        PRIVATE
        nop.cpp
)

add_executable(cimple-misc-sandbox)
target_sources(cimple-misc-sandbox
        PRIVATE
        sandbox.cpp
)
target_link_libraries(cimple-misc-sandbox
        PRIVATE
        cimple-misc
)

#if (BUILD_TESTING)
#
#    find_package(Catch2 REQUIRED)
#
#    add_executable(cimple-misc-tests)
#    target_sources(cimple-misc-tests
#            PRIVATE
#            raw_vector.tests.cpp
#            stateful_fn.tests.cpp
#    )
#    target_link_libraries(cimple-misc-tests
#            PRIVATE
#            Catch2::Catch2WithMain)
#
#endif ()
