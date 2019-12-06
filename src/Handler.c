#include "Assembler.h"

void handler_opcode_hashtable_setup(Handler_Class* self){
  hcreate(self->NumberOfOpcode);
  self->Opcode_Table.key = "add";
  self->Opcode_Table.data = (void*)&self->opcode_list.Add;
  hsearch(self->Opcode_Table, ENTER);

  self->Opcode_Table.key = "push";
  self->Opcode_Table.data = (void*)&self->opcode_list.Push;
  hsearch(self->Opcode_Table, ENTER);
}

void* handler_get_opcode_struct_pointer(Handler_Class* self, char* key){
  return hsearch(self->Opcode_Table, key)->data;
}
