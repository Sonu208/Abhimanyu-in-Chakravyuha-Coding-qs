Problem Statement :

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by
different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11
circles to reach Pandavas army back.
Given:
Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11
powers
Abhimanyu start from the innermost circle with p power
Abhimanyu has a boon to skip fighting enemy a times
Abhimanyu can recharge himself with power b times
Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. If
Abhimanyu enter the circle with energy less than the respective enemy, he will lose the battle
k3 and k7 enemies are endured with power to regenerate themselves once with half of their
initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle
Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of
test cases.

Algorithm :

1) Initialize Variables:

     p: initial power of Abhimanyu.
     a: the number of skips available.
     b: the number of recharges available.
     k3_regenerated and k7_regenerated: flags for regeneration of the 3rd and 7th enemies.

2) Iterate Over the Enemies:
For each enemy i in the array of enemies:

    a. Handle Regeneration of k3 and k7:
       If the enemy at index i is k3 (i.e., i == 2), check if it has already regenerated. If so, halve the power of the enemy and reset the regeneration flag.
       Similarly, if the enemy at index i is k7 (i.e., i == 6), halve the power and reset the regeneration flag.

    b. Check if Abhimanyu can Defeat the Current Enemy:
       If Abhimanyu's power (p) is greater than or equal to the current enemy's power, subtract the enemy's power from p and move to the next enemy.
       If Abhimanyu's power is less than the enemy's power:
       If there are skips (a > 0), use a skip and move to the next enemy without reducing Abhimanyu's power.
       If no skips are available but recharges (b > 0) are available, use a recharge to increase Abhimanyu's power by 20. If after recharging, Abhimanyu's power is enough to defeat the enemy, subtract the enemy's power and move on.
        If neither skips nor recharges are available and Abhimanyu cannot defeat the enemy, return false (Abhimanyu fails to cross the Chakravyuha).
   
   c. Set Regeneration Flags:
      If the current enemy is k3 (i.e., i == 2), set the k3_regenerated flag to true.
      If the current enemy is k7 (i.e., i == 6), set the k7_regenerated flag to true.

3)Return True if All Enemies are Defeated:
      If Abhimanyu defeats all enemies or skips/charges through, return true (Abhimanyu successfully crosses the Chakravyuha).
