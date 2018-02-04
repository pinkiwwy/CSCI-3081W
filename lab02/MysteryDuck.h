#ifndef LAB02_MYSTERYDUCK_H_
#define LAB02_MYSTERYDUCK_H_

#include <string>
#include "Duck.h"

class MysteryDuck : public Duck {
 public:
  std::string descriptionText;
  std::string sound;
  MysteryDuck(std::string description, std::string quack);
  std::string getDescription();
  void performQuack();
};

#endif
