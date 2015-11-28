//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/toShared.h"
#include <memory>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

namespace
{
    using IntSP = std::shared_ptr<int>;
    using IntUP = std::unique_ptr<int>;
}

TEST( toShared, toShared )
{
    IntUP originalUP = IntUP{ new int{ 1 } };
    IntSP copy1SP = toShared( originalUP );
    IntSP copy2SP = copy1SP;
    
    CHECK( originalUP == nullptr )
    CHECK_EQUAL( 1, *copy1SP )
    CHECK_EQUAL( 1, *copy2SP )
    
    *copy1SP = 22;
    CHECK_EQUAL( 22, *copy1SP )
    CHECK_EQUAL( 22, *copy2SP )
    
}
