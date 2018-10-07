#include "Player.h"
#include "Entity.h"

#include <string>


/*TODO
	Make Virtual functions
	Better inheritance patterns
	run time polymorphism
*/

Player::Player(int type_of_entity) : Entity(type_of_entity){
  type_of_entity_ = type_of_entity;
  GenerateName();
  health_ = 10;
  base_power_ = 1;
}
int Player::GetHealth() {
  return health_;
  }
void TakeDamage(int damage_to_take);
void RestoreHealth(int health_to_restore);
void SetEntityType(int entity_type);
void Player::GenerateName() {
  switch(type_of_entity_) {
  case(0):
    name_of_entity_ = "The Unmistakable Hero";
    return;
  case(1):
    name_of_entity_ = "The Unfathomable Beast";
    return;
  case(2):
    name_of_entity_ = "The Undead Queen";
    return;
  case(3):
    name_of_entity_ = "The Unknown Challenger";
    return;
  }
}
string Player::ReturnName(){
  return name_of_entity_;
}

