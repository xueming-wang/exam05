#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <iostream>
#include <iterator>
#include <vector>

class TargetGenerator {
    public:
        TargetGenerator();
        virtual ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);


    private:
        TargetGenerator(TargetGenerator const& src);
        TargetGenerator &operator=(TargetGenerator const& rhs);
        std::vector<ATarget *>targets;
};

#endif