//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Rock.h header file					Chris Dang
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <string>
using namespace std ;


#ifndef ROCK
#define ROCK

enum RockName {BASALT, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE,
				   OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW} ;



class Rock
{
	public:
	
		Rock(){myName = ROCK_OVERFLOW;} ;					// default constructor
		Rock(RockName GRANITE){myName = GRANITE ;} ;// explicit value constructor


		void display(ostream &out) const;
		Rock Rock::read(istream &in) ;
		string Rock::kind() ;
		string Rock::texture() ;
		RockName Rock::name() const ;
		Rock Rock::nextOne() ;
		Rock operator++() ;
		Rock operator++(int) ;

	private:

		// holds Rock variable
		RockName myName;
	
	
} ; // end class

ostream &operator<<(ostream &out, const Rock &RockVal) ;
istream &operator>>(istream &in, Rock &RockVal) ;
bool &operator<(const Rock &aRock1, const Rock &aRock2) ;
bool &operator==(const Rock &aRock1, const Rock &aRock2) ;

#endif


