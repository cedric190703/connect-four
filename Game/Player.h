# pragma once
#include <string>
using namespace std;

class Player {
public:
    Player(string name, char token) : name(name), token(token) {};
    ~Player() {};
    string getName() { return this->name; };
    char getToken() { return this->token; };

private:
    string name;
    char token;
};