/**
 * @Author Basilio Gómez Navarro
 * @date 30/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 3rd
 * Practice 1 - Artificial Intelligence
 * Email: alu0101049151@ull.edu.es
 * Graph.h file: Graph class. Represents the graph with which the A *
 *                            search will be carried out.
 *                            This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE6_GRAPH_H
#define PRACTICE6_GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Node.h"

const char NEWLINE = '\n';

class Graph {
public:

  /**
  * @brief parameter constructor.
  * @param distancesFile name of the input file that contains the distances between nodes.
  * @param heuristicsFile name of the input file that contains the heuristic of each node.
  * @param origin id of the star node.
  * @param destination id of the destination node.
  */
  Graph(std::string& distancesFile, std::string& heuristicsFile, int origin, int destination);
  ~Graph();
  std::vector<std::vector<float> > getAdjacencyMatrix() const;
  std::vector<float> getHeuristics() const;



  /**
  * @brief Method to carry out the A* search.
  */
  void AstarSearch();

  /**
  * @brief prints result.
  */
  void printResult(std::string& outputfile);

protected:
  /**
  * @brief Reads the input file with the distances btween nodes and fill the
  * adjacency matrix.
  * @param inputFile File containing the distances between nodes.
  */
  void fillMatrix(std::string& inputFile);
  /**
  * @brief Reads the input file with the heuristics of each node and fill the
  * heuristics vector.
  * @param inputFile File containing the heuristic of each node.
  */
  void fillHeuristics(std::string& inputFile);

  /**
  * @brief Checks if the node to generate is in the branch.
  * @param newNode is the node to generate.
  * @param father it the node to compare.
  * @return true if the node is in the branch.
  */
  bool checkBranch(int id, Node* father);

  /**
  * @brief Enter in the path_ vector the backtrace of the path followed from the origin
  * node to the destination node.
  */
  void pathBackTrace(Node* currentNode);

private:
  std::vector<std::vector<float> > adjacencyMatrix_;  //!< Is the matrix of distances between nodes.
  std::vector<float> heuristics_;      //!< Contains the heuristics of this Graph nodes.
  std::vector<int> path_;      //!< Contains the ids of the nodes of the final path.
  std::vector<Node*>  generatedNodes_;  //!< Contains the generated nodes in the graph.
  std::vector<Node*>  inspectedNodes_;  //!< Contains the inspected nodes of all those that have been
                                       //!< generated.

  int origin_;             //!< Is the id of the start node.
  int destination_;        //!< Is the id of the node we want to reach from the origin node.
  int totalGeneratedNodes_; //!< Is the total amount of generated nodes.
  int finalDistance_;
};

#endif //PRACTICE6_GRAPH_H
