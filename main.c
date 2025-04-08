#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 320
#define MAX_SIZE 100

typedef struct {
  int registers[16];
  int pc; // program counter
  int memory[4 * 1024];
} CPU;

typedef enum { CLEAR, JUMP } Instruction;

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int value) { stack->arr[++stack->top] = value; }
int pop(Stack *stack) {
  int popped = stack->arr[stack->top];
  stack->top--;
  return popped;
}

char display[HEIGHT][WIDTH / 8];

char keys[4][4] = {{'1', '2', '3', '4'},
                   {'Q', 'W', 'E', 'R'},
                   {'A', 'S', 'D', 'F'},
                   {'Z', 'X', 'C', 'V'}};

void setPixel(int x, int y, int value) {
  int byteIndex = x / 8;
  int bitIndex = x % 8;

  if (value == 1) {
    display[y][byteIndex] |= (1 << (7 - bitIndex));
  } else {
    display[y][byteIndex] &= ~(1 << (7 - bitIndex));
  }
}

void turnOffPixels() {
  for (int i = 0;i<HEIGHT; i ++){
    for (int j =0; j < WIDTH; j++) {
      display[i][j] = 0;
    }
  }
}

void execute_instruction(CPU *cpu, Instruction instr, int reg1, int reg2,
                         int address) {
  switch (instr & 0xF000) {
  case 0x00E0:
      ClearBackground(BLACK);
    break;
  case 0x1NNN:
    printf("not implemented");
    break;
  }

  cpu->pc += 4;
}

int main() {

  InitWindow(WIDTH, HEIGHT, "8 Bit Emulation");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(WHITE);

    EndDrawing();
  }

  int KB = 1024;
  int FOUR_KB = 4 * KB;

  char stack[16];

  char memory[FOUR_KB];
  char delay_timer;
  char sound_timer;

  char font[] = {0xF0, 0x90, 0x90, 0x90, 0xF0,  // 0
                 0x20, 0x60, 0x20, 0x20, 0x70,  // 1
                 0xF0, 0x10, 0xF0, 0x80, 0xF0,  // 2
                 0xF0, 0x10, 0xF0, 0x10, 0xF0,  // 3
                 0x90, 0x90, 0xF0, 0x10, 0x10,  // 4
                 0xF0, 0x80, 0xF0, 0x10, 0xF0,  // 5
                 0xF0, 0x80, 0xF0, 0x90, 0xF0,  // 6
                 0xF0, 0x10, 0x20, 0x40, 0x40,  // 7
                 0xF0, 0x90, 0xF0, 0x90, 0xF0,  // 8
                 0xF0, 0x90, 0xF0, 0x10, 0xF0,  // 9
                 0xF0, 0x90, 0xF0, 0x90, 0x90,  // A
                 0xE0, 0x90, 0xE0, 0x90, 0xE0,  // B
                 0xF0, 0x80, 0x80, 0x80, 0xF0,  // C
                 0xE0, 0x90, 0x90, 0x90, 0xE0,  // D
                 0xF0, 0x80, 0xF0, 0x80, 0xF0,  // E
                 0xF0, 0x80, 0xF0, 0x80, 0x80}; // F

  setPixel(5, 5, 1);

  return 0;
}
