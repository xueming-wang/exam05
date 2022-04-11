
#include "ATarget.hpp"

ATarget::ATarget() : type() {}

ATarget::ATarget(std::string const & type) : type(type) {}

ATarget::ATarget(ATarget const & src) { *this = src; }

ATarget::~ATarget() {}

ATarget & ATarget::operator=(ATarget const & rhs) {
	if (this == &rhs) return *this;

	this->type = rhs.type;
	return *this;
}

std::string const & ATarget::getType() const { return this->type; }

void	ATarget::getHitBySpell(ASpell const& spell) const {
	std::cout << this->type << " has been " << spell.getEffects()
		<< "!" << std::endl;
}