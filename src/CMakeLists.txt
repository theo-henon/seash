add_subdirectory(token)
add_subdirectory(lexer)

target_sources(seash PRIVATE
        main.cc)

target_link_libraries(seash PRIVATE token lexer)