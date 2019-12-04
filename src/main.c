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
  strcpy(Handler->FileRead.filename, filename);
  Handler->FileRead.file_buffer = NULL;
  Handler->FileRead.file_read = file_read;
}

void Error_Handling(char* msg){
  printf("%s\n",msg);
  exit(1);
}
