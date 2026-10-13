/* Decompiled C draft; module arm7; ROM address 037fc478. No matching claim. */
#include "types.h"
#include "deps/037fc478_FUN_037fc478.h"

uint FUN_037fc478(int param_1,int param_2)

{
  char cVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = FUN_037fc73c(param_1 + 0x28);
  uVar4 = (int)uVar3 >> 0x1f;
  if (uVar3 != 0) {
    cVar1 = *(char *)(param_1 + 0x28);
    if (cVar1 == '\0') {
      uVar4 = uVar4 << 6 | uVar3 >> 0x1a;
      uVar3 = uVar3 << 6;
    }
    else if (cVar1 == '\x01') {
      uVar2 = (ulonglong)uVar3;
      uVar3 = (uint)(uVar2 * 0x3c);
      uVar4 = uVar4 * 0x3c + (int)(uVar2 * 0x3c >> 0x20);
    }
    else if (cVar1 == '\x02') {
      uVar4 = uVar4 << 6 | uVar3 >> 0x1a;
      uVar3 = uVar3 << 6;
    }
    uVar3 = uVar3 >> 0xe | uVar4 << 0x12;
  }
  if (param_2 != 0) {
    FUN_037fc78c(param_1 + 0x28);
  }
  return uVar3;
}

