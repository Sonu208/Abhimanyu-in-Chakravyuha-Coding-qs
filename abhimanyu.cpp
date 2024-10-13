#include <iostream>
#include <vector>
using namespace std;

bool canCrossChakravyuha(vector<int>& enemies, int p, int a, int b) {
    bool k3_regenerated = false;
    bool k7_regenerated = false;

    for (int i = 0; i < enemies.size(); i++) {
        // Check if current enemy is k3 or k7 and handle regeneration
        if (i == 2 && k3_regenerated) {  
            enemies[i] /= 2;  // k3 regenerates to half power
            k3_regenerated = false;  // Reset regeneration status
        } else if (i == 6 && k7_regenerated) {  
            enemies[i] /= 2; 
            k7_regenerated = false;  
        }

        // Logic for rest of the enemies
        if (p >= enemies[i]) {
            p -= enemies[i];  // Abhimanyu defeats the enemy
        } else {
            // skip the enemy if possible
            if (a > 0) {
                a--;  // Use a skip
                continue; 
            } else if (b > 0) {
                b--;  // retry enemy
                p += 20;  // Recharge by 20 power
                if (p >= enemies[i]) {
                    p -= enemies[i];  // Now defeat the enemy
                } else {
                    return false;  // Not enough power to defeat 
                }
            } else {
                return false;  // No power, no skips or recharges left :')
            }
        }

        // Set regeneration flags for k3 and k7
        if (i == 2) {
            k3_regenerated = true; 
        } else if (i == 6) {
            k7_regenerated = true;  
        }
    }

    return true;  // Abhimanyu Win's Yeahhh !!!!!
}

int main() {
   
   //Test case 1 when abhimanyu has small enemies , more skips and recharges so he crosses all circles 
    vector<int> enemies1 = {5, 5, 10, 7, 8, 6, 10, 9, 6, 5, 12};
   
int initial_power1 = 40, skips1 = 2, recharges1 = 3;
    if (canCrossChakravyuha(enemies1, initial_power1, skips1, recharges1)) {
        cout << "Abhimanyu can cross Chakravyuha in test case 1 !" << endl;
    } else {
        cout << "Abhimanyu cannot cross Chakravyuha in test case 1 !" << endl;
    }

  //Test case 2 when abhimanyu got more powerful enemies, fewer skips and recharges and he fails 
     vector<int> enemies2 = {20, 30, 25, 40, 50, 25, 60, 30, 20, 10, 70};
    int initial_power2 = 100, skips2 = 1, recharges2 = 2;

  if (canCrossChakravyuha(enemies2, initial_power2, skips2, recharges2)) {
        cout << "Abhimanyu can cross Chakravyuha in test case 2 :')" << endl;
    } else {
        cout << "Abhimanyu cannot cross Chakravyuha in test case 2 :') " << endl;
    }

    return 0;
}
