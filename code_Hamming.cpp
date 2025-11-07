#include <iostream>
#include <vector>
using namespace std;

void affiche_vecteur(vector<int> a){
   for(int i= 0; i<a.size(); i++){
      cout << a[i] << ' ';
   }
   cout << '\n';
   return;
}

int hamming(vector<int> donnee){
   /* fonctionne pour les donnees en blocks de puissance n ieme de deux avec n+1 bits de sécurité*/
   // attention entier mantisse
   
   int pos=0;
   int parite=0;
   for(int i =1; i<donnee.size(); i++){
      if(donnee[i]){
          pos^=i;
          parite^=1;
      }
   }
   if(!pos){
      return -(parite^donnee[0]);
   }
   return pos;
}

void ajoute_bits_securite(vector<int>& donnee) {
   int n = 1;
   while (n < donnee.size()) n *= 2;

   int res_xor = 0;
   int parite = 0;
   for (int i = 1; i < donnee.size(); i++) {
      if (donnee[i] == 1) {
         res_xor ^= i;
         parite ^= 1;
      }
   }

   for (int j = 1; j < n; j *= 2) {
      donnee[j] = (res_xor & j) ? 1 : 0;
      if (donnee[j]) parite ^= 1;
   }
   donnee[0] = parite;
}

int main(){
   vector<int> test= {0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
   vector<int> test2= {-1, -1, -1, 1, -1, 0, 0, 1, -1, 1, 0, 1, 1, 1, 0, 1};
   affiche_vecteur(test);
   ajoute_bits_securite(test2);
   affiche_vecteur(test2);
   return 0;
}