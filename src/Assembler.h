#ifndef __H_ASSEMBLER_
#define __H_ASSEMBLER_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct _String_Class{
  unsigned int size;
  unsgiend char* buffer;
  void (*append)(struct _String_Class* self, unsigned char hexbyte);
  void (*print)(struct _String_Class* self);
}String_Class;

typedef struct _FileRead_Class{
/*variable*/
  unsigned char* file_buffer;
  unsigned int file_descriptor;
  struct stat file_information;
  unsigned char filename[100];
/*function*/
  void (*file_read)(struct _FileRead_Class* self);
}FileRead_Class;

typedef struct _Assembler_Class{
/*Variable*/
  int pass;
/*Function*/
}Assembler_Class;

typedef struct _Handler_Class{
/*Variable*/
  FileRead_Class FileRead;
  Assembler_Class Assembler;
  String_Class String;
/*Function*/
}Handler_Class;

void string_append(String_Class* self, unsigned char hexbyte);
void string_print(String_Class* self);

void __function_init(Handler_Class* Handler, const char* filename);

void Error_Handling(char* msg);

void file_read(FileRead_Class* self);

#endif
