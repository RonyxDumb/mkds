/* Decompiled C draft; module arm9; ROM address 0201dc88. No matching claim. */
#include "types.h"
#include "deps/0201dc88_func_0201dc88.h"

void func_0201dc88(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar2 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  puVar4 = (ushort *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  if (param_3 < (int)(uint)(byte)puVar4[2]) {
    uVar2 = (uint)*puVar4;
    iVar1 = _s32_div_f(param_3 * (((uVar2 << 0x16) >> 0x1b) - (uVar2 & 0x1f)));
    uVar2 = iVar1 + (uVar2 & 0x1f);
  }
  else if (param_3 < (int)(uint)*(byte *)((int)puVar4 + 5)) {
    uVar2 = ((uint)*puVar4 << 0x16) >> 0x1b;
  }
  else {
    uVar2 = (uint)*puVar4 << 0x11;
    iVar1 = _s32_div_f((param_3 + -0xff) * ((uVar2 >> 0x1b) - (((uint)*puVar4 << 0x16) >> 0x1b)),
                       0xff - (uint)*(byte *)((int)puVar4 + 5));
    uVar2 = iVar1 + (uVar2 >> 0x1b);
  }
  uVar3 = (*(uint *)((uint)puRam0201dd58 & 0xfffffffc) >> ((uint)puRam0201dd58 & 3) * 8 |
          *(uint *)((uint)puRam0201dd58 & 0xfffffffc) << ((uint)puRam0201dd58 & 3) * -8 + 0x20) *
          iRam0201dd5c + iRam0201dd60;
  *puRam0201dd58 = uVar3;
  *(ushort *)(param_1 + 0x2e) =
       *(ushort *)(param_1 + 0x2e) & 0xfc1f |
       (ushort)((uVar2 * (0xff - ((int)((uint)(byte)puVar4[1] * (uVar3 >> 0x18)) >> 8)) * 0x100 >>
                 0x10 & 0x1f) << 5);
  return;
}

