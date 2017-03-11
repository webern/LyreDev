//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/Pitch.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

TEST( defaultConstructor, Pitch )
{
    PitchUP n{ new Pitch{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getOctaveValue() )
    CHECK_EQUAL( 12, n->getValue() )
}
T_END

TEST( constructor01, Pitch )
{
    PitchUP n{ new Pitch{ 1, 2, 4 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    CHECK_EQUAL( 64, n->getValue() )
}
T_END

TEST( constructor02, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getOctaveValue() )
    CHECK_EQUAL( 56, n->getValue() )
}
T_END

TEST( copyConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ orig };
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 84, copy.getValue() )
}
T_END

TEST( moveConstructor, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy{ std::move( orig ) };
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 84, copy.getValue() )
}
T_END

TEST( assignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy = orig;
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 95, orig.getValue() )
    CHECK_EQUAL( 84, copy.getValue() )
}
T_END

TEST( moveAssignment, Pitch )
{
    Pitch orig{ "B6" };
    Pitch copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 95, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 84, copy.getValue() )
}
T_END

TEST( clone, Pitch )
{
    PitchUP orig{ new Pitch{ "B6" } };
    IPitchUP copy;
    CHECK( ! ( copy ) )
    copy = orig->clone();
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 95, orig->getValue() )
    CHECK_EQUAL( 95, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 95, orig->getValue() )
    CHECK_EQUAL( 84, copy->getValue() )
}
T_END

TEST( getValue01, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gddd-2" );
    CHECK_EQUAL( -11, n->getValue() )
}
T_END

TEST( getValue02, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gddb-1" );;
    CHECK_EQUAL( 2, n->getValue() )
}
T_END

TEST( getValue03, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gdd0" );;
    CHECK_EQUAL( 15, n->getValue() )
}
T_END

TEST( getValue04, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gdb1" );;
    CHECK_EQUAL( 28, n->getValue() )
}
T_END

TEST( getValue05, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gd2" );;
    CHECK_EQUAL( 41, n->getValue() )
}
T_END

TEST( getValue06, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gb3" );;
    CHECK_EQUAL( 54, n->getValue() )
}
T_END

TEST( getValue07, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 67, n->getValue() )
}
T_END

TEST( getValue08, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G#5" );;
    CHECK_EQUAL( 80, n->getValue() )
}
T_END

TEST( getValue09, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx6" );;
    CHECK_EQUAL( 93, n->getValue() )
}
T_END

TEST( getValue10, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx#7" );;
    CHECK_EQUAL( 106, n->getValue() )
}
T_END

TEST( getValue11, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxx8" );;
    CHECK_EQUAL( 119, n->getValue() )
}
T_END

TEST( getValue12, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxx#9" );;
    CHECK_EQUAL( 132, n->getValue() )
}
T_END

TEST( getValue13, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gxxx10" );;
    CHECK_EQUAL( 145, n->getValue() )
}
T_END

TEST( getValue14, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dddd-31" );;
    CHECK_EQUAL( -364, n->getValue() )
}
T_END

TEST( getValue15, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dddb-3" );;
    CHECK_EQUAL( -27, n->getValue() )
}
T_END

TEST( getValue16, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ddd-2" );;
    CHECK_EQUAL( -14, n->getValue() )
}
T_END

TEST( getValue17, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ddb-1" );;
    CHECK_EQUAL( -1, n->getValue() )
}
T_END

TEST( getValue18, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dd0" );;
    CHECK_EQUAL( 12, n->getValue() )
}
T_END

TEST( getValue19, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Db1" );;
    CHECK_EQUAL( 25, n->getValue() )
}
T_END

TEST( getValue20, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D2" );;
    CHECK_EQUAL( 38, n->getValue() )
}
T_END

TEST( getValue21, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D#3" );;
    CHECK_EQUAL( 51, n->getValue() )
}
T_END

TEST( getValue22, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dx4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
T_END

TEST( getValue23, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dx#5" );;
    CHECK_EQUAL( 77, n->getValue() )
}
T_END

TEST( getValue24, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxx6" );;
    CHECK_EQUAL( 90, n->getValue() )
}
T_END

TEST( getValue25, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxx#7" );;
    CHECK_EQUAL( 103, n->getValue() )
}
T_END

TEST( getValue26, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Dxxx8" );;
    CHECK_EQUAL( 116, n->getValue() )
}
T_END

TEST( getValue27, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "B#9" );;
    CHECK_EQUAL( 132, n->getValue() )
}
T_END

TEST( getValue28, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "C10" );;
    CHECK_EQUAL( 132, n->getValue() )
}
T_END

TEST( getValue29, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Db4" );;
    CHECK_EQUAL( 61, n->getValue() )
}
T_END

