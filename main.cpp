
// Connect 4 Game

/*
    |   Documentation:
    |
    |
    |   * we put here all references I looked up during the course.
    |   -----------------------------------
    |   Video #16:  Multidimentional Arrays
    |   -----------------------------------
    |
    |   Multidimensional Arrays in C / C++
    |   see here: https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/
    |
    |   ---------------------------------------------
    |   Video #17: Multidimentional Arrays - practice 
    |   ---------------------------------------------
    |
    |   enumeration in cpp
    |   see here: https://en.cppreference.com/w/cpp/language/enum
    |             https://www.programiz.com/cpp-programming/enumeration
    |             https://www.geeksforgeeks.org/enumeration-enum-c/
    |
    |   char array initialization
    |   see here: http://www.cplusplus.com/doc/tutorial/ntcs/
    |
    |
    |   Homework: connect 4 game
    |
    |   making delay time function
    |   see here: https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
    |             http://www.cplusplus.com/forum/beginner/27291/
    |             http://www.cplusplus.com/forum/beginner/27291/
    |             http://www.cplusplus.com/reference/ctime/clock/
    |             http://www.cplusplus.com/forum/unices/10491/#msg49054
    |
    |   Tab space Vs. 4 spaces
    |   see here: http://www.cplusplus.com/forum/lounge/249840/
    |
    |
    |   Random and how to get different resutl each time
    |   see here: https://stackoverflow.com/questions/7748071/same-random-numbers-every-time-i-run-the-program
    |             https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    |             http://www.fredosaurus.com/notes-cpp/misc/random.html
    |             https://en.cppreference.com/w/cpp/numeric/random/rand
    |             
    |   unable to establish connection to GDB problem
    |   see here: https://github.com/microsoft/vscode-cpptools/issues/2889
    |             https://github.com/Microsoft/vscode-cpptools/issues/2767
    |
    |
    |
    |   Access to a base class member is ambiguous
    |   see here: https://stackoverflow.com/questions/29387600/reference-to-is-ambiguous
    |             https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.1.0/com.ibm.zos.v2r1.cbclx01/cplr138.htm
    |             https://www.quora.com/What-is-ambiguity-in-C++
    |             http://www.cplusplus.com/forum/beginner/11759/
    |
    |   indentation backwards use: Ctrl + [ to unindent and Ctrl + ] to indent.
    |   see more: https://stackoverflow.com/questions/790711/how-to-remove-tab-indent-from-several-lines-in-idle
    |             https://stackoverflow.com/questions/4559896/how-to-tab-backwards-remove-a-tab-or-tab-spaces-in-vim    
    |
    |
    |   function prototype:
    |   see here: https://www.programiz.com/cpp-programming/function
    |             https://codescracker.com/cpp/cpp-function-definition.htm
    |             http://www.cplusplus.com/articles/yAqpX9L8/
    |
    |   function prototype with multi-dimentional array as a parameter:
    |   see here: https://stackoverflow.com/questions/41884801/function-prototypes-with-multi-dimensional-arrays-as-a-parameter
    |
    |   Input Validation technique: (it can not catch input like this if i wanna enter integer value (1234lqwjr) or (1234.1234))
    |   see here: https://stackoverflow.com/questions/17928865/correct-way-to-use-cin-fail
    |             http://www.cplusplus.com/forum/beginner/2957/
    |             https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
    |             https://study.com/academy/lesson/validating-input-data-in-c-plus-plus-programming.html
    |
    |
    |   cin.fail():
    |   see here: https://en.cppreference.com/w/cpp/io/basic_ios/fail
    |             https://en.cppreference.com/w/cpp/io/ios_base/failure
    |             http://www.cplusplus.com/reference/ios/ios/fail/
    |
    |
    |   static variables 
    |   see here: https://www.studytonight.com/cpp/static-keyword.php
    |
    |
    |   enter one value for entire 2d array (connect4Game()) (#include <cstring>)
    |   see here: https://stackoverflow.com/questions/15520880/initializing-entire-2d-array-with-one-value
    |             https://www.geeksforgeeks.org/memset-in-cpp/
    |
    |   Static variable c++ (winnerC4Game())
    |   see here: https://www.geeksforgeeks.org/static-keyword-cpp/
    |             https://www.bogotobogo.com/cplusplus/statics.php
    |
    |   initializing an array with a specific value (winnerC4Game())
    |   see here: https://stackoverflow.com/questions/1065774/initialization-of-a-normal-array-with-one-default-value
    |             https://en.cppreference.com/w/cpp/algorithm/fill_n
    |
    |   indent backwards in VScode is 'shift + tab' (winnerC4Game())
    |   see more: https://stackoverflow.com/questions/40492960/how-to-indent-format-a-selection-of-code-in-vscode-with-ctrlshiftf
    |             https://stackoverflow.com/questions/4559896/how-to-tab-backwards-remove-a-tab-or-tab-spaces-in-vim
    |
    |   GDB ignores my breakpoints (main.cpp Connect 4 Game) (worked after reboot)
    |   see more: https://stackoverflow.com/questions/20809174/gdb-ignores-my-breakpoints
    |
    |
*/

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <random>
#include <algorithm>

using namespace std;

// Homework: connect 4 game




/* 
    ------------------------------------------------------------------------------
    -> Defined constants and the array layout of the game
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    | here we define our constansts for the game
    | we have the nr. of our rows and colomns  
    | we have also our nr. of steps to check the win situation
    | for each color so if the red for exampel had 4 reds horizontly the red wins
    | and to check this we need to move 4 steps, therefore we have our 
    | constant steps with value = 4
    | we also defined our array with the ROWS, COLS constanst which indicates 
    | our game layout and we initialized it with zero
    | and we declared 2 variables 'redWins' for red winning times and blackWins
    | for black winning times globally during the game untill the end of the game
    |  
    | I defined another array which is like history for all our previous plays so 
    | it will help the PC to play well against me it consist of 3 informations
    | the color and the two coordinates row and col.
    -----------------------------------------------------------------------------
*/
const int ROWS = 6, COLS = 7, steps = 4;
int arr[ROWS][COLS] = {};

const int x = ROWS * COLS, y = 3;
int historyArr[x][y] = {0};

int redWins = 0, blackWins = 0;

string fstPlayer, scndPlayer;
int fstPlayerCol = 0, scndPlayerCol = 0;


/* 
    ------------------------------------------------------------------------------
    -> here we define our enumerations 
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    | we have 4 enumerations each serves us in a specific way:
    |
    | 1. PC - is the hardness level if the player chose to play against PC. 
    |
    | 2. colorPlayer - is our red and black player and we use it as nr. to make 
    |    our compares easier instead of comparing strings or chars.
    | 
    | 3. state - which indicates as you can see the the fullness of our colomns
    |    so we can use it to ensure the fullness of each colomn and the fullness 
    |    and the fullness of the entire game.
    | 
    | 4. direction "dir" enumeration - is a little bit complicated one because 
    |    there is two components of this kind of trick direction aims to move
    |    in the 2d array one move step in 8 directions as you can see down there
    |    so to do that we first defined our enum which have the 8 directions
    |    contains its values from 0 to 7. second we defined 2 1D arrays one
    |    contains the x-axis (colomn) moving step and the other one contains
    |    the y-axis (row) moving step so for example if wanna move to the Right
    |    in our predefined array we simply take the values of its nr. right here is
    |    the second element in the "dir" so its default nr. should be 1 as you know 
    |    our default is to start numbering from 0. so to move right we need to know
    |    our step in our both axis x and y how do this, we simply go to the first array 
    |    " dir_r[] " which indicates the y (row) and take the element which is 
    |    in the index 1 which is 0 that means we will not move in this axis 
    |    we just stay at our row and that is quite right because moving right 
    |    as we can imagine is moving on the x-axis so when we go to the
    |    second array " dir_c " and move to index 1 we see that its value is 1 so
    |    that means we should go one step to the right direction ( -> ) at the end 
    |    of this example moving right is to move at the y-axis (row) 0 steps and 
    |    at the x-axis (colomn) 1 step.   
    | 
    ------------------------------------------------------------------------------

*/
enum PCLevel
{
    EASY = 1,
    MEDIUM,
    HARD
};

enum colorPlayer
{
    red = 1,
    black
};

enum state
{
    notFull,
    isFull
};

enum trackStatus
{
    PC,
    PLAYER
};

enum dir      { DOWN, RIGHT, UP, LEFT, UP_LEFT, DOWN_RIGHT, UP_RIGHT, DOWN_LEFT };
int dir_r[] = { 1,    0,    -1,  0,   -1,       1,         -1,        1         };
int dir_c[] = { 0,    1,     0, -1,   -1,       1,          1,       -1         };



/* 
    ------------------------------------------------------------------------------
    -> brief explanation for our Game functions
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |   we splitted our game into 4 main functions:
    |       1. connect4Game() 
    |       2. inputC4Game() 
    |       3. printC4Game() 
    |       4. winnerC4Game()
    |
    |   1. connect4Game()
    |       its the interface of our Game which we show you all the options you
    |       can choose from with input validation for each input the user may give
    |       and at the end it calls the input function
    |
    |   2. inputC4Game()
    |       its our input function where we enter our plays for both 
    |       red and black players here we do many things 
    |           * we generate with random virtual device our first player
    |           * we start playing after that each color in a mutual manner
    |           * we start looking for winner after the first 7 plays
    |           * we validate our input to not be out the range and do not put 
    |             a nother one upon a full colomn and of course 
    |   
    |   3. printC4Game()
    |       its a simple GUI consol output to simulate the game we use ' | ' symbol
    |       for the borders of the game and ' O ' to indicate the empty cell and 
    |       red and black words instead of red and black coins
    | 
    |   4. winnerC4Game()
    |       its the core of the Game code here we check the winner dynamically 
    |       after each play and at the end        
    |     
    ------------------------------------------------------------------------------

*/

