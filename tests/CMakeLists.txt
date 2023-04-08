
set(CMAKE_CXX_STANDARD 20)
add_executable(tests 
    main.cpp
    pq_tests.cpp
)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE priority_queue)
