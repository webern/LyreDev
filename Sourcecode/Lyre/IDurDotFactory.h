//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurDot.h"
#include <memory>

namespace Lyre
{
    enum class DurDotFactoryType
    {
        Standard = 0
    };
    
    // Forward Declarations
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    
    class IDurDotFactory;
    using IDurDotFactorySP = std::shared_ptr<IDurDotFactory>;
    using IDurDotFactoryUP = std::unique_ptr<IDurDotFactory>;
    
    IDurDotFactoryUP createDurDotFactory( const DurDotFactoryType t );

    class IDurDotFactory
    {
    public:
        
        virtual ~IDurDotFactory();
        
        virtual IDurDotUP createDurDot(
            const String& durName,
            const Integer dotCount ) const = 0;
        
        virtual IDurDotUP createDurDot(
            const String& durName ) const = 0;
    };
}
