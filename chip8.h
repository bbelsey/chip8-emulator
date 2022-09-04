#include <inttypes.h>
const unsigned int REGISTER_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int STACK_LEVELS = 16;
const unsigned int INPUT_KEYS = 16;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int VIDEO_WIDTH = 64;

    unsigned char V[REGISTER_COUNT];
    char memory[MEMORY_SIZE];
    unsigned short index;
    unsigned short pc;
    unsigned short stack[STACK_LEVELS];
    unsigned char sp;
    unsigned char delaytime;
    unsigned char soundtime;
    unsigned char inputkey[INPUT_KEYS];
    unsigned long video[VIDEO_WIDTH * VIDEO_HEIGHT];
    unsigned short opcode;
    /*
    Legend
    NNN: address
    NN: 8-bit constant
    N: 4-bit constant
    I: 16-bit register (for memory address)
    */
    void OP_NULL(); //Do nothing
    void OP_00E0(); //Clears display
    void OP_00EE(); //Returns from subroutine
    void OP_1NNN(); //Jumps to address NNN
    void OP_2NNN(); //Call address
    void OP_3XNN(); //Skips next instruction if X register == NN
    void OP_4XNN(); //Skips next instruction if X register != NN
    void OP_5XY0(); //Skips next instruction if X register == Y register
    void OP_6XNN(); //Sets X register to NN
    void OP_7XNN(); //Adds NN to X register
    void OP_8XY0(); //Sets X register = Y register
    void OP_8XY1(); //Sets X register to X or Y register (OR operation)
    void OP_8XY2(); //Sets X register to X and Y register (AND operation)
    void OP_8XY3(); //Sets X register to X xor Y register (XOR operation)
    void OP_8XY4(); //Adds Y register to X register (carry flag is 1 when carry, 0 when no carry)
    void OP_8XY5(); //Y register subtracted from X register (carry flag is 1 when no borrow, 0 when borrow)
    void OP_8XY6(); //Stores LSB of X register in Flag register, shifts X register to right by 1
    void OP_8XY7(); //Sets X register = Y register - X register
    void OP_8XYE(); //Stores MSB of X register in Flag register, shifts X register to left by 1
    void OP_9XY0(); //If X register != Y register, skip next instruction
    void OP_ANNN(); //Sets I to NNN address
    void OP_BNNN(); //Jumps to NNN address
    void OP_CXNN(); //Sets X register to NN and random number
    void OP_DXYN(); //Draw sprite starting at I at coordinate (X register, Y register) with width of 8 pixels and height of N pixels. Flag register set to collision
    void OP_EX9E(); //Skips next instruction if key stored in X register is pressed (usually next instruction is a jump to skip code block)
    void OP_EXA1(); //Skips next instruction if key stored in X register is not pressed
    void OP_FX07(); //Sets X register to value of delay timer
    void OP_FX0A(); //Key press awaited, then stored in X register (blocking operation; all instruction halted until next key event)
    void OP_FX15(); //Sets delay timer to X register
    void OP_FX18(); //Sets sound timer to X register
    void OP_FX1E(); //Adds X register to I (Flag register is not affected)
    void OP_FX29(); //Sets I to location of sprite for character in X register (chars 0-F are represented by 4x5 font)
    void OP_FX33(); //Store binary-coded decimal representation of X register, place hudreds digit at location I, tens digit at I+1, ones digit at I+2
    void OP_FX55(); //Store from V0 to X register in memory, starting at I. Offset from I increased by 1 for each value written
    void OP_FX65(); //Fills from V0 to X register in memory, starting at I. Offset from I increased by 1 for each value read
