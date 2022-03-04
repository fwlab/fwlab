#ifndef FWLAB_CORE_IDISPOSABLE_H
#define FWLAB_CORE_IDISPOSABLE_H

namespace fwlab::core
{
	class IDisposable
	{
	public:
		virtual void dispose() = 0;
	};
}

#endif