# pic10c-finalproject
Final project for PIC10C

### Progress Documentation:
* **05/04/2020**: project proposal, see below
* **05/08/2020**: received project approval, see proposal for further implementation plans/goals

### Proposal:
Chose **2. nonogram game**:
1. highway traffic simulation - more challenging because I am unfamiliar on how to real-time present/animate this; plan to use random variables/user input for number of lanes, car speed/size, lane changes and highway exists/entrances
2. **nonogram game** - I'm a big fan of nonograms and thought it would be fun to recreate the puzzle game myself first starting with random generated blocks and proceeding to scanning input image files to create a personalized nonogram; see [here](https://en.wikipedia.org/wiki/Nonogram) for an explanation of nonograms
    * start with plain cout | | grids and user text input, work toward click interactive userface
    * use randomly generated blocks, eventually make it possible to take in image files to scan and form personalized nonograms
    * create difficulty by generating different sized grids and/or penalty for choosing wrong blocks (3 tries)
    * allow users to request hints, choose between filling in a block or marking X where there isn't
