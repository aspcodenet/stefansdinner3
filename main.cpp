#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include<cstdlib>

// inheritance . baseclass(superclass) - subclass
// virtual functions
// polymorhism ()

// public functions+properties are accesible from ANYWHERE
// private are onlt accessible from the class itself
// proteted are accessible from the class itself AND it derived classes

// abstract classes . .- methods
// add some game behaviour
//      help with implementing LEVELLING 
//  humans to have a level - starting at 0
// add a mightLevelUp() function for all gameobejcts
// call it in the loop
// if a human burps three times in a row then level++

class GameObject{
public:    

    void draw(){
        
    }

    virtual void act() {
        std::cout << "This is gameobject act "  << std::endl;
    }
protected:
    int x;
    int y;
};

class  : public GameObject {
public:
    Human(std::string name):name(name){
        }
    void act() override{
        std::string actions[]={"eats","drinks","burps"};
        int index = rand()%3;        

        std::cout << name << " " << actions[index] << std::endl;
    }
private:
    std::string name;        
};

class Fly : public GameObject{
public:
    void act() override{
        std::string actions[]={"fly around","land in the food","buzzes"};
        int index = rand()%3;        

        std::cout << "Fly " << " " << actions[index] << std::endl;
    }
private:
};




int main(){

    auto h = Human("Stefan");
    h.draw();

    srand((unsigned) time(NULL));
    std::vector<GameObject *> gameObjects;
    gameObjects.push_back(new Human("Stefan"));
    gameObjects.push_back(new Human("Oliver"));
    gameObjects.push_back(new Human("Kerstin"));
    gameObjects.push_back(new Fly());
    
    while(true){ // gameloop
        for(auto actor: gameObjects){
            actor->act(); // jmp != -> function  jmp to special fuinction -> RUNTIME check actual type anbd call SPECIALIZED function - overridden funktion
            actor->draw();
        }
    }

    return 0;
}
