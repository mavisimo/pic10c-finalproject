# pic10c-finalproject
Final project for PIC10C

### Progress Documentation:
* **05/04/2020**: project proposal, see below
* **05/08/2020**: received project approval, see proposal for further implementation plans/goals
* **05/12/2020**: created random block and fill generator functions, can now apply these functions to each row of a nonogram puzzle to randomly generate a nonogram (the next step)
* **05/17/2020**: began creating layout in Qt, issues with button spacing and window sizing to fit puzzles as large as 15x15 and higher to be resolved in future
* **05/21/2020**: working on C++ code to generate a nonogram solution to then begin coding the game, possible thoughts of weighting the random generator of the puzzle in some way such that there are more fill blocks than empty to make it easier to solve?
* **05/28/2020**: working on printing nonogram game board, figured out using another matrix to keep track of coordinates checked but struggling with converting solution matrix into clues to be printed on empty board
* **05/29/2020** fixed generating horizontal clues but something's not working on counting the vertical clues... began simple user input and life system C++ nonogram game but need some way to end game when all filled blocks are found
* **06/03/2020**: spent a long time making fine edits to print the clues, especially printing the verticle clues I ultimately needed many loops to find the max length to know how many rows I needed to print before the board, then finding the right set width. I STRONGLY ADVISE choosing a board size of <10 for the sake of being able to solve a randomly generated puzzle and formatting consistency (couldn't decide on a suitable equation for setw of varying board sizes)
* I wanted something playable to present by the end of this quarter but if time permits I will try to transfer this C++ code onto Qt for better interface


### Proposal:
Chose **2. nonogram game**:
1. highway traffic simulation - more challenging because I am unfamiliar on how to real-time present/animate this; plan to use random variables/user input for number of lanes, car speed/size, lane changes and highway exists/entrances
2. **nonogram game** - I'm a big fan of nonograms and thought it would be fun to recreate the puzzle game myself first starting with random generated blocks and proceeding to scanning input image files to create a personalized nonogram; see [here](https://en.wikipedia.org/wiki/Nonogram) for an explanation of nonograms
    * start with plain cout | | grids and user text input, work toward click interactive userface
    * use randomly generated blocks, eventually make it possible to take in image files to scan and form personalized nonograms
    * create difficulty by generating different sized grids and/or penalty for choosing wrong blocks (3 tries)
    * allow users to request hints, choose between filling in a block or marking X where there isn't
