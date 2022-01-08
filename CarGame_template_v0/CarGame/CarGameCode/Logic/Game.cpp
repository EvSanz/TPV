//Include
#include "Game.h"
#include "GameObjectGenerator.h"

Game::Game(string name, int width, int height, int roadLength) {

    //Asignamos el nombre del juego, el tamaño del juego, 
    //el ancho y altura de la pantalla
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;

    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);

    //Creamos un infobar
    infoBar = new Infobar(this);
}

//Metodo para cambiar el estado del juego 
void Game::changeState()
{
    //Si el estado actual es menu o gameover
    if (state == Menu || state == GameOver)
    {
        //En el caso de ser el gameover, eliminamos el 
        //contador de objetos 
        if (state == GameOver)
            con->~GameObjectContainer();

        //Y cambiamos al estado de juego, empezando la partida
        state = Playing;
        startGame(); 
    }

}

//Metodo para empezar el juego 
void Game::startGame() {

    //Indicamos que no ha terminado el juego y reseteamos el cronometro
    finished = false;
    srand(time(NULL));

    //Si hay un coche creado, lo eliminamos y despues volvemos
    //a crear, estableciendo sus dimensiones, posicion y textura
    if (car != nullptr)
        delete car;
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height / 2.0);
    car->setTextureObject(carTexture);

    //En el caso de haber un contador de objetos creado, lo 
    //eliminamos para despues crearlo vacio
    if (con != nullptr) {
        delete con;
        con = nullptr;
    }
    con = new GameObjectContainer();

    //Generamos los objetos del mapa
    GameObjectGenerator::generateRocks(this, 5, 10, 10, 5, 3, 5, 6); 

    //Si hay una meta creada, la eliminamos y despues volvemos
    //a crear, estableciendo sus dimensiones, posicion y textura
    if (goal != nullptr)
        delete goal;
    goal = new Goal(this);
    goal->setDimension(GOAL_WIDTH, getWindowHeight());
    goal->setPosition(roadLength, getWindowHeight()/2);
    goal->setTextureObject(goalTexture); 

    //Iniciamos el cronometro de milisegundos 
    startTime = SDL_GetTicks();
}

//Metodo para devolver el nombre del juego 
string Game::getGameName() {
    return name;
}

//Metodo para eliminar todos los elementos del juego 
//si no han sido eliminado con anterioridad
Game::~Game() {

    cout << "[DEBUG] deleting game" << endl;

    if(car != nullptr)
        delete car;
    
    delete con;
    con = nullptr;

    if(goal != nullptr)
        delete goal;
    
    if(font != nullptr)
        delete font;

    if(textureContainer != nullptr)
        delete textureContainer;

    if (infoBar != nullptr)
        delete infoBar;
}

//Metodo para modificar los objetos
void Game::update(){

    car->update();
    con->update(); 

    //Eliminamos los elementos destruimos del contador de objetos
    con->removeDead();

    //Si el jugador ha perdido todas sus vidas, acabamos con el juego 
    if (!car->isAlive()) {
        finished = true;
    }

    //Si el coche ha colisionado con la meta, finalizamos el juego 
    //y detenemos el cronometro 
    if (SDL_HasIntersection(&car->getCollider(),
        &goal->getCollider())) {
        endTime = SDL_GetTicks() - startTime;
        finished = true;
    }
}

//Metodo para obtener el vector de colisiones de los objetos 
vector<GameObject*> Game::getCollisions()
{
    return con->getVector(); 
}

//Metodo para dibujar los elementos, teniendo en cuenta 
//que los ultimos en dibujarse se mostraran por encima de los anteriores
void Game::draw(){
    con->draw();
    goal->draw();
    car->draw();
    drawInfo();
}

//Metodo para mostrar la informacion y el estado del juego 
void Game::drawInfo() {

    infoBar->drawInfo();

    //Si activamos la ayuda, mostramos tambien el panel de ayuda
    if(help)
        infoBar->drawHelp();

    infoBar->drawState();
}

//Metodo para finalizar el juego 
void Game::gameOver()
{
    //Dependiendo del estado del jugador, mostraremos 
    //un mensaje u otro en pantalla
    if (car->isAlive())
    {
        vector<string> texts = {
            "User wins",
            "Time: " + to_string(endTime) + " ms",
            "Press space to play again"
        };

        renderVectorText(texts, getWindowWidth() / 2 - 100, getWindowHeight() / 2 - 50);
    }

    else {

        vector<string> texts = {
            "User loses",
            "Press space to retry"
        };

        renderVectorText(texts, getWindowWidth() / 2 - 100, getWindowHeight() / 2 - 50);
    }

    //Cambiamos el estado del juego 
    infoBar->drawState();
}

//Metodo para indicar que el jugador ha salido del juego 
void Game::setUserExit() {
    doExit = true;
}

//Metodo para comprobar si se puede gastar dinero 
bool Game::spendMoney(int cost)
{
    if (car->getCoins() >= cost) {

        //Si se puede gastar, restamos las monedas 
        car->spentCoins(cost);
        return true;
    }

    else
        return false; 
}

//Metodo para devolver el ancho de la pantalla
int Game::getWindowWidth(){
    return width;
}

//Metodo para devolver la altura de la pantalla
int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

//Metodo para cargar las texturas del juego si no son nulas 
void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

//Metodo para escribir en pantalla una linea de texto 
void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

//Metodo para renderizar vectores de textos (Varias lineas) 
void Game::renderVectorText(vector<string> text, int x, int y, SDL_Color color)
{
    //Creamos un valor para aumentar la posicion y 
    int inc = font->getSize() * 1.5;

    //Renderizamos cada linea de texto en posiciones de y cambiadas
    for (auto s : text) {
        renderText(s, x, y, color);
        y += inc;
    }
}

//Metodo para devolver el bool que indica si el jugador esta jugando o no 
bool Game::doQuit() {
    return doExit;
}

//Metodo para obtener una textura concreta 
Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

//Metodo para obtener las coordenadas de origen 
Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}

//Metodo para ralentizar o acelerar el coche dependiendo del bool
void Game::carSpeedo(bool stade) {
    car->speedControl(stade);  
}

//Metodo para mover el coche en una direccion u otra dependiendo del bool
void Game::carUpDown(bool state) {
    car->verticalmove(state);
}

//Metodo para renderizar el texto y establecer el estado del menu
void Game::menu() {
    vector<string> texts = {
    "Welcome to Super Cars",
    "Press space to start",
    "Press [h] for help"
    };

    renderVectorText(texts, getWindowWidth() / 2 - 100, getWindowHeight() / 2 - 50);
    infoBar->drawState();
}

//Metodo para comprobar si los objetos estan detras del jugador o delante de la meta
bool Game::isRebased(GameObject* gameObject) {
    return gameObject != nullptr &&
        (gameObject->getX() < car->getX() - car->getWidth() / 2
            || gameObject->getX() >= goal->getX() - goal->getWidth() / 2);
}