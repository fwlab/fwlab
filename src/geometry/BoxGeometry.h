#ifndef FWLAB_GEOMETRY_BOX_GEOMETRY_H
#define FWLAB_GEOMETRY_BOX_GEOMETRY_H

namespace fwlab::geometry
{
	class BoxGeometry
	{
	public:
		class Builder
		{
		public:
			Builder();
			virtual ~Builder();
			BoxGeometry* build();
		};
	};
}

#endif