#include "Warlock.hpp"

Warlock::Warlock(std::string const& name, std::string const& title):name(name),title(title){
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
        delete *it;
    this->spells.clear();
    std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const& Warlock::getName()const {return this->name;}
std::string const& Warlock::getTitle()const { return this->title;}
void Warlock::setTitle(std::string const& title){ this->title = title;}
void Warlock::introduce()const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
    {
        if ((*it)->getName() == spell->getName())
            return;
    }
    this->spells.push_back(spell->clone());
}
void Warlock::forgetSpell(std::string const& spellname){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
    {
        if ((*it)->getName() == spellname)
        {
            delete (*it);
            this->spells.erase(it);
            return;
        }
    }
}
void Warlock::launchSpell(std::string const& spellname, ATarget & target){
     std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
    {
        if ((*it)->getName() == spellname){
            (*it)->launch(target);
            return;
        }
    }
}

