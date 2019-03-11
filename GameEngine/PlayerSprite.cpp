#include "PlayerSprite.h"
#include "Projectile.h"
#include "GameEngine.h"

PlayerSprite::PlayerSprite(std::string imagePath, Position startingPosition) : MovingSprite(imagePath, startingPosition, "PlayerSprite")
{
}

PlayerSprite::~PlayerSprite()
{
}

PlayerSprite* PlayerSprite::getInstance(std::string imagePath, Position startingPosition) {
	return new PlayerSprite(imagePath, startingPosition);
}

void PlayerSprite::handleInput(SDL_Event SDLevent, const std::vector<Sprite*>* allSprites)
{

		if (SDLevent.type == SDL_KEYDOWN) {
	switch (SDLevent.key.keysym.sym)
	{
	case SDLK_UP:
		//"OOF!"
		break;
	case SDLK_DOWN:
		//"OOF!"
		break;
	case SDLK_LEFT:
		position.x -= 20;
		break;
	case SDLK_RIGHT:
		position.x += 20;
		break;
	case SDLK_SPACE :
		
		shoot();
			break;
	default:
		break;
		}
	}
}

void PlayerSprite::shoot() {
	auto engine = getGameEngine();
	auto projectileSprite = Projectile::getInstance({-999, -999 }, UP);

	int projectileWidth = projectileSprite->getRect()->w;
	int ProjectileHeight = projectileSprite->getRect()->h;
	auto center = getCenter();

	projectileSprite->position = {
		center.x - projectileWidth/ 2,
		position.y-75
	};

	engine->queueAddSprite(projectileSprite);
}
