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
 *                          used to carry out the search algorithm A*
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE6_DFA2dot_H
#define PRACTICE6_DFA2dot_H

class Node {
public:
  Node::Node();
  Node::Node(int id, int totalDistance, int heuristic);
  Node::Node(const Node& node);

  int getId() const;
  int getHeuristic() const;
  int getTotalCost() const;

//TODO:
// -Sobre carga del <
// - Setters
protected:

private:
  int id_;           //!< Node numeric identifier.
  int heuristic_;    //!< Node heuristic.
  int totalCost_;    //!< Estimated total cost of the cheapest solution that goes
                     //!< through this node.
};

#endif //PRACTICE6_DFA2dot_H
