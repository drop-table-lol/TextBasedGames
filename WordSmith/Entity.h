
#ifndef ENTITY_H_
#define ENTITY_H_ //combat is a boring name for now...
/*TODO
	Make Virtual functions
	Better inheritance patterns
*/


#include <string>
using std::string;

class Entity {
private:
  int health_;
  int base_power_;
  int type_of_entity_;
  int strength_;
  int dexterity_;
  string name_of_entity_;


public:
  Entity(int type_of_entity);
  int GetHealth();
  void TakeDamage(int damage_to_take);
  void RestoreHealth(int health_to_restore);
  void SetEntityType(int entity_type);
  void GenerateName();
  string ReturnName();

};//end entity




#endif ENTITY_H_