TEST( getValue30, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "C#4" );;
    CHECK_EQUAL( 61, n->getValue() )
}
T_END

TEST( getValue31, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D4" );;
    CHECK_EQUAL( 62, n->getValue() )
}
T_END

TEST( getValue32, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Cx4" );;
    CHECK_EQUAL( 62, n->getValue() )
}
T_END

TEST( getValue33, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Eb4" );;
    CHECK_EQUAL( 63, n->getValue() )
}
T_END

TEST( getValue34, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "D#4" );;
    CHECK_EQUAL( 63, n->getValue() )
}
T_END

TEST( getValue37, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "E4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
T_END

TEST( getValue38, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Fb4" );;
    CHECK_EQUAL( 64, n->getValue() )
}
T_END

TEST( getValue39, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "F4" );;
    CHECK_EQUAL( 65, n->getValue() )
}
T_END

TEST( getValue40, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "E#4" );;
    CHECK_EQUAL( 65, n->getValue() )
}
T_END

TEST( getValue41, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gb4" );;
    CHECK_EQUAL( 66, n->getValue() )
}
T_END

TEST( getValue42, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "F#4" );;
    CHECK_EQUAL( 66, n->getValue() )
}
T_END

TEST( getValue43, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G4" );;
    CHECK_EQUAL( 67, n->getValue() )
}
T_END

TEST( getValue44, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ad4" );;
    CHECK_EQUAL( 67, n->getValue() )
}
T_END

TEST( getValue45, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Ab4" );;
    CHECK_EQUAL( 68, n->getValue() )
}
T_END

TEST( getValue46, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "G#4" );;
    CHECK_EQUAL( 68, n->getValue() )
}
T_END

TEST( getValue47, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "A4" );;
    CHECK_EQUAL( 69, n->getValue() )
}
T_END

TEST( getValue48, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Gx4" );;
    CHECK_EQUAL( 69, n->getValue() )
}
T_END

TEST( getValue49, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Bb4" );;
    CHECK_EQUAL( 70, n->getValue() )
}
T_END

TEST( getValue50, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "A#4" );;
    CHECK_EQUAL( 70, n->getValue() )
}
T_END

TEST( getValue51, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "B4" );;
    CHECK_EQUAL( 71, n->getValue() )
}
T_END

TEST( getValue52, Pitch )
{
    PitchUP n{ new Pitch{} };
    n->parse( "Cb4" );;
    CHECK_EQUAL( 59, n->getValue() )
}
T_END

TEST( parse_fail01, Pitch )
{
    PitchUP n{ new Pitch{ "F4" } };
    CHECK_EQUAL( 65, n->getValue() )
    CHECK( ! n->parse( "Cbd3" ) )
    CHECK_EQUAL( 65, n->getValue() )
}
T_END

TEST( parse_fail02, Pitch )
{
    PitchUP n{ new Pitch{ "F#2" } };
    CHECK_EQUAL( 42, n->getValue() )
    CHECK( ! n->parse( "B-" ) )
    CHECK_EQUAL( 42, n->getValue() )
}
T_END

TEST( parse_fail03, Pitch )
{
    PitchUP n{ new Pitch{ "G6" } };
    CHECK_EQUAL( 91, n->getValue() )
    CHECK( ! n->parse( "#6" ) )
    CHECK_EQUAL( 91, n->getValue() )
}
T_END

