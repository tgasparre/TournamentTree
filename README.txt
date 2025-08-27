Tatiana Gasparre
CPSC350-01


Source Files: 
DOTFileGenerator.cpp (provided), main.cpp, Monster.h, RunScareGame.cpp, RunScareGame.h, 
TournamentNode.h, TournamentTree.cpp, TournamentTree.h

Known Errors:
n/a

Deviations:
The instructions suggested using DOTFileGenerator's methods inside the TournamentTree class, but in this implimentation
they were used inside RunScareGame.cpp (done with permission)

References:
ChatGPT used in lines 58-60 and line 70 in TournamentNode.cpp
prompt asked: "I keep getting a 'double free or corruption' error when running my code, how can I fix this?"

Instructions to build:
g++ -o A5.exe *.cpp

Instructions to run:
./A5.exe inputfile.txt, tournamentLogic
replace tournamentLogic with either single or double

output will be produced as the file output.dot

