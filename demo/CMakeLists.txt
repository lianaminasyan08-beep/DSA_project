# Add executables for the demo programs
add_executable(graph_demo graph_demo.c)
target_link_libraries(graph_demo PRIVATE dsalib)

add_executable(hash_map_demo hash_map_demo.c)
target_link_libraries(hash_map_demo PRIVATE dsalib)

add_executable(vector_demo vector_demo.c)
target_link_libraries(vector_demo PRIVATE dsalib)

add_executable(bst_demo bst_demo.c)
target_link_libraries(bst_demo PRIVATE dsalib)
