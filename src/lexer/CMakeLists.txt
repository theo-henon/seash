add_library(lexer
    lexer.cc lexer.hh)

target_link_libraries(lexer PRIVATE token)