// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#include "simcraft.h"

// util_t::talent_rank =====================================================

double util_t::talent_rank( int    num, 
                            int    max, 
                            double increment )
{
  assert( num >= 0 );
  assert( max > 0 );

  if( num > max ) num = max;

  return num * increment;
}

// util_t::talent_rank =====================================================

int util_t::talent_rank( int num, 
                         int max, 
                         int increment )
{
  assert( num >= 0 );
  assert( max > 0 );

  if( num > max ) num = max;

  return num * increment;
}

// util_t::talent_rank =====================================================

double util_t::talent_rank( int    num, 
                            int    max, 
                            double first, 
                            double second, ... )
{
  assert( num >= 0 );
  assert( max > 0 );

  if( num > max ) num = max;

  if( num == 1 ) return first;
  if( num == 2 ) return second;

  va_list vap;
  va_start( vap, second );

  double value=0;

  for( int i=3; i <= num; i++ )
  {
    value = (double) va_arg( vap, double );
  }
  va_end( vap );

  return value;
}

// util_t::talent_rank =====================================================

int util_t::talent_rank( int num, 
                         int max, 
                         int first, 
                         int second, ... )
{
  assert( num >= 0 );
  assert( max > 0 );

  if( num > max ) num = max;

  if( num == 1 ) return first;
  if( num == 2 ) return second;

  va_list vap;
  va_start( vap, second );

  int value=0;

  for( int i=3; i <= num; i++ )
  {
    value = (int) va_arg( vap, int );
  }
  va_end( vap );

  return value;
}

// util_t::ability_rank ====================================================

double util_t::ability_rank( int    player_level, 
                             double ability_value, 
                             int    ability_level, ... )
{
  va_list vap;
  va_start( vap, ability_level );

  while( player_level < ability_level )
  {
    ability_value = (double) va_arg( vap, double );
    ability_level = (int) va_arg( vap, int );
  }
  
  va_end( vap );

  return ability_value;
}

// util_t::ability_rank ====================================================

int util_t::ability_rank( int player_level, 
                          int ability_value, 
                          int ability_level, ... )
{
  va_list vap;
  va_start( vap, ability_level );

  while( player_level < ability_level )
  {
    ability_value = (int)    va_arg( vap, int );
    ability_level = (int) va_arg( vap, int );
  }
  
  va_end( vap );

  return ability_value;
}

// util_t::dup =============================================================

char* util_t::dup( const char *value )
{
   return strcpy( (char*) malloc( strlen( value ) + 1 ), value );
}

// util_t::race_type_string ================================================

const char* util_t::race_type_string( int type )
{
  switch( type )
  {
  case RACE_NONE:      return "none";
  case RACE_BEAST:     return "beast";
  case RACE_BLOOD_ELF: return "blood_elf";
  case RACE_DRAENEI:   return "draenei";
  case RACE_DRAGONKIN: return "dragonkin";
  case RACE_DWARF:     return "dwarf";
  case RACE_GIANT:     return "giant";
  case RACE_GNOME:     return "gnome";
  case RACE_HUMAN:     return "human";
  case RACE_HUMANOID:  return "humanoid";
  case RACE_NIGHT_ELF: return "night_elf";
  case RACE_ORC:       return "orc";
  case RACE_TAUREN:    return "tauren";
  case RACE_TROLL:     return "troll";
  case RACE_UNDEAD:    return "undead";
  }
  return "unknown";
}

// util_t::profession_type_string ==========================================

const char* util_t::profession_type_string( int type )
{
  switch( type )
  {
  case PROF_NONE:           return "none";
  case PROF_ALCHEMY:        return "alchemy";
  case PROF_BLACKSMITHING:  return "blacksmithing";
  case PROF_ENCHANTING:     return "enchanting";
  case PROF_ENGINEERING:    return "engineering";
  case PROF_HERBALISM:      return "herbalism";
  case PROF_INSCRIPTION:    return "inscription";
  case PROF_JEWELCRAFTING:  return "jewelcrafting";
  case PROF_LEATHERWORKING: return "leatherworking";
  case PROF_MINING:         return "mining";
  case PROF_SKINNING:       return "skinning";
  case PROF_TAILORING:      return "tailoring";  
  }
  return "unknown";
}

