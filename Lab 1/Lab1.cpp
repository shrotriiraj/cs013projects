#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> jersey (5);
vector <int> rating (5);
char input = 'b';

void showMenu() {
   cout << "MENU" << endl;
   cout << "a - Add player" << endl;
   cout << "d - Remove player" << endl;
   cout << "u - Update player rating" << endl;
   cout << "r - Output players above a rating" << endl;
   cout << "o - Output roster" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
   cout << "Choose an option:" << endl;
}

void outputRoster() {
   cout << "ROSTER" << endl;
   for (unsigned int j = 0; j < rating.size(); ++j){
      cout << "Player " << j + 1 << " -- Jersey number: " << jersey.at(j) << ", Rating: " << rating.at(j) << endl;
   }
   cout << endl;
}

void addPlayer(){
   int c;
   cout << "Enter a new player's jersey number:" << endl;
   cin >> c;
   jersey.push_back(c);
   cout << "Enter the player's rating:" << endl;
   cin >> c;
   rating.push_back(c);
}

void deletePlayer(){
   int c;
   cout << "Enter a jersey number:" << endl;   
   cin >> c;
   for (unsigned int k = 0; k < jersey.size(); ++k){
      if (c == jersey.at(k)){
         c = k;
      }
   }
   jersey.erase(jersey.begin()+c);
   rating.erase(rating.begin()+c);
}

void updateRating(){
   int c;
   int d;
   cout << "Enter a jersey number:" << endl;
   cin >> c;
   for (unsigned int k = 0; k < jersey.size(); ++k){
      if (c == jersey.at(k)){
         c = k;
      }
   }
   cout << "Enter a new rating for player:" << endl;
   cin >> d;
   rating.at(c) = d;
}

void outputAboveRating(){
   int c;
   cout << "Enter a rating:" << endl;
   cin >> c;
   cout << "ABOVE" << c << endl;
   for (unsigned int k = 0; k < rating.size(); ++k){
      if (c >= rating.at(k)){
         cout << "Player " << k + 1 << " -- Jersey number: " << jersey.at(k) << ", Rating: " << rating.at(k) << endl; 
      }
   }
}

int main() {

   for (unsigned int i = 1; i < ( rating.size() + 1 ); ++i) {
      cout << "Enter player " << i << "'s jersey number:" << endl;
      cin >> jersey.at(i - 1);
      cout << "Enter player " << i << "'s rating:" << endl;
      cin >> rating.at(i - 1);
      cout << endl;
   }
   outputRoster();
   
   while( input != 'q' ){
      showMenu();
      cin >> input;
      if (input == 'o')
         outputRoster();
      if (input == 'a')
         addPlayer();
      if (input == 'd')
         deletePlayer();
      if (input == 'u')
         updateRating();
      if (input == 'r')
         outputAboveRating();
   }
   
   return 0;
}