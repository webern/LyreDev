//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/NoteGroup.h"

#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
    struct Factories
    {
        IMeasureFactoryUP measureFactory;
        ITimeSignatureFactoryUP timeSignatureFactory;
        INoteFactoryUP noteFactory;
        IPitchFactoryUP pitchFactory;
        IDurationFactoryUP durationFactory;

        Factories()
            :measureFactory( createMeasureFactory() )
            ,timeSignatureFactory( createTimeSignatureFactory() )
            ,noteFactory( createNoteFactory() )
            ,pitchFactory( createPitchFactory() )
            ,durationFactory( createDurationFactory() )
        {}

        inline IMeasureUP defaultMeasure()
        {
            return measureFactory->create();
        }

        inline IMeasureUP fourFour()
        {
            return measureFactory->create( 4, 4 );
        }

        inline IMeasureUP threeFour()
        {
            auto timeSig = timeSignatureFactory->create( 3, 4 );
            return measureFactory->create( timeSig );
        }

        inline IMeasureUP sevenEight()
        {
            auto timeSig = timeSignatureFactory->create( 7, 8 );
            return measureFactory->create( timeSig );
        }
        
        inline INoteUP note( int pitchValue, String durValue )
        {
            pitchFactory->setPitch( pitchValue );
            auto p = pitchFactory->createPitch();
            auto d = durationFactory->createDuration( durValue );
            return noteFactory->createNote( p, d );
        }
        
        inline INoteGroupUP noteGroup1()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 1, "Quarter") );
            noteGroup->addNote( note( 2, "Quarter") );
            noteGroup->addNote( note( 3, "Quarter") );
            return std::move( noteGroup );
        }
        
        inline INoteGroupUP noteGroup2()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 11, "Eighth") );
            noteGroup->addNote( note( 12, "Eighth") );
            noteGroup->addNote( note( 13, "Eighth") );
            return std::move( noteGroup );
        }
        
        inline INoteGroupUP noteGroup3()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 21, "16th") );
            noteGroup->addNote( note( 22, "16th") );
            noteGroup->addNote( note( 23, "16th") );
            return std::move( noteGroup );
        }
        
        inline IMeasureUP measureA()
        {
            auto m = threeFour();
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup2() );
            return m;
        }
        
        inline IMeasureUP measureB()
        {
            auto m = sevenEight();
            m->setLayerContext( 1 );
            m->addGroup( noteGroup1() );
            m->removeNote( 0 );
            m->addGroup( noteGroup2() );
            m->setLayerContext( 2 );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addNote( note( 55, "Eighth" ) );
            return m;
        }
    };
}

TEST( getTimeSignature_default, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_fourFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_threeFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 3, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_sevenEight, Measure )
{
    Factories f;
    IMeasureUP measure = f.sevenEight();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 7, timeSig->getTop() )
    CHECK_EQUAL( 8, timeSig->getBottom() )
}
T_END

TEST( getSetLayerContext_default, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_0, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    measure->setLayerContext( 1 );
    measure->setLayerContext( 0 );
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_1, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    measure->setLayerContext( 1 );
    CHECK_EQUAL( 1, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_throwNegative, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    try
    {
        measure->setLayerContext( -1 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        ;
    }
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_throwPositive, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    int tooBig = MAX_NUMBER_OF_LAYERS;
    try
    {
        measure->setLayerContext( tooBig );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        String msg = e.what();
        CHECK( msg.size() > 0 )
    }
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( toStreamA, Measure )
{
    Factories f;
    IMeasureUP m = f.measureA();
    std::stringstream ss;
    m->toStream( ss );
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 0" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStreamB, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    std::stringstream ss;
    m->toStream( ss );
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 1" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ D-1 : Quarter }" << std::endl;
    ex << w6 << "{ Eb-1 : Quarter }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << w2 << "Layer 2" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ G3 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStringA, Measure )
{
    Factories f;
    IMeasureUP m = f.measureA();
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 0" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = m->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperatorB, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    std::stringstream ss;
    ss << (*m);
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 1" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ D-1 : Quarter }" << std::endl;
    ex << w6 << "{ Eb-1 : Quarter }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << w2 << "Layer 2" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ G3 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
