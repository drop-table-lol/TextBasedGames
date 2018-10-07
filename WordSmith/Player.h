#ifndef PLAYER_H_
#define PLAYER_H_ //combat is a boring name for now...


/*TODO
	Make Virtual functions
	Better inheritance patterns
	polymorphism
*/
#include "Entity.h"

#include <string>
using std::string;


class Player : public Entity {

private:
  int health_;
  int base_power_;
  int type_of_entity_;
  string name_of_entity_;

public:
  Player(int type_of_entity);
  int GetHealth();
  void TakeDamage(int damage_to_take);
  void RestoreHealth(int health_to_restore);
  void SetEntityType(int entity_type);
  void GenerateName();
  string ReturnName();

};//end Player




#endif PLAYER_H_

