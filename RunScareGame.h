/**
 * Tatiana Gasparre
 */
#ifndef RUN_SCARE_GAMES_H
#define RUN_SCARE_GAMES_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "TournamentTree.h"

/**
 * The runscaregame class reads in the competitors from a file and runs a tournament with those monsters
 */
class RunScareGame {
    public:
    /**
     * RunScareGame - the constructor, creates the RunScareGame object
     */
        RunScareGame();
    /**
     * ~RunScareGame - the destructor, destroys the RunScareGame object
     */
        ~RunScareGame();
    /**
     * runTournament - runs a tournament from the monsters in the inputFile and produces a dot file of the resulting tree
     * @param inputFile - a string representing the input file path
     * @param format - a string representing the format of the tournament (single or double elimination)
     * @param outputFIle - a string representing the output file name
     * @throws runtime error if the input file could not be opened
     */
        void runTournament(std::string inputFile, std::string format, std::string outputFile);
    private:
    /**
     * populateTournament - creates a list of competitors from the input file
     * @param bracket - a TournamentTree object, the tournament that the competitors are being added to
     * @param inputFile - string, the input file path 
     * @throws runtime error if the input file could not be opened
     */
        void populateTournament(TournamentTree& bracket, std::string inputFile);

};


#endif
