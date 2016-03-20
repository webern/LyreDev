//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Handle.h"
#include <memory>

using namespace Lyre;
using namespace std;

namespace
{
    class TestObject
    {
    public:
        TestObject() : publicValue( 0 ), myValue( 0 ) {}
        int publicValue;
        int getPrivateValue() const { return myValue; }
        void setPrivateValue( const int value ) { myValue = value; }
    private:
        int myValue;
    };
}

TEST( mutablePtrInt, Handle )
{
    int* x = new int{ 1 };
    Handle<int> h{ x };
    *h = 5;
    CHECK_EQUAL( 5, *h )
    delete x;
}
T_END

TEST( mutablePtrObj, Handle )
{
    std::unique_ptr<TestObject> uptr{ new TestObject{} };
    Handle<TestObject> h{ uptr.get() };
    h->publicValue = 10;
    h->setPrivateValue( 11 );
    CHECK_EQUAL( 10, h->publicValue )
    CHECK_EQUAL( 11, h->getPrivateValue() )
}
T_END

TEST( operatorBool, Handle )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	Handle<TestObject> h{ uptr.get() };
	CHECK( h );
	uptr.reset( nullptr );
	
    // unfortunately this is how it works
    // so use the uptr specialization
    CHECK( h );
}
T_END

TEST( operatorBoolUptr, Handle )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	Handle<std::unique_ptr<TestObject>> h{ uptr };
	CHECK( h );
	uptr.reset( nullptr );
	
    // with uptr specialization we get
    // the desired operator bool behavior
    CHECK( !h );
}
T_END

TEST( uptr, Handle )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	Handle<std::unique_ptr<TestObject>> h( uptr );
	CHECK( h );
	CHECK_EQUAL( 0, h->getPrivateValue() );
	auto ptr = uptr.get();
	uptr.release();
	delete ptr;
	CHECK( !h );
}
T_END

TEST( mutablePtrInt, HandleConst )
{
	int* x = new int{ 1 };
	HandleConst<int> h{ x };
	CHECK_EQUAL( 1, *h )
	delete x;
}
T_END

TEST( mutablePtrObj, HandleConst )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	HandleConst<TestObject> h{ uptr.get() };
	CHECK_EQUAL( 0, h->publicValue )
	CHECK_EQUAL( 0, h->getPrivateValue() )
}
T_END



TEST( operatorBool, HandleConst )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	HandleConst<TestObject> h{ uptr.get() };
	CHECK( h );
	uptr.reset( nullptr );
	
    // unfortunately this is how it works
    // so use the uptr specialization
    CHECK( h );
}
T_END

TEST( operatorBoolUptr, HandleConst )
{
	std::unique_ptr<TestObject> uptr{ new TestObject{} };
	HandleConst<std::unique_ptr<TestObject>> h{ uptr };
	CHECK( h );
	uptr.reset( nullptr );
	
    // with uptr specialization we get
    // the desired operator bool behavior
    CHECK( !h );
}
T_END