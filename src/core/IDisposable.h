#ifndef GL_CORE_IDISPOSABLE_H
#define GL_CORE_IDISPOSABLE_H

namespace gl::core
{
	class IDisposable
	{
	public:
		virtual void dispose() = 0;
	};
}

#endif