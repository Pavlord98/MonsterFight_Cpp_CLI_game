# Simple C++ command line game
A simple console game inspired by RPGs and based on a learncpp.com/ assignments with an addition of new gameplay elements such as pet companions and ASCII art visualization

Here's a gameplay screenshot:
<p align="center">
  <img src=https://github.com/Pavlord98/Simple-C-Console-Game/blob/main/GameplayScreenshot.png>
</p>

## Rules of the game

<ul>
<li>This game is inspired by RPGs, and its gameplay consists of choosing a pet companion and going on an adventure of encountering and fighting monsters.</li>
<li>The player starts out with 10 health, 0 gold and a damage level of 1.</li>
<li>Each round a random monster is encountered and the player can choose to fight it or to run.</li> 
<li>If the player decides to run, there is a 50% chance of getting away scar-free and a 50% chance of getting damaged by the monster while running away.</li>
<li>Running away does not cause leveling up.</li>
<li>If the player decides to fight, the player attacks first and if the monster has remaining health it attack back.</li>
<li>After this exchange of blows, the monster runs away and the player levels up (damage increase by 1) and proceeds to the next round.</li>
<li>At the start of the game the player gets to choose a pet companion and to give them a name.</li>
<li>There are three types of pets and each of them add an unique gameplay element.</li>
<li>Cats heal the player for 1 health at the start of each round.</li>
<li>Dogs increase the players damage by 1 at the start of each round.</li>
<li>Crows provide the player with additional gold at the start of each round. </li>
</ul>

Monster attribures can be seen in the following table:
| Type   | Health | Damage | Gold |
|--------|--------|--------|------|
| Dragon |   20   |    4   |  100 |
| Orc    |    4   |    2   |  25  |
| Slime  |    1   |    1   |  10  |

The game ends when the player reaches level 20 (win condition), and ends if the players health drops to zero (lose condition).
Glhf
