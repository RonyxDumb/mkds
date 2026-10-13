/* Decompiled C draft; module arm9; ROM address 02054208. No matching claim. */
#include "types.h"
#include "deps/02054208_func_02054208.h"

void func_02054208(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = uRam02054328;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x15c4;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),0,8);
  iVar6 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(param_1 + iVar6 * 4 + 0x10) = 0;
    uVar3 = param_1 + 0xcU & 3;
    uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    Mem_CpuFill8((uint *)(uintptr_t)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar5),0,8);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 8;
  } while (iVar6 < 8);
  iVar6 = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  iVar5 = 0;
  do {
    iVar4 = iVar6 * 2;
    iVar6 = iVar6 + 1;
    *(undefined2 *)(param_1 + iVar4 + 0x3c) = 0;
  } while (iVar6 < 7);
  *(undefined1 *)(param_1 + 0x4a) = 0;
  *(undefined4 *)(param_1 + 0x34) = 5;
  *(undefined2 *)(param_1 + 0x38) = 0;
  uVar3 = uRam02054328;
  *(undefined1 *)(param_1 + 0x30) = 0;
  iVar6 = iRam0205432c;
  uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x454) = *(ushort *)(uVar2 + 0x454) & 0xffef;
  uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(byte *)(uVar2 + 0x8b) = *(byte *)(uVar2 + 0x8b) & 0xfe;
  iVar6 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar6;
  *(undefined1 *)(iVar6 + 0x60) = 0;
  *(undefined1 *)(iVar6 + 0x68) = 0;
  do {
    iVar4 = 0;
    do {
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(iVar1 + iVar6 + iVar5 * 8) = 0;
    } while (iVar4 < 3);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  uVar3 = *(uint *)(uRam02054328 & 0xfffffffc) >> (uRam02054328 & 3) * 8 |
          *(uint *)(uRam02054328 & 0xfffffffc) << (uRam02054328 & 3) * -8 + 0x20;
  *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) & 0xffef;
  return;
}

