#include "Lyre/Private/DurBreve.h"

namespace Lyre
{
    namespace Private
    {
        const Rational DurBreve::ourRational = Rational { 8, 1 };
        
        const String DurBreve::ourName = "Breve";
        
        DurBreve::~DurBreve() {}
        
        Rational DurBreve::getValue() const
        {
            return ourRational;
        }
        std::ostream& DurBreve::toStream( std::ostream& os ) const
        {
            return os << ourName;
        }
    }
}