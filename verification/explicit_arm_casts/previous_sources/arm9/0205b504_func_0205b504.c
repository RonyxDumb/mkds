/* Decompiled C draft; module arm9; ROM address 0205b504. No matching claim. */
#include "types.h"
#include "deps/0205b504_func_0205b504.h"

void func_0205b504(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar2 = DAT_0205b6b8;
  uVar5 = *(uint *)(DAT_0205b6b8 & 0xfffffffc) >> (DAT_0205b6b8 & 3) * 8 |
          *(uint *)(DAT_0205b6b8 & 0xfffffffc) << (DAT_0205b6b8 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  if (((uint)*(byte *)(uVar5 + 0x749) & 1 << (*param_2 & 3)) == 0) {
    return;
  }
  *(undefined2 *)(uVar5 + (*param_2 & 3) * 2 + 0x740) = 0;
  *(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + (*param_2 & 3) + 0x74a) =
       (byte)(((uint)param_2[2] << 0x1c) >> 0x1c);
  *(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + (*param_2 & 3) + 0x74e) =
       param_2[1];
  switch(((uint)*param_2 << 0x18) >> 0x1c) {
  case 0:
    bVar1 = *param_2;
    uVar2 = func_0x0219bb50();
    if (*(ushort *)(param_2 + 4) == uVar2) {
      uVar6 = Os_GetTick();
      *(undefined8 *)(param_2 + 0x20) = uVar6;
      func_0205b824(param_2 + 8,bVar1 & 3);
      return;
    }
    if (3 < *(ushort *)(param_2 + 4)) {
      return;
    }
    iVar3 = (bVar1 & 3) * 0x38;
    iVar4 = (*(uint *)(DAT_0205b6b8 & 0xfffffffc) >> (DAT_0205b6b8 & 3) * 8 |
            *(uint *)(DAT_0205b6b8 & 0xfffffffc) << (DAT_0205b6b8 & 3) * -8 + 0x20) + 0x14 + iVar3;
    Mem_CpuCopy8(param_2 + 4,iVar4,0x28);
    uVar6 = Os_GetTick();
    *(undefined8 *)(iVar4 + 0xc) = uVar6;
    *(undefined4 *)
     ((*(uint *)(DAT_0205b6b8 & 0xfffffffc) >> (DAT_0205b6b8 & 3) * 8 |
      *(uint *)(DAT_0205b6b8 & 0xfffffffc) << (DAT_0205b6b8 & 3) * -8 + 0x20) + iVar3 + 0x44) = 1;
    return;
  case 1:
    uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    *(byte *)(uVar2 + 0xfa) = *(byte *)(uVar2 + 0xfa) | (byte)(1 << (*param_2 & 3));
    return;
  case 2:
    func_0205b6bc();
    return;
  case 3:
    func_0205b778();
    break;
  case 4:
    break;
  case 5:
  }
  return;
}

