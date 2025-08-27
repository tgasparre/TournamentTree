/**
 * Tatiana Gasparre
 * 2429174
 *  gasparre@chapman.edu
 * CPSC350-01
 * PA5: Scare Games
 */
#include "RunScareGame.h"
using namespace std;
/**
 * The runscaregame class reads in the competitors from a file and runs a tournament with those monsters
 */

/**
* RunScareGame - the constructor, creates the RunScareGame object
*/
RunScareGame::RunScareGame()
{
   
}

/**
* ~RunScareGame - the destructor, destroys the RunScareGame object
*/
RunScareGame::~RunScareGame()
{

}

/**
* runTournament - runs a tournament from the monsters in the inputFile and produces a dot file of the resulting tree
* @param inputFile - a string representing the input file path
* @param format - a string representing the format of the tournament (single or double elimination)
* @param outputFIle - a string representing the output file name
* @throws runtime error if the input file could not be opened
*/
void RunScareGame::runTournament(std::string inputFile, std::string format, std::string outputFile)
{
    if (format == "double" || format == "Double")
    {
        TournamentTree bracket(true);
        populateTournament(bracket, inputFile);
        bracket.organizeCompetitors();
        bracket.determineWinner();
        saveTreeAsDot(outputFile, bracket.rootWinner);
    }
    else if (format == "single" || format == "Single")
    {
        TournamentTree bracket(false);
        populateTournament(bracket, inputFile);
        bracket.organizeCompetitors();
        bracket.determineWinner();
        saveTreeAsDot(outputFile, bracket.rootWinner);
    }
    else
    {
        throw runtime_error("The tournament format is invalid. Please run the program again and choose 'single' or 'double'");
    }

}

/**
* populateTournament - creates a list of competitors from the input file
* @param bracket - a TournamentTree object, the tournament that the competitors are being added to
* @param inputFile - string, the input file path 
* @throws runtime error if the input file could not be opened
*/
void RunScareGame::populateTournament(TournamentTree& bracket, string inputFile)
{
    ifstream in(inputFile);
    if (in.fail())
    {
        throw runtime_error("The specified input file does not exist. Please run the program again with a different input file.");
    }
    string line;
    while (getline(in, line))
    {
        // stringstream ss(line);
        string monsterName = "";
        string monsterScreamPower = "";

        //this reads a comment into the name, fix that
        for (char c : line)
        {
            if (isalpha(c))
            {
                monsterName += c;
            }
            else if (isdigit(c))
            {
                monsterScreamPower += c;
            }
        }
        Monster newMonster(monsterName, stoi(monsterScreamPower));
        bracket.monsters.push_back(newMonster);
    }
}
