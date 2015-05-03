#include <string>
#include <vector>
#include "sprite.h"
#include "multisprite.h"
#include "gamedata.h"
#include "collisionStrategy.h"
#include "meteors.h"

class Player {
public:
  Player(const std::string& name);
  virtual ~Player();

  virtual void draw() const; 
  virtual void update(Uint32 ticks); 
  void reset();
  Drawable* getSprite() { return &player; }
  //MultiSprite* getSprite() { return &player; }
  Vector2f getPlayerPos() const { return player.getPosition(); }
  Vector2f getPlayerVel() const { return player.getVelocity(); }
  float getX() const { return player.X(); }
  float getY() const { return player.Y(); }
  float getVX() const { return player.velocityX(); }
  float getVY() const { return player.velocityY(); }

  bool collidedWith(Drawable* d) {       
    return strategy->execute(player, *d);
  }
  void setCollisionStrategy(int index) {
    strategy = strategies[index];
  }
  void addShield(){player.addShield();}
  void addgodShield(){player.addgodShield();}
  void Pchangeflag(){player.changeflag();}
  void stop() { 
    player.velocityX(0); 
    player.velocityY(0); 
  }
  void right();
  void left();
  void up();
  void down();

private:
  MultiSprite player;
  float playerWidth;
  float playerHeight;
  Vector2f velocity;
  float worldWidth;
  float worldHeight;
  std::vector<CollisionStrategy*> strategies;
  CollisionStrategy * strategy;
  Player(const Player&);
  Player& operator=(const Player&);
};
