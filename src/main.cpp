#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Msg {
  uint16_t type;
  std::string payload;
};

// Parses: [type:2 bytes little-endian][len:2 bytes little-endian][payload:len bytes]
Msg parseMessage(const uint8_t* data, size_t n) {
  if (n < 4) throw std::runtime_error("short header");

  uint16_t type = static_cast<uint16_t>(data[0] | (data[1] << 8));
  uint16_t len  = static_cast<uint16_t>(data[2] | (data[3] << 8));

  // ❌ BUG: doesn't verify n >= 4 + len
  std::vector<char> buf(len);
  std::memcpy(buf.data(), data + 4, len);  // OOB read if len > n-4

  return Msg{type, std::string(buf.begin(), buf.end())};
}

int main() {
    // Example: type=1, len=5, payload="Hello"
    uint8_t data[] = {0x01, 0x00, 0x05, 0x00, 'H', 'e', 'l', 'l', 'o'};

    Msg msg = parseMessage(data, sizeof(data));
    std::cout << "Type: " << msg.type << "\n";
    std::cout << "Payload: " << msg.payload << "\n";

    return 0;
}
