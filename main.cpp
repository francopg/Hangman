#include <iostream>
#include <vector>

using namespace std;

char GetUserChar(const string& prompt);
int GetUserInt(const string& prompt);

int main(){
    unsigned int randomIndex;
    //Here is where I'm creating my vector of the words to use.
    vector<string> words(10);
    words.at(0) = "apple";
    words.at(1) = "banana";
    words.at(2) = "pineapple";
    words.at(3) = "kiwi";
    words.at(4) = "watermelon";
    words.at(5) = "strawberry";
    words.at(6) = "orange";
    words.at(7) = "cantaloupe";
    words.at(8) = "grape";
    words.at(9) = "blueberry";

    int userResponse = 1;

    while(userResponse == 1) { //Using while loop to determine if I will play the game or not.
        char userLetterGuess = '?';
        int numberOfGuesses = 0;
        int correctGuesses = 0;
        int incorrectGuesses = 0;
        srand(time(NULL));
        randomIndex = rand() % 10;
        string randomWord = words.at(randomIndex);
        int wordSize = randomWord.size();
        string wordMatch(randomWord);
        vector<char> wrongLetters;
        bool letterIsInWord = false;

        for (int i = 0; i < wordSize; ++i) { //Using this loop to show the _ for the unguessed letters.
            wordMatch[i] = '_';
        }

        cout << "Welcome to the Hangman game!" << endl << endl;  //Here I'm welcoming you to the game.
        cout << "This word has " << wordSize << " letters" << endl << endl;
        userLetterGuess = tolower(GetUserChar("Please guess a letter: ")); //I wanted to make the game case-insensitive
        numberOfGuesses = numberOfGuesses + 1;

        while (wordMatch != randomWord) {  //Checking to see if the guessed word has any _ left in it.
            for (int i = 0; i < wordSize; ++i) {
                if (randomWord[i] == userLetterGuess) { //Checking if the guessed letter exists in the word.
                    wordMatch[i] = userLetterGuess;
                    correctGuesses = correctGuesses + 1;
                    letterIsInWord = true;
                }
            }
            if (letterIsInWord == false) { //Adding wrong letter to the wrong letter vector.
                incorrectGuesses = incorrectGuesses + 1;
                wrongLetters.push_back(userLetterGuess);
            } else {
                letterIsInWord = false; //Resetting boolean for next iteration.
            }
            cout << "Word Guess: " << endl << wordMatch << endl;
            cout << "Wrong Letters: " << endl;
            for (int i = 0; i < wrongLetters.size(); ++i) { //Outputting letters from wrong letter vector.
                cout << wrongLetters.at(i) << " ";
            }
            cout << endl;
            cout << "Total Guesses: " << numberOfGuesses << ", Correct Guesses: " << correctGuesses
                 << ", Incorrect Guesses: " << incorrectGuesses << endl << endl;
            if (wordMatch != randomWord) { //Using the If statement to see if I need to go through the while loop again.
                userLetterGuess = tolower(GetUserChar("Please guess another letter: "));
                numberOfGuesses = numberOfGuesses + 1;
            } else {
                cout << "You have correctly guessed the word in " << numberOfGuesses << " guesses!" << endl;
            }
        }
        userResponse = GetUserInt("Would you like to play again? 1 = Yes, 2 = No : ");
        if (userResponse != 1){ //If user enters a number other than 1, the while loop will not re-iterate and game will end.
            cout << "Thanks for playing!" << endl;
        }
    }
    return 0;
}

char GetUserChar(const string& prompt) {
    char userChar = '?';
    cout << prompt;
    cin >> userChar;
    cout << endl;
    return userChar;
}

int GetUserInt(const string& prompt) {
    int userInt = 0;
    cout << prompt;
    cin >> userInt;
    cout << endl;
    return userInt;
}