// util_t::player_type_string ==============================================

const char* util_t::player_type_string( int type )
{
  switch( type )
  {
  case PLAYER_NONE:     return "none";
  case DEATH_KNIGHT:    return "death_knight";
  case DRUID:           return "druid";
  case HUNTER:          return "hunter";
  case MAGE:            return "mage";
  case PALADIN:         return "paladin";
  case PRIEST:          return "priest";
  case ROGUE:           return "rogue";
  case SHAMAN:          return "shaman";
  case WARLOCK:         return "warlock";
  case WARRIOR:         return "warrior";
  case PLAYER_PET:      return "pet";
  case PLAYER_GUARDIAN: return "guardian";
  }
  return "unknown";
}

// util_t::attribute_type_string ===========================================

const char* util_t::attribute_type_string( int type )
{
  switch( type )
  {
  case ATTR_STRENGTH:  return "strength";
  case ATTR_AGILITY:   return "agility";
  case ATTR_STAMINA:   return "stamina";
  case ATTR_INTELLECT: return "intellect";
  case ATTR_SPIRIT:    return "spirit";
  }
  return "unknown";
}

// util_t::dmg_type_string =================================================

const char* util_t::dmg_type_string( int type )
{
  switch( type )
  {
  case DMG_DIRECT:    return "hit";
  case DMG_OVER_TIME: return "tick";
  }
  return "unknown";
}

// util_t::result_type_string ==============================================

const char* util_t::result_type_string( int type )
{
  switch( type )
  {
  case RESULT_NONE:   return "none";
  case RESULT_MISS:   return "miss";
  case RESULT_RESIST: return "resist";
  case RESULT_DODGE:  return "dodge";
  case RESULT_PARRY:  return "parry";
  case RESULT_BLOCK:  return "block";
  case RESULT_GLANCE: return "glance";
  case RESULT_CRIT:   return "crit";
  case RESULT_HIT:    return "hit";
  }
  return "unknown";
}

// util_t::resource_type_string ============================================

const char* util_t::resource_type_string( int type )
{
  switch( type )
  {
  case RESOURCE_NONE:   return "none";
  case RESOURCE_HEALTH: return "health";
  case RESOURCE_MANA:   return "mana";
  case RESOURCE_RAGE:   return "rage";
  case RESOURCE_ENERGY: return "energy";
  case RESOURCE_FOCUS:  return "focus";
  case RESOURCE_RUNIC:  return "runic_power";
  }
  return "unknown";
}

// util_t::school_type_string ==============================================

const char* util_t::school_type_string( int school )
{
  switch( school )
  {
  case SCHOOL_ARCANE:    return "arcane";
  case SCHOOL_BLEED:     return "bleed";
  case SCHOOL_CHAOS:     return "chaos";
  case SCHOOL_FIRE:      return "fire";
  case SCHOOL_FROST:     return "frost";
  case SCHOOL_FROSTFIRE: return "frostfire";
  case SCHOOL_HOLY:      return "holy";
  case SCHOOL_NATURE:    return "nature";
  case SCHOOL_PHYSICAL:  return "physical";
  case SCHOOL_SHADOW:    return "shadow";
  }
  return "unknown";
}

// util_t::talent_tree_string ==============================================

const char* util_t::talent_tree_string( int tree )
{
  switch( tree )
  {
  case TREE_BALANCE:     return "balance";
  case TREE_FERAL:       return "feral";
  case TREE_RESTORATION: return "restoration";
  case TREE_ARCANE:      return "arcane";
  case TREE_FIRE:        return "fire";
  case TREE_FROST:       return "frost";
  case TREE_DISCIPLINE:  return "discipline";
  case TREE_HOLY:        return "holy";
  case TREE_SHADOW:      return "shadow";
  case TREE_ELEMENTAL:   return "elemental";
  case TREE_ENHANCEMENT: return "enhancement";
  case TREE_AFFLICTION:  return "affliction";
  case TREE_DEMONOLOGY:  return "demonology";
  case TREE_DESTRUCTION: return "destruction";
  case TREE_ARMS:        return "arms";
  case TREE_FURY:        return "fury";
  case TREE_PROTECTION:  return "protection";
  }
  return "unknown";
}

