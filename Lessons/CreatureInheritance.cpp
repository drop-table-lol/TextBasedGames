class Creature {
	protected:
		string name_;
		char symbol_;
		int health_;
		int damage_;
		int gold_;
	public:
		Creature(string name, char symbol, int health, int damage, int gold) : 
		name_(name), symbol_(symbol), health_(health), damage_(damage), gold_(gold) {
		}
		void GetName(){Return name_;}
		void GetSymbol(){Return symbol_;}
		void GetHealth(){Return health_;}
		void GetDamage(){Return damage_;}
		void GetGold(){Return gold_;}
		void ReduceHealth(int dmg) {health -= dmg;}
		bool IsDead() {return (health_ > 0);}
		void AddGold(int gold) {gold_ += gold;}
};

class Player : public Creature {	
	protected:
		int level_ = 1;	
	public:
		Player(string name)	
		Creature(name, '@', 10, 1, 0) {
		}
		void LevelUp() {
			++level_;
			++damage_;
		}
		void GetLevel() {return level_;}
		bool hasWon() { return level_>19);}
};