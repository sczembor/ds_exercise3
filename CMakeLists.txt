cmake_minimum_required (VERSION 2.8.11)

Project (ds_exercise3)


add_executable(client calc_client.c)
add_library(keys SHARED calc_xdr.c calc_clnt.c keys.c)
add_executable(server calc_server.c calc_xdr.c calc_svc.c)


#target_include_directories(keys PUBLIC)



find_package (Threads)

target_link_libraries (server ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (client keys)

# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
