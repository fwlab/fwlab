#include "BoxGeometry.h"

namespace fwlab::geometry
{
	BoxGeometry::Builder::Builder()
	{

	}

	BoxGeometry::Builder::~Builder()
	{

	}

	BoxGeometry* BoxGeometry::Builder::build()
	{
		return new BoxGeometry();
	}
}