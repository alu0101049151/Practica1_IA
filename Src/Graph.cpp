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
 *                            This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

 #include "Graph.h"

Graph::Graph(std::string& distancesFile, std::string& heuristicsFile, std::string& origin, std::string& destination):
  origin_(origin),
  destination_(destination) {
    fillMatrix (distancesFile);
    fillHeuristics (heuristicsFile);
  }

Graph::~Graph() {}


void Graph::fillMatrix(std::string& inputFile) {
  std::ifstream distancesFile;
  distancesFile.open(inputFile);

  if (!distancesFile.is_open()) {
    std::cerr << "There was a problem opening the input file with the distances";
    std::cerr << "between nodes. Please try again." << NEWLINE;
  }
  else {
    std::string readed;
    int n;   // Number of nodes of the graph.
    std::getline(distancesFile, readed);  // Reads number of nodes.
    n = stoi(readed);
    readed.clear();

    int auxInt;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        std::getline(distancesFile, readed);
        //if (readed != "-1") {
          auxInt = stoi(readed);
          adjacencyMatrix_[i][j] = auxInt;
          adjacencyMatrix_[j][i] = auxInt;
        //}
      }
    }
  }
}


void Graph::fillHeuristics(std::string& inputFile) {
  std::ifstream heuristicsFile;
  heuristicsFile.open(inputFile);

  if (!heuristicsFile.is_open()) {
    std::cerr << "There was a problem opening the input file with the ";
    std::cerr << "nodes heuristics. Please try again." << NEWLINE;
  }
  else {
    std::string readed;
    int auxHeuristic;
    int n; // Number of heuristics;

    std::getline(heuristicsFile, readed);
    n = stoi(readed);
    readed.clear();

    for (int i = 0; i < n; ++i) {
      std::getline(heuristicsFile, readed);
      auxHeuristic = stoi(readed);
      heuristics_.push_back(auxHeuristic);
    }
  }
}