// here is prototypes of our functions
void connect4Game();
void inputC4Game(int[][COLS], int, int);
int inputC4GamePC(int[][COLS], int, int, int);
void printC4Game(int[][COLS], int);
void winnerC4Game(int[][COLS], int, int, int, int);
int DownTracking(int[][COLS], int, int); // new not documented
int RightLeftTracking(int[][COLS], int, int); // new not documented
int Up_Left_Down_RightTracking(int[][COLS], int, int); // new not documented
int Up_Right_Down_LeftTracking(int[][COLS], int, int); // new not documented


//============================
//----------------------------

int main()
{
    // Homework: connect 4 game

    connect4Game();

    return 0;
}

//----------------------------
//============================


// functions declared above as prototypes:
// ---------------------------------------

/* 
    ------------------------------------------------------------------------------
    -> connect4Game() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |   here we have our main interface of the Game and it has many components:
    |
    |   the 1st component is declarations:
    |       int option     - declared for first option to play Vs. player or the PC
    |       int PlStatus   - player status is for the option who I wanna play against
    |                        Human or PC and if I will play against PC it will have
    |                        the info about which color will PC play with me by taking
    |                        the my color and the send the opisite color so if I 
    |                        I chose to play with RED I will send BLACK. 
    |       bool check     - uesed for terminating the loops after checking the 
    |                        input validation
    |       char ClrOption - a sugar code thing "choose a color" we did a countdown
    |                        timer for 5 seconds waiting to let the two players 
    |                        decides who gonna play with which color.
    |       int PClevel    - this variable will have the hardness level of the game
    |                        the player plays against PC.
    |
    |       char chOption  - to let the player choose if he wanna play again or not
    | 
    |   the 2nd component is:
    |       choosing the option to play with your PC or with a player and after we
    |       take the input we make a validation check within a loop to repeat the 
    |       code if the entry input is not valid. 
    |
    |   the 3rd component is:
    |       after we decided to play with PC or with a player we have two parts for
    |       each option you may hav chosen. 
    |         * The first part is to play with a player
    |           here we start with a nice intro to ask the two player to discuss and 
    |           decide who plays with which color and we gave them 5 Seconds to do so
    |           and after the 5 seconds we ask them if they finished the discuss and
    |           wanna continue then they can say yes if not they can say no and then 
    |           will simply repeat the 5 seconds wait and not to forget we made our 
    |           validation upon the yes or no input from the players
    |
    |         * The second part is to play with PC
    |           here we ask the player for his wanted color and validate his input
    |           and then made a checker for the player color to send the PC color
    |           the opisite color of the player and this help us at the input part
    |           to let the PC enter his play movement. 
    |       
    |   the 4th component is:
    |       we did add a small feature at the end to give the player the option to
    |       play again after each play, so we made a do while loop on the 
    |       2nd and 3rd component and we did add the same input validation
    |       which we did before in the 3rd component, but we add a small condition
    |       for the big while loop which break the loop if the player typed 'n' or 'N'
    |       to respond to the request of the game.
    |       * not to forget to mention we also initialize our game after each game 
    |         and we used a special function to initialize our 2d array celled memset().
    |
    |
    ------------------------------------------------------------------------------

*/

// TODO: * write an option to play again(Done)
//       * how to make input validation functions for each type of input
void connect4Game()
{
    // the 1st component:
    // -----------------
    int option = 0;   // declared to choose between play vs. player or vs. PC
    int PlStatus = 0; // for player status to know if I will play with a partner or against the PC
    int PCLevel = 0; // it take the hardness level to play VS. PC
    //int colChoice = 0;  // declared for collumn choice
    //int iStatus = 0; // declared for input status
    bool check; // check our input validation
    char ClrOption;  // for the time delay step to let the players decide together who take which color
    char chOption;   

    do
    {
        // it works actually only for char datatype of arrays but with 0 it is okay
        memset(arr, 0, sizeof(arr[0][0]) * ROWS * COLS);
        memset(arr, 0, sizeof(historyArr[0][0]) * x * y);
        // initializing 'redWins' and 'blackWins' for the next game round
        redWins = 0; blackWins = 0;
        // the 2nd component:
        // -----------------

        cout << "\t\t\t*** Welcom in Connect 4 Game ***\n\n\n";
        do
        {
            check = true;
            cout << "\n\t+++-----------------+++\n"
                 << "\t1- for play Vs. PC.\n"
                 << "\t2- for play Vs. player."
                 << "\n\t+++-----------------+++\n"
                 << "\n\tChoose your option:";
            cin >> option;

            //input validation
            if (cin.fail() || (option > 2 || option < 1))
            {
                cout << "\n\t\t\t!!! Your entered an unvalid value. plz try again !!!\n";
                cin.clear();
                cin.ignore(10000, '\n');
                check = false;
            }
        } while (!check);

        // the 3rd component:
        // -----------------
        if (option == 2)
        {

            cout << "\n\n\t\t\t+++ You chose to play Vs. another player. +++\n\n";
                 
            do
            {

                check = true;
                
                cout << "\tFirst player Name: ";     
                cin >> fstPlayer;
                cout <<"\n";
                
                cout <<"\n\n\t+++-------------------+++" 
                     <<"\n\t+ Choose a color:\n"
                     << "\t1. Red\t 2. Black\n"
                     << "\t+++------------------+++"
                     << "\n\tYour color Nr. is: ";
                cin >>fstPlayerCol;

                cout <<"\n\n";

                cout << "\tSecond player Name: ";     
                cin >> scndPlayer;
                cout <<"\n";
                cout <<"\tSecond player Color: ";
                if(fstPlayerCol == red)
                {
                    cout<<"black\n";
                    scndPlayerCol = black;
                }

                //input validation
                if (cin.fail() || (fstPlayerCol > 2 || fstPlayerCol < 1))
                {
                    cout << "\n\n\n\t\t\t!!! You entered an unvalid value. plz try again !!!\n\n\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    check = false;
                }

            } while (!check || ClrOption == 'n' || ClrOption == 'N');

            // TODO: is it neccesseray to send the array if it is already defined Global
            //       may be it will be better like that so if I decided later to define it locally
            //       or use it some where else then I should not change the parameters for all functions.
            inputC4Game(arr, PlStatus, PCLevel);
        }
        else
        {

            // option = 0; // I will use the same Var used before but not needed to init
            cout << "\n\n\t\t\t +++ You choosed to play Vs. PC. +++\n";
            
             do
            {
                check = true;
                
                cout <<"\n\t+++----------------------------+++" 
                     <<"\n\t+ Choose The level:\n"
                     << "\t1. Easy\t   2. Medium\t3. Hard\n"
                     << "\t+++----------------------------+++"
                     << "\n\tYour level is: ";
                cin >> PCLevel;

                //input validation
                if (cin.fail() || (PCLevel > 3 || PCLevel < 1))
                {
                    cout << "\t\t\t!!! You entered an unvalid value. plz try again !!!\n";
                    cin.clear();
                    cin.ignore(10000, '\n'); // I should ask why the ignore after the failier
                    check = false;
                }

            } while (!check);

            
            do
            {
                check = true;

                cout << "\n\n\tFirst player Name: ";     
                cin >> fstPlayer;
                cout <<"\n";

                cout <<"\n\n\t+++-------------------+++" 
                     <<"\n\t+ Choose a color:\n"
                     << "\t1. Red\t 2. Black\n"
                     << "\t+++------------------+++"
                     << "\n\tYour color Nr. is: ";
                cin >> fstPlayerCol;

                PlStatus = fstPlayerCol;
                //input validation
                if (cin.fail() || (fstPlayerCol > 2 || fstPlayerCol < 1))
                {
                    cout << "\t\t\t!!! You entered an unvalid value. plz try again !!!\n";
                    cin.clear();
                    cin.ignore(10000, '\n'); // ask why the ignore after the failier
                    check = false;
                }

            } while (!check);

            // here I will get my color and if my color is red then I send black
            if (PlStatus == red)
                inputC4Game(arr, black, PCLevel);
            else
                inputC4Game(arr, red, PCLevel);
        }

        // the 4th component:
        // -----------------
        do
        {

            check = true;

            cout << "\n\n\t- if you wanna play again\n\t* write 'y' for yes and 'n' for no: ";
            cin >> chOption;

            //input validation
            if (cin.fail() || (chOption != 'y' && chOption != 'n' && chOption != 'Y' && chOption != 'N'))
            {
                cout << "\n\t\t\t!!! You entered an unvalid value. plz try again !!!\n";
                cin.clear();
                cin.ignore(10000, '\n');
                check = false;
            }

        } while (!check);

        if (chOption == 'N' || chOption == 'n')
            check = false;

        cout << "\n\n\n";
    } while (check);
}

