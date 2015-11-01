//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"

namespace Lyre
{
    class IStep;
    using IStepSP = std::shared_ptr<IStep>;
    using IStepUP = std::unique_ptr<IStep>;
    class IStep
    {
    public:
        virtual ~IStep() = default;
        
        /* return a deep copy of "this" */
        virtual IStepUP clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        /* return the Step as an integer */
        virtual Integer getValue() const = 0;
        
        /* set the value from an int */
        virtual void setValue( const Integer val ) = 0;
        
        /* get the min/max allowable Step values */
        virtual Integer getMin() const = 0;
        virtual Integer getMax() const = 0;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str ) = 0;
        
        /* stream the Step name's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        /* return the Step as a string, this has a definition
         which calls toStream. */
        virtual String toString() const;
        
        /* compares the return values of getValue() */
        virtual bool isLessThan( const IStep& other ) const;
        virtual bool isGreaterThan( const IStep& other ) const;
        virtual bool isEqualTo( const IStep& other ) const;
        
        /* returns true if the two objects are identical in value,
         e.g. Ab is not identical to G# even though isEqualTo
         returns true */
        virtual bool isIdenticalTo( const IStep& other ) const = 0;
        
        /* increments/decrements, should wraps around to min/max */
        virtual void increment() = 0;
        virtual void decrement() = 0;
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const IStep& StepName );
}