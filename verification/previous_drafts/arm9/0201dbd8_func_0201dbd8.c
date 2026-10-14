/* Decompiled C draft; module arm9; ROM address 0201dbd8. No matching claim. */
#include "types.h"
#include "deps/0201dbd8_func_0201dbd8.h"

void func_0201dbd8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_2 + 0x14U & 3;
  uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  sVar2 = *(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4);
  iVar4 = (sVar2 + -0x1000) * (param_3 + -0xff);
  *(short *)(param_1 + 0x34) =
       sVar2 + ((short)(iVar4 + (int)((ulonglong)((longlong)iRam0201dc20 * (longlong)iVar4) >> 0x20)
                       >> 7) - (short)(iVar4 >> 0x1f));
  return;
}

