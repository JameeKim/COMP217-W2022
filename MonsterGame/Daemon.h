#pragma once

class Daemon
{
private:
    int health;
    int mana;

public:
    Daemon(int health, int mana);

    int getHealth() const;

    virtual void attack() = 0;
};