/* 
    ------------------------------------------------------------------------------
    -> inputC4Game() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    | here we input the players play movements
    |
    | Parameters: 
    |   arr[ROWS][COLS] - is our 2D array game layout it is not needed to send it
    |                     because it is globally defined but in case we changed 
    |                     our 2D array from global definition to local definition
    |                     the functions remain the same and do not need to 
    |                     change any thing to be compatible with the new changes.
    |   int status      - its value indicates the option of the player who I will play  
    |                     against if its 0 then I play against another player
    |                     but if it is 1 or 2 it means I will play agains PC and 1 means
    |                     PC's color is red and 2 means PC's color is black.
    |
    | Declerations:
    |   we have 5 variables:
    |                       - int playerColor: init to 0 and we assign the player
    |                         color in it and we use it for many conditions like
    |                           * knowing who plays first and for the input to seperate
    |                             between the input of a person and the PC input which 
    |                             has its own function.
    |                           
    |                           * we use it also in a condition to exchange between 
    |                             the players after each play .
    |  
    |                       - int Count: init to 0 and it counts for us the 
    |                         nr. of plays and we use it also for many other
    |                         purposes such as 
    |                           * the first random generator to know who is going to
    |                             play first by make condition to only do it if
    |                             Count is 0 so it will do it only once at
    |                             the first time of playing the Game. 
    |
    |                           * after each play we increas it by one as its
    |                             the main purpose of Count (Variable).
    |                         
    |                           * we use it also for the winner function to only 
    |                             send the array of the Game after the 7th play.
    |
    |                           * we use it finally for a condition to break if the 
    |                             count nr. reachs the maximum nr. of cells in the 
    |                             2D array of the Game which is 7 * 6 = 42.
    |
    |                       - int colChoice: init to 0 we assign our player input 
    |                         which refers to the colomn which the player wanna
    |                         play his red or black coin. 
    |                            * we use it for our validation to ensure the user 
    |                              a valid value.
    |
    |                            * we use it also to assign the player input in 
    |                              the array of the Game and to check each 
    |                              colomn not to be full so we will be then able to  
    |                              assign the player input.
    |                            
    |                        - int colStatus: we use it mainly to assign our 2D array
    |                          status if its full or not and this help us with many
    |                          things:
    |                            * we use it for a condition to only make the 
    |                              player switch if the colomn where the player 
    |                              chose to is not full.
    |
    |                       - int row: we initialize it to 0 and we use it in the
    |                         part where we add the player choice in the 2D array
    |                         and row indicates the row where we put his choice.
    |
    |                       - bool check: we use it for our loops conditions and 
    |                         also often for input validation.
    |
    | function components:
    |   we have 8 components in our input functions
    |                       - 1st component: 
    |                         random generator for 1 and 2 numbers
    |                         to know who will play first red or black  
    |                         and it will generate only one time at the first
    |                         by using a condition using the count variable so 
    |                         at the begining count has value 0 so it will generate
    |                         but after that it will go over 0 and then the condition
    |                         will fail every time and thats the goal of the condition.
    |                         The detailed functionality about how it works you can 
    |                         find it above by references documentation.
    |
    |                       - 2nd component: 
    |                         its a cout message based upon the random generator 
    |                         to tell the players who will play first based on the
    |                         playerColor value.
    |
    |                       - 3rd component:
    |                         from 3rd to 8th component all of them are laying out 
    |                         in a do while loop for input validation and other
    |                         exception cases.
    |                         here we firstly initialize two variables our check 
    |                         to be true and colStatus (colomn Status) and we print
    |                         our 2D array. 
    |                         the 3rd component is responsible of getting the input
    |                         movement for each player so we made a small cout 
    |                         message with a condition for each player and also 
    |                         a condition for the input in case I play against 
    |                         PC so then we get the input from another function .
    |                         
    |                       - 4th component:
    |                         is a validation input part to grasp two potentially 
    |                         errors first if I entered a value which is different
    |                         from the input datatype and the second if the value
    |                         of the colomn the player entered is out of the range
    |                         which should be between [1 -> 7].
    |
    |                       - 5th component:
    |                         here we do the assignment part of the player input
    |                         in the 2D array the process goes like this:
    |                           * we decrease the user chosen colomn nr. by 1
    |                             so it fits with the array indexing starts from 0.
    |
    |                           * here we have two implementations:
    |                             
    |                           -> the old one goes like this: (with a loop)
    |
    |                             1- we assign the bottom of the array to r so we try to 
    |                             search down up approach to reach the free place and 
    |                             then placing our player choice there. 
    |                             
    |                             2- then we wrote a while loop which run over the 
    |                             rows from max to 0 (included) and we decrease it
    |                             one by one each loop.
    |
    |                             3- we have a condition which aims to do 2 things one is to  
    |                             skip the full cells from down to up by a restriction  
    |                             which checks if the current cell is free if yes
    |                             the condition turns true and it will execute the condition
    |                             and there is another condition which is with ||
    |                             OR notation it means that either of both occures 
    |                             and then if the 'if condition' turns true it
    |                             will be executed the second condition aims  
    |                             to take care of the Colomns boundry to prevent 
    |                             adding in a full colomn.
    |
    |                             4- at the end we have our second 'if condition'
    |                             which is core of our component here we have two
    |                             choices the first one is for the flag output if
    |                             i try to add my choice play in a full colomn and 
    |                             its condition will turns true only if two things
    |                             happening together when the cell is not equal to 0
    |                             which means this cell is full and the row where 
    |                             this cell is lcoated is 0 which means this cell is
    |                             at the top of the array.
    |                             
    |                           -> the new one goes like this: (with an array saves the loc.)
    |
    |                             1- here we depended on a nother way to get the
    |                             position of each play, we simply declared an array
    |                             with the size of the colomns and each colomn should
    |                             contains the nr. of cells which are full so we
    |                             we can simply add above this nr. the new play
    |                             without using a loop to find the next empty cell.
    |
    |                             2- we have a condition 'if else' parts the if part
    |                             is for assigning the player choice into the array
    |                             and in order to do that we have to follow some 
    |                             steps before.
    |                                   * as we know we start from bottom so we 
    |                                     wanna know which row has the first free
    |                                     cell from down, to konw that we simply
    |                                     subtract the nr. of rows which the array 
    |                                     have from the nr. of rows of the colomn 
    |                                     which the player chose to play in it.
    |
    |                                   * the second step is the assigning statement
    |                                     where we assign the value of the player color
    |                                     in our array where 'row' which we calculated
    |                                     it from the previous step and 'colChoice'
    |                                     which is the player chosen colomn subtracted
    |                                     of course by one to overcome the indexing 
    |                                     problem of arrays.
    |
    |                                   * the third step we simply then update the 
    |                                     array of the colomns and add one to the 
    |                                     colomn which we just assigned our new play
    |                                     in it to keep track where we will put our
    |                                     next play at the next time if the player chose
    |                                     the same colomn.
    |
    |                                   * and last not the least we increase our
    |                                     count by one.
    |
    |                                   * the else part is the part where the 
    |                                     flag of full colomn happen. we cout
    |                                     a flag to the player that he should
    |                                     look for another colomn and we set
    |                                     the 'colStatus' to 'isFull'.
    |
    |                             3- we added this part recently its an array
    |                                to save each play in a history contains
    |                                3 infos for each play a. player color 
    |                                b. & c. are the two coordinates row & col.
    |
    |                       - 6th component:
    |                         here we send our 2D array with its first 7 plays and
    |                         above to the winnerGame function to check if winning
    |                         situations for each player and gather them together
    |                         and print out the winner at the end of the Game.
    |                         we send many attributes to the winner game function:
    |                         * the 2D array which contain the game layout it self
    |                         * the position of the current playing position using
    |                           'row' and 'colChoice'.           
    |                         * the 'Count' which has the value of all the plays occured
    |                           since start playing the game.
    |                       
    |                       - 7th component: 
    |                         it is our interchange part to change the player color
    |                         each play with a small condition that it will only 
    |                         change if colStatus is not full to prevent adding
    |                         in a full colomns
    |
    |                       - 8th component:
    |                         it's an exception error to get out of the funciton when
    |                         the game is finished by filling all the 2D array.
    |               
    ------------------------------------------------------------------------------

*/

