#include <iostream>
#include <string>
#include "MysteryDuck.h"

using std::cout;
using std::endl;
using std::string;

MysteryDuck::MysteryDuck(string description, string quack) : Duck(){
  descriptionText = description;
  sound = quack;
}

string MysteryDuck::getDescription() {
  return descriptionText;
}

void MysteryDuck::performQuack() {
    cout << sound << endl;
}
