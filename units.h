#pragma once

enum class Team {
    Player,
    Computer
};

class Unit {
protected:
    Team team;
    int lane;
    double position;

    int hp;
    int damage;
    int armor;
    double speed;

public:
    Unit(Team team, int lane, double position,
         int hp, int damage, int armor, double speed);

    virtual ~Unit() = default;

    virtual double getAttackRange() const noexcept = 0;

    int getHP() const noexcept;
    int getLane() const noexcept;
    double getPosition() const noexcept;
    Team getTeam() const noexcept;

    bool isAlive() const noexcept;

    void takeDamage(int amount) noexcept;
    void move() noexcept;

    int calculateDamage(const Unit& target) const noexcept;
    void attack(Unit& target) const noexcept;
};
