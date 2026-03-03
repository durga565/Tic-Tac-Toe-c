###🎮 Tic-Tac-Toe Game(c)

- This is a a console-based project Tic-Tac-Toe game written in C language. It allowa two player to play turn-by-turn
  on a 3x3 board with proper input validation, with detection, and draw handling


  ###🚀 Features

  - Two player gameplay(x and o)
  - Safe numeric input using fgets and sscanf
  - Prevents invalid or repeated moves
  - Win detection using row, column, and corner to corner line logic
  - Detects draw after 9 turns
  - Screen clearing for better console display(Window cls)
  - Pause after game result

----------

  ### Languae used

  - C 
  - Libraries: 
  -        stdio.h -> input/output opeartions
  -        stdlib.h -> Command and exit handling
  -        ctype.h -> Character handling

----------


  ### How to Run

  - Compile -> gcc/g++ TicToe.c
  - -o game / ./a.exe (Windows)

-----------
 
  ### How to play

  - Start the program,
  - Choose two player,
  - Enter number(1-9) to place your mark,
  - Player 1-> x, Player 2 -> o,
  - Complete a row, column or corner line to win,
  - if all block fill without a winner -> Draw
 
----------


  ### Logic 

  - The board stores numeric values only
  - Player X -> 3
  - Player O -> 5
  - With detection uses multiplication:
  - 3 x 3 x 3 = 27 -> Player X wins,
  - 5 x 5 x = 125 -> Player O wins

----------

  ### Program Structure

  - getNumber() -> reads validated numeric input
  - waitInput() -> Pause after win or draw
  - gameMenu() -> Display menu
  - resetGame() -> Intializes board
  - displayBoard() -> Printd board layout
  - isMoveValid() -> Checks move validity
  - inputMove() -> gets valid more from player
  - makeMove() -> Updates board with X or O
  - CheckWin() -> Determines winner
  - main() -> Control game flow
