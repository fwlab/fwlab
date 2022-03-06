#ifndef FWLAB_SERIALIZATION_CONVERT_H
#define FWLAB_SERIALIZATION_CONVERT_H
#include <string>

namespace fwlab::serialization
{
	class Convert final {
	public:
		Convert();
		virtual ~Convert();
		std::string toJSON();
		bool fromJSON(std::string value);
	};
}

#endif