/// How are you
///
/// I am inpuC4Game function    
void inputC4Game(int arr[ROWS][COLS], int status, int PCLevel)
{
    int playerColor = 0; //
    int Count = 0;       // Done: make a condition of checking the winner function after the first 7 steps
    int colChoice = 0;
    int colStatus; // I used to use '::' for empty before because it is may be built-in variables
    int colArr[COLS] = {0};
    int row = 0;
    bool check;

    // - 1st component:
    if (Count == 0)
    {
        // ----------------------------
        // the old random generator way
        // ----------------------------

        // a new way (better) || wiered! it works although it shows up underline error
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(1, 2);
        playerColor = distr(eng);
    }

    // - 2nd component:
    
    if(status != 0)
    {
        if (playerColor == status)
        {
            cout << "\n\t\t\t +++ The player who start first is: PC +++\n\n";
            cout << "\n\t- Plz enter your cell nr. from 1 to 7 \n\n";
        }
        else
        {
            cout << "\n\t\t\t+++ The player who start first is: "<<fstPlayer<<" +++\n\n";
            cout << "\n\t- Plz enter your cell nr. from 1 to 7 \n\n";
        }
    }
    else
    {
        if (playerColor == fstPlayerCol)
        {
            cout << "\n\t\t\t +++ The player who start first is: "<<fstPlayer<<" +++\n\n";
            cout << "\n\t- Plz enter your cell nr. from 1 to 7 \n\n";
        }
        else
        {
            cout << "\n\t\t\t+++ The player who start first is: "<<scndPlayer<<" +++\n\n";
            cout << "\n\t- Plz enter your cell nr. from 1 to 7 \n\n";
        }
    }

    // wait to let user read the output message
    Sleep(2000);

    // TODO: may be it will be better if you made a general validation function to call it think a little !
    // make a do while loop for 2 players playing until it is full
    do
    {
        // - 3rd component:
        check = true; // do really need this?

        colStatus = notFull;
        printC4Game(arr, status);

        if(status != 0)
        {
            if (playerColor == status)
                cout << "\n\t- PC choice is: ";
            else
                cout << "\n\t- "<<fstPlayer<<" choice is: ";
        }
        else
        {
            if (playerColor == fstPlayerCol)
                cout << "\n\t- "<<fstPlayer<<" choice is: ";
            else
                cout << "\n\t- "<<scndPlayer<<" choice is: ";
        }


        if (playerColor == status)
        {
            colChoice = inputC4GamePC(arr, status, PCLevel, Count);
            cout << colChoice << '\n';
            Sleep(2000); // to see the PC input
        }
        else
            cin >> colChoice; // I put it out side the if else condition because it is duplication

        // - 4th component:
        //input Validation
        if (cin.fail() || (colChoice < 1 || colChoice > 7))
        {
            if (!cin.fail())
                cout << "\n\t\t\t!!! Your value is out of range plz enter values between 1 and 7 !!!\n\n";
            else
                cout << "\n\t\t\t!!! Plz enter correct values. !!!\n\n";

            cin.clear();
            cin.ignore(10000, '\n');
            //check = false;
        }
        else
        {
            // - 5th component:
            colChoice--; // to use it easily later

            if (colArr[colChoice] < ROWS)
            {
                row = (ROWS - 1) - colArr[colChoice];
                arr[row][colChoice] = playerColor;
                
                // this part is archive part
                historyArr[Count][0] = playerColor;
                historyArr[Count][1] = row;
                historyArr[Count][2] = colChoice;
                
                colArr[colChoice]++;
                Count++;
            }
            else
            {
                cout << "\n\t\t\t!!! This Column is full plz try another one. !!!\n\n"; // only current col is full
                //check = false;
                colStatus = isFull;
            }

            // ------------------------------
            // the old input way look up down
            //-------------------------------

            // - 6th component:
            if (Count >= 7 && (colStatus != isFull) )
                winnerC4Game(arr, row, colChoice, Count, status);

            // - 7th component:
            if (colStatus != isFull)
            {
                // to switch each time between red and black players
                if (playerColor == red)
                    playerColor = black;
                else
                    playerColor = red;
            }

            // - 8th component:
            if (Count == (ROWS * COLS))
            {
                //cout<<"\n\t Do you wanna play again? "
                //    <<"\n\t'y' for yes, 'n' for no.\n"
                break;
            }
        }
    } while (check);
}


// here we track the player and PC moves
// -------------------------------------

/* 
    ------------------------------------------------------------------------------
    -> DownTracking() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |
    |
    |
    |     
    ------------------------------------------------------------------------------

*/

int DownTracking(int arr[ROWS][COLS], int x, int y,int trackStatus)
{
    int row = x, col = y;
    int plColor = arr[x][y];
    int winDirCount = 1;
    bool dirCheck = true;
    
    for (int i = 1; i < steps; i++)
    {
        // DOWN direction
        if (row < 5 && row > 0 && dirCheck)
        {
            row += dir_r[DOWN];
            col += dir_c[DOWN];
            
            if (arr[row][col] == plColor)
                winDirCount++;
            else
                dirCheck = false;
        }
    }
    
    if(trackStatus == PLAYER)
    {
        row = --x;
        if(winDirCount >= 3)
        {
            if(arr[row][col] == 0)
                return ++col;
        }   
    }
    else
    {
        if(row > 0)
        {
          //row += dir_r[UP];     // to check if I played after PC last play on top
            row = --x;            // I don't know why above doesn't work
            if(arr[row][col] == 0)
            {
                if(winDirCount >= 3)
                    return (++col * -1);
                else
                    return ++col;
            }   
        }
    }
    return 0;
}

/* 
    ------------------------------------------------------------------------------
    -> RightLeftTracking() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |
    |
    |
    |     
    ------------------------------------------------------------------------------

*/

int RightLeftTracking(int[ROWS][COLS], int x, int y, int trackStatus) // new not documented
{
    int rowR = x, colR = y;
    int rowL = x, colL = y;
    
    int tmpRowR = 0, tmpColR = 0; 
    int tmpRowL = 0, tmpColL = 0;
    
    int plColor = arr[x][y];
    int winDirCountR = 1, winDirCountL = 1;
    
    bool dirCheckR = true, dirCheckL = true;
    bool checkR = true, checkL = true;
    
    for (int i = 1; i < steps; i++)
    {
        // RIGHT direction
        if (colR < 6 && (dirCheckR))
        {
            rowR += dir_r[RIGHT];
            colR += dir_c[RIGHT];
            
            if (arr[rowR][colR] == plColor)
                winDirCountR++;
            else
            {
                // I think it will be executed in case winDirCount = 3
                // which is the normal case.
                if(arr[rowR][colR] == 0 && checkR)
                {
                    tmpRowR = rowR; 
                    tmpColR = colR;
                    checkR = false;
                }
                else
                    dirCheckR = false;
            }
        }

        // LEFT direction
        if (colL > 0 && (dirCheckL))
        {            
            rowL += dir_r[LEFT];
            colL += dir_c[LEFT];
            
            if (arr[rowL][colL] == plColor)
                winDirCountL++;
            else
            {
                if(arr[rowL][colL] == 0 && checkL)
                {
                    tmpRowL = rowL; 
                    tmpColL = colL;
                    checkL = false;
                }
                else
                    dirCheckL = false;
            }
        }
    }

    // to get default back
    if(!dirCheckR && !checkR)
    {
        rowR += dir_r[LEFT];
        colR += dir_c[LEFT];
        checkR = true;
    }
    
    if(!dirCheckL && !checkL)
    {
        rowL += dir_r[RIGHT];
        colL += dir_c[RIGHT];
        checkL = true;
    }

    // RIGHT <> LEFT
    winDirCountR += (winDirCountL - 1); 
    if(winDirCountR >= steps || trackStatus == PC)
    {
        if(arr[rowR][colR] == 0 || !checkR) // in case we have this case (2 and 1) 
        {
            if(rowR < 5)
            {
                rowR += dir_r[DOWN];
                colR += dir_c[DOWN];

                if(arr[rowR][colR] != 0)
                {
                    rowR -= 2; tmpRowR--; // I will check every up cell for all funcs for HARD and MEDIUM levels

                    if(winDirCountR >= 3)
                    {   
                        if((tmpColR == colR)&& trackStatus == PLAYER)
                        {
                            if(arr[rowR][colR] == 0)
                                return ++colR;
                        }
                        else
                        {
                            if(arr[tmpRowR][tmpColR] == 0)
                                return (++tmpColR * -1);
                        }
                    }
                    else
                    {
                        if(arr[rowR][colR] == 0)
                            return ++colR;
                    }    
                }
            }
            else
            {
                rowR--; tmpRowR--;

                if(winDirCountR >= 3)
                {
                    if( (tmpColR == colR)  && trackStatus == PLAYER)
                    {
                        if(arr[rowR][colR] == 0)
                            return ++colR;
                    }
                    else
                    {
                        if(arr[tmpRowR][tmpColR] == 0)
                            return (++tmpColR * -1);
                    }
                }
                else
                {   
                    if(arr[rowR][colR] == 0)
                        return ++colR;
                }
            }
        }
        else
        {
            if(arr[rowL][colL] == 0 || !checkL)
            {
                if(rowL < 5)
                {
                    rowL += dir_r[DOWN];
                    colL += dir_c[DOWN];

                    if(arr[rowL][colL] != 0)
                    {
                        rowL -= 2; tmpRowL--;

                        if(winDirCountR >= 3 && trackStatus == PC)
                        {
                            if( (tmpColL == colL) && trackStatus == PLAYER)
                            {   
                                if(arr[rowL][colL] == 0)
                                    return ++colL;
                            }
                            else
                            {
                                if(arr[tmpRowL][tmpColL] == 0)
                                    return (++tmpColL * -1);
                            }
                        }
                        else
                        {
                            if(arr[rowL][colL] == 0)
                                return ++colL;
                        }
                    }
                }else
                {
                    rowL--; tmpRowL--;

                    if(winDirCountR >= 3)
                    {
                        if((tmpColL == colL) && trackStatus == PLAYER) // I think we can keep only the tmp var. its enough!
                        {
                            if(arr[rowL][colL] == 0)    
                                return ++colL;
                        }
                        else
                        {
                            if(arr[tmpRowL][tmpColL] == 0)
                                return (++tmpColL * -1);
                        }
                    }
                    else
                    {
                        if(arr[rowL][colL] == 0)
                            return ++colL;
                    }
                }
            }
        }
    }
    return 0;
}

/* 
    ------------------------------------------------------------------------------
    -> Up_Left_Down_RightTracking() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |
    |
    |
    |     
    ------------------------------------------------------------------------------

*/

