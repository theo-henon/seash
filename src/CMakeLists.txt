add_subdirectory(token)
add_subdirectory(lexer)
add_subdirectory(ast)
add_subdirectory(parser)
add_subdirectory(visitor)

target_sources(seash PRIVATE
        main.cc)

target_link_libraries(seash PRIVATE token lexer ast parser visitor)