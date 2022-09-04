#include <chip8.h>

unsigned char fontset[80] =
{ 
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};
void initialize(){
V[REGISTER_COUNT] =0;
memory[MEMORY_SIZE] = 0;
index = 0;
pc = 0x200;
stack[STACK_LEVELS] = 0;
sp = 0;
delaytime = 0;
soundtime = 0;
inputkey[INPUT_KEYS] = 0;
video[VIDEO_WIDTH * VIDEO_HEIGHT] = 0;
opcode = 0;

memcpy(memory, fontset, sizeof(fontset));
};

int load_rom(char* filename){};

void emulate_cycle(){
  //Fetch opcode

  /*
  Opcodes are 2 byte instructions, and array addresses contain 1 byte.
  In order to store the opcode properly in a variable, we must merge 2 bytes together.
  This is done by fetching 2 bytes and merging them together using bitwise OR to obtain the opcode.
  */
  opcode = memory[pc] << 8 | memory[pc+1]; 
  
  //Decode opcode
  switch(opcode & 0xF000){
    case(0x0000){
      switch(opcode & 0x000F){

      }
    }
  };
};