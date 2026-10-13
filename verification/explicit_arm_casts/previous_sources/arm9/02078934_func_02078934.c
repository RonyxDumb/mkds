/* Decompiled C draft; module arm9; ROM address 02078934. No matching claim. */
#include "types.h"
#include "deps/02078934_func_02078934.h"

void func_02078934(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar2 = FX_Div(uRam020789b4,uRam020789b8);
  uVar3 = (uVar2 << 9) >> 0xc | (((int)uVar2 >> 0x1f) << 9 | uVar2 >> 0x17) << 0x14;
  iVar1 = -uVar3;
  uVar6 = Multiply64(iVar1,iVar1 >> 0x1f,uRam020789bc,0);
  uVar4 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar2 = uVar4;
  uVar5 = -uVar4;
  if (param_1 != 0) {
    uVar2 = -uVar4;
    uVar5 = uVar4;
  }
  func_01ff9048(0x15,0,0);
  G3i_FrustumW_(uVar3,iVar1,uVar2,uVar5,uRam020789c0,uRam020789c4,uRam020789c8,0,uRam020789cc);
  *(uint *)(iRam020789d0 + 0x7c) = *(uint *)(iRam020789d0 + 0x7c) & 0xffffffaf;
  func_02011034();
  return;
}

