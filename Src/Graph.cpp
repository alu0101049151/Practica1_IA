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
 *                            This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

 #include "Graph.h"

Graph::Graph(std::string& distancesFile, std::string& heuristicsFile, int origin, int destination):
  origin_(origin),
  destination_(destination),
  totalGeneratedNodes_(0) {
    fillMatrix (distancesFile);
    fillHeuristics (heuristicsFile);
  }

Graph::~Graph() {}

std::vector<std::vector<float> > Graph::getAdjacencyMatrix() const {
  return adjacencyMatrix_;
}

std::vector<float> Graph::getHeuristics() const {
  return heuristics_;
}

/**
* Reads the input file with the distances btween nodes and fill the
* adjacency matrix.
*/
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

    std::vector<std::vector<float> > auxMatrix(n, std::vector<float>(n));
    adjacencyMatrix_ = auxMatrix;

    float auxInt;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        std::getline(distancesFile, readed);
        //if (readed != "-1") {
          auxInt = stof(readed);
          adjacencyMatrix_[i][j] = auxInt;
          adjacencyMatrix_[j][i] = auxInt;
        //}
      }
    }
  }
}

/**
* Reads the input file with the heuristics of each node and fill the
* heuristics vector.
*/
void Graph::fillHeuristics(std::string& inputFile) {
  std::ifstream heuristicsFile;
  heuristicsFile.open(inputFile);

  if (!heuristicsFile.is_open()) {
    std::cerr << "There was a problem opening the input file with the ";
    std::cerr << "nodes heuristics. Please try again." << NEWLINE;
  }
  else {
    std::string readed;
    float auxHeuristic;
    int n; // Number of heuristics;

    std::getline(heuristicsFile, readed);
    n = stoi(readed);
    readed.clear();

    for (int i = 0; i < n; ++i) {
      std::getline(heuristicsFile, readed);
      if (!readed.empty()) {
        auxHeuristic = stof(readed);
        heuristics_.push_back(auxHeuristic);
        readed.clear();
      }
    }
  }
}


/**
* Method to carry out the A* search.
*/
void Graph::AstarSearch() {
  Node currentNode(origin_, 0.0, heuristics_[origin_]);  // start node
  generatedNodes_.push_back(currentNode);
  totalGeneratedNodes_++;
  inspectedNodes_.push_back(currentNode);

  while (currentNode.getId() != destination_) {
   // If it isn't the destination node, generate its children nodes.
      bool condition1;
      bool condition2;
      int auxInt = currentNode.getId();

      for (int j = 0; j < adjacencyMatrix_.size(); ++j) {
        condition1 = adjacencyMatrix_[auxInt][j] != -1;
        condition2 = adjacencyMatrix_[auxInt][j] != 0;

        if (condition1 && condition2) {
          float auxCost = currentNode.getCost() + adjacencyMatrix_[auxInt][j];
          Node auxNode(j, auxCost, heuristics_[j], &currentNode);
          //Comprobar que el nodo no se encuentra en la rama o no ha sido generado.
          if (!checkBranch(auxNode, auxNode.getFather())) {
            bool allowed = true;
            for (int i = 0; i < generatedNodes_.size(); ++i) {
              if (auxNode.getId() == generatedNodes_[i].getId()) {
                allowed = false;
                 if (auxNode.getTotalCost() < generatedNodes_[i].getTotalCost())
                    generatedNodes_[i] = auxNode;
              }
            }
            if (allowed) {
              generatedNodes_.push_back(auxNode);
              totalGeneratedNodes_++;
            }
          }
        }
      }
      std::sort (generatedNodes_.begin(), generatedNodes_.end());
      currentNode = generatedNodes_[0];
      inspectedNodes_.push_back(currentNode);
      generatedNodes_.erase(generatedNodes_.begin());
  }

  if (currentNode.getId() == destination_) { // If it's the destination.
    pathBackTrace(&currentNode);
  }
}

/**
* Checks if the node to generate is in the branch.
* Returns true if the node is in the branch.
*/
bool Graph::checkBranch(Node newNode, Node* father) {
  if (father != nullptr) {
    if (newNode.getId() == father->getId())
       return true;
    else
       checkBranch(newNode, father->getFather());
  }
  return false;
}


/**
* Enter in the path_ vector the backtrace of the path followed from the origin
* node to the destination node.
*/
void Graph::pathBackTrace(Node* currentNode) {
  if (currentNode != nullptr) {
    path_.push_back(currentNode->getId());
    pathBackTrace(currentNode->getFather());
  }
}
