# Soccer_opp_board
# Exhaustive Apporach

The staged opponent avoidance problem is a puzzle that comes from a modified real-life scenario,
where soccer players of a team maneuver through an opponent-filled field in order to find a safe
passage to reach the goal post. For example, we could consider the Red Team trying to overcome
the Blue Team. The field is represented by a square r × c grid with r rows and c columns. In this
modified game, unlike in real-life, players of the opposing team are stationary, and are located in
some cells. The Red Team starts from the top-left corner of the field, at (row,
column) location (0,0), dribbles past the opponents, and aims to reach the goal post in the bottomright corner at location (r−1, c−1). The occupied cells are impenetrable and movements towards
the goal post can only be done by moving right, from location (i,j) to (i,j + 1); or down,
from (i,j) to (i+1,j). A path may not go through an occupied cell, so the Red Team can only
move to a new location, if there is no opponent at that location.

The field can be displayed as a 2D grid, like the following:
......X.X
---------
X........
...X...X.
..X....X.
.X....X..
....X....
..X.....X
.........
The Red Team starts at row 0 and column 0, i.e. coordinate (0,0) at the top-left corner. Each period
represents a passable spot and each X represents an opponent-occupied spot (i.e. an impenetrable
spot). The Red Team's goal is to plan a passable route to cross the field, and reach the opponents
goal post, while avoiding the occupied cells. The problem objective is to compute the number
of different paths to cross the field. Two paths are different if they differ by at least one location.
For the previous grid, the optimal solution is 102.
This puzzle can be defined as an algorithmic problem.
