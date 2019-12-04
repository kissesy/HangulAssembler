#include "Assembler.h"

void string_append(String_Class* self, unsigned char hexbyte){
  if(self->size == 0){
    self->buffer = realloc(NULL, sizeof(unsigned char) * 1);
    self->buffer[size] = hexbyte;
  }
  else{
    self->buffer = realloc(self->buffer, sizeof(unsigned char) * 1);
    self->buffer[size] = hexbyte;
  }
  self->size += 1;
}

void string_print(String_Class* self){
  printf("=============HexByte Code============\n");
  for(int i=0;i<self->size;i++){
    printf("%ld ", self->buffer[i]);
  }
  printf("\n");
}
