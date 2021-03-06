#include "printers.h"

#include "common/buffer/buffer_impl.h"
#include "common/http/header_map_impl.h"

namespace Http {
void PrintTo(const HeaderMapImpl& headers, std::ostream* os) {
  headers.iterate([os](const LowerCaseString& key, const std::string& value)
                      -> void { *os << "{'" << key.get() << "','" << value << "'}"; });
}

void PrintTo(const HeaderMapPtr& headers, std::ostream* os) {
  PrintTo(*dynamic_cast<HeaderMapImpl*>(headers.get()), os);
}

void PrintTo(const HeaderMap& headers, std::ostream* os) {
  PrintTo(*dynamic_cast<const HeaderMapImpl*>(&headers), os);
}
}

namespace Buffer {
void PrintTo(const Instance& buffer, std::ostream* os) {
  *os << "buffer with size=" << buffer.length();
}

void PrintTo(const Buffer::OwnedImpl& buffer, std::ostream* os) {
  PrintTo(dynamic_cast<const Buffer::Instance&>(buffer), os);
}
}
