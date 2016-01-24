//PRIVATE
#include "Lyre/Private/Note.h"
#include "Lyre/INoteGroup.h"
#include "Lyre/INoteIter.h"

namespace Lyre
{
    FORWARD_DECLARE(MockNoteGroup)
    class MockNoteGroup : public INoteGroup
    {
    public:
        virtual INoteGroupUP clone() const;
        virtual bool getIsEmpty() const;
        virtual int getCount() const;
        virtual Rational getDurationValue() const;
        virtual void add( const INoteSP& note );
        virtual void remove( const INoteSP& note );
        virtual INoteIterUP getIterator() const;

    protected:
        virtual const INoteSP getNote( int index ) const;
    
    private:
        VecINoteSP myNotes;
        int size() const;
    };
}