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
 *                          This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE6_NODE_H
#define PRACTICE6_NODE_H

class Node {

public:
  Node();

  /**
  * @brief param constructor of the node class.
  * @param id is the node numeric identifier.
  * @param totalDistance is cost of the route from the starting node to the
  * current node.
  * @param heuristic is the heuristic value of this node.
  */
  Node(int id, int totalDistance, int heuristic);
  Node(const Node& node);
  ~Node();

  int getId() const;
  int getHeuristic() const;
  int getTotalCost() const;
  Node* getFather() const;

  int operator< (const Node& node) const;

//TODO:
// - Setters
protected:

private:
  Node* father_;     //!< Father of the current node.
  int id_;           //!< Node numeric identifier.
  int heuristic_;    //!< Node heuristic. h(n).
  int totalCost_;    //!< Estimated total cost of the cheapest solution that goes
                     //!< through this node. f(n) = g(n) + h(n).
};

#endif //PRACTICE6_NODE_H
