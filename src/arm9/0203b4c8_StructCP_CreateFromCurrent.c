/* Decompiled C draft; module arm9; ROM address 0203b4c8. No matching claim. */
#include "types.h"
#include "deps/0203b4c8_StructCP_CreateFromCurrent.h"

void StructCP_CreateFromCurrent(undefined2 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  uVar3 = uRam0203b58c;
  *param_1 = 0;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Mem_CpuCopy8((ushort *)(uintptr_t)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0xc),(uint *)(void *)(param_1 + 2),0x14);
  uVar5 = uRam0203b590;
  uVar3 = 0;
  do {
    uVar1 = uVar5 & 3;
    uVar4 = *(uint *)(uVar5 & 0xfffffffc);
    StructCP_SetTimeFromCPAndTime
              (param_1,(ushort *)(uintptr_t)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x98 + uVar3 * 4),param_1)
    ;
    iVar2 = iRam0203b594;
    uVar1 = uRam0203b590;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  uVar5 = (*(uint *)(uRam0203b590 & 0xfffffffc) >> (uRam0203b590 & 3) * 8 |
          *(uint *)(uRam0203b590 & 0xfffffffc) << (uRam0203b590 & 3) * -8 + 0x20) + 0x90;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(byte *)((int)param_1 + 0x19) = (byte)(uVar5 >> uVar3 * 8) | (byte)(uVar5 << uVar3 * -8 + 0x20);
  uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x94;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(byte *)(param_1 + 0xd) = (byte)(uVar5 >> uVar3 * 8) | (byte)(uVar5 << uVar3 * -8 + 0x20);
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x7c;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(undefined1 *)(param_1 + 0xe) =
       *(undefined1 *)(iVar2 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20));
  *(char *)((int)param_1 + 0x1d) =
       (char)*(undefined2 *)
              ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
               *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xa8);
  uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x80;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(byte *)(param_1 + 0xf) = (byte)(uVar5 >> uVar3 * 8) | (byte)(uVar5 << uVar3 * -8 + 0x20);
  *(undefined1 *)(param_1 + 0xc) = 1;
  return;
}

