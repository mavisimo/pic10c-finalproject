# pic10c-finalproject
Final project for PIC10C

### Progress Documentation:
* **05/04/2020**: project proposal, see below
* **05/08/2020**: received project approval for nonogram, see proposal for further implementation plans/goals
* **05/12/2020**: created random block and fill generator functions that determine in a row of n blocks how many should be filled, can now apply these functions to n columns to randomly generate a nxn nonogram puzzle
* **05/17/2020**: began playing with possibile layouts in Qt, can already see issues with button spacing and window sizing to fit puzzles as large as 15x15 and higher, definitely see a signal for clicked button to slot of change color button with color depending on right or wrong coming up
* **05/21/2020**: back to working on C++ code to generate a nonogram solution to then begin coding the game - want a matrix of 1 and 0 where 0 indicates a filled spot and 1 is empty. possible thoughts of weighting the random generator of the puzzle in some way such that there are more fill blocks than empty to make it easier to solve?
* **05/28/2020**: working on printing nonogram game board, figured out I needed another matrix to keep track of coordinates guessed and struggling with converting solution matrix into clues to be printed on empty board - basically how can I loop through the solution matrix to count how many fills are in a given row or column and how do I store that info? decided a 1x2n matrix with the first n being horizontal clues and n+1 to 2n being the vertical clues was a simple solution
* **05/29/2020** fixed counting horizontal clues but something's not working on counting the vertical clues with the indices being switched... began simple user input of row and column to guess the puzzle and a 3 life system C++ nonogram game but need some way to exit the game when all filled blocks are found, not just when you run out of lives - needed another loop through the clues to get a count of how many fill blocks there were and to decrease that each time one was found
* **06/03/2020**: spent a long time making fine edits to print the clues, especially printing the verticle clues I ultimately needed many loops to find the max length to know how many rows I needed to print before the board, then finding the right set width. I STRONGLY ADVISE choosing a board size of <10 for the sake of being able to solve a randomly generated puzzle and formatting consistency (couldn't decide on a suitable equation for setw of varying board sizes)
* I wanted something playable to present by the end of this quarter but if time permits I will try to transfer this C++ code onto Qt for better interface
* **06/03/2020**: I just realized belatedly during week 10 this game's concept is very similar to battleships which I know is a common coding challenge, just with clues involved - seeing as the C++ code is done I went looking for some Qt implementation of battleships that could maybe help with my nonogram implementation and found [this Github code](https://github.com/amahdy/qtbattleship) that I will look through for guidance

### Proposal:
Chose **2. nonogram game**:
1. highway traffic simulation - more challenging because I am unfamiliar on how to real-time present/animate this; plan to use random variables/user input for number of lanes, car speed/size, lane changes and highway exists/entrances
2. **nonogram game** - I'm a big fan of nonograms and thought it would be fun to recreate the puzzle game myself first starting with random generated blocks and proceeding to scanning input image files to create a personalized nonogram; see [here](https://en.wikipedia.org/wiki/Nonogram) for an explanation of nonograms
    * start with plain cout | | grids and user text input, work toward click interactive userface
    * use randomly generated blocks, eventually make it possible to take in image files to scan and form personalized nonograms
    * create difficulty by generating different sized grids and/or penalty for choosing wrong blocks (3 lives)
    * allow users to request hints, choose between filling in a block or marking X where there isn't
