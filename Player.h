# pragma once
#include <string>
using namespace std;

class Player {
public:
    Player(string name, char token, int isAI) : name(name), token(token), isAI(isAI) {};
    ~Player() {};
    string getName() { return this->name; };
    char getToken() { return this->token; };
    
private:
    string name;
    char token;
    int isAI;
};