TEST( parse_fail04, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "Ab" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
T_END

TEST( parse_fail05, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "F-0" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
T_END

TEST( parse_fail06, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "G01" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
T_END

TEST( parse_fail07, Pitch )
{
    PitchUP n{ new Pitch{ "Ab3" } };
    CHECK_EQUAL( 56, n->getValue() )
    CHECK( ! n->parse( "G0-1" ) )
    CHECK_EQUAL( 56, n->getValue() )
}
T_END

TEST( parse_success01, Pitch )
{
    PitchUP n{ new Pitch{ "F1" } };
    CHECK_EQUAL( 29, n->getValue() )
    CHECK( n->parse( "B#3" ) )
    CHECK_EQUAL( 60, n->getValue() )
}
T_END

TEST( parse_success02, Pitch )
{
    PitchUP n{ new Pitch{ "F#-1" } };
    CHECK_EQUAL( 6, n->getValue() )
    CHECK( n->parse( "Bb2" ) )
    CHECK_EQUAL( 46, n->getValue() )
}
T_END

TEST( parse_success03, Pitch )
{
    PitchUP n{ new Pitch{ "G" } };
    CHECK_EQUAL( 12, n->getValue() )
    CHECK( n->parse( "C#-1000" ) )
    CHECK_EQUAL( -11987, n->getValue() )
}
T_END

TEST( parse_success04, Pitch )
{
    PitchUP n{ new Pitch{ "Ab-1" } };
    CHECK_EQUAL( 8, n->getValue() )
    CHECK( n->parse( "Cdb1537" ) )
    CHECK_EQUAL( 18453, n->getValue() )
}
T_END

TEST( toStream00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream01, Pitch )
{
    String str = "Cxxx-1";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream02, Pitch )
{
    String str = "G#5";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream03, Pitch )
{
    String str = "Bb-2";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream04, Pitch )
{
    String str = "Ed6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream05, Pitch )
{
    String str = "Fb0";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream06, Pitch )
{
    String str = "Gb7";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream07, Pitch )
{
    String str = "B8";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream08, Pitch )
{
    String str = "A10";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream09, Pitch )
{
    String str = "Axxxxxxx9487";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream10, Pitch )
{
    String str = "Edddddddddddddb-7581";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    n->toStream( ss );
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator01, Pitch )
{
    String str = "Cxxx5";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator02, Pitch )
{
    String str = "G#6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator03, Pitch )
{
    String str = "Bb1024";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator04, Pitch )
{
    String str = "Ed-123";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator05, Pitch )
{
    String str = "Fb6";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator06, Pitch )
{
    String str = "Gb3";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator07, Pitch )
{
    String str = "B76";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator08, Pitch )
{
    String str = "A8";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator09, Pitch )
{
    String str = "Axxxxxxx-1073";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator10, Pitch )
{
    String str = "Edddddddddddddb336";
    PitchUP n{ new Pitch{ str } };
    stringstream ss;
    ss << (*n);
    String expected = str;
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString00, Pitch )
{
    String str = "Bb4";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString01, Pitch )
{
    String str = "Cxxx5";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString02, Pitch )
{
    String str = "G#3";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString03, Pitch )
{
    String str = "Bb6";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString04, Pitch )
{
    String str = "Ed1";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString05, Pitch )
{
    String str = "Fb9";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString06, Pitch )
{
    String str = "Gb0";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString07, Pitch )
{
    String str = "B-1";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString08, Pitch )
{
    String str = "A-2";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString09, Pitch )
{
    String str = "Axxxxxxx-4568";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString10, Pitch )
{
    String str = "Edddddddddddddb2459";
    PitchUP n{ new Pitch{ str } };
    String expected = str;
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( compare_a_isLessThan_b_01, Pitch )
{
    String a_str = "Cb4";
    String b_str = "B#3";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( compare_a_isLessThan_b_02, Pitch )
{
    String a_str = "Axx4";
    String b_str = "D5";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK(   ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( compare_a_isEqualTo_b_01, Pitch )
{
    String a_str = "F#6";
    String b_str = "Gb6";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( compare_a_isEqualTo_b_02, Pitch )
{
    String a_str = "Cd-3";
    String b_str = "Gx#-4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK(   ( a->isEqualTo( *b ) ) )
    CHECK( ! ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( compare_a_isGreaterThan_b_01, Pitch )
{
    String a_str = "C4";
    String b_str = "Gdddd4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( compare_a_isGreaterThan_b_02, Pitch )
{
    String a_str = "F4";
    String b_str = "E4";
    IPitchUP a{ new Pitch{ a_str } };
    IPitchUP b{ new Pitch{ b_str } };
    CHECK( ! ( a->isLessThan( *b ) ) )
    CHECK( ! ( a->isEqualTo( *b ) ) )
    CHECK(   ( a->isGreaterThan( *b ) ) )
}
T_END

TEST( getStepValue0, Pitch )
{
    String str = "C2";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 0, n->getStepValue() )
}
T_END

TEST( getStepValue1, Pitch )
{
    String str = "Db1";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 1, n->getStepValue() )
}
T_END

TEST( getStepValue2, Pitch )
{
    String str = "E#3";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 2, n->getStepValue() )
}
T_END

TEST( getStepValue3, Pitch )
{
    String str = "F4";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 3, n->getStepValue() )
}
T_END

TEST( getStepValue4, Pitch )
{
    String str = "Gb5";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 4, n->getStepValue() )
}
T_END

TEST( getStepValue5, Pitch )
{
    String str = "A#-1";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 5, n->getStepValue() )
}
T_END

TEST( getStepValue6, Pitch )
{
    String str = "B-2";
    IPitchUP n{ new Pitch{ str } };
    CHECK_EQUAL( 6, n->getStepValue() )
}
T_END

TEST( setStepValue0, Pitch )
{
    String str = "F1";
    int setTo = 0;
    int expected = 0;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setStepValue1, Pitch )
{
    String str = "G2";
    int setTo = 7;
    int expected = 6;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setStepValue2, Pitch )
{
    String str = "D3";
    int setTo = -1;
    int expected = 0;
    IPitchUP n{ new Pitch{ str } };
    n->setStepValue( setTo );
    int actual = n->getStepValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( incrementStep, Pitch )
{
    IPitchUP n{ new Pitch{ "C4" } };
    n->incrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
    n->incrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getOctaveValue() )
}
T_END

TEST( decrementStep, Pitch )
{
    IPitchUP n{ new Pitch{ "C-1" } };
    n->decrementStep();
    CHECK_EQUAL( 6, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
    n->decrementStep();
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( -1, n->getOctaveValue() )
}
T_END

TEST( getAlterValue00, Pitch )
{
    String str{ "C8" };
    int expected = 0;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue01, Pitch )
{
    String str{ "Fb4" };
    int expected = -1;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue02, Pitch )
{
    String str{ "G#5" };
    int expected = 1;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue03, Pitch )
{
    String str{ "Bd-101" };
    int expected = -2;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue04, Pitch )
{
    String str{ "Ax12" };
    int expected = 2;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue05, Pitch )
{
    String str{ "Ddb3" };
    int expected = -3;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue06, Pitch )
{
    String str{ "Cx#7" };
    int expected = 3;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue07, Pitch )
{
    String str{ "Edd3" };
    int expected = -4;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue08, Pitch )
{
    String str{ "Fxx1013" };
    int expected = 4;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue09, Pitch )
{
    String str{ "Cddb-321" };
    int expected = -5;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getAlterValue10, Pitch )
{
    String str{ "Cxx#8" };
    int expected = 5;
    IPitchUP n{ new Pitch{ str } };
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue01, Pitch )
{
    String str{ "Cxx#4" };
    int setTo = 3;
    int expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue02, Pitch )
{
    String str{ "Cx1" };
    int setTo = 0;
    int expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue03, Pitch )
{
    String str{ "Gb2" };
    int setTo = 100;
    int expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( setAlterValue04, Pitch )
{
    String str{ "Gb3" };
    int setTo = -100;
    int expected = setTo;
    IPitchUP n{ new Pitch{ str } };
    n->setAlterValue( setTo );
    int actual = n->getAlterValue();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( incrementAlter, Pitch )
{
    IPitchUP n{ new Pitch{ "Eddd9" } };
    n->incrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( 6, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->setAlterValue( std::numeric_limits<int>::max() );
    CHECK_EQUAL( std::numeric_limits<int>::max(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
    n->incrementAlter();
    CHECK_EQUAL( std::numeric_limits<int>::min(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( 9, n->getOctaveValue() )
}
T_END

TEST( decrementAlter, Pitch )
{
    IPitchUP n{ new Pitch{ "Exxx-2" } };
    n->decrementAlter();
    CHECK_EQUAL( 5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( 0, n->getAlterValue() )
    n->decrementAlter();
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -2, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -3, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -4, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -5, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( -6, n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->setAlterValue( std::numeric_limits<int>::min() );
    CHECK_EQUAL( std::numeric_limits<int>::min(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
    n->decrementAlter();
    CHECK_EQUAL( std::numeric_limits<int>::max(), n->getAlterValue() )
    CHECK_EQUAL( 2, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
}
T_END

TEST( getOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "Gx-2" } };
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getStepValue() )
    CHECK_EQUAL( -2, n->getOctaveValue() )
}
T_END

TEST( setOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->setOctaveValue( -1 );
    CHECK_EQUAL( -1, n->getOctaveValue() )
}
T_END

TEST( incrementOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->incrementOctave();
    CHECK_EQUAL( 8, n->getOctaveValue() )
}
T_END

TEST( decrementOctave, Pitch )
{
    IPitchUP n{ new Pitch{ "F#7" } };
    CHECK_EQUAL( 1, n->getAlterValue() )
    CHECK_EQUAL( 3, n->getStepValue() )
    CHECK_EQUAL( 7, n->getOctaveValue() )
    n->decrementOctave();
    CHECK_EQUAL( 6, n->getOctaveValue() )
}
T_END

TEST( isIdenticalTo_true01, Pitch )
{
    IPitchUP a{ new Pitch{ "C4" } };
    IPitchUP b{ new Pitch{ "C4" } };
    CHECK( a->isIdenticalTo( *b ) )
}
T_END

TEST( isIdenticalTo_false01, Pitch )
{
    IPitchUP a{ new Pitch{ "C4" } };
    IPitchUP b{ new Pitch{ "B#3" } };
    CHECK( a->isEqualTo( *b ) );
    CHECK( ! a->isIdenticalTo( *b ) )
}
T_END

TEST( VALUE_N10_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -10;
	int fromval = -10;
	String expected = "D-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N10_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -10;
	int fromval = -10;
	String expected = "D-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N9_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -9;
	int fromval = -10;
	String expected = "Eb-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N9_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -9;
	int fromval = -8;
	String expected = "Eb-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N8_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -8;
	int fromval = -9;
	String expected = "E-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N8_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -8;
	int fromval = -7;
	String expected = "E-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N7_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -7;
	int fromval = -9;
	String expected = "F-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N7_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -7;
	int fromval = -5;
	String expected = "F-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N6_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -6;
	int fromval = -8;
	String expected = "F#-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N6_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -6;
	int fromval = -4;
	String expected = "F#-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N5_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -5;
	int fromval = -8;
	String expected = "G-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N5_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -5;
	int fromval = -2;
	String expected = "G-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N4_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -4;
	int fromval = -7;
	String expected = "Ab-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N4_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -4;
	int fromval = -1;
	String expected = "Ab-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N3_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -3;
	int fromval = -7;
	String expected = "A-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N3_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -3;
	int fromval = 1;
	String expected = "A-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N2_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -2;
	int fromval = -6;
	String expected = "Bb-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N2_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -2;
	int fromval = 2;
	String expected = "Bb-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N1_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -1;
	int fromval = -6;
	String expected = "B-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_N1_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = -1;
	int fromval = 4;
	String expected = "B-2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_0_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 0;
	int fromval = -5;
	String expected = "C-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_0_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 0;
	int fromval = 5;
	String expected = "C-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_1_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 1;
	int fromval = -5;
	String expected = "C#-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_1_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 1;
	int fromval = 7;
	String expected = "C#-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_2_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 2;
	int fromval = -4;
	String expected = "D-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_2_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 2;
	int fromval = 8;
	String expected = "D-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_3_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 3;
	int fromval = -4;
	String expected = "Eb-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_3_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 3;
	int fromval = 10;
	String expected = "Eb-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_4_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 4;
	int fromval = -3;
	String expected = "E-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_4_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 4;
	int fromval = 11;
	String expected = "E-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_5_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 5;
	int fromval = -3;
	String expected = "F-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_5_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 5;
	int fromval = 13;
	String expected = "F-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_6_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 6;
	int fromval = -2;
	String expected = "F#-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_6_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 6;
	int fromval = 14;
	String expected = "F#-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_7_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 7;
	int fromval = -2;
	String expected = "G-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_7_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 7;
	int fromval = 16;
	String expected = "G-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_8_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 8;
	int fromval = -1;
	String expected = "Ab-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_8_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 8;
	int fromval = 17;
	String expected = "Ab-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_9_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 9;
	int fromval = -1;
	String expected = "A-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_9_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 9;
	int fromval = 19;
	String expected = "A-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_10_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 10;
	int fromval = 0;
	String expected = "Bb-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_10_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 10;
	int fromval = 20;
	String expected = "Bb-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_11_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 11;
	int fromval = 0;
	String expected = "B-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_11_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 11;
	int fromval = 22;
	String expected = "B-1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_12_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 12;
	int fromval = 1;
	String expected = "C0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_12_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 12;
	int fromval = 23;
	String expected = "C0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_13_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 13;
	int fromval = 1;
	String expected = "C#0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_13_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 13;
	int fromval = 25;
	String expected = "C#0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_14_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 14;
	int fromval = 2;
	String expected = "D0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_14_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 14;
	int fromval = 26;
	String expected = "D0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_15_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 15;
	int fromval = 2;
	String expected = "Eb0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_15_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 15;
	int fromval = 28;
	String expected = "Eb0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_16_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 16;
	int fromval = 3;
	String expected = "E0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_16_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 16;
	int fromval = 29;
	String expected = "E0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_17_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 17;
	int fromval = 3;
	String expected = "F0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_17_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 17;
	int fromval = 31;
	String expected = "F0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_18_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 18;
	int fromval = 4;
	String expected = "F#0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_18_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 18;
	int fromval = 32;
	String expected = "F#0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_19_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 19;
	int fromval = 4;
	String expected = "G0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_19_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 19;
	int fromval = 34;
	String expected = "G0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_20_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 20;
	int fromval = 5;
	String expected = "Ab0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_20_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 20;
	int fromval = 35;
	String expected = "Ab0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_21_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 21;
	int fromval = 5;
	String expected = "A0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_21_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 21;
	int fromval = 37;
	String expected = "A0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_22_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 22;
	int fromval = 6;
	String expected = "Bb0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_22_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 22;
	int fromval = 38;
	String expected = "Bb0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_23_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 23;
	int fromval = 6;
	String expected = "B0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_23_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 23;
	int fromval = 40;
	String expected = "B0";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_24_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 24;
	int fromval = 7;
	String expected = "C1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_24_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 24;
	int fromval = 41;
	String expected = "C1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_25_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 25;
	int fromval = 7;
	String expected = "C#1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_25_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 25;
	int fromval = 43;
	String expected = "C#1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_26_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 26;
	int fromval = 8;
	String expected = "D1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_26_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 26;
	int fromval = 44;
	String expected = "D1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_27_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 27;
	int fromval = 8;
	String expected = "Eb1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_27_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 27;
	int fromval = 46;
	String expected = "Eb1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_28_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 28;
	int fromval = 9;
	String expected = "E1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_28_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 28;
	int fromval = 47;
	String expected = "E1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_29_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 29;
	int fromval = 9;
	String expected = "F1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_29_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 29;
	int fromval = 49;
	String expected = "F1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_30_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 30;
	int fromval = 10;
	String expected = "F#1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_30_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 30;
	int fromval = 50;
	String expected = "F#1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_31_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 31;
	int fromval = 10;
	String expected = "G1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_31_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 31;
	int fromval = 52;
	String expected = "G1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_32_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 32;
	int fromval = 11;
	String expected = "Ab1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_32_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 32;
	int fromval = 53;
	String expected = "Ab1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_33_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 33;
	int fromval = 11;
	String expected = "A1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_33_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 33;
	int fromval = 55;
	String expected = "A1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_34_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 34;
	int fromval = 12;
	String expected = "Bb1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_34_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 34;
	int fromval = 56;
	String expected = "Bb1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_35_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 35;
	int fromval = 12;
	String expected = "B1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_35_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 35;
	int fromval = 58;
	String expected = "B1";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_36_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 36;
	int fromval = 13;
	String expected = "C2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_36_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 36;
	int fromval = 59;
	String expected = "C2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_37_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 37;
	int fromval = 13;
	String expected = "C#2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_37_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 37;
	int fromval = 61;
	String expected = "C#2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_38_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 38;
	int fromval = 14;
	String expected = "D2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_38_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 38;
	int fromval = 62;
	String expected = "D2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_39_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 39;
	int fromval = 14;
	String expected = "Eb2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_39_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 39;
	int fromval = 64;
	String expected = "Eb2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_40_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 40;
	int fromval = 15;
	String expected = "E2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_40_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 40;
	int fromval = 65;
	String expected = "E2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_41_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 41;
	int fromval = 15;
	String expected = "F2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_41_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 41;
	int fromval = 67;
	String expected = "F2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_42_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 42;
	int fromval = 16;
	String expected = "F#2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_42_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 42;
	int fromval = 68;
	String expected = "F#2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_43_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 43;
	int fromval = 16;
	String expected = "G2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_43_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 43;
	int fromval = 70;
	String expected = "G2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_44_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 44;
	int fromval = 17;
	String expected = "Ab2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_44_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 44;
	int fromval = 71;
	String expected = "Ab2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_45_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 45;
	int fromval = 17;
	String expected = "A2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_45_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 45;
	int fromval = 73;
	String expected = "A2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_46_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 46;
	int fromval = 18;
	String expected = "Bb2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_46_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 46;
	int fromval = 74;
	String expected = "Bb2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_47_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 47;
	int fromval = 18;
	String expected = "B2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_47_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 47;
	int fromval = 76;
	String expected = "B2";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_48_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 48;
	int fromval = 19;
	String expected = "C3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_48_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 48;
	int fromval = 77;
	String expected = "C3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_49_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 49;
	int fromval = 19;
	String expected = "C#3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_49_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 49;
	int fromval = 79;
	String expected = "C#3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_50_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 50;
	int fromval = 20;
	String expected = "D3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_50_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 50;
	int fromval = 80;
	String expected = "D3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_51_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 51;
	int fromval = 20;
	String expected = "Eb3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_51_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 51;
	int fromval = 82;
	String expected = "Eb3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_52_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 52;
	int fromval = 21;
	String expected = "E3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_52_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 52;
	int fromval = 83;
	String expected = "E3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_53_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 53;
	int fromval = 21;
	String expected = "F3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_53_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 53;
	int fromval = 85;
	String expected = "F3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_54_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 54;
	int fromval = 22;
	String expected = "F#3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_54_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 54;
	int fromval = 86;
	String expected = "F#3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_55_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 55;
	int fromval = 22;
	String expected = "G3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_55_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 55;
	int fromval = 88;
	String expected = "G3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_56_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 56;
	int fromval = 23;
	String expected = "Ab3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_56_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 56;
	int fromval = 89;
	String expected = "Ab3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_57_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 57;
	int fromval = 23;
	String expected = "A3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_57_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 57;
	int fromval = 91;
	String expected = "A3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_58_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 58;
	int fromval = 24;
	String expected = "Bb3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_58_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 58;
	int fromval = 92;
	String expected = "Bb3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_59_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 59;
	int fromval = 24;
	String expected = "B3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_59_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 59;
	int fromval = 94;
	String expected = "B3";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_60_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 60;
	int fromval = 25;
	String expected = "C4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_60_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 60;
	int fromval = 95;
	String expected = "C4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_61_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 61;
	int fromval = 25;
	String expected = "C#4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_61_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 61;
	int fromval = 97;
	String expected = "C#4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_62_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 62;
	int fromval = 26;
	String expected = "D4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_62_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 62;
	int fromval = 98;
	String expected = "D4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_63_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 63;
	int fromval = 26;
	String expected = "Eb4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_63_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 63;
	int fromval = 100;
	String expected = "Eb4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_64_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 64;
	int fromval = 27;
	String expected = "E4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_64_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 64;
	int fromval = 101;
	String expected = "E4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_65_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 65;
	int fromval = 27;
	String expected = "F4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_65_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 65;
	int fromval = 103;
	String expected = "F4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_66_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 66;
	int fromval = 28;
	String expected = "F#4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_66_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 66;
	int fromval = 104;
	String expected = "F#4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_67_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 67;
	int fromval = 28;
	String expected = "G4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_67_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 67;
	int fromval = 106;
	String expected = "G4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_68_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 68;
	int fromval = 29;
	String expected = "Ab4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_68_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 68;
	int fromval = 107;
	String expected = "Ab4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_69_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 69;
	int fromval = 29;
	String expected = "A4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_69_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 69;
	int fromval = 109;
	String expected = "A4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_70_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 70;
	int fromval = 30;
	String expected = "Bb4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_70_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 70;
	int fromval = 110;
	String expected = "Bb4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_71_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 71;
	int fromval = 30;
	String expected = "B4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_71_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 71;
	int fromval = 112;
	String expected = "B4";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_72_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 72;
	int fromval = 31;
	String expected = "C5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_72_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 72;
	int fromval = 113;
	String expected = "C5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_73_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 73;
	int fromval = 31;
	String expected = "C#5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_73_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 73;
	int fromval = 115;
	String expected = "C#5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_74_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 74;
	int fromval = 32;
	String expected = "D5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_74_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 74;
	int fromval = 116;
	String expected = "D5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_75_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 75;
	int fromval = 32;
	String expected = "Eb5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_75_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 75;
	int fromval = 118;
	String expected = "Eb5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_76_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 76;
	int fromval = 33;
	String expected = "E5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_76_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 76;
	int fromval = 119;
	String expected = "E5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_77_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 77;
	int fromval = 33;
	String expected = "F5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_77_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 77;
	int fromval = 121;
	String expected = "F5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_78_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 78;
	int fromval = 34;
	String expected = "F#5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_78_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 78;
	int fromval = 122;
	String expected = "F#5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_79_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 79;
	int fromval = 34;
	String expected = "G5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_79_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 79;
	int fromval = 124;
	String expected = "G5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_80_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 80;
	int fromval = 35;
	String expected = "Ab5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_80_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 80;
	int fromval = 125;
	String expected = "Ab5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_81_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 81;
	int fromval = 35;
	String expected = "A5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_81_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 81;
	int fromval = 127;
	String expected = "A5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_82_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 82;
	int fromval = 36;
	String expected = "Bb5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_82_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 82;
	int fromval = 128;
	String expected = "Bb5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_83_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 83;
	int fromval = 36;
	String expected = "B5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_83_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 83;
	int fromval = 130;
	String expected = "B5";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_84_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 84;
	int fromval = 37;
	String expected = "C6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_84_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 84;
	int fromval = 131;
	String expected = "C6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_85_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 85;
	int fromval = 37;
	String expected = "C#6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_85_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 85;
	int fromval = 133;
	String expected = "C#6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_86_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 86;
	int fromval = 38;
	String expected = "D6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_86_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 86;
	int fromval = 134;
	String expected = "D6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_87_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 87;
	int fromval = 38;
	String expected = "Eb6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_87_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 87;
	int fromval = 136;
	String expected = "Eb6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_88_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 88;
	int fromval = 39;
	String expected = "E6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_88_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 88;
	int fromval = 137;
	String expected = "E6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_89_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 89;
	int fromval = 39;
	String expected = "F6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_89_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 89;
	int fromval = 139;
	String expected = "F6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_90_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 90;
	int fromval = 40;
	String expected = "F#6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_90_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 90;
	int fromval = 140;
	String expected = "F#6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_91_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 91;
	int fromval = 40;
	String expected = "G6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_91_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 91;
	int fromval = 142;
	String expected = "G6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_92_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 92;
	int fromval = 41;
	String expected = "Ab6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_92_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 92;
	int fromval = 143;
	String expected = "Ab6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_93_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 93;
	int fromval = 41;
	String expected = "A6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_93_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 93;
	int fromval = 145;
	String expected = "A6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_94_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 94;
	int fromval = 42;
	String expected = "Bb6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_94_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 94;
	int fromval = 146;
	String expected = "Bb6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_95_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 95;
	int fromval = 42;
	String expected = "B6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_95_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 95;
	int fromval = 148;
	String expected = "B6";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_96_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 96;
	int fromval = 43;
	String expected = "C7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_96_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 96;
	int fromval = 149;
	String expected = "C7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_97_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 97;
	int fromval = 43;
	String expected = "C#7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_97_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 97;
	int fromval = 151;
	String expected = "C#7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_98_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 98;
	int fromval = 44;
	String expected = "D7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_98_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 98;
	int fromval = 152;
	String expected = "D7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_99_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 99;
	int fromval = 44;
	String expected = "Eb7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_99_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 99;
	int fromval = 154;
	String expected = "Eb7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_100_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 100;
	int fromval = 45;
	String expected = "E7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_100_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 100;
	int fromval = 155;
	String expected = "E7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_101_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 101;
	int fromval = 45;
	String expected = "F7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_101_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 101;
	int fromval = 157;
	String expected = "F7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_102_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 102;
	int fromval = 46;
	String expected = "F#7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_102_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 102;
	int fromval = 158;
	String expected = "F#7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_103_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 103;
	int fromval = 46;
	String expected = "G7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_103_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 103;
	int fromval = 160;
	String expected = "G7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_104_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 104;
	int fromval = 47;
	String expected = "Ab7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_104_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 104;
	int fromval = 161;
	String expected = "Ab7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_105_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 105;
	int fromval = 47;
	String expected = "A7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_105_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 105;
	int fromval = 163;
	String expected = "A7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_106_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 106;
	int fromval = 48;
	String expected = "Bb7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_106_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 106;
	int fromval = 164;
	String expected = "Bb7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_107_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 107;
	int fromval = 48;
	String expected = "B7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_107_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 107;
	int fromval = 166;
	String expected = "B7";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_108_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 108;
	int fromval = 49;
	String expected = "C8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_108_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 108;
	int fromval = 167;
	String expected = "C8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_109_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 109;
	int fromval = 49;
	String expected = "C#8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_109_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 109;
	int fromval = 169;
	String expected = "C#8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_110_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 110;
	int fromval = 50;
	String expected = "D8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_110_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 110;
	int fromval = 170;
	String expected = "D8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_111_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 111;
	int fromval = 50;
	String expected = "Eb8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_111_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 111;
	int fromval = 172;
	String expected = "Eb8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_112_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 112;
	int fromval = 51;
	String expected = "E8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_112_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 112;
	int fromval = 173;
	String expected = "E8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_113_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 113;
	int fromval = 51;
	String expected = "F8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_113_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 113;
	int fromval = 175;
	String expected = "F8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_114_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 114;
	int fromval = 52;
	String expected = "F#8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_114_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 114;
	int fromval = 176;
	String expected = "F#8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_115_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 115;
	int fromval = 52;
	String expected = "G8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_115_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 115;
	int fromval = 178;
	String expected = "G8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_116_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 116;
	int fromval = 53;
	String expected = "Ab8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_116_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 116;
	int fromval = 179;
	String expected = "Ab8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_117_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 117;
	int fromval = 53;
	String expected = "A8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_117_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 117;
	int fromval = 181;
	String expected = "A8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_118_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 118;
	int fromval = 54;
	String expected = "Bb8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_118_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 118;
	int fromval = 182;
	String expected = "Bb8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_119_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 119;
	int fromval = 54;
	String expected = "B8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_119_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 119;
	int fromval = 184;
	String expected = "B8";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_120_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 120;
	int fromval = 55;
	String expected = "C9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_120_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 120;
	int fromval = 185;
	String expected = "C9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_121_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 121;
	int fromval = 55;
	String expected = "C#9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_121_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 121;
	int fromval = 187;
	String expected = "C#9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_122_fromAbove, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 122;
	int fromval = 56;
	String expected = "D9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END

TEST( VALUE_122_fromBelow, Pitch )
{
	IPitchUP pitch{ new Pitch{ "C4" } };
	int value = 122;
	int fromval = 188;
	String expected = "D9";
	pitch->setValue( fromval );
	pitch->setValue( value );
	String actual = pitch->toString();
	CHECK_EQUAL( expected, actual )
}
T_END
