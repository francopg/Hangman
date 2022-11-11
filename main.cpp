#include <iostream>
#include <vector>

using namespace std;

char GetUserChar(const string& prompt);
int GetUserInt(const string& prompt);

int main(){
    unsigned int randomIndex;
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

    while(userResponse == 1) {
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

        for (int i = 0; i < wordSize; ++i) {
            wordMatch[i] = '_';
        }

        cout << "Welcome to the Hangman game!" << endl << endl;
        cout << "This word has " << wordSize << " letters" << endl << endl;
        userLetterGuess = tolower(GetUserChar("Please guess a letter: "));
        numberOfGuesses = numberOfGuesses + 1;

        while (wordMatch != randomWord) {
            for (int i = 0; i < wordSize; ++i) {
                if (randomWord[i] == userLetterGuess) {
                    wordMatch[i] = userLetterGuess;
                    correctGuesses = correctGuesses + 1;
                    letterIsInWord = true;
                }
            }
            if (letterIsInWord == false) {
                incorrectGuesses = incorrectGuesses + 1;
                wrongLetters.push_back(userLetterGuess);
            } else {
                letterIsInWord = false;
            }
            cout << "Word Guess: " << endl << wordMatch << endl;
            cout << "Wrong Letters: " << endl;
            for (int i = 0; i < wrongLetters.size(); ++i) {
                cout << wrongLetters.at(i) << " ";
            }
            cout << endl;
            cout << "Total Guesses: " << numberOfGuesses << ", Correct Guesses: " << correctGuesses
                 << ", Incorrect Guesses: " << incorrectGuesses << endl << endl;
            if (wordMatch != randomWord) {
                userLetterGuess = tolower(GetUserChar("Please guess another letter: "));
                numberOfGuesses = numberOfGuesses + 1;
            } else {
                cout << "You have correctly guessed the word in " << numberOfGuesses << " guesses!" << endl;
            }
        }
        userResponse = GetUserInt("Would you like to play again? 1 = Yes, 2 = No : ");
        if (userResponse != 1){
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




