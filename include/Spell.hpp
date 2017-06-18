#ifndef SPELL_HPP
# define SPELL_HPP

# include <functional>
# include <unordered_map>

class Logic;
class Player;

namespace SpellType
{
  constexpr unsigned int ARROW_SHOT{0u};
  constexpr unsigned int JUMP{1u};
  constexpr unsigned int ARROW_ULTI{2u};

  constexpr unsigned int FIRE_BALL{3u};
  constexpr unsigned int NOT_IMPL{4u};
  constexpr unsigned int FROST_WALL{5u};
  
};

struct Spell
{
  unsigned int type;
  unsigned int cooldown;
  unsigned int duration;
  unsigned int timeLeft;
  bool active;

  Spell() = delete;

  constexpr Spell(unsigned int type, unsigned int cooldown,
	unsigned int duration = 1, unsigned int timeLeft = 0)
  : type(type)
      , cooldown(cooldown)
      , duration(duration)
      , timeLeft(timeLeft)
      , active(false)
  {}

  void update(Logic &, Player &);
};

class SpellList
{
private:
  std::unordered_map<unsigned int, std::function<void(Logic &, Player &, unsigned int)>> map;

public:
  SpellList();

  std::function<void(Logic &, Player &, unsigned int)> const &operator[](unsigned int type) const;
};

#endif