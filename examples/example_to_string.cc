#include <iostream>
#include <boost/mpl/vector.hpp>
#include "ListToString.h"
#include "helper/LaunchBounds.h"

using namespace std;
namespace mpl = boost::mpl;

typedef mpl::vector<mpl::int_<4>, mpl::int_<8>, LaunchBounds<2,3> > aList;

int main()
{
	cout << culgt::mplextension::ListToString<aList>::getString() << endl;
}
