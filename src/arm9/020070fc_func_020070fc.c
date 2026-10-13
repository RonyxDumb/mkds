/* Decompiled C draft; module arm9; ROM address 020070fc. No matching claim. */
#include "types.h"
#include "deps/020070fc_func_020070fc.h"

void func_020070fc(void)

{
  char *pcVar1;
  
  pcVar1 = pcRam02007110;
  *pcRam02007110 = *pcRam02007110 + '\x01';
  if (*pcVar1 == '\0') {
    *pcVar1 = '\x01';
  }
  return;
}