int Up_Left_Down_RightTracking(int[ROWS][COLS], int x, int y, int trackStatus) // new not documented
{
    int rowUL = x, colUL = y;
    int rowDR = x, colDR = y;
    
    int tmpRowUL = 0, tmpColUL = 0;
    int tmpRowDR = 0, tmpColDR = 0;

    int plColor = arr[x][y];
    int winDirCountUL = 1, winDirCountDR = 1;
    
    bool dirCheckUL = true, dirCheckDR = true;
    bool checkUL = true, checkDR = true;

    for (int i = 1; i < steps; i++)
    {
        // UP_LEFT direction
        if ( (colUL > 0 && rowUL > 0) && (dirCheckUL))
        {
            rowUL += dir_r[UP_LEFT];
            colUL += dir_c[UP_LEFT];
            
            if (arr[rowUL][colUL] == plColor)
                winDirCountUL++;
            else
            {
                if(arr[rowUL][colUL] == 0 && checkUL)
                {
                    tmpRowUL = rowUL;
                    tmpColUL = colUL;
                    checkUL = false;
                }
                else
                    dirCheckUL = false;
            }                
        }

        // DOWN_RIGHT direction
        if ( (colDR < 6 && rowDR < 5) && (dirCheckDR))
        {
            rowDR += dir_r[DOWN_RIGHT];
            colDR += dir_c[DOWN_RIGHT];
            
            if (arr[rowDR][colDR] == plColor)
                winDirCountDR++;
            else
            {
                if(arr[rowDR][colDR] == 0 && checkDR)
                {
                    tmpRowDR = rowDR;
                    tmpColDR = colDR;
                    checkDR = false;
                }
                else
                    dirCheckDR = false;
            }                
        }
    }

    // in case the next up right was the top 
    // we should turn dirCheckUR to false we 
    // declared it to be true only if we have
    // 3 or more wins, but here we donot have that
    if(rowUL == 0 && dirCheckUL && winDirCountUL < 3) // I don't think we need these any more
        dirCheckUL = false;

    if(rowDR == 5 && dirCheckDR && winDirCountDR < 3)
        dirCheckDR = false;

    if(!dirCheckUL && !checkUL)
    {
        rowUL += dir_r[DOWN_RIGHT];
        colUL += dir_c[DOWN_RIGHT];
        checkUL = true;
    }

    if(!dirCheckDR && !checkDR)
    {
        rowDR += dir_r[UP_LEFT];
        colDR += dir_c[UP_LEFT];
        checkDR = true;
    }

    // UP_LEFT <> DOWN_RIGHT
    winDirCountUL += (winDirCountDR - 1); 
    if(winDirCountUL >= 3 || trackStatus == PC)
    {
        if(arr[rowUL][colUL] == 0 || !checkUL)
        {
            rowUL += dir_r[DOWN];

            if (arr[rowUL][colUL] != 0)
            {
                rowUL -= 2; tmpRowUL--;
               
                if(winDirCountUL >= 3)
                {
                    if( (tmpColUL == colUL) && trackStatus == PLAYER)
                    {
                        if(arr[rowUL][colUL] == 0)
                            return ++colUL;
                    }
                    else
                    {
                        if(arr[tmpRowUL][tmpColUL] == 0)
                            return (++tmpColUL * -1);
                    }
                }
                else
                {
                    if(arr[rowUL][colUL] == 0)
                        return ++colUL;
                }
            }
        }
        else
        {
            if(arr[rowDR][colDR] == 0 || !checkDR)
            {
                if(rowDR < 5)
                {
                    rowDR += dir_r[DOWN];

                    if(arr[rowDR][colDR] != 0)
                    {
                        rowDR -= 2; tmpRowDR--;

                        if(winDirCountUL >= 3) // I don't know if PC is important here or not
                        {
                            if((tmpColDR == colDR) && trackStatus == PLAYER)
                            {
                                if(arr[rowDR][colDR] == 0)
                                    return ++colDR;
                            }
                            else
                            {
                                if(arr[tmpRowDR][tmpColDR] == 0)
                                    return (++tmpColDR * -1);
                            }
                        }
                    }
                }
                else
                {
                    if(winDirCountUL >= 3)
                    {
                        rowDR--; tmpRowDR--;

                        if( (tmpColDR == colDR) && trackStatus == PLAYER)
                        {
                            if(arr[rowDR][colDR] == 0)
                                return ++colDR;
                        }
                        else
                        {
                            if(arr[tmpRowDR][tmpColDR] == 0)
                                return (++tmpColDR * -1);
                        }
                    }
                    else
                    {
                        if(arr[rowDR][colDR] == 0)
                            return ++colDR;
                    }
                }
            }
        }
    }
    return 0;
}

/* 
    ------------------------------------------------------------------------------
    -> Up_Right_Down_LeftTracking() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |
    |
    |
    |     
    ------------------------------------------------------------------------------

*/

int Up_Right_Down_LeftTracking(int[ROWS][COLS], int x, int y, int trackStatus) // new not documented
{
    int rowUR = x, colUR = y;
    int rowDL = x, colDL = y;

    int tmpRowUR = 0, tmpColUR = 0;
    int tmpRowDL = 0, tmpColDL = 0;

    int plColor = arr[x][y];
    int winDirCountUR = 1, winDirCountDL = 1;

    bool dirCheckUR = true, dirCheckDL = true;
    bool checkUR = true, checkDL = true;

    for (int i = 1; i < steps; i++)
    {
        // UP_RIGHT direction
        if ( (colUR < 6 && rowUR > 0) && (dirCheckUR))
        {
            rowUR += dir_r[UP_RIGHT];
            colUR += dir_c[UP_RIGHT];
            
            if (arr[rowUR][colUR] == plColor)
                winDirCountUR++;
            else
            {
                if(arr[rowUR][colUR] == 0 && checkUR)
                {
                    tmpRowUR = rowUR;
                    tmpColUR = colUR;
                    checkUR = false;
                }else
                    dirCheckUR = false;
            }
        }

        // DOWN_LEFT direction
        if ( (colDL > 0 && rowDL < 5) && (dirCheckDL))
        {
            rowDL += dir_r[DOWN_LEFT];
            colDL += dir_c[DOWN_LEFT];
            
            if (arr[rowDL][colDL] == plColor)
                winDirCountDL++;
            else
            {
                if(arr[rowDL][colDL] == 0 && checkDL)
                {
                    tmpRowDL = rowDL;
                    tmpColDL = colDL;
                    checkDL = false;
                }
                else
                    dirCheckDL = false;
            }
        }
    }

    // in case the next up right was the top 
    // we should turn dirCheckUR to false we 
    // declared it to be true only if we have
    // 3 or more wins, but here we donot have that
    if(rowUR == 0 && dirCheckUR && winDirCountUR < 3)
        dirCheckUR == false;

    if(rowDL == 5 && dirCheckDL && winDirCountDL < 3)
        dirCheckDL == false;
        
    // restore every thing to its default
    if(!dirCheckUR && !checkUR)
    {
        rowUR += dir_r[DOWN_LEFT];
        colUR += dir_c[DOWN_LEFT];
        checkUR = true;
    }

    if(!dirCheckDL && !checkDL)
    {
        rowDL += dir_r[UP_RIGHT];
        colDL += dir_c[UP_RIGHT];
        checkDL = true;
    }

    // UP_RIGHT <> DOWN_LEFT
    winDirCountUR += (winDirCountDL - 1); 
    if(winDirCountUR >= 3 || trackStatus == PC)
    {
        if(arr[rowUR][colUR] == 0 || !checkUR)
        {
            rowUR += dir_r[DOWN];

            if (arr[rowUR][colUR] != 0)
            {
                rowUR -= 2; tmpRowUR--;
                
                if(winDirCountUR >= 3)
                {
                    if((tmpColUR == colUR) && trackStatus == PLAYER)
                    {
                        if(arr[rowUR][colUR] == 0)
                            return ++colUR;
                    }
                    else
                    {
                        if(arr[tmpRowUR][tmpColUR] == 0)
                            return (++tmpColUR * -1);
                    }
                }
                else
                {
                    if(arr[rowUR][colUR] == 0)
                        return ++colUR;
                }
            }
        }
        else
        {
            if(arr[rowDL][colDL] == 0 || !checkDL)
            {
                if(rowDL < 5)
                {
                    rowDL += dir_r[DOWN];

                    if(arr[rowDL][colDL] != 0)
                    {
                        rowDL -= 2; tmpRowDL--;

                        if(winDirCountUR >= 3)
                        {
                            if((tmpColDL == colDL) && trackStatus == PLAYER)
                            {
                                if(arr[rowDL][colDL] == 0)
                                    return ++colDL;
                            }
                            else
                            {
                                if(arr[tmpRowDL][tmpColDL] == 0)
                                    return (++tmpColDL * -1);
                            }
                        }
                        else
                        {
                            if(arr[rowDL][colDL] == 0)
                                return ++colDL;
                        }
                    }
                }
                else
                {
                    rowDL--; tmpRowDL--;

                    if(winDirCountUR >= 3)
                    {
                        if( (tmpColDL == colDL) && trackStatus == PLAYER)
                        {
                            if(arr[rowDL][colDL] == 0)
                                return ++colDL;
                        }
                        else
                        {
                            if(arr[tmpRowDL][tmpColDL] == 0)
                                return (++tmpColDL * -1);
                        }
                    }
                    else
                    {
                        if(arr[rowDL][colDL] == 0)
                            return ++colDL;
                    }
                }
            }
        }
    }
    return 0;
}

/* 
    ------------------------------------------------------------------------------
    -> inputC4GamePC() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |
    |
    |
    |     
    ------------------------------------------------------------------------------

*/

