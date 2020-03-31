#include <boost/test/unit_test.hpp>
#include <trajectory_generation/Dummy.hpp>

using namespace trajectory_generation;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    trajectory_generation::DummyClass dummy;
    dummy.welcome();
}