// util_t::weapon_type_string ==============================================

const char* util_t::weapon_type_string( int weapon )
{
  switch( weapon )
  {
  case WEAPON_NONE:     return "none";
  case WEAPON_DAGGER:   return "dagger";
  case WEAPON_FIST:     return "fist";
  case WEAPON_BEAST:    return "beast";
  case WEAPON_SWORD:    return "sword";
  case WEAPON_MACE:     return "mace";
  case WEAPON_AXE:      return "axe";
  case WEAPON_BEAST_2H: return "beast_2h";
  case WEAPON_SWORD_2H: return "sword_2h";
  case WEAPON_MACE_2H:  return "mace_2h";
  case WEAPON_AXE_2H:   return "axe_2h";
  case WEAPON_STAFF:    return "staff";
  case WEAPON_POLEARM:  return "polearm";
  case WEAPON_BOW:      return "bow";
  case WEAPON_CROSSBOW: return "crossbow";
  case WEAPON_GUN:      return "gun";
  case WEAPON_THROWN:   return "thrown";
  }
  return "unknown";
}

// util_t::weapon_enchant_type_string ======================================

const char* util_t::weapon_enchant_type_string( int enchant )
{
  switch( enchant )
  {
  case WEAPON_ENCHANT_NONE: return "none";
  case BERSERKING:          return "berserking";
  case DEATH_FROST:         return "deathfrost";
  case EXECUTIONER:         return "executioner";
  case MONGOOSE:            return "mongoose";
  case SCOPE:               return "scope";
  }
  return "unknown";
}

// util_t::weapon_buff_type_string =========================================

const char* util_t::weapon_buff_type_string( int buff )
{
  switch( buff )
  {
  case WEAPON_BUFF_NONE:  return "none";
  case ANESTHETIC_POISON: return "anesthetic_poison";
  case DEADLY_POISON:     return "deadly_poison";
  case FIRE_STONE:        return "fire_stone";
  case FLAMETONGUE:       return "flametongue";
  case INSTANT_POISON:    return "instant_poison";
  case SHARPENING_STONE:  return "sharpening_stone";
  case SPELL_STONE:       return "spell_stone";
  case WINDFURY:          return "windfury";
  case WIZARD_OIL:        return "wizard_oil";
  case WOUND_POISON:      return "wound_poison";
  }
  return "unknown";
}

// util_t::flask_type_string ===============================================

const char* util_t::flask_type_string( int flask )
{
  switch( flask )
  {
  case FLASK_NONE:               return "none";
  case FLASK_BLINDING_LIGHT:     return "blinding_light";
  case FLASK_DISTILLED_WISDOM:   return "distilled_wisdom";
  case FLASK_ENDLESS_RAGE:       return "endless_rage";
  case FLASK_FROST_WYRM:         return "frost_wyrm";
  case FLASK_MIGHTY_RESTORATION: return "mighty_restoration";
  case FLASK_PURE_DEATH:         return "pure_death";
  case FLASK_RELENTLESS_ASSAULT: return "relentless_assault";
  case FLASK_SUPREME_POWER:      return "supreme_power";
  }
  return "unknown";
}

// util_t::food_type_string ================================================

const char* util_t::food_type_string( int food )
{
  switch( food )
  {
  case FOOD_NONE:                    return "none";
  case FOOD_SMOKED_SALMON:           return "smoked_salmon";
  case FOOD_TENDER_SHOVELTUSK_STEAK: return "tender_shoveltusk_steak";
  case FOOD_SNAPPER_EXTREME:         return "snapper_extreme";
  case FOOD_POACHED_BLUEFISH:        return "poached_bluefish";
  case FOOD_BLACKENED_BASILISK:      return "blackened_basilisk";
  case FOOD_GOLDEN_FISHSTICKS:       return "golden_fishsticks";
  case FOOD_CRUNCHY_SERPENT:         return "crunchy_serpent";
  case FOOD_BLACKENED_DRAGONFIN:     return "blackened_dragonfin";
  case FOOD_DRAGONFIN_FILET:         return "dragonfin_filet";
  case FOOD_GREAT_FEAST:             return "great_feast";
  case FOOD_FISH_FEAST:              return "fish_feast";
  }
  return "unknown";
}

