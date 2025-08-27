/**
 * Tatiana Gasparre
 * 2429174
 *  gasparre@chapman.edu
 * CPSC350-01
 * PA5: Scare Games
 */
#include "TournamentTree.h"
#include <iostream>
using namespace std;

/**
 * the tournamentTree class uses a list of all the competitors and compares their scream power levels to determine who
 * wins each match. It builds a tournament tree using the list, which has been sorted by who wins each competition
 */

/**
* TournamentTree - the constructor, creates a single elimination tree
*/
TournamentTree::TournamentTree()
{
    doubleElimination = false;
    rootWinner = NULL;
}

/**
* TournamentTree - the overloaded constructor, creates either a single or double elimination tree
* @param doubleElimination - a boolean, if true, the tree will use double elimination logic
* if false, the tree will use single elimination logic
*/
TournamentTree::TournamentTree(bool doubleElimination)
{
    this->doubleElimination = doubleElimination;
    rootWinner = NULL;

}

/**
* ~TournamentTree - the destructor, destroys the TournamentTree
*/
TournamentTree::~TournamentTree()
{
    delete rootWinner;

}

/**
* organizeCompetitors - organizes the vector of competitors by who wins each match 
*/
void TournamentTree::organizeCompetitors()
{
    for (int i = 0; i < monsters.size(); ++i)
    {
        // make sure we aren't indexing out / trying to reach a child that does not exist
        if (i + 1 < monsters.size())
        {
            if (monsters[i] > monsters[i+1])
            {
                Monster winner = monsters[i];
                monsters.push_back(winner);

                if (doubleElimination)
                {
                    loserMonsters.push_back(monsters[i+1]);
                }
            }
            else 
            {
                Monster winner = monsters[i + 1];
                monsters.push_back(winner);
                if (doubleElimination)
                {
                    loserMonsters.push_back(monsters[i]);
                }
            }
            // increase i again so the program can analyze the next two monsters
            ++i;
        }
    }
    if (doubleElimination)
    {
        organizeCompetitorsHelper();
    }
}

/**
* organizeCompetitorsHelper - called if the tournament is a double elimination. Orders the monsters in the losers bracket
* depending on who wins and loses each match
*/
void TournamentTree::organizeCompetitorsHelper()
{
    for (int i = 0; i < loserMonsters.size(); ++i)
    {
        if (i + 1 < loserMonsters.size())
        {
            if (loserMonsters[i] > loserMonsters[i+1])
            {
                Monster winner = loserMonsters[i];
                loserMonsters.push_back(winner);
            }
            else 
            {
                Monster winner = loserMonsters[i + 1];
                loserMonsters.push_back(winner);
            }
            ++i;
        }
    }
}

/**
* determineWinner - using the organized vector of competitors, this method creates a vector of TournamentNode<Monster>
* objects and links the appropriate winners and losers
*/
void TournamentTree::determineWinner()
{
    for (int i = 0; i < monsters.size(); ++i)
    {
        TournamentNode<Monster>* newNode = new TournamentNode<Monster>(monsters[i]);
        winnerTournament.push_back(newNode);
    }

    // links up the created nodes' left and right children according to their spacing in the vector
    int spaceBetweenChild = 1;
    for (int i = winnerTournament.size() - 1; i >= 0; --i)
    {
        winnerTournament[i]->left = winnerTournament[i - (spaceBetweenChild + 1)];
        winnerTournament[i]->right = winnerTournament[i - spaceBetweenChild];
        
        // if the left child is at position zero, then the last node with children has been reached
        if (i - (spaceBetweenChild + 1) == 0)
        {
            break;
        }
        // the space between a parent node and its right child increases by one for every iteration
        ++spaceBetweenChild;
    }

    // if the tree is a double elimination bracket, repeat the above steps with the loser bracket 
    if (doubleElimination)
    {
        for (int i = 0; i < loserMonsters.size(); ++i)
        {
            TournamentNode<Monster>* newNode = new TournamentNode<Monster>(loserMonsters[i]);
            losersTournament.push_back(newNode);
        }

        int spaceBetweenChild = 1;
        for (int i = losersTournament.size() - 1; i >= 0; --i)
        {
            losersTournament[i]->left = losersTournament[i - (spaceBetweenChild + 1)];
            losersTournament[i]->right = losersTournament[i - spaceBetweenChild];
        
            if (i - (spaceBetweenChild + 1) == 0)
            {
                break;
            }
            ++spaceBetweenChild;
        }
        runDoubleEliminationFinal();
    }
    else
    {
        // if the tournament is single elimination, the root is the last node in this vector
        rootWinner = winnerTournament[winnerTournament.size() - 1];
    }
    


}

/**
* runDoubleEliminationFinal - if the tournament is a double elimination, this makes the winner of the losers bracket and
* the winner of the regular bracket compete. It creates a node that points to the winner and adds it to the regular
* bracket. This is responsible for initalizing the rootWinner (only if its a double elimination tournament)
*/
void TournamentTree::runDoubleEliminationFinal()
{
    if (doubleElimination)
    {
        if (monsters[monsters.size() - 1].screamPower > loserMonsters[loserMonsters.size() - 1].screamPower)
        {
            TournamentNode<Monster>* ultimateWinner = new TournamentNode<Monster>(monsters[monsters.size() - 1]);
            ultimateWinner->left = winnerTournament[winnerTournament.size() - 1];
            ultimateWinner->right = losersTournament[losersTournament.size() - 1];
            winnerTournament.push_back(ultimateWinner);
            rootWinner = ultimateWinner;
        }
        else
        {
            TournamentNode<Monster>* ultimateWinner = new TournamentNode<Monster>(loserMonsters[loserMonsters.size() - 1]);
            ultimateWinner->left = winnerTournament[winnerTournament.size() - 1];
            ultimateWinner->right = losersTournament[losersTournament.size() - 1];
            winnerTournament.push_back(ultimateWinner);
            rootWinner = ultimateWinner;
        }
    }
}