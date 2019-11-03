/**
 * @Author Basilio Gómez Navarro
 * @date 30/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 3rd
 * Practice 1 - Artificial Intelligence
 * Email: alu0101049151@ull.edu.es
 * Graph.h file: Graph class. Represents represents the graph with which the A *
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
//include <algorithm>?????

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
  Graph(std::string& distancesFile, std::string& heuristicsFile, std::string& origin, std::string& destination);
  ~Graph();
  /**
  * @brief Read the input file with the distances btween nodes and fill the
  * adjacency matrix.
  * @param inputFile File containing the distances between nodes.
  */
  void fillMatrix(std::string& inputFile);
  /**
  * @brief Read the input file with the heuristics of each node and fill the
  * heuristics vector.
  * @param inputFile File containing the heuristic of each node.
  */
  void fillHeuristics(std::string& inputFile);
  /**
  * @brief Method that carries out the A* search.
  */
  void AstarSearch();
  //Imprimir tabla de resultados al fichero.

protected:
private:
  std::vector<std::vector<float> > adjacencyMatrix_;  //!< Is the matrix of distances between nodes.
  std::vector<float> heuristics_;      //!< Contains the heuristics of this Graph nodes.
  std::vector<Node>  generatedNodes_;  //!< Contains the generated nodes in the graph.
  std::vector<Node>  inspectedNodes_;  //!< Contains the inspected nodes of all those that have been
                                       //!< generated.
  // ES NECESARIO UN VECTOR PARA ALMACENAR LA TRAZA?
  std::string origin_;       //!< Is the id of the start node.
  std::string destination_;  //!< Is the id of the node we want to reach from the origin node.
};

#endif //PRACTICE6_GRAPH_H