// TODO: prevent PC to choose a full colomn from your algorithms using any exception
// TODO: what is better many returns or only one for function?
int inputC4GamePC(int arr[ROWS][COLS], int PCcolor, int PCLevel, int Index)
{
    // player position
    int plRow = 0, plCol = 0, plColor = 0;
    int PCRow = 0, PCCol = 0;
    int plIndex = 0, PCIndex = 0;
    
    int countHARD = 6;

    const int NrOfDir = 8;
    int PCColChoice[NrOfDir] = {0};
    int colChoice = 0;
    int _colChoice = 0; // in case we have 3 plays then 

    // the first play 
    if(historyArr[0][0] == 0 || Index == 1)
        colChoice = 4;
    else
    {        
        if(Index < 7)
        {
            PCIndex = Index - 2; // here we get our last play position from the history
            int tmp = arr[5][historyArr[PCIndex][2] + 1]; // get the next colomn value
            
            if(tmp == 0)
                colChoice = historyArr[PCIndex][2] + 2;  // -> we add 2 instead of 1 because at the
            else                                         //    main input function the col will be 
                colChoice = historyArr[PCIndex][2] + 1;  //    decreased by one before playing it 
                                                         //    to change from game interface input 
                                                         //    and array index.
        }
        else
        {
            do
            {
                // 1st track the player
                // --------------------

                // the player infos
                plIndex = Index-1-countHARD;
                plColor = historyArr[plIndex][0];
                plRow = historyArr[plIndex][1];
                plCol = historyArr[plIndex][2];
                
                // tracking the player DOWN, LEFT and RIGHT
                PCColChoice[DOWN] = DownTracking(arr, plRow, plCol, PLAYER);
                PCColChoice[RIGHT] = RightLeftTracking(arr, plRow, plCol, PLAYER); // Right <> Left
                
                // 2nd PC play and track him self
                // ------------------------------
                if(PCColChoice[DOWN] > 0)
                    colChoice = PCColChoice[DOWN];
                else
                {
                    if(PCColChoice[RIGHT] > 0)
                        colChoice = PCColChoice[RIGHT];
                    // PC track it self part:
                    else
                    {
                        // The PC infos:
                        PCIndex = Index-2-countHARD;
                        PCRow = historyArr[PCIndex][1];
                        PCCol = historyArr[PCIndex][2];
                        
                        // tracking the PC DOWN, LEFT and RIGHT
                        PCColChoice[DOWN] = DownTracking(arr, PCRow, PCCol, PC);
                        PCColChoice[RIGHT] = RightLeftTracking(arr, PCRow, PCCol, PC);

                        // PC plays after less than 3 plays before
                        if(PCColChoice[RIGHT] > 0)
                            colChoice = PCColChoice[RIGHT];
                        else
                        {
                            if(PCColChoice[DOWN] > 0)
                                colChoice = PCColChoice[DOWN];
                        }

                        // PC plays after 3 or more plays before
                        if(PCColChoice[RIGHT] < 0)
                            _colChoice = PCColChoice[RIGHT];
                        else
                        {
                            if(PCColChoice[DOWN] < 0)
                                _colChoice = PCColChoice[DOWN];
                        }
                    }
                }
            

                if(PCLevel == MEDIUM || PCLevel == HARD)
                {
                    // tracking the player UP_LEFT DOWN_RIGHT and UP_RIGHT DOWN_LEFT
                    PCColChoice[UP_LEFT] = Up_Left_Down_RightTracking(arr, plRow, plCol, PLAYER);
                    PCColChoice[UP_RIGHT] = Up_Right_Down_LeftTracking(arr, plRow, plCol, PLAYER);

                    // 2nd PC play and track him self
                    // ------------------------------
                    if(PCColChoice[UP_LEFT] > 0)
                        colChoice = PCColChoice[UP_LEFT];
                    else
                    {
                        if(PCColChoice[UP_RIGHT] > 0)
                            colChoice = PCColChoice[UP_RIGHT];
                        // PC track it self part:
                        else
                        {
                            // tracking the PC UP_LEFT DOWN_RIGHT and UP_RIGHT DOWN_LEFT
                            PCColChoice[UP_LEFT] = Up_Left_Down_RightTracking(arr, PCRow, PCCol, PC);
                            PCColChoice[UP_RIGHT] = Up_Right_Down_LeftTracking(arr, PCRow, PCCol, PC);
                            
                            // PC plays after less than 3 plays before
                            if(PCColChoice[UP_LEFT] > 0)
                                colChoice = PCColChoice[UP_LEFT];
                            else
                            {
                                if(PCColChoice[UP_RIGHT] > 0)
                                    colChoice = PCColChoice[UP_RIGHT];
                            }

                            // PC plays after 3 or more than 3 plays before
                            if(PCColChoice[UP_LEFT] < 0)
                                _colChoice = PCColChoice[UP_LEFT];
                            else
                            {
                                if(PCColChoice[UP_RIGHT] < 0)
                                    _colChoice = PCColChoice[UP_RIGHT];
                            }
                        }
                    }
                }

                if(PCLevel == HARD && countHARD <= 6)
                {
                    countHARD -= 2;
                    if(countHARD < 0)
                        break;
                }
            }while(PCLevel == HARD);    
        }
    }

    // in case I do not konw exactly where I should play
    if(colChoice == 0)
    {
        for(int i = 0; i < COLS; i++)
        {
            if(arr[0][i] == 0)
            {
                colChoice = ++i;
                break;
            }
                
        }
    }

    if(_colChoice < 0)
        return (_colChoice * -1) ; // in case nothing works
    else
        return colChoice;
}

/* 
    ------------------------------------------------------------------------------
    -> printC4Game() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |   - here we output our layout which represents the game interface:
    |     as we can see the program when it runs that we do a first line
    |     with numbers so the player  could know where he will put the coin
    |     red or black and then the 2D array layout and we boundered the 
    |     cells with the char '|' and representing empty cells with a big O and then
    |     the red and black coins with its color names.
    |
    |   - to print we need only the arr[ROWS][COLS] as an argument.   
    |
    |   - our print function has two loops an outer loop which represents
    |     the rows of the 2D array and the inner loop which represents the 
    |     colomns.
    |
    |   - then we have two conditions: actually these two conditions are only
    |     for the layout and interface purposes, because the first '|' char 
    |     at each row should be printed sperated from the rest.
    |
    |   - the flow is like this red/black/O   |   red/black/O     | ...
    |     but at the begening of the row we do '|' first before the red/black output.
    |
    |     
    ------------------------------------------------------------------------------

*/

void printC4Game(int arr[ROWS][COLS], int PCStatus)
{
    char ch = '|';
    for (int i = 1; i <= 7; i++)
        cout << setw(8) << i;

    cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j == 0)
            {
                if (arr[i][j] == 1)
                    cout << setw(4) << ch << "  red  " << ch;
                else
                {
                    if (arr[i][j] == 2)
                        cout << setw(4) << ch << " black " << ch;
                    else
                        cout << setw(4) << ch << "   O   " << ch;
                }
            }
            else
            {
                if (arr[i][j] == 1)
                    cout << "  red  " << ch;
                else
                {
                    if (arr[i][j] == 2)
                        cout << " black " << ch;
                    else
                        cout << "   O   " << ch;
                }
            }
        }
        cout << "\n\n";
    }
    cout<<"\n\t- Red: \t\t\t\t- Black:\n";
    if(PCStatus != 0)
    {
        if(PCStatus == red)
            cout<<"\n\t- PC wins: "<<redWins<<"\t\t\t- "<<fstPlayer<<" wins: "<<blackWins<<"\n";
        else
            cout<<"\n\t- "<<fstPlayer<<" wins: "<<redWins<<"\t\t\t- PC wins: "<<blackWins<<"\n";
    
    }
    else
    {
        if(fstPlayerCol == red)
            cout<<"\n\t- "<<fstPlayer<<" wins: "<<redWins<<"\t\t\t- "<<scndPlayer<<" wins: "<<blackWins<<"\n";
        else
            cout<<"\n\t- "<<scndPlayer<<" wins: "<<redWins<<"\t\t\t- "<<fstPlayer<<" wins: "<<blackWins<<"\n";
    }
}

