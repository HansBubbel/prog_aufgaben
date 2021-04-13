#include <stdio.h>
#include <stdlib.h>

#define MAX_PROG_SIZE 1000 /* Maximum number of chars in brainfuck program string. */

/* Find corresponding closing bracket, searching forward in code and return it's index. */
int iterate_brackets_fwd(char* bf_prog, int start_index) {
  int index, opened;
  opened = 0;

  for(index = start_index; bf_prog[index] != '\0'; ++index) {
    if(bf_prog[index] == '[') {
      ++opened;
    } else if(bf_prog[index] == ']') {
      --opened;
      if(opened == 0){
        break;
      }
    }
  }

  return index;
}

/* Find corresponding opening bracket, search backward in code and return it's index. */
int iterate_brackets_bwd(char* bf_prog, int start_index) {
  int index, closed;
  closed = 0;

  for(index = start_index; index > 0; --index){
    if(bf_prog[index] == ']') {
      ++closed;
    } else if(bf_prog[index] == '[') {
      --closed;
      if(closed == 0) {
        break;
      }
    }


  }

  return index;
}

/* Check if code blocks have valid brackets. */
int brackets_wellformed(char* bf_prog) {
  int opened = 0;

  for(int i = 0; bf_prog[i] != '\0'; ++i) {
    if(bf_prog[i] == '[') {
      ++opened;
    } else if(bf_prog[i] == ']') {
      --opened;
    }
  }

  return opened == 0 ? 1 : 0;
}

/* Interpret brainfuck program code to console output.  */
void interpret(char* bf_prog) {
  char cells[MAX_PROG_SIZE];
  int position = 0;

  for(int i = 0; bf_prog[i] != '\0'; ++i) {
      switch(bf_prog[i]) {
        case '<':
            if(position > 0) {
              --position;
            }
            break;
        case '>':
            ++position;
            break;
        case '+':
            ++cells[position];
            break;
        case '-':
            --cells[position];
            break;
        case '/':
            cells[position] *= 2;
            break;
        case '.':
          printf("%c", cells[position] % 128);
            break;
        case '[':
            if(cells[position] == 0) {
              i = iterate_brackets_fwd(bf_prog, i);
            }
            break;
        case ']':
            if(cells[position] != 0) {
              i = iterate_brackets_bwd(bf_prog, i);
            }
            break;
        default:
            break;
      }
  }
  
  printf("\n");
}

int main(int argc, char* argv[]) {
  //TODO Implement input stream.
  char bf_prog[MAX_PROG_SIZE] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  
  if(brackets_wellformed(bf_prog)) {
    interpret(bf_prog);
  } else {
    printf("Brackets not good.\n");
    return -1;
  }


  return 0;
}


