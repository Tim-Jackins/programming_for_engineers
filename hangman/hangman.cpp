#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <bits/stdc++.h>

using namespace std;

bool cleanWord(string &word)
{
  int i = 0;
  char c;
  for (int i = 0; i < word.length(); i++)
  {
    c = word[i];
    
    if (isalpha(c))
      word[i] = tolower(c);
    else
      return false;
  }
  return true;
}

char cleanGuess(string guessedLetters)
{
  char cleanGuess;
  string guessIn;
  do
  {
    cout << "What's you're guess: ";
    getline(cin, guessIn);

    if (guessIn.length() == 1 and isalpha(guessIn[0]))
    {
      if (guessedLetters.find(tolower(guessIn[0])) != -1)
      {
        cout << endl
             << "Please guess a new letter" << endl;
        cleanGuess = '\0';
      }
      else
        cleanGuess = tolower(guessIn[0]);
    }
    else
    {
      cout << endl
           << "Please enter a valid guess" << endl;
      cleanGuess = '\0';
    }
  } while (cleanGuess == '\0');
  return cleanGuess;
}

void alphaAdd(char guess, string &guessedLetters)
{
  if (guessedLetters.length() > 0)
  {
    bool forElse = true;
    for (int index = 0; index < guessedLetters.length(); index++)
    {
      if (guess < guessedLetters[index])
      {
        guessedLetters.insert(index, 1, guess);
        forElse = false;
        break;
      }
    }
    if (forElse)
      guessedLetters += guess;
  }
  else
    guessedLetters += guess;
}

void printDisplay(int strikes, string secretWord, string guessedLetters, bool &win)
{
  vector<string> body;
  body.push_back(" | ");
  body.push_back(" o ");
  body.push_back("/  ");
  body.push_back("/| ");
  body.push_back("/|\\");
  body.push_back(" | ");
  body.push_back("/  ");
  body.push_back("/ \\");

  string displayLetters;
  if (guessedLetters.size() == 0)
    displayLetters = "No guesses yet!";
  else
    displayLetters = guessedLetters;

  string blanks;
  win = true;
  string letter;
  for (int i = 0; i < secretWord.size(); i++)
  {
    letter = secretWord[i];

    if (guessedLetters.find(letter) == -1){
      win = false;
      blanks += "_";
    }
    else
      blanks += letter;
  }

  int blankDiff = 13 - blanks.size();
  if (blanks.size() < 13)
    for (int i = 0; i < blankDiff; i++)
    {
      blanks += " ";
    }
  string empty = "   ";
  system("clear");
  cout << "   ____" << endl;
  cout << "  |   " << ((strikes > 0) ? body[0] : empty) << "     Guessed : " << displayLetters << endl;
  cout << "  |   " << ((strikes > 1) ? body[1] : empty) << "     Average : 50%" << endl;
  cout << "  |   " << ((strikes > 2) ? body[(strikes < 5) ? strikes-1: 4] : empty) << "     Strikes : " << strikes << endl;
  cout << "  |   " << ((strikes > 5) ? body[5] : empty) << endl;
  cout << "  |   " << ((strikes > 6) ? body[(strikes < 8) ? strikes - 1: 7] : empty) << endl;
  cout << " _|_" << endl;
  cout << "|   |___________" << endl;
  cout << "|               |" << endl;
  cout << "| " << blanks << " |" << endl;
  cout << "|_______________|"
       << "\n\n";
}

int main(void)
{
  string secretWord;
  // Get the word:
  while (true)
  {
    cout << "[Player one] Enter a secret word: ";
    //getline(cin, secret_word);
    secretWord = "Hello";
    if (cleanWord(secretWord))
    {
      cout << "The secret word is " << secretWord << "\n";
      break;
    }
    else
    {
      cout << "No dice, please enter a valid word\n";
    }
  }

  // Init the game
  int strikes = 0;
  int maxStrikes = 8;
  string guessedLetters;
  char guess = '\0';
  bool win = false;
  
  do
  {
    printDisplay(strikes, secretWord, guessedLetters, win);
    if (win) break;

    guess = cleanGuess(guessedLetters);
    if (secretWord.find(guess) == -1)
      strikes++;

    alphaAdd(guess, guessedLetters);
  } while (strikes < maxStrikes);
  printDisplay(strikes, secretWord, guessedLetters, win);
  cout << (win ? "Yay, you win!" : "You lose you loser!") << endl;

  return 0;
}
