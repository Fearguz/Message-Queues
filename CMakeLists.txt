cmake_minimum_required(VERSION 3.5)
project(untitled7)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES_SERVER server_main.cpp MessageQueue.cpp MessageQueue.h MessageQueueServer.cpp MessageQueueServer.h MessageQueueClient.cpp MessageQueueClient.h MessageQueueSubscriber.cpp MessageQueueSubscriber.h)
set(SOURCE_FILES_SUB subscriber_main.cpp MessageQueue.cpp MessageQueueSubscriber.cpp)

add_executable(server ${SOURCE_FILES_SERVER})
target_link_libraries(server rt)

add_executable(subscriber ${SOURCE_FILES_SUB})
target_link_libraries(subscriber rt)
