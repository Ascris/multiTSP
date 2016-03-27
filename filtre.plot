set term jpeg
set output 'pls_500_KroAB.jpeg'
plot 'build2/allSol500_KroAB.txt', 'build2/offlinePareto500_KroAB.txt', 'build2/onlinePareto500_KroAB.txt', 'build2/PLS500_KroAB.txt'
