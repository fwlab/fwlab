#include "BaseSerializer.h"

namespace fwlab::serialization
{
	template <typename T, typename P>
	BaseSerializer<T, P>::BaseSerializer()
	{

	}

	template <typename T, typename P>
	BaseSerializer<T, P>::~BaseSerializer()
	{

	}

	template <typename T, typename P>
	rapidjson::Value BaseSerializer<T, P>::toJSON(T* object, P* parent)
	{

	}

	template <typename T, typename P>
	T* BaseSerializer<T, P>::fromJSON(rapidjson::Value* value)
	{

	}
}