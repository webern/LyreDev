//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(IDurDot)
    FORWARD_DECLARE(IDurBase)
    
    static const int DURATION_MAX_DOTS = 20;
    
    class PUBLIC IDurDot
    {
    public:
        virtual ~IDurDot();
        
        virtual IDurDotUP clone() const = 0;
        
        virtual Rational getValue() const = 0;
        virtual Rational getDurBaseValue() const = 0;
        
        virtual int getDotCount() const = 0;
        
        virtual void setDotCount( const int dots ) = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual std::ostream& durBaseToStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        virtual String getDurBaseName() const = 0;
        
        virtual bool isEqualTo( const IDurDot& other ) const = 0;
        virtual bool isGreaterThan( const IDurDot& other ) const = 0;
        virtual bool isLessThan( const IDurDot& other ) const = 0;
    };
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const IDurDot& object );
    
	PUBLIC bool operator==( const IDurDot& l, const IDurDot& r );
	PUBLIC bool operator!=( const IDurDot& l, const IDurDot& r );
	PUBLIC bool operator>=( const IDurDot& l, const IDurDot& r );
	PUBLIC bool operator<=( const IDurDot& l, const IDurDot& r );
	PUBLIC bool operator>( const IDurDot& l, const IDurDot& r );
	PUBLIC bool operator<( const IDurDot& l, const IDurDot& r );
}
