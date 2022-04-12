/* 
    SIMPLE GAME BASED ON THE COURSE "Unreal Engine C++ Developer Learn C++ and Make Video Games" (Unity)
*/

#include <iostream>
#include <ctime>
using namespace std;

void PlayIntro(int LevelMax)
{
    // intro messages
    cout << "You are a hacker breaking into " << LevelMax << " servers.\n";
    cout << "The server codes have exactly 3 digits.\n";
    cout << "Figure out the correct code to beat the game...\n\n";

}

bool PlayGame(int Level)
{ 
    // declare variables
    const int CodeA = rand() % Level + Level;
    const int CodeB = rand() % Level + Level;
    const int CodeC = rand() % Level + Level;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC; 

    // explain the game logic
    cout << "You are now in level " << Level << "...";
    cout << "\n - The code digits add up to [ " << CodeSum << " ] and their product is [ " << CodeProduct << " ]";

    // declare variables for player guesses
    cout << "\n\n : : : E N T E R  C O D E : : : \n";
    int GuessA, GuessB, GuessC;
  
    // asks for guess numbers
    cin >> GuessA >> GuessB >> GuessC;

    // set sum and product
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // check guesses
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n\n* * * Congratulations, you beat this level " << Level << " * * *\n\n";
        return true;
    }else
    { 
        cout << "\n\n* * * Wrong code, try again and be careful! * * *\n\n";
        return false;
    }
}

int main()
{
    // seed random everytime
    srand(time(NULL)); 
    
    // set difficulty/levels variables
    int Level = 1;
    const int LevelMax = 5;

    // welcome message
    cout << " W E L C O M E   T O   T R I P L E   X   G A M E\n\n";

    // calls intro once
    PlayIntro(LevelMax);

    // until all levels are completed
    while (Level <= LevelMax)
    {
        bool CheckAnswer = PlayGame(Level);

        // error handling
        cin.clear();
        cin.ignore(); 

        // increase lvl difficulty
        if (CheckAnswer)
        {   
            ++Level;
        }     
    }

    cout << "\n\n* * * Congratulations, Agent! You beat the game! * * *\n\n";

    return 0;
}