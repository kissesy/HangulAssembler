#ifndef __H_OPCODE_STRUCT_
#define __H_OPCODE_STRUCT_

#include "Assembler.h"
/*
typedef struct _Function_List{
  void (*fp_rm8_r8)(Handler_Class* self, unsigned char opcode);
  void (*fp_rm16rm32_r16r32)(Handler_Class* self, unsigned char opcode);
  void (*fp_r8_rm8)(Handler_Class* self, unsigned char opcode);
  void (*fp_r16r32_rm16rm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_al_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_eax_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_es)(Handler_Class* self, unsigned char opcode);
}Function_List;
*/
/*
typedef struct _ADD{
  void (*fp_rm8_r8)(Handler_Class* self, unsigned char opcode);
  void (*fp_rm16rm32_r16r32)(Handler_Class* self, unsigned char opcode);
  void (*fp_r8_rm8)(Handler_Class* self, unsigned char opcode);
  void (*fp_r16r32_rm16rm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_al_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_eax_imm16imm32)(Handler_Class* self, unsigned char opcode);
}ADD;

typedef struct _PUSH{
  void (*fp_es)(Handler_Class* self, unsigned char opcode);
}PUSH;

typedef struct _POP{
  void (*fp_es)(Handler_Class* self, unsigned char opcode);
}POP;

typedef struct _OR{
  void (*fp_rm8_r8)(Handler_Class* self, unsigned char opcode);
  void (*fp_rm16rm32_r16r32)(Handler_Class* self, unsigned char opcode);
  void (*fp_r8_rm8)(Handler_Class* self, unsigned char opcode);
  void (*fp_r16r32_rm16rm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_al_imm16imm32)(Handler_Class* self, unsigned char opcode);
  void (*fp_eax_imm16imm32)(Handler_Class* self, unsigned char opcode);
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
*/
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

#endif
