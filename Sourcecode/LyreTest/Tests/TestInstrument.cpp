//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IInstrument.h"
#include "Lyre/IRangeFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IInstrumentFactoryUP factory =
	createInstrumentFactory();
}

TEST( toStream, Instrument )
{
    String name = "Trumpet in Bb";
    String shortName = "Bb Trp";
    auto range = createRangeFactory()->create( "Bb3", "C5" );
    
    IInstrumentUP inst = factory->create( name, shortName, range );
    std::stringstream ss;
    inst->toStream( ss );
    String expected = "Trumpet in Bb";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
