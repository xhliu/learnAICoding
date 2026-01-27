#include <cassert>
#include <iostream>
#include "message_parser.h"

void testValidMessage() {
    uint8_t data[] = {0x01, 0x00, 0x05, 0x00, 'H', 'e', 'l', 'l', 'o'};
    Msg msg = parseMessage(data, sizeof(data));
    assert(msg.type == 1);
    assert(msg.payload == "Hello");
    std::cout << "[PASS] testValidMessage\n";
}

void testTruncatedPayload() {
    // len=100 but only 4 bytes total - must throw
    uint8_t bad[] = {0x01, 0x00, 0x64, 0x00};  // type=1, len=100
    bool threw = false;
    try {
        parseMessage(bad, sizeof(bad));
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    assert(threw && "should reject truncated payload");
    std::cout << "[PASS] testTruncatedPayload\n";
}

void testShortHeader() {
    uint8_t data[] = {0x01, 0x00, 0x00};  // only 3 bytes
    bool threw = false;
    try {
        parseMessage(data, sizeof(data));
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    assert(threw && "should reject short header");
    std::cout << "[PASS] testShortHeader\n";
}

void testEmptyPayload() {
    uint8_t data[] = {0x02, 0x00, 0x00, 0x00};  // type=2, len=0
    Msg msg = parseMessage(data, sizeof(data));
    assert(msg.type == 2);
    assert(msg.payload.empty());
    std::cout << "[PASS] testEmptyPayload\n";
}

void testExactFit() {
    uint8_t data[] = {0x03, 0x00, 0x01, 0x00, 'X'};  // type=3, len=1
    Msg msg = parseMessage(data, sizeof(data));
    assert(msg.type == 3);
    assert(msg.payload == "X");
    std::cout << "[PASS] testExactFit\n";
}

void testMaxLenClaim() {
    // Attacker claims max payload (0xFFFF) but provides nothing
    uint8_t data[] = {0x00, 0x00, 0xFF, 0xFF};  // type=0, len=65535
    bool threw = false;
    try {
        parseMessage(data, sizeof(data));
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    assert(threw && "should reject when len exceeds buffer");
    std::cout << "[PASS] testMaxLenClaim\n";
}

int main() {
    std::cout << "Running message parser tests...\n\n";

    testValidMessage();
    testTruncatedPayload();
    testShortHeader();
    testEmptyPayload();
    testExactFit();
    testMaxLenClaim();

    std::cout << "\nAll tests passed!\n";
    return 0;
}
