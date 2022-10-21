#include <iostream>
#include <time.h>
using namespace std;

// Generate Random Number using time.h  library in C++
int randomNumber = time(0) % 10 + 1;
int score = 0;

bool play_again()
{
    char answer;
    cout << endl;
    cout << "Do You wanna play again ? Yes/No..";
    cout << endl;
    cin >> answer;

    switch (answer)
    {
    case 'y':
    {
        cout << "Sounds Good 😊 Let's play Again!!!" << endl;
        return true;
    }
    case 'n':
    {
        cout << "Thanks for playing. Press any key to exit." << endl;
        cin.get();
        return false;
    }
    default:
    {
        cout << "Invalid input! Please try again." << endl;
        play_again();
    }
    }
}
bool guessNumber()
{
    int guess;
    cout << "-----------------------------------------";
    cout << endl;
    cout << "Guess the number between 1 and 10";
    cout << endl;
    cout << "-----------------------------------------";
    cout << endl;
    cout << "Enter your guess: ";
    cout << endl;
    cin >> guess;
    // --------------------------------------------------------
    if (guess > randomNumber || guess < randomNumber)
    {
        cout << "Sorry, you guessed wrong! 😔" << endl;
        cout << "Your score is: " << score << endl;
        guessNumber();
    }
    else if (guess == randomNumber)
    {
        cout << "Congratulations! You guessed right! 😃" << endl;
        score += 1;
        cout << "Your score is: " << score << endl;

        bool answer = play_again();
        return answer;
    }
    else
    {
        cout << "Invalid input! Please try again." << endl;
        bool answer = play_again();
        return answer;
    }
}

int main()
{
    cout << randomNumber << endl;
    cout << "_________________________________________";
    cout << endl;
    cout << "Welcome to the Number guessing game! 🎮";
    cout << endl;
    cout << "_________________________________________";
    cout << endl;
    guessNumber();

    bool user_input = guessNumber();
    if (user_input == true)
    {
        guessNumber();
    }
    else
    {
        // cout << "Thanks for playing. Press any key to exit." <<endl;
        cin.get();
    }

    return 0;
}