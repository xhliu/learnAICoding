#include <iostream>
#include "message_parser.h"

int main() {
    // Example: type=1, len=5, payload="Hello"
    uint8_t data[] = {0x01, 0x00, 0x05, 0x00, 'H', 'e', 'l', 'l', 'o'};

    Msg msg = parseMessage(data, sizeof(data));
    std::cout << "Type: " << msg.type << "\n";
    std::cout << "Payload: " << msg.payload << "\n";

    return 0;
}
