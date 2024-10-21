1.  Name    - Abinash Biswal
    UTA ID  - 1002175520

2.  Programming Language Used = C++

3.  Compiler Information - g++ (MinGW.org GCC-6.3.0-1) 6.3.0

4.  How code is Structured?
    -   There are three c++ files
        -   red_blue_nim.cpp
        -   standardFile.cpp
        -   misereFile.cpp

    -   standardFile.cpp
        -   This file contains the code for the execution of the standard version of the game.
        -   There are two functions in it
            -   childrenPairs()
            -   bestMove()
        -   The childrenPairs() functions returns the children of a node by following the standard move ordering.
            Example 
            For the node (2,3), it's children are the following
            -   (0,3)
            -   (2,1)
            -   (1,3)
            -   (2,2)
        -   The bestMove() function finds the best move by applying the minmax algorithm
            with alpha-beta pruning.
            -   The bestMove function takes 4 arguments.
                -   red marble
                -   blue marble
                -   node Type
                -   parent node utility value (variable name = parentCentralizedValue)
            -   The bestMove function return an array.
                This array has the two elements, i.e red and blue
    
    -   misereFile.cpp
        -   This file contains the code for the execution of the misere version of the game.
        -   There are two functions in it
            -   misereChildrenPairs()
            -   misereBestMove()
        -   The misereChildrenPairs() functions returns the children of a node by following the misere move ordering.
            Example 
            For the node (6,3), it's children are the following
            -   (6,2)
            -   (5,3)
            -   (6,1)
            -   (4,3)
        -   The misereBestMove() function finds the best move by applying the minmax algorithm
            with alpha-beta pruning.
            -   This is almost the same as the bestMove() function but with one change.
            -   The change is present in line 69.
            -   It is there because in the miser version, the player who reaches zero first, loses.
        
    -   red_blue_nim.cpp
        -   This is the file where the game play code is present.
        -   Here the standardFile.cpp and misereFile.cpp are being imported.
        -   The main function starts in line 64.
        -   Before the main function, 4 functions are defined. they are
            -   breakLoopCondition
            -   humanMovePrompt
            -   printGameStatus
            -   computerMoveFunction
        -   In the main function, there is a while loop.
            -   It runs, until the game is over.
            -   If the first player is human, then the code in the 'if' block run.
                else if the first player is computer, then the code in the 'else' block runs.
            -   The code inside the 'if' and the 'else' block is similar.
                The only difference is the winner depending on the type of game being played.
                In the standard version, the first player who reaches zero, wins.
                In the misere version, the first player who reaches zero, loses.



        
    
5.  How to run the code?
    -   Install a c++ complier like minGW for windows.
        Youtube Video Link for Installation: https://www.youtube.com/watch?v=FEeFG9OR-QU
        Watch from 0:00 - 4:50
    -   Open command prompt (windows) in the folder(directory) where the program files are located.
    -   Type: g++ red_blue_nim.cpp -o red_blue_nim
        The step above will generate the executable file with the name 'red_blue_nim'
    -   Now you may type the following command and see the results
        Command: 
        .\red_blue_nim.exe redMarbles blueMarbles version startingPlayer
        example - .\red_blue_nim.exe 5 8 misere computer

6.  Important Points
    **  Please make sure that the number of marbles provided are not more than 11 each.
        Providing more than that may make the program slow or show undefined behaviour.
        Please keep in mind that sometimes when an input of 10 , 10 is provided for the number of red and blue
        marbles, the computer may take a few seconds to execute.

    **  In the command line, ensure that every letter of the full command is in lowercase.
        Example - standard , misere , human , computer
        Wrong Inputs - Standard , STANDARD , CompuTer etc

    **  Ensure that all the files are in the same folder 
        -   red_blue_nim.cpp
        -   standardFile.cpp
        -   misereFile.cpp
        -   red_blue_nim.exe
    
    **  The inputs have to be entered in a particular order.
        Executable_red_blue_nim redMarbles blueMarbles version firstPlayer

    **  redMarbles and blueMarbles are integers, so enter 3 or 8 etc.
        3.0, 8.0 are not accepted.

    **  if the version is not 'standard' or 'misere'
        The program will not execute.

    **  if the first play is not 'human' or 'computer'
        The program will not execute.

    **  When it is the human's turn to make the move, the input has to be enterd in the following way:
        color number
        Example - red 2, blue 1
        The number is always precedded by a single space.
        Entering commands like the following will lead to undefined behaviour
        Example - red3 , ble5 , red , blue , 0 etc

    **  This project does not handle corner stone cases for user inputs.
        Kindly enter your inputs accurately.
        Please enter the number as either 1 or 2.
        Please enter the color as either 'red' or 'blue'.
        Writing a command like "red 4" will NOT stop the program.

    **  Before running the code please ensure that the executable file preceeded by '.\'
        Example - .\red_blue_nim.exe