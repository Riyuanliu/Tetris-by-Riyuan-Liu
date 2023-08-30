# Tetris-by-Riyuan-Liu
*Game Mechanics: 
      The project implements the classic Tetris game mechanics, where different-shaped blocks called "tetrominos" fall from the top of the screen. 
      The player can move and rotate the tetrominos to fit them together in a horizontal line at the bottom of the screen. 
      Once a line is complete, it disappears, and the player earns points.
*User Interface: 
      The project includes a graphical user interface (GUI) using a library like SDL or SFML to render the game elements and handle user input. 
      The GUI displays the game board, the falling tetrominos, the score, and other relevant information.
<img width="220" alt="image" src="https://github.com/Riyuanliu/Tetris-by-Riyuan-Liu/assets/100328034/d16876ae-6d03-4d21-be7a-9218320d9980">
*Game Loop: 
      The project implements a game loop that continuously updates the game state, handles user input, and renders the updated visuals. 
      The game loop ensures a smooth gameplay experience by controlling the timing and framerate.
*Collision Detection: 
      The project incorporates collision detection to prevent tetrominos from overlapping with existing blocks or the game boundaries. 
      It checks for collisions when moving or rotating tetrominos and adjusts their positions accordingly.
*Scorekeeping: 
      The project keeps track of the player's score based on the number of lines cleared. 
      It increments the score when lines are completed and updates the display accordingly.
*Level and Speed: 
      As the game progresses, the project can implement increasing difficulty levels. 
      Each level raises the falling speed of the tetrominos, making the game more challenging. 
      The player's level may increase based on the number of lines cleared.
*Game Over: 
      The project detects the end of the game when the stack of tetrominos reaches the top of the screen, resulting in a "Game Over" condition.
      It displays the final score and offers the option to restart the game.
*Random Tetromino Generation: 
      The project generates random tetrominos for the player to control and drop onto the game board. 
      It uses a random number generator to select the next tetromino from a predefined set of shapes.
*Additional Features: 
      Depending on the project's complexity, you can consider adding features like a preview of the next tetromino, 
      a "hold" mechanic to store a tetromino temporarily, special power-ups or bonus blocks, multiplayer support, or a high score leaderboard.
