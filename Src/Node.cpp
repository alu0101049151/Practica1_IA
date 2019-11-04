/**
 * @Author Basilio Gómez Navarro
 * @date 30/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 3rd
 * Practice 1 - Artificial Intelligence
 * Email: alu0101049151@ull.edu.es
 * Node.h file: Node class. It represents a node of the graph that is subsequently
 *                          used to carry out the search algorithm A*.
 *                          This file contains the class implementation.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

#include "Node.h"

Node::Node():
  father_(nullptr) {}

/**
* totalDistance is cost of the route from the starting node to the current node.
*/
Node::Node(int id, float cost, float heuristic):
  father_(nullptr),
  id_(id),
  cost_(cost),
  heuristic_(heuristic),
  totalCost_(cost_ + heuristic_) {}

Node::Node(int id, float cost, float heuristic, Node* father):
  id_(id),
  cost_(cost),
  heuristic_(heuristic),
  totalCost_(cost_ + heuristic_) {
    father_ = father;
  }

Node::Node(const Node& node):
  father_(node.father_),
  id_(node.id_),
  cost_(node.cost_),
  heuristic_(node.heuristic_),
  totalCost_(node.totalCost_) {}


Node::~Node() {}

/**
* Returns the node numeric identifier.
*/
int Node::getId() const {
  return id_;
}

/**
* Returns the heuristic value of the node (h(n)).
*/
float Node::getHeuristic() const {
  return heuristic_;
}

/**
* Returns the sum of the heuristic of the node plus cost of the route
* from the starting node to the current node (f(n)).
*/
float Node::getTotalCost() const {
  return totalCost_;
}

/**
* Returns the accumulated cost (g(n)).
*/
float Node::getCost() const {
  return cost_;
}

/**
* Returns a pointer to the parent node of the current node.
*/
Node* Node::getFather() const {
  return father_;
}

/**
* < operator overload to order the nodes from least to greatest according to the
* value of "totalCost_";
*/
int Node::operator< (const Node& node) const {
  if (this->totalCost_ == node.totalCost_) return 1;
  if (this->totalCost_ < node.totalCost_) return 1;
  return 0;
}
