/* Decompiled C draft; module arm9; ROM address 0203d8fc. No matching claim. */
#include "types.h"
#include "deps/0203d8fc_LoadCurrentCourseRanktime.h"

void LoadCurrentCourseRanktime(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  *(undefined2 *)
   ((*(uint *)(uRam0203d9cc & 0xfffffffc) >> (uRam0203d9cc & 3) * 8 |
    *(uint *)(uRam0203d9cc & 0xfffffffc) << (uRam0203d9cc & 3) * -8 + 0x20) + 0xc) = 0;
  if (*(ushort *)(param_1 + 8) == 0) {
    return;
  }
  pbVar3 = (byte *)(param_1 + 0x1c);
  uVar2 = *(uint *)(uRam0203d9d0 & 0xfffffffc) >> (uRam0203d9d0 & 3) * 8 |
          *(uint *)(uRam0203d9d0 & 0xfffffffc) << (uRam0203d9d0 & 3) * -8 + 0x20;
  while ((uint)*pbVar3 !=
         (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20)) {
    iVar4 = iVar4 + 1;
    pbVar3 = pbVar3 + 8;
    if ((int)(uint)*(ushort *)(param_1 + 8) <= iVar4) {
      return;
    }
  }
  uVar1 = uVar2 + 0x10 & 3;
  uVar2 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 0) {
    *(undefined2 *)
     ((*(uint *)(uRam0203d9cc & 0xfffffffc) >> (uRam0203d9cc & 3) * 8 |
      *(uint *)(uRam0203d9cc & 0xfffffffc) << (uRam0203d9cc & 3) * -8 + 0x20) + 0xc) =
         *(undefined2 *)(pbVar3 + 2);
    return;
  }
  if (uVar2 == 1) {
    *(undefined2 *)
     ((*(uint *)(uRam0203d9cc & 0xfffffffc) >> (uRam0203d9cc & 3) * 8 |
      *(uint *)(uRam0203d9cc & 0xfffffffc) << (uRam0203d9cc & 3) * -8 + 0x20) + 0xc) =
         *(undefined2 *)(pbVar3 + 4);
    return;
  }
  if (uVar2 == 2) {
    *(undefined2 *)
     ((*(uint *)(uRam0203d9cc & 0xfffffffc) >> (uRam0203d9cc & 3) * 8 |
      *(uint *)(uRam0203d9cc & 0xfffffffc) << (uRam0203d9cc & 3) * -8 + 0x20) + 0xc) =
         *(undefined2 *)(pbVar3 + 6);
  }
  return;
}

