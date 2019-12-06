#include "Assembler.h"

void string_append(String_Class* self, unsigned char hexbyte){
  if(self->buffer == NULL){
    self->buffer = (unsigned char*)malloc(sizeof(unsigned char) * 1);
    self->buffer[self->size] = hexbyte;
  } else{
    if(realloc(self->buffer, sizeof(unsigned char) * 1) == NULL){
      Error_Handling("Realloc Function Error!");
    }
    self->buffer[self->size] = hexbyte;
  }
  self->size += 1;
}

void string_print(String_Class* self){
  printf("=============HexByte Code============\n");
  for(int i=0;i<self->size;i++){
    printf("%d ", self->buffer[i]);
  }
  printf("\n");
}

void string_free(String_Class* self){
  if(self->buffer == NULL){
    printf("Do Not Free Null Pointer");
  } else{
    memset(self->buffer, 0, self->size);
    free(self->buffer);
    self->buffer = NULL;
    self->size = 0;
  }
}
