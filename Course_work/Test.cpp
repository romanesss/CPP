#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

#include "QueueP.h"

BOOST_AUTO_TEST_SUITE(IsEmpty)
BOOST_AUTO_TEST_CASE(isEmptyTest_Empty)
{
	QueueP Container;
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), true);
}

BOOST_AUTO_TEST_CASE(isEmptyTest_notEmpty)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);
	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskOne);
	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Amount)
BOOST_AUTO_TEST_CASE(AmountTest_Empty)
{
	QueueP Container;

	BOOST_REQUIRE_EQUAL(Container.getAmount(), 0);
}
BOOST_AUTO_TEST_CASE(AmountTest_notEmpty)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);
	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskOne);
	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 2);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Push)
BOOST_AUTO_TEST_CASE(PushGuarantee)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);

	Container.Push(taskOne);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
}
BOOST_AUTO_TEST_CASE(PushRegulation)
{
	QueueP Container;

	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Pop)
BOOST_AUTO_TEST_CASE(PopGuarantee)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);

	Container.Push(taskOne);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
	Container.Pop();
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), true);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 0);
}

BOOST_AUTO_TEST_CASE(PopGuaranteeReturn)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);

	Container.Push(taskOne);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
	BOOST_REQUIRE_EQUAL(Container.Pop(), taskOne);
}

BOOST_AUTO_TEST_CASE(PopRegulation)
{
	QueueP Container;

	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
	Container.Pop();
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), true);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 0);
}

BOOST_AUTO_TEST_CASE(PopRegulationReturn)
{
	QueueP Container;

	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 1);
	BOOST_REQUIRE_EQUAL(Container.Pop(), taskTwo);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Clean)
BOOST_AUTO_TEST_CASE(Clean_Empty)
{
	QueueP Container;
	Container.Clean();
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), true);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 0);
}

BOOST_AUTO_TEST_CASE(Clean_notEmpty)
{
	QueueP Container;

	Task* taskOne = new Guarantee("RepairIphone", "David", "Apple", 5, 30, 150);
	Task* taskTwo = new Regulation("RepairIphone", "David", "Apple", 5, "NewButton", 3);

	Container.Push(taskOne);
	Container.Push(taskTwo);
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), false);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 2);
	Container.Clean();
	BOOST_REQUIRE_EQUAL(Container.isEmpty(), true);
	BOOST_REQUIRE_EQUAL(Container.getAmount(), 0);
}
BOOST_AUTO_TEST_SUITE_END()