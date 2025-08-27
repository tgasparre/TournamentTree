
/**
 * Tatiana Gasparre
 * CPSC350-01
 */
#include "TournamentNode.h"
#include <fstream>
#include <iostream>
/*
You will use these methods in your code to save your winner and/ or loser bracket trees as DOT files
Then, you'll be able to visualize your trees at this link: https://dreampuf.github.io/GraphvizOnline/
*/

// Function to save the tree as a DOT file
/**
 * saveTreeAsDot 
 * @param filename - the name of the output file
 * @param rootNode - the root node of the tournamentTree
 */
template <typename T>
void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}

// Recursive helper function for DOT file generation
/**
 * saveTreeAsDotHelper 
 * @param node - starting node
 * @param file - output file path
 * @param nodeID - current node
 */
template <typename T>
void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->winner->name
         << " (Power: " << node->winner->screamPower << ")\"];\n";

    if (node->left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}
