//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(ITupletDef)
    FORWARD_DECLARE(IDurDot)
    
    class ITupletDef
    {
    public:
        virtual ~ITupletDef() = default;
        
        virtual ITupletDefUP clone() const = 0;
        
        virtual Rational getMultiplier() const = 0;
        virtual Rational getTotalLength() const = 0;
        
        virtual Integer getCount() const = 0;
        virtual IDurDotUPC getCountType() const = 0;
        
        virtual Integer getInTheSpaceOf() const = 0;
        virtual IDurDotUPC getInTheSpaceOfType() const = 0;
        
        virtual bool getIsValid() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        
    };
    
    std::ostream& operator<<( std::ostream& os, const ITupletDef& val );
}
