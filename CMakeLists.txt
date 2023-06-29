cmake_minimum_required(VERSION 3.0.0)
project(paper-trading-app VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(paper-trading-app app.cpp account.cpp portfolio.cpp holding.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(CURL CONFIG REQUIRED)
target_link_libraries(paper-trading-app PRIVATE CURL::libcurl)

find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(paper-trading-app PRIVATE JsonCpp::JsonCpp)

include_directories(package)