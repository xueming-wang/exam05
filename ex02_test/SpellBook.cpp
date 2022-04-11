#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook:: ~SpellBook(){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
        delete *it;
    this->spells.clear();
}
void SpellBook::learnSpell(ASpell* spell){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
    {
        if ((*it)->getName() == spell->getName())
            return;
    }
    this->spells.push_back(spell->clone());
}
void SpellBook::forgetSpell(std::string const &spellname){
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
ASpell* SpellBook::createSpell(std::string const &spellname){
    std::vector<ASpell *>::iterator it = this->spells.begin();
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for(; it != ite; it++)
    {
        if ((*it)->getName() == spellname)
            return *it;
    }
    return NULL;
}