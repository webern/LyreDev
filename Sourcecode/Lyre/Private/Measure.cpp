#include "Lyre/Private/Measure.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/NoteGroup.h"

namespace Lyre
{
    namespace Private
    {

#define LAYER getLayer()->second

        Measure::~Measure()
        {
            
        }
        
        Measure::Measure( const ITimeSignatureUP& timeSignature )
        :myCurrentLayer( 0 )
        ,myLayers()
        ,myMaxLayers( MAX_NUMBER_OF_LAYERS )
        ,myTimeSignature( timeSignature->clone() )
        ,myMaxDur( timeSignature->getTotalDuration() )
        {
            if ( myMaxLayers <= 0 )
            {
                THROW( "max layers must be positive" )
            }
            initializeLayers();
        }

        Measure::Measure( const Measure& other )
        :myCurrentLayer( other.myCurrentLayer )
        ,myLayers()
        ,myMaxLayers( MAX_NUMBER_OF_LAYERS )
        ,myTimeSignature( other.myTimeSignature->clone() )
        ,myMaxDur( other.myTimeSignature->getTotalDuration() )
        {
            copyLayers( other.myLayers );
        }

        Measure::Measure( Measure&& other )
        :myCurrentLayer( std::move( other.myCurrentLayer ) )
        ,myLayers( std::move( other.myLayers ) )
        ,myMaxLayers( std::move( other.myMaxLayers ) )
        ,myTimeSignature( std::move( other.myTimeSignature ) )
        ,myMaxDur( std::move( other.myMaxDur ) )
        {
            
        }

        Measure& Measure::operator=( const Measure& other )
        {
            myCurrentLayer = other.myCurrentLayer;
            copyLayers( other.myLayers );
            myTimeSignature = other.myTimeSignature->clone();
            myMaxDur = other.myMaxDur;
            return *this;
        }

        Measure& Measure::operator=( Measure&& other )
        {
            myCurrentLayer = std::move( other.myCurrentLayer );
            myLayers = std::move( other.myLayers );
            myTimeSignature = std::move( other.myTimeSignature );
            myMaxDur = std::move( other.myMaxDur );
            return *this;
        }

        IMeasureUP Measure::clone() const
        {
            return IMeasureUP{ new Measure{ *this } };
        }

        IMeasureUP Measure::move()
        {
            Measure* measureP = new Measure( myTimeSignature );
            measureP->myCurrentLayer = std::move( myCurrentLayer );
            measureP->myLayers = std::move( myLayers );
            myCurrentLayer = 0;
            myLayers = Layers();
            return IMeasureUP( measureP );
        }

        std::ostream& Measure::toStream( std::ostream& os ) const
        {
            String line;
            os << "Measure" << std::endl;
            os << "{" << std::endl;
            for ( int i = 0; i < myMaxLayers; ++i )
            {
                auto iter = myLayers.find( i );
                if ( iter != myLayers.cend() && !iter->second->getIsEmpty() )
                {
                    os << "  Layer " << i << std::endl;
                    os << "  {" << std::endl;
                    std::istringstream ss( iter->second->toString() );
                    while( std::getline( ss, line ) )
                    {
                        os << "      " << line << std::endl;
                    }
                    os << "  }" << std::endl;
                }
            }
            os << "}";
            return os;
        }
        
        void Measure::setLayerContext( int layer )
        {
            if ( layer < 0 || layer > myMaxLayers - 1 )
            {
                THROW( "index out of range" )
            }
            myCurrentLayer = layer;
        }
        
        int Measure::getLayerContext() const
        {
            return myCurrentLayer;
        }

        ITimeSignatureUP Measure::getTimeSignature() const
        {
            return myTimeSignature->clone();
        }
        
        void Measure::clearLayer()
        {
            LAYER->clear();
        }
        
        void Measure::clearMeasure()
        {
            for ( auto it = myLayers.begin(); it != myLayers.end(); ++it )
            {
                it->second->clear();
            }
        }
        
        bool Measure::getIsEmpty() const
        {
            return LAYER->getIsEmpty();
        }

        bool Measure::getIsComplete() const
        {
            return getTotalDuration() == myMaxDur;
        }
        
        int Measure::getCount() const
        {
            return LAYER->getCount();
        }
        
        Rational Measure::getUnusedRemaining() const
        {
            auto maxDuration = myTimeSignature->getTotalDuration();
            return  maxDuration - getTotalDuration();
        }
        
        Rational Measure::getTotalDuration() const
        {
            return LAYER->getTotalDuration();
        }
        
        const INoteUP& Measure::getNote( int noteIndex ) const
        {
            return LAYER->getNote( noteIndex );
        }
        
        void Measure::addNote( const INoteUP& note )
        {
            THROW_IF_NULL( note );
            Rational curTot = LAYER->getTotalDuration();
            Rational noteDur = note->getDuration()->getValue();
            if ( ( curTot + noteDur ) <= myMaxDur )
            {
                LAYER->addNote( note );
            }
            else
            {
                THROW( "beyond capacity" )
            }
        }
        
        void Measure::removeNote( int noteIndex )
        {
            LAYER->removeNote( noteIndex );
        }
        
        int Measure::getGroupCount() const
        {
            return LAYER->getGroupCount();
        }
        
        bool Measure::getIsInGroup( int noteIndex ) const
        {
            return LAYER->getIsInGroup( noteIndex );
        }
        
        int Measure::getGroupIndex( int noteIndex ) const
        {
            return LAYER->getGroupIndex( noteIndex );
        }
        
        const INoteGroupUP& Measure::getGroup( int groupIndex ) const
        {
            return LAYER->getGroup( groupIndex );
        }
        
        void Measure::addGroup( const INoteGroupUP& group )
        {
            THROW_IF_NULL( group )
            Rational curTot = LAYER->getTotalDuration();
            Rational groupDur = group->getTotalDuration();
            if ( ( curTot + groupDur ) <= myMaxDur )
            {
                LAYER->addGroup( group );
            }
            else
            {
                THROW( "beyond capacity" )
            }
        }
        
        void Measure::removeGroup( int groupIndex )
        {
            LAYER->removeGroup( groupIndex );
        }
        
        LayerIter Measure::getLayer()
        {
            LayerIter it = myLayers.find( myCurrentLayer );
            if ( it == myLayers.end() )
            {
                THROW( "bad internal state" )
            }
            return it;
        }
        
        LayerIterConst Measure::getLayer() const
        {
            LayerIterConst it = myLayers.find( myCurrentLayer );
            if ( it == myLayers.cend() )
            {
                THROW( "bad internal state" )
            }
            return it;
        }
        
        void Measure::copyLayers( const Layers& layers )
        {
            myLayers.clear();
            for ( auto i = layers.cbegin(); i != layers.cend(); ++i )
            {
                if ( i->second )
                {
                    myLayers[i->first] = i->second->clone();
                }
            }
        }
        
        void Measure::initializeLayers()
        {
            myLayers.clear();
            for ( int i = 0; i < myMaxLayers; ++i )
            {
                myLayers[i] = INoteGroupUP{ new NoteGroup{} };
            }
        }
    }
}
