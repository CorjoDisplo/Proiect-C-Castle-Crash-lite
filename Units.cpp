#include "Unit.h"
#include <algorithm>

Unit::Unit(Team team, int lane, double position,
    int hp, int damage, int armor, double speed)
    : team(team),
    lane(lane),
    position(std::clamp(position, 0.0, 100.0)),
    hp(std::max(1, hp)),
    damage(std::max(0, damage)),
    armor(std::max(0, armor)),
    speed(std::max(0.0, speed)) {
}

int Unit::getHP() const noexcept {
    return hp;
}

int Unit::getLane() const noexcept {
    return lane;
}

double Unit::getPosition() const noexcept {
    return position;
}

Team Unit::getTeam() const noexcept {
    return team;
}

bool Unit::isAlive() const noexcept {
    return hp > 0;
}

// Scade HP-ul in functie de damage-ul primit.
void Unit::takeDamage(int amount) noexcept {
    hp = std::max(0, hp - std::max(0, amount));
}

// Player-ul merge spre dreapta, AI-ul spre stanga.
void Unit::move() noexcept {
    if (team == Team::Player)
        position += speed;
    else
        position -= speed;

    position = std::clamp(position, 0.0, 100.0);
}

// Calculeaza damage-ul tinand cont de armura adversarului.
int Unit::calculateDamage(const Unit& target) const noexcept {
    return std::max(1, damage - target.armor);
}

void Unit::attack(Unit& target) const noexcept {
    target.takeDamage(calculateDamage(target));
}
