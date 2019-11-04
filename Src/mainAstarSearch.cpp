/**
 * @Author Basilio Gómez Navarro
 * @date 30/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 3rd
 * Practice 1 - Artificial Intelligence
 * Email: alu0101049151@ull.edu.es
 * Graph.h file: Graph class. This file contains the main function of the program.
 *
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/mod/resource/view.php?id=90332
 * Revision history:
 *                30/10/2019 - Creation (first version) of the code
 */

 #include "Graph.h"

 int main (int argc, char const *argv[]) {
   if (argc == 1 && argv[1] == "--help"){
     //PONER MENÚ DE AYUDA
   }
   else {
     std::string distancesFile = argv[1];
     std::string heuristicsFile = argv[2];
     std::string origin = argv[3];
     std::string destination = argv[4];
     std::string outputfile = argv[5];
     int auxOrigin = stoi(origin);
     int auxDestination = stoi (destination);

     Graph aStar(distancesFile, heuristicsFile, auxOrigin, auxDestination);

     std::cout << "adjacencyMatrix_.size() = " << aStar.getAdjacencyMatrix().size() << NEWLINE;
     for (int i = 0; i < aStar.getAdjacencyMatrix()[0].size(); ++i) {
       for (int j = 0; j < aStar.getAdjacencyMatrix()[0].size(); ++j) {
         std::cout << aStar.getAdjacencyMatrix()[i][j] << " ";
       }
       std::cout << NEWLINE;
     }
     std::cout << "heuristics_.size() = " << aStar.getHeuristics().size() << NEWLINE;
     for (int i = 0; i < aStar.getHeuristics().size(); ++i) {
       std::cout << aStar.getHeuristics()[i] << " 0";
     }
     std::cout << NEWLINE;
     aStar.AstarSearch();
     aStar.printResult(outputfile);
   }
   return 0;
 }
