cmake_minimum_required(VERSION 3.10)
project(11lab C)

set(CMAKE_C_STANDARD 99)

add_executable(11lab main.c validators.c integer_stack.c user_choice.c sort_third_stack.c arithmetic_expressions.c parse_&_calculate_expressions.c)