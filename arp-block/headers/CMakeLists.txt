set(HEADERS
    arphdr.h
    ethhdr.h
    hpch.h
)

message("CMAKE_PROJECT_NAME is ${CMAKE_PROJECT_NAME}")

foreach(header ${HEADERS})
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${header})
endforeach()