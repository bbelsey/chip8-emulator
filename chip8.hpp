#include <cstdint>
const unsigned int REGISTER_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int STACK_LEVELS = 16;
const unsigned int INPUT_KEYS = 16;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;
class Chip8{
public:
    uint8_t registers[REGISTER_COUNT]{};
    char memory[MEMORY_SIZE]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[STACK_LEVELS]{};
    uint8_t sp{};
    uint8_t delaytime{};
    uint8_t soundtime{};
    uint8_t inputkey[INPUT_KEYS]{};
    uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{};
    uint16_t opcode;

};