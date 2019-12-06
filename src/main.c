#include "Assembler.h"

int main(int argc, char** argv){
  if(argc != 2){
    Error_Handling("Usage Two Argument");
  }
  Handler_Class Handler;
  __function_init(&Handler, argv[1]);
  Handler.FileRead.file_read(&Handler.FileRead);
  return 0;
}

void __function_init(Handler_Class* Handler, const char* filename){

  //Handler->opcode_hashtable_setup = handler_opcode_hashtable_setup;

  strcpy(Handler->FileRead.filename, filename);
  Handler->FileRead.file_buffer = NULL;
  Handler->FileRead.file_read = file_read;

  Handler->String.append = string_append;
  Handler->String.print = string_print;
  Handler->String.free_space = string_free;
  Handler->String.size = 0;
  Handler->String.buffer = NULL;

}

void Error_Handling(char* msg){
  printf("%s\n",msg);
  exit(1);
}
