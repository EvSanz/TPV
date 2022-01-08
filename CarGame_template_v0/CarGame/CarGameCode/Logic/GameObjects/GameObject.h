#ifndef CARGAME_GAMEOBJECT_H
#define CARGAME_GAMEOBJECT_H

//Includes
#include "Collider.h"
#include "../../Utils/Vector2D.h"
#include "../../View/TextureContainer.h"

//Clases
class Game;

class GameObject : public Collider {

    //Puntero de posicion
    Point2D<double> pos;

    //Valores para el ancho y la altura
    int w, h;

protected:

    Texture *texture;
    Game* game;

    //Nombre de la textura
    TextureName textureName; 
    int id;

    void drawTexture(Texture* texture);

public:

    GameObject(Game *game): game(game){};
    virtual ~GameObject(){};

    virtual void draw(); 

    virtual void update()=0;

    virtual bool toDelete(){return false;}
    virtual void onEnter(){};
    virtual void onDelete(){};

    //Metodo para establecer la posicion (x, y) del objeto 
    void setPosition(double x, double y) {
        pos = Point2D<double>(x, y);
    };

    //Metodo para establecer el tamaño del objeto 
    void setDimension(double width, double height) {
        w = width;
        h = height;
    };

    //Metodo para establecer el nombre de la textura 
    void setTextureObject(TextureName name) {textureName = name;}

    //Metodos para devolver los valores del tamaño o posicion 
    int getWidth() {return w;};
    int getHeight() {return h;};
    int getX() {return pos.getX();};
    int getY() {return pos.getY();};

    //Metodo para obtener el collider del objeto 
    virtual SDL_Rect getCollider() {
        return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
    };

    bool collide(SDL_Rect other);
};
#endif //CARGAME_GAMEOBJECT_H
