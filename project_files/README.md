# OOP_project

Εντολες για compile και εκτελεση:
g++ -o myprog main.cpp attiki_odos.cpp entrance.cpp segment.cpp toll.cpp vehicle.cpp
./myprog 10 10 10 10    // N, Nsegs, K, Percent

Εντολη για ελεχνο απο leaks και errors:
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./myprog 10 10 10 10