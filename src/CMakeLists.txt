add_subdirectory(token)

target_sources(seash PRIVATE
        main.cc)

target_link_libraries(seash PRIVATE token)