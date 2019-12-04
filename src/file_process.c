#include "Assembler.h"

void file_read(FileRead_Class* self){
  self->file_descriptor = open(self->filename, O_RDONLY);
  if(self->file_descriptor == -1){
    Error_Handling("file open Error!");
  }
  else{
    if(fstat(self->file_descriptor, &self->file_information) == -1){
      Error_Handling("file stat Error!");
    }
    else{
      self->file_buffer = (unsigned char*)malloc(sizeof(unsigned char)* self->file_information.st_size);
      if(self->file_buffer == NULL){
        Error_Handling("Malloc Function Error");
      }
      read(self->file_descriptor, self->file_buffer, self->file_information.st_size);
      close(self->file_descriptor);
    }
  }
}
