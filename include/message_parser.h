#ifndef MESSAGE_PARSER_H
#define MESSAGE_PARSER_H

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

struct Msg {
  uint16_t type;
  std::string payload;
};

// Parses: [type:2 bytes little-endian][len:2 bytes little-endian][payload:len bytes]
inline Msg parseMessage(const uint8_t* data, size_t n) {
  if (n < 4) throw std::runtime_error("short header");

  uint16_t type = static_cast<uint16_t>(data[0] | (data[1] << 8));
  uint16_t len  = static_cast<uint16_t>(data[2] | (data[3] << 8));

  if (n - 4 < len) throw std::runtime_error("truncated payload");

  std::vector<char> buf(len);
  std::memcpy(buf.data(), data + 4, len);

  return Msg{type, std::string(buf.begin(), buf.end())};
}

#endif
