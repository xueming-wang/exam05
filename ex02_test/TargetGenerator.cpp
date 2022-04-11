#include "TargetGenerator.hpp"
TargetGenerator::TargetGenerator(){}

TargetGenerator:: ~TargetGenerator(){
    std::vector<ATarget *>::iterator it = this->targets.begin();
    std::vector<ATarget *>::iterator ite = this->targets.end();
    for(; it != ite; it++)
        delete *it;
    this->targets.clear();
}
void TargetGenerator::learnTargetType(ATarget* target){
    std::vector<ATarget *>::iterator it = this->targets.begin();
    std::vector<ATarget *>::iterator ite = this->targets.end();
    for(; it != ite; it++)
    {
        if ((*it)->getType() == target->getType())
            return;
    }
    this->targets.push_back(target->clone());
}
void TargetGenerator::forgetTargetType(std::string const &targettype){
    std::vector<ATarget *>::iterator it = this->targets.begin();
    std::vector<ATarget *>::iterator ite = this->targets.end();
    for(; it != ite; it++)
    {
        if ((*it)->getType() == targettype)
        {
            delete (*it);
            this->targets.erase(it);
            return;
        }
    }
}
ATarget* TargetGenerator::createTarget(std::string const &targettype){
    std::vector<ATarget *>::iterator it = this->targets.begin();
    std::vector<ATarget *>::iterator ite = this->targets.end();
    for(; it != ite; it++)
    {
        if ((*it)->getType() == targettype)
            return *it;
    }
    return NULL;
}