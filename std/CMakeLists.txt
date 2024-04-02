add_library(cimple-std)
target_sources(cimple-std
        PUBLIC
        raw_vector.hpp
        stateful_fn.hpp
        vector.hpp
        PRIVATE
        raw_vector.cpp
)

add_executable(cimple-std-sandbox)
target_sources(cimple-std-sandbox
        PRIVATE
        sandbox.cpp
)
target_link_libraries(cimple-std-sandbox)

if (BUILD_TESTING)

    find_package(Catch2 REQUIRED)

    add_executable(cimple-std-tests)
    target_sources(cimple-std-tests
            PRIVATE
            raw_vector.tests.cpp
            stateful_fn.tests.cpp
    )
    target_link_libraries(cimple-std-tests
            PRIVATE
            Catch2::Catch2WithMain)

endif ()
