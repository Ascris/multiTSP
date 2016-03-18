project(multitsp)

add_executable(multitsp remplissageMatrice.cpp chargementMegalopole.cpp Ville.cpp Megalopole.cpp main.cpp)
add_definitions(-Wall)

install(TARGETS multitsp RUNTIME DESTINATION bin)
