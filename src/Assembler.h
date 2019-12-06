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
#include <search.h>

/*
여기서 문제 해당 명령어의 opcode가 같을 수 도 있고 다를 수 도 있는데 어떻게 나눌 것인가
같은것끼리 묶을까 명령어끼리 묶을까 - 명령어끼리 묶고 opcode를 다르게 나타내기 위한 꼼수를 쓰자
*/

/*
그럼 필요한것이 현재 가리키고 있는 문자열 포인터가 add일떄 저 struct을 가지고오고
가지고오는것은 hashTable?

가지고와서 다음 가리키고 있는 포인터를 체킹 해당 포인터가 가리키는 문자열이
eax라면 eax가 add의 두번째에 올 수 있는 것이 있는지 체킹 - syntax 체킹
*/

typedef struct _ADD{

}ADD;

typedef struct _PUSH{

}PUSH;

typedef struct _POP{

}POP;

typedef struct _OR{

}OR;

typedef struct _ADC{

}ADC;

typedef struct _SBB{

}SBB;

typedef struct _AND{

}AND;


typedef struct _Opcode_List{
  ADD Add;
  PUSH Push;
  POP Pop;
  OR Or;
}Opcode_List;

//위에것들은 어떻게 활용할 수 있을지 생각해보자.

typedef struct _String_Class{
  unsigned int size;
  unsigned char* buffer;
  void (*append)(struct _String_Class* self, unsigned char hexbyte);
  void (*print)(struct _String_Class* self);
  void (*free_space)(struct _String_Class* self);
}String_Class;

/*
Opcode table이랑
bss symbol table
data symbol table  이 table도 어떻게 만들지 생가해보자.
*/
typedef struct _Symbol_Class{
  void* pass;
}Symbol_Class;

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
  void* pass;
/*Function*/
}Assembler_Class;

typedef struct _Handler_Class{
/*Variable*/
  FileRead_Class FileRead;
  Assembler_Class Assembler;
  String_Class String;
  Symbol_Class Symbol;

  Opcode_List opcode_list;

  ENTRY Opcode_Table, *Result;
  unsigned int NumberOfOpcode;

  void (*opcode_hashtable_setup)(struct _Handler_Class* self);
  void* (*get_opcode_struct_pointer)(struct _Handler_Class* self, char* key);
/*Function*/
}Handler_Class;

typedef struct _Function_List{
  void (*fp_rm8_r8)(Handler_Class* self, unsigned char opcode);
  void (*fp_rm16rm32_r16r32)(Handler_Class* self, unsigned char opcode);
  void (*fp_r8_rm8)(Handler_Class* self, unsigned char opcode);
  void (*fp_r16r32_rm16rm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_al_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_eax_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_es)(Handler_Class* self, unsigned char opcode);
}Function_List;

//Function List 객체는 따로 선언해야겠당 전역으로 둘까

/*String Class Method*/
void string_append(String_Class* self, unsigned char hexbyte);
void string_print(String_Class* self);
void string_free(String_Class* self);

/*Handler Class Method*/
void handler_opcode_hashtable_setup(Handler_Class* self);
void* handler_get_opcode_struct_pointer(Handler_Class* self, char* key);
/*Assembler Class Handler*/

void __function_init(Handler_Class* Handler, const char* filename);
void Error_Handling(char* msg);
/*File Process Class Method*/
void file_read(FileRead_Class* self);

#endif
