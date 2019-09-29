enable_testing()

add_executable(test_string_init test_string.c)
add_executable(test_string_data test_string_data.c)
add_executable(test_string_setf test_string_setf.c)

target_link_libraries(test_string_init tlib)
target_link_libraries(test_string_data tlib)
target_link_libraries(test_string_setf tlib)

add_test(NAME string-init COMMAND test_string_init)
add_test(NAME string-data COMMAND test_string_data)
add_test(NAME string-setf COMMAND test_string_setf)
