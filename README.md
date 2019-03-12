# ZAPPY

The goal of this project is to create a network game.

The game consists of managing a universe and its inhabitants. This world, named Trantor, is geographically made up of plains and includes no other relief.
The game board represents the entire surface of this world, like a planisphere. Food and mining resources are generated randomly in the field.
The Trantorian is peaceful. He is neither violent nor aggressive. He roams gaily in search of stones and feeds in the passage. He crosses without difficulty his fellows on the same unit of ground and sees as far as his visual abilities allow it.
It is an immaterial being, fuzzy, which occupies the whole box in which it is. It is impossible to distinguish its orientation when crossed. The food he picks up allows him to live for a certain amount of time.
The objective of the players is to rise in the hierarchy trantorienne. This "increase", which increases one's physical and mental capacities, must be carried out according to a particular rite. It is indeed necessary to gather on the same unit of ground:
- A combination of stones,
- A number of players of the same level.
- A player begins the incantation and thus initiates the elevation process. Participants need not be from the same team. Only their level matters. All players in the casting group reach the next level.

To complicate the task of the AI, the field of vision of the players is limited. At each elevation, vision increases one unit of measurement forward and one on each side of the new row.
A Trantorian can also detect the presence of his congeners by emitting a radar wave indicating the direction to take to join them.

The game is played by team. The winning team is the one with 6 players who reached maximum elevation.

# Language
  - Server: C Programming
  - AI: C Programming
  - Graphical client: C++
### Run

```sh
$ make
$ ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
$ ./zappy_ai -p port -n name -h machine
```
##### Server
port is the port number
width is the width of the world
height is the height of the world
nameX is the name of the team X
clientsNb is the number of authorized clients per team
freq is the reciprocal of time unit for execution of actions

##### AI
port is the port number
name is the name of the team
machine is the name of the machine; localhost by default

Unfortunately, the program does not work 100% due to lack of time, the different parts don't work together

**Authors**

Raphael OTAL
Matthias GAYAUD
Léo MAIGNAN
Guilhem AMARDEILH
Charly DAI
