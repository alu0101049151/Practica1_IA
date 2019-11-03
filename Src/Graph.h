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
#include <string>
//include <algorithm>?????

#include "Node.h"

const char NEWLINE = '\n';

class Graph {
public:
  Graph(std::string& distancesFile, std::string& heuristicsFile, int origin, int destination);
  ~Graph();

  void fillMatrix(std::string& inputFile);
  void fillHeuristics(std::string& inputFile);
  //Búsqueda A*
  //Imprimir tabla de resultados al fichero.

protected:
private:
  std::vector<std::vector<float> > adjacencyMatrix_;  //!< Is the matrix of distances between nodes.
  std::vector<float> heuristics_;      //!< Contains the heuristics of this Graph nodes.
  std::vector<Node>  generatedNodes_;  //!< Contains the generated nodes in the graph.
  std::vector<Node>  inspectedNodes_;  //!< Contains the inspected nodes of all those that have been
                                       //!< generated.
  int origin_;       //!< Is the id of the start node.
  int destination_;  //!< Is the node we want to reach from the origin node.
};

#endif //PRACTICE6_GRAPH_H
