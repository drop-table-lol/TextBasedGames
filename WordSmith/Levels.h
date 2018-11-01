//Levels.h

namespace LevelScale {
		
	class enum scale {
		Pathetic = 1;//default of 0 would kill pathetic enemies before combat check
		Weakling = 2;
		Normal = 3;
		Tough = 4;
		Insane = 5;
		Impossible = 6;
		H4X0R = 10; //why? Because I can...
	};
		
	ScaleToLevel(Entity E, int scale) {
		int lvl = E.GetLevel*scale;
		E.SetHealth(lvl); //HMM, this doesn't scale well for low level.
		int dmg = lvl/3;
		(dmg < 1) ? 1 : dmg;
		E.SetDexterity(dmg); //for high level we can scale dmg and whatnot
		E.SetStrength(dmg); //might need to affect for dex/str specialties
	}
	
	LevelUp(Entity E, int scale) {
		E.SetLevel(++E.GetLevel);
	}//TODO write dex and str funcs that account or test type of E for dex or strength
	//TODO maybe new card every 5?
}//end namespace LevelScale