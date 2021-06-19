#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
#include<fstream>
using namespace std;

const int MAX_TRIES=5;
int letterFill (char, string, string&);

class Game
{
    public:
    char Question[100];
    char Answer[25];

};
int main ()
{
    system("color F0");
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;

	srand(time(NULL));
	int n=rand()% 10;

	Game G;
    ifstream fin("Game.dat",ios::in|ios::binary);
    fin.seekg(n*sizeof(G));
    fin.read((char*)&G,sizeof(G));
	word=G.Answer;

	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	// welcome the user
	cout << "\n\n\t\tWelcome to ProLan - Guess the Programming Language";
	cout << "\n--------------------------------------------------------------------------------";
	cout << "\n\n\t\t Rules:";
	cout << "\n\n\t\tEach letter is represented by a star.";
	cout << "\n\n\t\tYou have to type only one letter in one try";
	cout << "\n\n\t\tYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n--------------------------------------------------------------------------------";
	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout<<endl<<endl;
		cout<<G.Question;
		cout<<endl;
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Great work! Keep going!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
		    cout <<"------------------------------------------"<<endl;
            cout<<endl;
			cout << word << endl;
			cout << "That's the right answer!Great work!"<<endl;
			cout <<"------------------------------------------"<<endl;
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...Better luck next time." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	cout<<"\n\n\n\n\nCreated by C G Mitun Akil, copyrights licensed\n\n\n";
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

