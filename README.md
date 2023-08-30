# Tetris-by-Riyuan-Liu
*Game Mechanics: <br />
             * The project implements the classic Tetris game mechanics, where different-shaped blocks called "tetrominos" fall from <br />
                the top of the screen. <br />
             * The player can move and rotate the tetrominos to fit them together in a horizontal line at the bottom of the screen. <br />
             * Once a line is complete, it disappears, and the player earns points.<br />
<br />
<br />
*User Interface: <br />
             * The project includes a graphical user interface (GUI) using a library like SDL or SFML to render the game elements <br />
                 and handle user input. <br />
             * The GUI displays the game board, the falling tetrominos, the score, and other relevant information.<br />
                                                                 <img width="220" alt="image" src="https://github.com/Riyuanliu/Tetris-by-Riyuan-Liu/assets/100328034/d16876ae-6d03-4d21-be7a-9218320d9980"><br />
*Game Loop: <br />
             * The project implements a game loop that continuously updates the game state, handles user input, and renders <br />
                the updated visuals. <br />
             * The game loop ensures a smooth gameplay experience by controlling the timing and framerate.<br />
<br />
<br />
*Collision Detection: <br />
                                                                 <img width="204" alt="image" src="https://github.com/Riyuanliu/Tetris-by-Riyuan-Liu/assets/100328034/37ebf1aa-3d23-4da8-9dfb-ba7b104da2cb">

             The project incorporates collision detection to prevent tetrominos from overlapping with existing blocks or the game boundaries. <br />
             It checks for collisions when moving or rotating tetrominos and adjusts their positions accordingly.<br />
*Scorekeeping: <br />
<img width="82" alt="image" src="https://github.com/Riyuanliu/Tetris-by-Riyuan-Liu/assets/100328034/f3cad87a-3336-4459-b322-5d9f5730efc5"><br />
             The project keeps track of the player's score based on the number of lines cleared. <br />
             It increments the score when lines are completed and updates the display accordingly.<br />
*Level and Speed: <br />
             As the game progresses, the project can implement increasing difficulty levels. <br />
             Each level raises the falling speed of the tetrominos, making the game more challenging. <br />
             The player's level may increase based on the number of lines cleared.<br />
*Game Over: <br />
             The project detects the end of the game when the stack of tetrominos reaches the top of the screen, resulting in a "Game Over" condition.<br />
             It displays the final score and offers the option to restart the game.<br />
*Random Tetromino Generation: <br />
             The project generates random tetrominos for the player to control and drop onto the game board. <br />
             It uses a random number generator to select the next tetromino from a predefined set of shapes.<br />
             <img width="80" alt="image" src="https://github.com/Riyuanliu/Tetris-by-Riyuan-Liu/assets/100328034/a465a4b3-2b43-4f9f-b1be-abe451288ec0"><br />
*Additional Features: <br />
             Depending on the project's complexity, you can consider adding features like a preview of the next tetromino, <br />
             a "hold" mechanic to store a tetromino temporarily, special power-ups or bonus blocks, multiplayer support, or a high score leaderboard.<br />
