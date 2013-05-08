/*
 * spellingwordgame.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: amaier
 *
 *      This game is intended for use with a child's spelling
 *      word list. It takes a spelling word list and, after
 *      sorting by alphabetical order, picks a random word
 *      which the player tries to guess. The player is given
 *      an indication of whether the word they guessed is
 *      higher or lower in the alphabetical order than the
 *      target word. Then the player gets to guess again.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  //This section declares variables
	const int LENGTH = 10; //length of word list
	string wordList [LENGTH]; //This will contain the list of words as typed in by the user, later.

	int n; //for keeping place in for loop
	int i; //for keeping place in lower-casing loop
	string temp; //for storing words in lower-casing loop


	string targetWord; //is the randomly picked target word (picked once per round).
	string guessWord; //is the player's current guess

	char playerContinue = 'y'; //variable determining whether player wants to play again.

	srand(static_cast<unsigned int>(time(0))); //seed random number generator

	//this for loop fills in the wordList array with the spelling words.
	cout << "Please type in your spelling words, pressing Enter after each one:\n";
	for (n = 0; n < LENGTH; n++) {
		cin >> temp;
		for (i = 0; i < temp.length(); i++) {
			temp[i] = tolower(temp[i]);
		}
		wordList[n] = temp;
	}
	sort(wordList, wordList+LENGTH);

	//This while loop repeats until the player wants to quit the whole game
	while (playerContinue == 'y') {
		bool victory = false; //sets victory status for a round

		cout << "Your spelling list is the following words:\n";
		//this prints the players spelling words in order
		for (n = 0; n < LENGTH; n++) {
			cout << n + 1 << "): " << wordList[n] << endl;
		}

		targetWord = wordList[rand() % 10]; //this chooses the target word for this round.
		cout << "Try and guess what word I'm thinking of!\n";

		//this while loop repeats until the player wins a round
		while (victory == false) {
			bool correctSpelling = false; //used to mark whether the guess is on wordList
			cout << "Type the spelling word that you guess I'm thinking on the next line." << endl;

			//this while loop repeats until the player makes a legal guess
			while (correctSpelling == false) {
				cin >> guessWord;
				//this lower cases guessWord so it conforms with the list
				for (i = 0; i < guessWord.length(); i++) {
					guessWord[i] = tolower(guessWord[i]);
				}

				//checks to make sure guessWord is in wordList
				for (i = 0; i < LENGTH; i++) {
					//sets correctSpelling to true and breaks this for loop if the guessWord is found in wordList
					if (wordList[i].compare(guessWord) == 0) {
						correctSpelling = true;
						break;
					}
				}
				if (correctSpelling == false) {
					cout << "Oops! It looks like you might have misspelled your guess (or you choose a word not on the list). Give it another shot:" << endl;
				}
			}

			if (targetWord.compare(guessWord) == 0) {
				victory = true;
				cout << "Good job! You guessed " << targetWord << " and that was the word I was thinking of!" << endl;
			}

			else {
				cout << "Not quite!";
				if (targetWord.compare(guessWord) > 0) {
					cout << "I'll give you a hint: you're looking for a word further down on the list." << endl;
				}
				if (targetWord.compare(guessWord) < 0) {
					cout << "I'll give you a hint: you're looking for a word higher up on the list." << endl;
				}
			}
		}
		cout << "Would you like to play again? (type y to play again and n to quit):";
		cin >> playerContinue;
		//while ((playerContinue != 'n') || (playerContinue != 'y')) {
		//	cout << "Please type in either a y or an n:";
		//	cin >> playerContinue;
		//}
	}
	return 0;
}




