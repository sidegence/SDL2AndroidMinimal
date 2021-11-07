cmake_minimum_required (VERSION 3.10.2)
project(SDL2AndroidMinimal)

set(CMAKE_CXX_STANDARD 11)

set(SDL2			"c:/SDL2_devel/SDL2-2.0.16")
set(SDL2_image		"c:/SDL2_devel/SDL2_image-2.0.5")

include_directories(${SDL2}/include ${SDL2_image}/include)

set(SOURCE_FILES
main.cpp
)

set(SDL2_LIBRARIES "${SDL2}/lib/x64/SDL2.lib;${SDL2}/lib/x64/SDL2main.lib")
set(SDL2_Image_LIBRARIES "${SDL2_image}/lib/x64/SDL2_image.lib")

add_library( SDL2_LIBRARIES SHARED IMPORTED )
add_library( SDL2_Image_LIBRARIES SHARED IMPORTED )

add_executable (SDL2AndroidMinimal ${SOURCE_FILES})
target_link_libraries(SDL2AndroidMinimal ${SDL2_LIBRARIES} ${SDL2_Image_LIBRARIES})

file(GLOB RES_FILES "assets/*.*")
add_custom_command(TARGET SDL2AndroidMinimal POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${RES_FILES} ${CMAKE_CURRENT_BINARY_DIR})
