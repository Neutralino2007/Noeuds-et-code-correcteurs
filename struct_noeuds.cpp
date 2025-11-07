#include <iostream>
#include <vector>
#include <map>
using namespace std;

// se renseigner sur l'algorithme de Haken
// implémenter les mouvements de reidemeister, calculer des invariants
// algorithme naif de comparaison des noueds type invariants puis BFS
// algo de facilatation de representation des noeud
// visualisation des noeuds ?
// Lien avec les codes correcteurs si temps restant

enum TypeCroisement { OVER, UNDER };

struct Croisement {
    int id;
    int arc_entrant;
    int arc_sortant;
    TypeCroisement type;
};

struct DiagrammeNoeud {
    vector<Croisement> croisements;
    map<int, int arcs[2];
};
   
int main(){

}