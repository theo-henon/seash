add_library(parser
    parser.cc parser.hh)
target_link_libraries(parser PRIVATE ast)