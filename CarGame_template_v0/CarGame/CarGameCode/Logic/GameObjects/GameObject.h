#ifndef CARGAME_GAMEOBJECT_H
#define CARGAME_GAMEOBJECT_H

// TODO: add includes
#include "Collider.h"
#include "../../Utils/Vector2D.h"
#include "../../View/TextureContainer.h"

class Game;

class GameObject : public Collider {

    Point2D<double> pos;
    int w, h;

protected:
    Texture *texture;
    Game* game;

    void drawTexture(Texture* texture);

    int id;
    TextureName textureName; 

public:
    GameObject(Game *game): game(game){};
    virtual ~GameObject(){};

    virtual void draw(); 

    virtual void update()=0;

    virtual bool toDelete(){return false;}
    virtual void onEnter(){};
    virtual void onDelete(){};

    void setPosition(double x, double y) {
        pos = Point2D<double>(x, y);
    };
    void setDimension(double width, double height) {
        w = width;
        h = height;
    };

    void setTextureObject(TextureName name)
    {
        textureName = name;
    }

    int getWidth() {return w;};
    int getHeight() {return h;};

    int getX() {return pos.getX();};
    int getY() {return pos.getY();};

    virtual SDL_Rect getCollider() {
        return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
    };

    //virtual SDL_Rect getCenter();
    bool collide(SDL_Rect other);
};
#endif //CARGAME_GAMEOBJECT_H