// util_t::stat_type_string =================================================

const char* util_t::stat_type_string( int stat )
{
  switch( stat )
  {
  case STAT_STRENGTH:  return "strength";
  case STAT_AGILITY:   return "agility";
  case STAT_STAMINA:   return "stamina";
  case STAT_INTELLECT: return "intellect";
  case STAT_SPIRIT:    return "spirit";

  case STAT_HEALTH: return "health";
  case STAT_MANA:   return "mana";
  case STAT_RAGE:   return "rage";
  case STAT_ENERGY: return "energy";
  case STAT_FOCUS:  return "focus";
  case STAT_RUNIC:  return "runic";

  case STAT_SPELL_POWER:       return "spell_power";
  case STAT_SPELL_PENETRATION: return "spell_penetration";
  case STAT_MP5:               return "mp5";

  case STAT_ATTACK_POWER:             return "attack_power";
  case STAT_EXPERTISE_RATING:         return "expertise_rating";
  case STAT_ARMOR_PENETRATION_RATING: return "armor_penetration_rating";

  case STAT_HIT_RATING:   return "hit_rating";
  case STAT_CRIT_RATING:  return "crit_rating";
  case STAT_HASTE_RATING: return "haste_rating";

  case STAT_WEAPON_DPS:   return "weapon_dps";
  case STAT_WEAPON_SPEED: return "weapon_speed";

  case STAT_ARMOR: return "armor";

  default: assert(0);
  }
  return 0;
}

// util_t::stat_type_abbrev =================================================

const char* util_t::stat_type_abbrev( int stat )
{
  switch( stat )
  {
  case STAT_STRENGTH:  return "Str";
  case STAT_AGILITY:   return "Agi";
  case STAT_STAMINA:   return "Sta";
  case STAT_INTELLECT: return "Int";
  case STAT_SPIRIT:    return "Spi";

  case STAT_HEALTH: return "Health";
  case STAT_MANA:   return "Mana";
  case STAT_RAGE:   return "Rage";
  case STAT_ENERGY: return "Energy";
  case STAT_FOCUS:  return "Focus";
  case STAT_RUNIC:  return "Runic";

  case STAT_SPELL_POWER:       return "SP";
  case STAT_SPELL_PENETRATION: return "SPen";
  case STAT_MP5:               return "MP5";

  case STAT_ATTACK_POWER:             return "AP";
  case STAT_EXPERTISE_RATING:         return "Exp";
  case STAT_ARMOR_PENETRATION_RATING: return "ArPen";

  case STAT_HIT_RATING:   return "Hit";
  case STAT_CRIT_RATING:  return "Crit";
  case STAT_HASTE_RATING: return "Haste";

  case STAT_WEAPON_DPS:   return "Wdps";
  case STAT_WEAPON_SPEED: return "Wspeed";

  case STAT_ARMOR: return "Armor";

  default: assert(0);
  }
  return 0;
}

// util_t::string_split ====================================================

int util_t::string_split( std::vector<std::string>& results, 
                          const std::string&        str,
                          const char*               delim )
{
  std::string buffer = str;
  std::string::size_type cut_pt;
  
  while( ( cut_pt = buffer.find_first_of( delim ) ) != buffer.npos )
  {
    if( cut_pt > 0 )
    {
      results.push_back( buffer.substr( 0, cut_pt ) );
    }
    buffer = buffer.substr( cut_pt + 1 );
  }
  if( buffer.length() > 0 )
  {
    results.push_back( buffer );
  }

  return static_cast<int>( results.size() );
}

// util_t::string_split ====================================================

