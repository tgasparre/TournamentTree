/**
 * Tatiana Gasparre
 * 2429174
 *  gasparre@chapman.edu
 * CPSC350-01
 * PA5: Scare Games
 */
#ifndef TOURNAMENT_NODE_H
#define TOURNAMENT_NODE_H
#include "Monster.h"

/**
 * the tournamentNode class handles every node in the tournament tree, which include a monster object and pointers to their
 * left and right children. It uses a template type so nodes of any type can be created
 */
template <typename T>
class TournamentNode {
    public: 
    /**
     * TournamentNode - the default constructor, creates the TournamentNode object
     */
        TournamentNode();
    /**
     * TournamentNode - the overloaded constructor, creates a node with the specified winner 
     * @param winner - an object of any type that the winner pointer will point to 
     */
        TournamentNode(T winner);
    /**
     * ~TournamentNode - the destructor, destroys the TournamentNode object
     */
        ~TournamentNode();
    /**
     * winner - a pointer to the winner of the match
     */
        T* winner;
    /**
     * left - the pointer to the left child of this node
     */
        TournamentNode<T>* left;
    /**
     * right - the pointer to the right child of this node
     */
        TournamentNode<T>* right;
};

template <typename T>
TournamentNode<T>::TournamentNode()
{
    left = NULL;
    right = NULL;
    winner = NULL;
}

template <typename T>
TournamentNode<T>::~TournamentNode()
{
    //START CODE FROM CHATGPt, PROMPT ASKED: "I keep getting a 'double free or corruption' error when running my code, how can I fix this?"
    left = nullptr;
    right = nullptr;
    winner = nullptr;
    //END CODE FROM CHATGPt, PROMPT ASKED: "I keep getting a 'double free or corruption' error when running my code, how can I fix this?"
}

template <typename T>
TournamentNode<T>::TournamentNode(T winner)
{
    left = NULL;
    right = NULL;
    //START CODE FROM CHATGPt, PROMPT ASKED: "I keep getting a 'double free or corruption' error when running my code, how can I fix this?"
    this->winner = new T(winner);
    //END CODE FROM CHATGPt, PROMPT ASKED: "I keep getting a 'double free or corruption' error when running my code, how can I fix this?"
}
#endif