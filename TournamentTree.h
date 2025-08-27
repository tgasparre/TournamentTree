/**
 * Tatiana Gasparre
 * 2429174
 *  gasparre@chapman.edu
 * CPSC350-01
 * PA5: Scare Games
 */
#ifndef TOURNAMENT_TREE_H
#define TOURNAMENT_TREE_H
#include "TournamentNode.h"
#include "DOTFileGenerator.cpp"
#include <vector>

/**
 * the tournamentTree class uses a vector of all the competitors and compares their scream power levels to determine who
 * wins each match. It builds a tournament tree using the vector, which has been sorted by who wins each competition
 */
class TournamentTree {
    public:
    /**
     * TournamentTree - the constructor, creates a single elimination tree
     */
        TournamentTree();
    /**
     * TournamentTree - the overloaded constructor, creates either a single or double elimination tree
     * @param doubleElimination - a boolean, if true, the tree will use double elimination logic
     * if false, the tree will use single elimination logic
     */
        TournamentTree(bool doubleElimination);
    /**
     * ~TournamentTree - the destructor, destroys the TournamentTree
     */
        ~TournamentTree();
    /**
     * organizeCompetitors - organizes the vector of competitors by who wins each match 
     */
        void organizeCompetitors();
    /**
     * determineWinner - using the organized vector of competitors, this method creates a vector of TournamentNode<Monster>
     * objects and links the appropriate winners and losers
     */
        void determineWinner();

    /**
     * winnerTournament - the 'bracket' of the tournament, a vector of TournamentNode<Monster>* objects
     */
        std::vector<TournamentNode<Monster>*> winnerTournament;
    /**
     * losersTournament - a vector of TournamentNode<Monster>* objects, used for the loser's bracket if the tournament
     * uses double elimination logic
     */
        std::vector<TournamentNode<Monster>*> losersTournament;
    /**
     * monsters - a vector of all the competitors in the tournament (monster objects) used to keep track of
     * who wins and who loses each match
     */
        std::vector<Monster> monsters;
    /**
     * rootWinner - the root node of the tree, aka the node containing the monster that won the entire tournament
     */
        TournamentNode<Monster>* rootWinner;

    private:
    /**
     * organizeCompetitorsHelper - called if the tournament is a double elimination. Orders the monsters in the losers bracket
     * depending on who wins and loses each match
     */
        void organizeCompetitorsHelper();
    /**
     * runDoubleEliminationFinal - if the tournament is a double elimination, this makes the winner of the losers bracket and
     * the winner of the regular bracket compete. It creates a node that points to the winner and adds it to the regular
     * bracket. This is responsible for initalizing the rootWinner (only if its a double elimination tournament)
     */
        void runDoubleEliminationFinal();
    /**
     * doubleElimination - a boolean determining wether or not the tournament uses double elimination logic
     * if true, then double elimination logic is used
     * if false, then single elimination logic is used
     */
        bool doubleElimination;
    /**
     * loserMonsters - a vector of monsters that keeps track of the competitors in the losers bracket
     */
        std::vector<Monster> loserMonsters;

};

#endif