/* 
    ------------------------------------------------------------------------------
    -> winnerC4Game() function
    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    |
    |   - here we check the winners each time any player plays his game after the
    |     first 7 movements.
    |
    |   - we have here as arguments 4 attributes:
    |       1- arr[ROWS][COLS] - the 2D array it self which have the players moves
    |       2 & 3- int x, int y - indicate the play movement positioin for the player 
    |          who played it just now.
    |       4- int count: it has the nr. of plays since we started the game.
    |
    |   + we have here 3 main components:
    |   =================================
    |       |-> 1st component: is the Decleration, we have 7 varibales:
    |       |----------------------------------------------------------
    |       |
    |       |   1. int plColor = arr[x][y] - this is the color of the player 
    |       |   who played now and we use its value to check the next cell 
    |       |   in any direction
    |       |   
    |       |   2. int direction = 0 - this is for the specified direction
    |       |   to look for similar color cells in the nearby of our position
    |       |   and we have total 7 directions excluded UP because its always empty
    |       |   
    |       |   3. const int NrOfDir = 8 - this is the nr. of directions we use to 
    |       |   specify the size of the 4 comming arrays because we will calculate
    |       |   calcs for each directions we made it default 8 but in reality we
    |       |   only make calcs on 7 directions because we exclude UP as we 
    |       |   mentioned before. 
    |       |
    |       |   4. int winDirCount[NrOfDir] = {0} - here we track each direction count 
    |       |   and the count should find the similar color occurance for current 
    |       |   playing position in all directions so we can calc the winner each time
    |       |   if there is a one.
    |       |
    |       |   5 & 6. int row[NrOfDir] = {0}; - here we save our new position
    |       |          int col[NrOfDir] = {0};   during the search for similar
    |       |          colors in the nearby from the current playing position,
    |       |          for example if we try to go left and look which color we
    |       |          have there firstly we initialize our 'row' and 'col' arrays
    |       |          with the current position and then sub -1 from the col in the
    |       |          left element of the array and do nothing to left element in the
    |       |          row array to shift to lef in our 2D array.
    |       |
    |       |   7. bool dirCheck[NrOfDir] = {0}; - here we have a checker to turn
    |       |   any direction of by assigning to its loc here false in case the 
    |       |   cell of our nearby cell is empty or has a different color so 
    |       |   we will not go further at the next loop, and we do this stop status
    |       |   because we move many steps (3) in each direction so if there is no 
    |       |   more same color at the next step we should then stop even if we did 
    |       |   not reach our maximum 3 steps.
    |       |
    |       |   Hint: all the previous 4 variables we declared them in array form
    |       |   because we want to do all directions at once in one loop.
    |       |          
    |       |-> 2nd Component: final part to print out the winner in our if part
    |       |--------------------------------------------------------------------
    |       |
    |       |   - then we made a condition 'if else' the first part is true when 
    |       |   count equal to the nr. of cells in the 2D array and then print the 
    |       |   winner name based on the nr. of wins each of them both earned through
    |       |   the game.
    |       |
    |       |-> 3rd Component: the tracking and winner finding section:
    |       |----------------------------------------------------------
    |       |   
    |       |   * breif abstract:  
    |       |   ----------------
    |       |   the 'else' part of the game is the tracker part 
    |       |   which looks for each winning movement and add them to the player
    |       |   who won that time and at the end we compare between the nr. of wins
    |       |   of the both of players and print the winner at the end.
    |       |
    |       |   the 3rd component "else" consist of 2 parts:
    |       |       * the first part: is the tracking part: where we made a loop 
    |       |         looping 3 times to look for 4 similar colors in each direction
    |       |         starting from my current playing location and moving 3 steps in the all 8
    |       |         directions, and whenever I find a similar color in any direction I will count
    |       |         it.
    |       |
    |       |       * the second part: is the Calculation part: where we add each two counting opisite
    |       |         directions to each other and if we have a result which is more than or equal 4
    |       |         then we have a win situation, in this case we will add a win point to that color
    |       |    
    |       |   * Explain in detailes:    
    |       |   ----------------------
    |       |
    |       |       - 3rd Component: first part:(tracking)
    |       |           a)  we starting the first part by initializing our tracking arrays
    |       |               by using fill() function because we assign nonzero values.
    |       |              
    |       |               we defined it as arrays to track all directions simultanseously
    |       |               so each array has size '8' because we have 8 directions in general
    |       |               the first two arrays are 'row' and 'col' here we assign the coordinate
    |       |               of the play position (x, y) to the all elemnets in the 2 arrays so we can use
    |       |               them as starting point when we start tracking the similar colors in all 
    |       |               directions.
    |       |           
    |       |               the third fill() is winDirCount[8] which is the counter for any similer
    |       |               color found during the tracking in all directions, and this array is very 
    |       |               important because we use it to calc the wins situations.
    |       |
    |       |               the fourth fill() is dirCheck[8] which is a false true checker for our 
    |       |               similar color searching so whenever I move to a specific direction and 
    |       |               I did not found a similar color or it was empty I mark this direction
    |       |               with false so I will not look in this direction at the next iteration.
    |       |               
    |       |           b)  now we are begining with our loop part here, and it will iterate 3 times
    |       |               not 4 because we count our starting point where the player just played now
    |       |               
    |       |               here in the loop we have a tracking part for each direction contained in 
    |       |               if condition with two constrained the first is for boundaries to prevent
    |       |               moving in to a direction which is at the boundary like if I am at the bottom
    |       |               I will not search DOWN direction because I am already at the bottom of the 2D array
    |       |               and the second condition is the direction checker and this one will be true at the
    |       |               first loop because did not started moving yet so all the elemnets are true but if
    |       |               moved in a direction and the nearby cell at this directioin was not similar to our
    |       |               player color then this direction is off and we do not need to look init again so 
    |       |               we change the status of this DirCheck to false so at the next loop we skip this 
    |       |               direction and move forward to another one.  
    |       |
    |       |               each direction container has a number of steps to track, first we assign our 
    |       |               direction to varibale called direction, then we move one step toward this 
    |       |               direction by using a small trick we learned before, we defined above globally
    |       |               enum dir for our 8 directions and after that we defined two arrays for row and col
    |       |               to indicate the shifting of the direction in the both coordinate row and col
    |       |               and we arranged it so the nr. of the direction in enum will have its shifting move
    |       |               in the two arrays 'row' & 'col' for example DOWN is nr. 0 in enum we will find then
    |       |               its moving shift at indix 0 in both 'row' & 'col' so row[0] = 1, & col[0] = 0, that
    |       |               means if we add 1 to our row current position that means we moved one step down
    |       |               and will not change any thing at col because DOWN is moving vertically not horizontly
    |       |               which means we move in the same col.
    |       |               
    |       |               the move part are taking place like this: row[DOWN] += dir_r[direction];
    |       |                                                         col[DOWN] += dir_c[direction];
    |       |               
    |       |               then we have our if else part after we moved to that direction
    |       |               to check its color with the player color if its the same we add
    |       |               1 to winDirCount[direction] 'else' we change the status of this
    |       |               direction to false like this 'dirCheck[direction] = false' so we
    |       |               will skip this direction at the next iterations.
    |       |
    |       |               we made the previous steps with each direction so we duplicated it
    |       |               8 times but in reality we use only 7 directions and we do not to track
    |       |               UP direction as we mentioned several times before, because the current
    |       |               play is always at the top.               
    |       |
    |       |       - 3rd component: second part: (Calculation)
    |       |           * here we try to claculate the winner if there is, we do this by add the 
    |       |             winDirCount[direction] of each two opisite directions like LEFT and RIGHT,
    |       |             but there is an exception for DOWN here we do not add UP because our plays
    |       |             are always on the top, and not to forget with the adding we should subtract
    |       |             1 each time to not duplicate the current player position which is our starting
    |       |             point of each direction separately. 
    |       |           
    |       |           * we have 4 calculations instead of 8 because we add each two opisite directions 
    |       |             together, and each calculation is contained in if condition checks first if the
    |       |             adding result exceed the 4 or is at least 4, if yes then we join in the condition
    |       |             what left for us inside is only to add the win point to its player color by checking
    |       |             the plColor with red and black and add 1 to winReds or winBlacks depend on which color
    |       |             the player is, but we have also a nother rule for example if we are more than 4 then
    |       |             we have more wins so each nr we add on 4 means we won one more time so if we have 5
    |       |             then we add 2 wins if we have 6 we add 3 wins if we have 7 we add 4 wins and that is
    |       |             is our limit because we are restricted with the size of our 2D array which is 6 x 7.
    |       |---------------------------------------------------------------------------------------------------
    |    
    ------------------------------------------------------------------------------

*/

