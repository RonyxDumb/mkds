/* Decompiled C draft; module arm9_ov001; ROM address 0218180c. No matching claim. */
#include "types.h"
#include "deps/0218180c_func_ov001_0218180c.h"

char func_ov001_0218180c(void)

{
  char cVar1;
  
  cVar1 = *(char *)(*piRam0218181c + 0x37);
  if (cVar1 == '\0') {
    cVar1 = '\x01';
  }
  return cVar1;
}

