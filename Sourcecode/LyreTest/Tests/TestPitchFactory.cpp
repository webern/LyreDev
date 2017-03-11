//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IPitchFactory.h"

#include <sstream>
#include <iostream>

using namespace Lyre;
using namespace std;

#define _GENERATE_PITCH_FACTORY_TESTS
#ifdef GENERATE_PITCH_FACTORY_TESTS

TEST( TestGenerator, PitchFactory )
{
    auto fact = createPitchFactory( PitchFactoryType::StandardChromatic );
    int distance = 0;
    for ( int i = -10; i < 123; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            int value = i;
            String valuestr = std::to_string( i );
            replace( valuestr.begin(), valuestr.end(), '-', 'N' );
            bool isFromAbove = static_cast<bool>( j );
            String fromstr = "fromBelow";
            if ( !isFromAbove )
            {
                fromstr = "fromAbove";
            }
            int direction = isFromAbove ? 1 : -1;
            int fromval = value + ( direction * distance );
            fact->setPitch( value );
            auto e = fact->createPitch()->toString();
            std::stringstream ss;
            ss << "TEST( VALUE_" << valuestr << "_" << fromstr <<", PitchFactory )" << std::endl;
            ss << "{" << std::endl;
            ss << '\t' << "IPitchFactoryUP factory =" << std::endl;
            ss << '\t' << '\t' << "createPitchFactory( PitchFactoryType::StandardChromatic );" << std::endl;
            ss << '\t' << "int value = " << value << ";" << std::endl;
            ss << '\t' << "int fromval = " << fromval << ";" << std::endl;
            ss << '\t' << "String expected = \"" << e << "\";" << std::endl;
            ss << '\t' << "factory->setPitch( fromval );" << std::endl;
            ss << '\t' << "factory->setPitch( value );" << std::endl;
            ss << '\t' << "IPitchUP pitch = factory->createPitch();" << std::endl;
            ss << '\t' << "String actual = pitch->toString();" << std::endl;
            ss << '\t' << "CHECK_EQUAL( expected, actual )" << std::endl;
            ss << "}" << std::endl;
            
            
            std::cout << ss.str() << std::endl;
        }
        if ( i % 2 == 0 )
        {
            ++distance;
        }
    }
}

#endif

#ifndef GENERATE_PITCH_FACTORY_TESTS