int util_t::string_split( const std::string& str,
                          const char*        delim, 
                          const char*        format, ... )
{
  std::vector<std::string>    str_splits;
  std::vector<std::string> format_splits;

  int    str_size = util_t::string_split(    str_splits, str,    delim );
  int format_size = util_t::string_split( format_splits, format, " "   );

  if( str_size == format_size )
  {
    va_list vap;
    va_start( vap, format );

    for( int i=0; i < str_size; i++ )
    {
      std::string& f = format_splits[ i ];
      const char*  s =    str_splits[ i ].c_str();

      if     ( f == "i" ) *( (int*)         va_arg( vap, int*    ) ) = atoi( s );
      else if( f == "f" ) *( (double*)      va_arg( vap, double* ) ) = atof( s );
      else if( f == "d" ) *( (double*)      va_arg( vap, double* ) ) = atof( s );
      else if( f == "s" ) strcpy( (char*)   va_arg( vap, char* ), s );
      else if( f == "S" ) *( (std::string*) va_arg( vap, std::string* ) ) = s;
      else assert( 0 );
    }
    va_end( vap );
  }

  return str_size;
}


int util_t::milliseconds(){

#if defined( _MSC_VER )
	return clock()/(CLOCKS_PER_SEC/1000);
#else
	return clock()/(CLOCKS_PER_SEC/1000); //if this is not available to other compilers, use below
	//return time( NULL )*1000;
#endif
}

// Normalized_roll  implementation


roll_t::roll_t(int sfmt, int normalized_roll, double phase){
	rng=0;
	normalized=0;
	phase_shift=0;
	init(sfmt, normalized_roll,phase);
}

roll_t::~roll_t(){
	reset();
}

void roll_t::init(int sfmt, int normalized_roll, double phase){
	if (!rng) rng = rng_t::init( sfmt );
	normalized=normalized_roll;
	if (phase<0) phase=abs(phase);
	if (phase>=1) phase=0;
	phase_shift= 0.5+phase;
	if (phase_shift>=1) phase_shift-=1;
}

void roll_t::reset(){
	rollMap.clear();
}

double roll_t::real(){
	if (!rng) init(0,normalized,0);
	return rng -> real(); 
}


int roll_t::rnd(double chance){
	if (!rng) init(0,normalized,0);
	if (chance<=0) return 0;
	if (chance>=1) return 1;
	return rng -> roll( chance ); 
}

int roll_t::roll(double chance){
	return rnd( chance ); 
}


int roll_t::roll(double chance, std::string rollName){
	if (!normalized) return rnd(chance);
	//check if new value
	std::map<std::string, roll_instance_t>::iterator it= rollMap.find(rollName);
	roll_instance_t* ri=0;
	//is this new one?
	if(it== rollMap.end())
	{	
		roll_instance_t rn;
		rollMap[rollName]=rn;
		ri=&rollMap[rollName];
	} else
		ri=&it->second;
	//check
	if (chance<=0) chance=0;
	if (chance>=1) chance=1;
	// advance
	ri->nTries++;
	ri->wanted+=chance;
	// decide if I should "give"
	if (ri->given+phase_shift < ri->wanted){
		ri->given++;
		return 1;
	}else
		return 0;
}



int roll_t::roll(double chance, player_t* plr, const char* rollName){
	if (!normalized) return rnd(chance);
	std::string s="";
	if (plr){
		s= plr->name_str;
	}
	s+=":";
	s+=rollName; 
	return roll(chance, s);
}
int roll_t::roll(double chance, player_t* plr, std::string& rollName){
	if (!normalized) return rnd(chance);
	return roll(chance, plr, rollName.c_str());
}

int roll_t::roll(double chance, action_t* act, const char* rollName){
	if (!normalized) return rnd(chance);
	std::string s="";
	player_t* plr= 0;
	if (act){
		plr= act->player;
		s= act->name_str;
	}
	s+=":";
	s+=rollName;
	return roll(chance, plr, s);
}
int roll_t::roll(double chance, action_t* act, std::string& rollName){
	if (!normalized) return rnd(chance);
	return roll(chance, act, rollName.c_str());
}

double roll_t::range( double min, double max ){
	if (normalized) return (min+max)/2.0;
	if (!rng) rng = rng_t::init(0);
	return rng->range(min,max);
}

double roll_t::gaussian( double mean, double stddev ){
	if (normalized) return mean;
	if (!rng) rng = rng_t::init(0);
	return rng->gaussian(mean, stddev);
}
