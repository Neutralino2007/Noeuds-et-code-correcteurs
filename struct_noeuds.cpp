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

// twist
void reidemeisterMouvementI(DiagrammeNoeud & D, bool ajouter) {
    if (ajouter) {
        // Ajouter une boucle (exemple : un croisement de type OVER)
        Croisement nouvelleBoucle;
        nouvelleBoucle.id = D.croisements.size(); // ID unique
        nouvelleBoucle.arc_entrant = nouvelleBoucle.id;
        nouvelleBoucle.arc_sortant = nouvelleBoucle.id;
        nouvelleBoucle.type = OVER;
        D.croisements.push_back(nouvelleBoucle);
    } else {
        // Supprimer une boucle (si elle existe)
        if (!D.croisements.empty()) {
            D.croisements.pop_back();
        }
    }
}

// poke 
void reidemeisterMouvementII(DiagrammeNoeud & D, bool ajouter) {
    if (ajouter) {
        // Ajouter deux croisements adjacents
        Croisement c1, c2;
        c1.id = D.croisements.size();
        c1.arc_entrant = c1.id;
        c1.arc_sortant = c1.id + 1;
        c1.type = OVER;

        c2.id = c1.id + 1;
        c2.arc_entrant = c2.id;
        c2.arc_sortant = c1.id;
        c2.type = UNDER;

        D.croisements.push_back(c1);
        D.croisements.push_back(c2);
    } else {
        // Supprimer deux croisements adjacents (si possible)
        if (D.croisements.size() >= 2) {
            D.croisements.pop_back();
            D.croisements.pop_back();
        }
    }
}

// slide
void reidemeisterMouvementIII(DiagrammeNoeud & D, int idCroisement) {
    // Trouver le croisement concerné
    for (auto &c : D.croisements) {
        if (c.id == idCroisement) {
            // Inverser le type de croisement (OVER <-> UNDER)
            c.type = (c.type == OVER) ? UNDER : OVER;
            break;
        }
    }
}

int main(){


}