TEST( VALUE_N10_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -10;
	int fromval = -10;
	String expected = "D-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N10_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -10;
	int fromval = -10;
	String expected = "D-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N9_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -9;
	int fromval = -10;
	String expected = "Eb-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N9_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -9;
	int fromval = -8;
	String expected = "Eb-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N8_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -8;
	int fromval = -9;
	String expected = "E-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N8_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -8;
	int fromval = -7;
	String expected = "E-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N7_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -7;
	int fromval = -9;
	String expected = "F-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N7_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -7;
	int fromval = -5;
	String expected = "F-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N6_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -6;
	int fromval = -8;
	String expected = "F#-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N6_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -6;
	int fromval = -4;
	String expected = "F#-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N5_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -5;
	int fromval = -8;
	String expected = "G-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N5_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -5;
	int fromval = -2;
	String expected = "G-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N4_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -4;
	int fromval = -7;
	String expected = "Ab-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N4_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -4;
	int fromval = -1;
	String expected = "Ab-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N3_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -3;
	int fromval = -7;
	String expected = "A-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N3_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -3;
	int fromval = 1;
	String expected = "A-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N2_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -2;
	int fromval = -6;
	String expected = "Bb-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N2_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -2;
	int fromval = 2;
	String expected = "Bb-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N1_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -1;
	int fromval = -6;
	String expected = "B-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N1_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = -1;
	int fromval = 4;
	String expected = "B-2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_0_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 0;
	int fromval = -5;
	String expected = "C-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_0_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 0;
	int fromval = 5;
	String expected = "C-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_1_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 1;
	int fromval = -5;
	String expected = "C#-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_1_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 1;
	int fromval = 7;
	String expected = "C#-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_2_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 2;
	int fromval = -4;
	String expected = "D-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_2_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 2;
	int fromval = 8;
	String expected = "D-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_3_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 3;
	int fromval = -4;
	String expected = "Eb-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_3_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 3;
	int fromval = 10;
	String expected = "Eb-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_4_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 4;
	int fromval = -3;
	String expected = "E-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_4_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 4;
	int fromval = 11;
	String expected = "E-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_5_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 5;
	int fromval = -3;
	String expected = "F-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_5_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 5;
	int fromval = 13;
	String expected = "F-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_6_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 6;
	int fromval = -2;
	String expected = "F#-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_6_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 6;
	int fromval = 14;
	String expected = "F#-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_7_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 7;
	int fromval = -2;
	String expected = "G-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_7_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 7;
	int fromval = 16;
	String expected = "G-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_8_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 8;
	int fromval = -1;
	String expected = "Ab-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_8_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 8;
	int fromval = 17;
	String expected = "Ab-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_9_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 9;
	int fromval = -1;
	String expected = "A-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_9_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 9;
	int fromval = 19;
	String expected = "A-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_10_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 10;
	int fromval = 0;
	String expected = "Bb-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_10_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 10;
	int fromval = 20;
	String expected = "Bb-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_11_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 11;
	int fromval = 0;
	String expected = "B-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_11_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 11;
	int fromval = 22;
	String expected = "B-1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_12_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 12;
	int fromval = 1;
	String expected = "C0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_12_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 12;
	int fromval = 23;
	String expected = "C0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_13_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 13;
	int fromval = 1;
	String expected = "C#0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_13_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 13;
	int fromval = 25;
	String expected = "C#0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_14_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 14;
	int fromval = 2;
	String expected = "D0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_14_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 14;
	int fromval = 26;
	String expected = "D0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_15_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 15;
	int fromval = 2;
	String expected = "Eb0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_15_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 15;
	int fromval = 28;
	String expected = "Eb0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_16_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 16;
	int fromval = 3;
	String expected = "E0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_16_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 16;
	int fromval = 29;
	String expected = "E0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_17_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 17;
	int fromval = 3;
	String expected = "F0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_17_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 17;
	int fromval = 31;
	String expected = "F0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_18_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 18;
	int fromval = 4;
	String expected = "F#0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_18_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 18;
	int fromval = 32;
	String expected = "F#0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_19_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 19;
	int fromval = 4;
	String expected = "G0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_19_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 19;
	int fromval = 34;
	String expected = "G0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_20_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 20;
	int fromval = 5;
	String expected = "Ab0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_20_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 20;
	int fromval = 35;
	String expected = "Ab0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_21_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 21;
	int fromval = 5;
	String expected = "A0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_21_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 21;
	int fromval = 37;
	String expected = "A0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_22_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 22;
	int fromval = 6;
	String expected = "Bb0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_22_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 22;
	int fromval = 38;
	String expected = "Bb0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_23_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 23;
	int fromval = 6;
	String expected = "B0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_23_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 23;
	int fromval = 40;
	String expected = "B0";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_24_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 24;
	int fromval = 7;
	String expected = "C1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_24_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 24;
	int fromval = 41;
	String expected = "C1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_25_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 25;
	int fromval = 7;
	String expected = "C#1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_25_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 25;
	int fromval = 43;
	String expected = "C#1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_26_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 26;
	int fromval = 8;
	String expected = "D1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_26_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 26;
	int fromval = 44;
	String expected = "D1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_27_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 27;
	int fromval = 8;
	String expected = "Eb1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_27_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 27;
	int fromval = 46;
	String expected = "Eb1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_28_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 28;
	int fromval = 9;
	String expected = "E1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_28_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 28;
	int fromval = 47;
	String expected = "E1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_29_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 29;
	int fromval = 9;
	String expected = "F1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_29_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 29;
	int fromval = 49;
	String expected = "F1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_30_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 30;
	int fromval = 10;
	String expected = "F#1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_30_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 30;
	int fromval = 50;
	String expected = "F#1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_31_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 31;
	int fromval = 10;
	String expected = "G1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_31_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 31;
	int fromval = 52;
	String expected = "G1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_32_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 32;
	int fromval = 11;
	String expected = "Ab1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_32_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 32;
	int fromval = 53;
	String expected = "Ab1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_33_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 33;
	int fromval = 11;
	String expected = "A1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_33_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 33;
	int fromval = 55;
	String expected = "A1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_34_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 34;
	int fromval = 12;
	String expected = "Bb1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_34_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 34;
	int fromval = 56;
	String expected = "Bb1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_35_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 35;
	int fromval = 12;
	String expected = "B1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_35_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 35;
	int fromval = 58;
	String expected = "B1";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_36_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 36;
	int fromval = 13;
	String expected = "C2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_36_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 36;
	int fromval = 59;
	String expected = "C2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_37_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 37;
	int fromval = 13;
	String expected = "C#2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_37_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 37;
	int fromval = 61;
	String expected = "C#2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_38_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 38;
	int fromval = 14;
	String expected = "D2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_38_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 38;
	int fromval = 62;
	String expected = "D2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_39_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 39;
	int fromval = 14;
	String expected = "Eb2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_39_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 39;
	int fromval = 64;
	String expected = "Eb2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_40_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 40;
	int fromval = 15;
	String expected = "E2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_40_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 40;
	int fromval = 65;
	String expected = "E2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_41_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 41;
	int fromval = 15;
	String expected = "F2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_41_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 41;
	int fromval = 67;
	String expected = "F2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_42_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 42;
	int fromval = 16;
	String expected = "F#2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_42_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 42;
	int fromval = 68;
	String expected = "F#2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_43_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 43;
	int fromval = 16;
	String expected = "G2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_43_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 43;
	int fromval = 70;
	String expected = "G2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_44_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 44;
	int fromval = 17;
	String expected = "Ab2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_44_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 44;
	int fromval = 71;
	String expected = "Ab2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_45_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 45;
	int fromval = 17;
	String expected = "A2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_45_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 45;
	int fromval = 73;
	String expected = "A2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_46_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 46;
	int fromval = 18;
	String expected = "Bb2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_46_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 46;
	int fromval = 74;
	String expected = "Bb2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_47_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 47;
	int fromval = 18;
	String expected = "B2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_47_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 47;
	int fromval = 76;
	String expected = "B2";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_48_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 48;
	int fromval = 19;
	String expected = "C3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_48_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 48;
	int fromval = 77;
	String expected = "C3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_49_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 49;
	int fromval = 19;
	String expected = "C#3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_49_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 49;
	int fromval = 79;
	String expected = "C#3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_50_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 50;
	int fromval = 20;
	String expected = "D3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_50_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 50;
	int fromval = 80;
	String expected = "D3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_51_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 51;
	int fromval = 20;
	String expected = "Eb3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_51_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 51;
	int fromval = 82;
	String expected = "Eb3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_52_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 52;
	int fromval = 21;
	String expected = "E3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_52_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 52;
	int fromval = 83;
	String expected = "E3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_53_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 53;
	int fromval = 21;
	String expected = "F3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_53_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 53;
	int fromval = 85;
	String expected = "F3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_54_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 54;
	int fromval = 22;
	String expected = "F#3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_54_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 54;
	int fromval = 86;
	String expected = "F#3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_55_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 55;
	int fromval = 22;
	String expected = "G3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_55_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 55;
	int fromval = 88;
	String expected = "G3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_56_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 56;
	int fromval = 23;
	String expected = "Ab3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_56_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 56;
	int fromval = 89;
	String expected = "Ab3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_57_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 57;
	int fromval = 23;
	String expected = "A3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_57_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 57;
	int fromval = 91;
	String expected = "A3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_58_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 58;
	int fromval = 24;
	String expected = "Bb3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_58_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 58;
	int fromval = 92;
	String expected = "Bb3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_59_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 59;
	int fromval = 24;
	String expected = "B3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_59_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 59;
	int fromval = 94;
	String expected = "B3";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_60_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 60;
	int fromval = 25;
	String expected = "C4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_60_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 60;
	int fromval = 95;
	String expected = "C4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_61_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 61;
	int fromval = 25;
	String expected = "C#4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_61_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 61;
	int fromval = 97;
	String expected = "C#4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_62_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 62;
	int fromval = 26;
	String expected = "D4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_62_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 62;
	int fromval = 98;
	String expected = "D4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_63_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 63;
	int fromval = 26;
	String expected = "Eb4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_63_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 63;
	int fromval = 100;
	String expected = "Eb4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_64_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 64;
	int fromval = 27;
	String expected = "E4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_64_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 64;
	int fromval = 101;
	String expected = "E4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_65_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 65;
	int fromval = 27;
	String expected = "F4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_65_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 65;
	int fromval = 103;
	String expected = "F4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_66_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 66;
	int fromval = 28;
	String expected = "F#4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_66_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 66;
	int fromval = 104;
	String expected = "F#4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_67_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 67;
	int fromval = 28;
	String expected = "G4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_67_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 67;
	int fromval = 106;
	String expected = "G4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_68_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 68;
	int fromval = 29;
	String expected = "Ab4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_68_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 68;
	int fromval = 107;
	String expected = "Ab4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_69_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 69;
	int fromval = 29;
	String expected = "A4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_69_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 69;
	int fromval = 109;
	String expected = "A4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_70_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 70;
	int fromval = 30;
	String expected = "Bb4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_70_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 70;
	int fromval = 110;
	String expected = "Bb4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_71_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 71;
	int fromval = 30;
	String expected = "B4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_71_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 71;
	int fromval = 112;
	String expected = "B4";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_72_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 72;
	int fromval = 31;
	String expected = "C5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_72_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 72;
	int fromval = 113;
	String expected = "C5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_73_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 73;
	int fromval = 31;
	String expected = "C#5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_73_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 73;
	int fromval = 115;
	String expected = "C#5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_74_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 74;
	int fromval = 32;
	String expected = "D5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_74_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 74;
	int fromval = 116;
	String expected = "D5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_75_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 75;
	int fromval = 32;
	String expected = "Eb5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_75_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 75;
	int fromval = 118;
	String expected = "Eb5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_76_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 76;
	int fromval = 33;
	String expected = "E5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_76_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 76;
	int fromval = 119;
	String expected = "E5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_77_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 77;
	int fromval = 33;
	String expected = "F5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_77_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 77;
	int fromval = 121;
	String expected = "F5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_78_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 78;
	int fromval = 34;
	String expected = "F#5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_78_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 78;
	int fromval = 122;
	String expected = "F#5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_79_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 79;
	int fromval = 34;
	String expected = "G5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_79_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 79;
	int fromval = 124;
	String expected = "G5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_80_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 80;
	int fromval = 35;
	String expected = "Ab5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_80_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 80;
	int fromval = 125;
	String expected = "Ab5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_81_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 81;
	int fromval = 35;
	String expected = "A5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_81_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 81;
	int fromval = 127;
	String expected = "A5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_82_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 82;
	int fromval = 36;
	String expected = "Bb5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_82_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 82;
	int fromval = 128;
	String expected = "Bb5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_83_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 83;
	int fromval = 36;
	String expected = "B5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_83_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 83;
	int fromval = 130;
	String expected = "B5";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_84_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 84;
	int fromval = 37;
	String expected = "C6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_84_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 84;
	int fromval = 131;
	String expected = "C6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_85_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 85;
	int fromval = 37;
	String expected = "C#6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_85_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 85;
	int fromval = 133;
	String expected = "C#6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_86_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 86;
	int fromval = 38;
	String expected = "D6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_86_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 86;
	int fromval = 134;
	String expected = "D6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_87_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 87;
	int fromval = 38;
	String expected = "Eb6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_87_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 87;
	int fromval = 136;
	String expected = "Eb6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_88_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 88;
	int fromval = 39;
	String expected = "E6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_88_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 88;
	int fromval = 137;
	String expected = "E6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_89_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 89;
	int fromval = 39;
	String expected = "F6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_89_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 89;
	int fromval = 139;
	String expected = "F6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_90_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 90;
	int fromval = 40;
	String expected = "F#6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_90_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 90;
	int fromval = 140;
	String expected = "F#6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_91_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 91;
	int fromval = 40;
	String expected = "G6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_91_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 91;
	int fromval = 142;
	String expected = "G6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_92_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 92;
	int fromval = 41;
	String expected = "Ab6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_92_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 92;
	int fromval = 143;
	String expected = "Ab6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_93_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 93;
	int fromval = 41;
	String expected = "A6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_93_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 93;
	int fromval = 145;
	String expected = "A6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_94_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 94;
	int fromval = 42;
	String expected = "Bb6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_94_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 94;
	int fromval = 146;
	String expected = "Bb6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_95_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 95;
	int fromval = 42;
	String expected = "B6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_95_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 95;
	int fromval = 148;
	String expected = "B6";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_96_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 96;
	int fromval = 43;
	String expected = "C7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_96_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 96;
	int fromval = 149;
	String expected = "C7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_97_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 97;
	int fromval = 43;
	String expected = "C#7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_97_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 97;
	int fromval = 151;
	String expected = "C#7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_98_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 98;
	int fromval = 44;
	String expected = "D7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_98_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 98;
	int fromval = 152;
	String expected = "D7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_99_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 99;
	int fromval = 44;
	String expected = "Eb7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_99_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 99;
	int fromval = 154;
	String expected = "Eb7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_100_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 100;
	int fromval = 45;
	String expected = "E7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_100_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 100;
	int fromval = 155;
	String expected = "E7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_101_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 101;
	int fromval = 45;
	String expected = "F7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_101_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 101;
	int fromval = 157;
	String expected = "F7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_102_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 102;
	int fromval = 46;
	String expected = "F#7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_102_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 102;
	int fromval = 158;
	String expected = "F#7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_103_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 103;
	int fromval = 46;
	String expected = "G7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_103_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 103;
	int fromval = 160;
	String expected = "G7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_104_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 104;
	int fromval = 47;
	String expected = "Ab7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_104_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 104;
	int fromval = 161;
	String expected = "Ab7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_105_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 105;
	int fromval = 47;
	String expected = "A7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_105_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 105;
	int fromval = 163;
	String expected = "A7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_106_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 106;
	int fromval = 48;
	String expected = "Bb7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_106_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 106;
	int fromval = 164;
	String expected = "Bb7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_107_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 107;
	int fromval = 48;
	String expected = "B7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_107_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 107;
	int fromval = 166;
	String expected = "B7";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_108_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 108;
	int fromval = 49;
	String expected = "C8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_108_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 108;
	int fromval = 167;
	String expected = "C8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_109_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 109;
	int fromval = 49;
	String expected = "C#8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_109_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 109;
	int fromval = 169;
	String expected = "C#8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_110_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 110;
	int fromval = 50;
	String expected = "D8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_110_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 110;
	int fromval = 170;
	String expected = "D8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_111_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 111;
	int fromval = 50;
	String expected = "Eb8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_111_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 111;
	int fromval = 172;
	String expected = "Eb8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_112_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 112;
	int fromval = 51;
	String expected = "E8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_112_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 112;
	int fromval = 173;
	String expected = "E8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_113_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 113;
	int fromval = 51;
	String expected = "F8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_113_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 113;
	int fromval = 175;
	String expected = "F8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_114_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 114;
	int fromval = 52;
	String expected = "F#8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_114_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 114;
	int fromval = 176;
	String expected = "F#8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_115_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 115;
	int fromval = 52;
	String expected = "G8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_115_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 115;
	int fromval = 178;
	String expected = "G8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_116_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 116;
	int fromval = 53;
	String expected = "Ab8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_116_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 116;
	int fromval = 179;
	String expected = "Ab8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_117_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 117;
	int fromval = 53;
	String expected = "A8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_117_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 117;
	int fromval = 181;
	String expected = "A8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_118_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 118;
	int fromval = 54;
	String expected = "Bb8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_118_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 118;
	int fromval = 182;
	String expected = "Bb8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_119_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 119;
	int fromval = 54;
	String expected = "B8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_119_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 119;
	int fromval = 184;
	String expected = "B8";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_120_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 120;
	int fromval = 55;
	String expected = "C9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_120_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 120;
	int fromval = 185;
	String expected = "C9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_121_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 121;
	int fromval = 55;
	String expected = "C#9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_121_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 121;
	int fromval = 187;
	String expected = "C#9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_122_fromAbove, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 122;
	int fromval = 56;
	String expected = "D9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_122_fromBelow, PitchFactory )
{
	IPitchFactoryUP factory =
    createPitchFactory( PitchFactoryType::StandardChromatic );
	int value = 122;
	int fromval = 188;
	String expected = "D9";
	factory->setPitch( fromval );
	factory->setPitch( value );
	IPitchUP pitch = factory->createPitch();
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

#endif
