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

Graph::~Graph() {
  /*for (auto i: generatedNodes_) {
    delete i;
  }
  for (auto j: inspectedNodes_) {
    delete j;
  }*/
}

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
  distancesFile.close();
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
  heuristicsFile.close();
}

/**
* Method to carry out the A* search.
*/
void Graph::AstarSearch() {
  float minimum = 0.0;
  bool found = false;
  Node* currentNode = new Node(origin_, 0.0, heuristics_[origin_]);  // start node
  //generatedNodes_.push_back(currentNode);  // Isn't necessary insert ir into generatedNodes_.
  totalGeneratedNodes_++;
  inspectedNodes_.push_back(currentNode);

  while (currentNode->getId() != destination_) {
   // If it isn't the destination node, generate its children nodes.
      bool condition1;
      bool condition2;
      int auxInt = currentNode->getId();

      for (int j = 0; j < adjacencyMatrix_.size(); ++j) {
        condition1 = adjacencyMatrix_[auxInt][j] != -1;
        condition2 = adjacencyMatrix_[auxInt][j] != 0;

        if (condition1 && condition2) {
          float auxCost = currentNode->getCost() + adjacencyMatrix_[auxInt][j];
          Node* auxNode = new Node(j, auxCost, heuristics_[j], currentNode);
          //Comprobar que el nodo no se encuentra en la rama o no ha sido generado.
          if (!checkBranch(auxNode->getId(), auxNode->getFather())) {
            bool allowed = true;
            for (int i = 0; i < generatedNodes_.size(); ++i) {
              if (auxNode->getId() == generatedNodes_[i]->getId()) {
                allowed = false;
                 if (auxNode->getTotalCost() < generatedNodes_[i]->getTotalCost())
                    generatedNodes_[i] = auxNode;   /// COMPROBAR!!!!!!!!!!!!!!!!
              }
            }
            if (allowed) {
              generatedNodes_.push_back(auxNode);
              totalGeneratedNodes_++;
            }
          }
        }
      }
      std::vector<Node*>::iterator ot = generatedNodes_.begin();
      minimum = (*ot)->getTotalCost();
      for (auto i: generatedNodes_) {
        if (i->getTotalCost() < minimum)
          minimum = i->getTotalCost();
      }
      found = false;
      std::vector<Node*>::iterator it = generatedNodes_.begin();
      while(!found && (it != generatedNodes_.end())){
        if ((*it)->getTotalCost() == minimum) {
          currentNode = (*it);
          generatedNodes_.erase(it);
          found = true;
        }
        it++;
      }
      inspectedNodes_.push_back(currentNode);
  }

  if (currentNode->getId() == destination_) { // If it's the destination.
    pathBackTrace(currentNode);
    finalDistance_ = currentNode->getTotalCost();
  }
}

/**
* Checks if the node to generate is in the branch.
* Returns true if the node is in the branch.
*/
bool Graph::checkBranch(int id, Node* father) {
//  bool allowed = false;
  if (father != nullptr) {
    if (id == father->getId())
       return true;
    else {
       return checkBranch(id, father->getFather());
     }
   }
   else
    return false;
  //return allowed;
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


/**
* Prints result.
*/
void Graph::printResult(std::string& outputfile) {
  std::ofstream ofs;
  ofs.open(outputfile);

  ofs << "Path: " << NEWLINE;
  for (int i = path_.size()-1; i >= 0; --i) {
    ofs << path_[i] + 1 << " ";
  }
  ofs << NEWLINE;
  ofs << "Distance: " << NEWLINE;
  ofs << finalDistance_ << NEWLINE;
  ofs << "Generates nodes: " << NEWLINE;
  ofs << totalGeneratedNodes_ << NEWLINE;
  ofs << "Inspected nodes: " << NEWLINE;
  ofs << inspectedNodes_.size() << NEWLINE;

  ofs.close();

}
