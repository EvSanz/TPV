//
// Created by eys on 24/8/21.
//

#ifndef CARGAME_TEXTURECONTAINER_H
#define CARGAME_TEXTURECONTAINER_H

#include <array>
#include "Texture.h"
#include <string>

using namespace std;

const string IMAGES_PATH = "../Images/";

//Texturas de los objetos 
enum TextureName {carTexture,
        rockTexture,
        goalTexture,
        powerUpTexture,
        coinTexture,
        bulletTexture, 
        turboTexture,
        superRockTexture, 
        oilTexture,
        truckTexture};

const int NUM_TEXTURES = 10;

typedef struct {
    string filename;
    int numRows; int numCols;
} TextureAttributes;

//Imagenes 
const TextureAttributes TEXTURE_ATTRIBUTES[NUM_TEXTURES] =
        {{"car.png",1,1},
         {"rock.png",1,1},
         {"goal.png",1,1},
         {"powerUp.png",1,1},
         {"coin.png",1,1},
         {"bullet.png",1,1},
         {"turbo.png",1,1},
         {"superrock.png",1,1},
         {"oil.png",1,1},
         {"truck.png",1,1}
        };



class TextureContainer {

    array<Texture*, NUM_TEXTURES> textures;

public:
    TextureContainer(SDL_Renderer *renderer){
        for (int i = 0; i < NUM_TEXTURES; i++) {
            const TextureAttributes& attributes = TEXTURE_ATTRIBUTES[i];
            textures[i] = new Texture(renderer, IMAGES_PATH + attributes.filename, attributes.numRows, attributes.numCols);
        }
    }

    ~TextureContainer(){
        for (int i = 0; i < NUM_TEXTURES; i++) {

            if(textures[i] != nullptr){
                textures[i]->free();
            }
            delete textures[i];
        }
    }

    Texture* getTexture(TextureName name) const {return textures[name];};

};

#endif //CARGAME_TEXTURECONTAINER_H

