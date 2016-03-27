project(multitsp)

add_executable(multitsp ChronoCHARLOT.cpp algorithm.cpp ecritureFichier.cpp champSolution.cpp Solution.cpp Chemin.cpp remplissageMatrice.cpp chargementMegalopole.cpp Ville.cpp Megalopole.cpp main.cpp)
add_definitions(-Wall)

install(TARGETS multitsp RUNTIME DESTINATION bin)
