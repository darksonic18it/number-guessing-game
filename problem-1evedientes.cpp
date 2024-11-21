#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime> // for time
using namespace std;

int main(){
  
  srand(time(0));

  int max, min;
  cout << "Enter the minimum range: ";
  cin >> min;
  cout << "Enter the maximum range: ";
  cin >> max;

  int secret = rand() % (max - min + 1) + min;
  cout << "You have selected a range between " << min << " and " << max << endl;
  cout << "Now! can you guess it?" << endl;
  cout << endl;

  int guess;
  int attempts = 0;
  bool hint = false;
  do{
    cout << "Enter your guess: ";
    cin >> guess;

    if(guess < min || guess > max){
      cout << "Choose a number between the choosen range!" << endl;
      continue;
    }

    attempts++;

    if(guess > secret){
      cout << endl;
      cout << "Too High! Try Again!" << endl;
    }else if(guess < secret){
      cout << endl;
      cout << "Too Low! Try Again!" << endl;
    }

    if(attempts == 3 && guess != secret && !hint){
      hint = true;
      if(secret % 2 == 0){
        cout << "Hint: the number is even" << endl;
      }else{
        cout << "Hint: the number is odd" << endl;
      }
    }
  }while(guess != secret);
    cout << endl;
    cout << "Congratulations you guessed it!" << endl;
    cout << "The secret number is " << secret << endl;
    cout << "You guessed it in " << attempts << " attempts " << endl;
  return 0;
}





