#ifndef FWLAB_SERIALIZATION_BASE_SERIALIZER_H
#define FWLAB_SERIALIZATION_BASE_SERIALIZER_H
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace fwlab::serialization
{
	template <typename T, typename P>
	class BaseSerializer {
	public:
		BaseSerializer();
		virtual ~BaseSerializer();
		virtual rapidjson::Value toJSON(T* object, P* parent);
		T* fromJSON(rapidjson::Value* value);
	};
}

#endif