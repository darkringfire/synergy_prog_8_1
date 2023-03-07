#include <vector>

class Block {
protected:
    int hardness;
};

class StoneBlock : public Block {
public:
    StoneBlock() : Block() {
        hardness = 10;
    }
};

class GrassBlock : public Block {
public:
    GrassBlock() : Block() {
        hardness = 5;
    }
};

class WaterBlock : public Block {
public:
    WaterBlock() : Block() {
        hardness = 1;
    }
};

class TreeBlock : public Block {
public:
    TreeBlock() : Block() {
        hardness = 3;
    }
};

class Character {
private:
    int health_ = 100;
    int damage_ = 0;
    int x_ = 0, y_ = 0, z_ = 0;
public:
    virtual void attack(Character character) {
        character.takeDamage(damage_);
    }

    void takeDamage(int damage) {
        health_ -= damage;
        if (health_ <= 0) {
            die();
        }
    }
    void move(int dx, int dy, int dz) {
        x_ += dx;
        y_ += dy;
        z_ += dz;
    }
    void moveTo(int x, int y, int z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }
    void die() {}
};

class Player : public Character {
};

class Zombie : public Character {
};

class World {
private:
    std::vector<std::vector<std::vector<Block *>>> blocks;
public:

    Block *getBlock(int x, int y, int z) {
        return blocks[x][y][z];
    }
};

class Game {
private:
    World world;
    std::vector<Character *> characters;
public:
};
