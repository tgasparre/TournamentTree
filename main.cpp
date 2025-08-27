/**
 * Tatiana Gasparre
 * 2429174
 *  gasparre@chapman.edu
 * CPSC350-01
 * PA5: Scare Games
 */
#include "RunScareGame.h"
#include <iostream>
using namespace std;
/**
 * The main file takes in command line arguments to run the scare games tournament
 */
int main(int argc, char* argv[])
{
    RunScareGame scareGame;
    scareGame.runTournament(argv[1], argv[2], "output.dot");
}