// TODO: How to indent backwards in VSCode? || DONE: shft + tab ||
void winnerC4Game(int arr[ROWS][COLS], int x, int y, int count, int PCStatus)
{
    // 1st Component: (Decleration)
    // ----------------------------


    //int r = 0, c = 0; // we do not need them anymore
    int plColor = arr[x][y]; 
    int direction = 0;

    // we could have used vector better than array so we shouldn't find a one place for our
    // all elements of the array
    const int NrOfDir = 8;
    int winDirCount[NrOfDir] = {0}; // we created this array to track the all direction in one
                                    // array
    // here we change the position for each direction
    int row[NrOfDir] = {0};
    int col[NrOfDir] = {0};

    // it is useful to prevent a direction the next loop if its the next one
    // is not the same color
    bool dirCheck[NrOfDir] = {0};

    
    // 2nd component: (tracking and calulating)
    // ---------------------------------------

    // first part:(tracking)
    //======================


    // initializing array with none zero value
    fill(row, row + NrOfDir, x);
    fill(col, col + NrOfDir, y);
    fill(winDirCount, winDirCount + NrOfDir, 1);
    fill(dirCheck, dirCheck + NrOfDir, true);

    for (int i = 1; i < steps; i++)
    {
        // ------------------------
        // The Up part look up down
        // ------------------------

        // DOWN direction
        if (row[DOWN] < 5 && (dirCheck[DOWN]))
        {
            direction = DOWN;
            row[DOWN] += dir_r[direction];
            col[DOWN] += dir_c[direction];
            
            if (arr[row[DOWN]][col[DOWN]] == plColor)
                winDirCount[DOWN]++;
            else
                dirCheck[DOWN] = false;
        }

        // RIGHT direction
        if (col[RIGHT] < 6 && (dirCheck[RIGHT]))
        {
            direction = RIGHT;
            row[RIGHT] += dir_r[direction];
            col[RIGHT] += dir_c[direction];
            
            if (arr[row[RIGHT]][col[RIGHT]] == plColor)
                winDirCount[RIGHT]++;
            else
                dirCheck[RIGHT] = false;
        }

        // LEFT direction
        if (col[LEFT] > 0 && (dirCheck[LEFT]))
        {
            direction = LEFT;
            row[LEFT] += dir_r[direction];
            col[LEFT] += dir_c[direction];
            
            if (arr[row[LEFT]][col[LEFT]] == plColor)
                winDirCount[LEFT]++;
            else
                dirCheck[LEFT] = false;
        }

        // UP_RIGHT direction
        if ( (col[UP_RIGHT] < 6 && row[UP_RIGHT] > 0) && (dirCheck[UP_RIGHT]))
        {
            direction = UP_RIGHT;
            row[UP_RIGHT] += dir_r[direction];
            col[UP_RIGHT] += dir_c[direction];
            
            if (arr[row[UP_RIGHT]][col[UP_RIGHT]] == plColor)
                winDirCount[UP_RIGHT]++;
            else
                dirCheck[UP_RIGHT] = false;
        }

        // UP_LEFT direction
        if ( (col[UP_LEFT] > 0 && row[UP_LEFT] > 0) && (dirCheck[UP_LEFT]))
        {
            direction = UP_LEFT;
            row[UP_LEFT] += dir_r[direction];
            col[UP_LEFT] += dir_c[direction];
            
            if (arr[row[UP_LEFT]][col[UP_LEFT]] == plColor)
                winDirCount[UP_LEFT]++;
            else
                dirCheck[UP_LEFT] = false;
        }

        // DOWN_RIGHT direction
        if ( (col[DOWN_RIGHT] < 6 && row[DOWN_RIGHT] < 5) && (dirCheck[DOWN_RIGHT]))
        {
            direction = DOWN_RIGHT;
            row[DOWN_RIGHT] += dir_r[direction];
            col[DOWN_RIGHT] += dir_c[direction];
            
            if (arr[row[DOWN_RIGHT]][col[DOWN_RIGHT]] == plColor)
                winDirCount[DOWN_RIGHT]++;
            else
                dirCheck[DOWN_RIGHT] = false;
        }

        // DOWN_LEFT direction
        if ( (col[DOWN_LEFT] > 0 && row[DOWN_LEFT] < 5) && (dirCheck[DOWN_LEFT]))
        {
            direction = DOWN_LEFT;
            row[DOWN_LEFT] += dir_r[direction];
            col[DOWN_LEFT] += dir_c[direction];
            
            if (arr[row[DOWN_LEFT]][col[DOWN_LEFT]] == plColor)
                winDirCount[DOWN_LEFT]++;
            else
                dirCheck[DOWN_LEFT] = false;
        }
    }

    // second part:(calculating)
    // =========================

    //----------------------------------
    // I sub 1 from DOWN count because
    // I start with my position as 1 
    // for each direction so when I add
    // 2 directions I should remove one
    // to prevent duplicate my position
    //----------------------------------

    // ---------------------------------------
    // the Up adding to Down part look up donw
    // ---------------------------------------
    
    // Down 
    if(winDirCount[DOWN] >= steps)
    {
        if(plColor == red)
            redWins++;
        else
            blackWins++;
        
        if(winDirCount[DOWN] > steps)
        {
            if(winDirCount[DOWN] == 5)
            {
                if(plColor == red)
                    redWins++;
                else
                    blackWins++;
            }else
            {
                if(winDirCount[DOWN] == 6)
                {
                    if(plColor == red)
                        redWins+=2;
                    else
                        blackWins+=2;
                }else
                {
                    if(plColor == red)
                        redWins+=3;
                    else
                        blackWins+=3;
                }
            }
        }
    }

    // RIGHT <> LEFT
    winDirCount[RIGHT] += (winDirCount[LEFT] - 1); 
    if(winDirCount[RIGHT] >= steps)
    {
        if(plColor == red)
            redWins++;
        else
            blackWins++;
        
        if(winDirCount[RIGHT] > steps)
        {
            if(winDirCount[RIGHT] == 5)
            {
                if(plColor == red)
                    redWins++;
                else
                    blackWins++;
            }else
            {
                if(winDirCount[RIGHT] == 6)
                {
                    if(plColor == red)
                        redWins+=2;
                    else
                        blackWins+=2;
                }else
                {
                    if(plColor == red)
                        redWins+=3;
                    else
                        blackWins+=3;
                }
            }
        }
    }

    // UP_RIGHT <> DOWN_LEFT
    winDirCount[UP_RIGHT] += (winDirCount[DOWN_LEFT] - 1); 
    if(winDirCount[UP_RIGHT] >= steps)
    {
        if(plColor == red)
            redWins++;
        else
            blackWins++;
        
        if(winDirCount[UP_RIGHT] > steps)
        {
            if(winDirCount[UP_RIGHT] == 5)
            {
                if(plColor == red)
                    redWins++;
                else
                    blackWins++;
            }else
            {
                if(winDirCount[UP_RIGHT] == 6)
                {
                    if(plColor == red)
                        redWins+=2;
                    else
                        blackWins+=2;
                }else
                {
                    if(plColor == red)
                        redWins+=3;
                    else
                        blackWins+=3;
                }
            }           
        }
    }

    // UP_LEFT <> DOWN_RIGHT
    winDirCount[UP_LEFT] += (winDirCount[DOWN_RIGHT] - 1); 
    if(winDirCount[UP_LEFT] >= steps)
    {
        if(plColor == red)
            redWins++;
        else
            blackWins++;
        
        if(winDirCount[UP_LEFT] > steps)
        {
            if(winDirCount[UP_LEFT] == 5)
            {
                if(plColor == red)
                    redWins++;
                else
                    blackWins++;
            }else
            {
                if(winDirCount[UP_LEFT] == 6)
                {
                    if(plColor == red)
                        redWins+=2;
                    else
                        blackWins+=2;
                }else
                {
                    if(plColor == red)
                        redWins+=3;
                    else
                        blackWins+=3;
                }
            }
        }
    }

    // 3rd component: (final winner)
    // -----------------------------

    // TODO: searching thing is it possible to run a programm in a loop multiple times without checking every time to save time
    if (count == (ROWS * COLS)) // all full
    {
        printC4Game(arr, PCStatus);
        
        cout<<"\n\t+++----------------------------+++\n";
        if (redWins > blackWins)
        {
            if(PCStatus != 0)
            {
                if(PCStatus == red)
                    cout << "\t- The winner is: PC";
                else
                    cout << "\t- The winner is: "<<fstPlayer;  
            
            }
            else
            {
                if(fstPlayerCol == red)
                    cout << "\t- The winner is: "<<fstPlayer;
                else
                    cout << "\t- The winner is: "<<scndPlayer;  
            }

             
        }
        else
        {
            if (redWins < blackWins)
            {
                if(PCStatus != 0)
                {
                    if(PCStatus == black)
                        cout << "\t- The winner is: PC";
                    else
                        cout << "\t- The winner is: "<<fstPlayer;
                }
                else
                {
                    if(fstPlayerCol == black)
                        cout << "\t- The winner is: "<<fstPlayer;
                    else
                        cout << "\t- The winner is: "<<scndPlayer;
                }
            }
            else
            {
                if(PCStatus != 0)
                    cout << "\t- PC and "<<fstPlayer<<" are equal both win";
                else
                    cout << "\t- "<<fstPlayer<<" and "<<scndPlayer<<" are equal both win";
            }
        }
        cout<<"\n\t+++----------------------------+++\n";
    }
}




/*

+ the replaced or removed code parts from above:
  ---------------------------------------

    -> Headers Not used for the Game
       =============================

    //#include <stdlib.h>
    //#include <assert.h>
    
    -> connectC4Game() function - edit the play vs. play part
       ======================================================

    cout << "\n\n\t\t\t+++ You chose to play Vs. another player. +++\n\n"
        << "\t- Discuss with your friend who wanna be red\n\t  and who wanna be black.\n\n"
        << "\t- we give you both 5 secounds to decide.\n";
    do
    {

        check = true;
        cout<<"  ";
        for (int i = 1; i <= 5; i++)
        {
            cout << setw(9) << i;
            Sleep(1000); // #include <windows.h>
                            // wiered! it works though it is here undefined
        }
        cout << "\n\n\n\t\t\t!!! Time up !!!\n\n"
                << "\t+++-------------------------------------+++\n"
                << "\t- Type 'y' to continue.\n"
                << "\t- Type 'n' for waiting more 5 secounds.\n"
                << "\t+++-------------------------------------+++\n"
                << "\n\tChoose your option: ";
        cin >> ClrOption;

        //input validation
        if (cin.fail() || (ClrOption != 'y' && ClrOption != 'n' && ClrOption != 'Y' && ClrOption != 'N'))
        {
            cout << "\n\t\t\t!!! You entered an unvalid value. plz try again !!!\n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
            check = false;
        }

    } while (!check || ClrOption == 'n' || ClrOption == 'N');

    -> inputC4Game() function - the old random generator way
       =====================================================

    simple way
    srand(time(0));
    int r = (rand() % 2) + 1;

    +----------------------------------------0-0------------------------------------------+
    +----------------------------------------0-0------------------------------------------+

    -> inputC4Game() function - the old input way
       ==========================================

    while( r >= 0)
    {
        if(arr[r][colChoice] == 0 || r == 0)
        {
            if(arr[r][colChoice] != 0 && r == 0)
            {
                cout<<"This Column is full plz try another one.\n\n"; // only current col is full
                //check = false;
                colStatus = isFull;
                break;
            }
            else
            {
                    arr[r][colChoice] = playerColor;
                    Count++;
                    break;
            }            
        }
        r--;
    }

    +----------------------------------------0-0------------------------------------------+
    +----------------------------------------0-0------------------------------------------+

    -> winnerC4Game() function - Up part when we search for 3 same colors
       ==================================================================    
    

    // Up direction
    // hint: here I should not search because the up is evry time empty
    if (row[UP] > 0 && (dirCheck[UP]))
    {
        direction = UP;
        row[UP] += dir_r[direction];
        col[UP] += dir_c[direction];
        
        if (arr[row[UP]][col[UP]] == plColor)
            winDirCount[UP]++;
        else
            dirCheck[UP] = false;
    }

    +----------------------------------------0-0------------------------------------------+
    +----------------------------------------0-0------------------------------------------+
    
    -> winnerC4Game() function - Up adding to Down part to calc winns
       ==================================================================

    // here I can simply add only DOWN because UP will be always only 1!!!!
    // winDirCount[UP] += (winDirCount[DOWN] - 1);

    +----------------------------------------0-0------------------------------------------+
    +----------------------------------------0-0------------------------------------------+


 */