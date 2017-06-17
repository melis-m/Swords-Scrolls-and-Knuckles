#include "Player.hpp"
#include "Logic.hpp"
#include "SaveGame.hpp"
#include "LoadGame.hpp"

void Player::checkSpells(Logic &logic)
{
  for (auto &spell : spells)
    spell.update(logic, *this);
}

void Player::setAttacking(unsigned int index, bool attacking)
{
  spells[index].active = attacking;
}

Player Player::makeArcher(Vect<2u, double> pos)
{
  return Player(Vect<3u, Spell>
		(Spell{SpellType::ARROW_SHOT, 60, 10},
		 Spell{SpellType::JUMP, 240, 30},
		 Spell{SpellType::ARROW_ULTI, 2400, 480}),
		100u, 0.5, pos);
}

int Player::getSpellTimeleft(size_t i) const {
  return (spells[i].timeLeft / 12);
}

Player Player::makeMage(Vect<2u, double> pos)
{
  return Player(Vect<3u, Spell>
		(
		 Spell{SpellType::FIRE_BALL, 90, 10},
		 Spell{0u, 240, 30}, // TODO
		 Spell{SpellType::FROST_WALL, 2400, 480}
		 ),
		100u, 0.5, pos);
}

Player Player::makeTank(Vect<2u, double> pos)
{
  return Player(Vect<3u, Spell>
		(Spell{SpellType::ARROW_SHOT, 60, 10},
		 Spell{SpellType::JUMP, 240, 30},
		 Spell{SpellType::ARROW_ULTI, 2400, 480}),
		100u, 0.5, pos);
}

Player Player::makeWarrior(Vect<2u, double> pos)
{
  return Player(Vect<3u, Spell>
		(Spell{SpellType::ARROW_SHOT, 60, 10},
		 Spell{SpellType::JUMP, 240, 30},
		 Spell{SpellType::ARROW_ULTI, 2400, 480}),
		100u, 0.5, pos);
}

void  Player::serialize(SaveState &state) const
{
  state.serialize(id);
  for (auto const &spell : spells)
    state.unserialize(spell.timeLeft);
}

void  Player::unserialize(LoadGame &game)
{
  game.unserialize(id);
  for (auto &spell : spells)
    game.unserialize(spell.timeLeft);
}
