/* Decompiled C draft; module arm9; ROM address 020b3584. No matching claim. */
#include "types.h"
#include "deps/020b3584_IncreaseB358Countdown.h"

void IncreaseB358Countdown(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (undefined4 *)
           (*(uint *)(uRam020b3698 & 0xfffffffc) >> (uRam020b3698 & 3) * 8 |
           *(uint *)(uRam020b3698 & 0xfffffffc) << (uRam020b3698 & 3) * -8 + 0x20);
  if (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 == 0 &&
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 == 0) {
    uVar4 = (*(uint *)(uRam020b369c & 0xfffffffc) >> (uRam020b369c & 3) * 8 |
            *(uint *)(uRam020b369c & 0xfffffffc) << (uRam020b369c & 3) * -8 + 0x20) + 8;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 5) {
      iVar2 = func_02054754();
      if (iVar2 == 1) {
        *(undefined4 *)
         (*(uint *)(uRam020b3698 & 0xfffffffc) >> (uRam020b3698 & 3) * 8 |
         *(uint *)(uRam020b3698 & 0xfffffffc) << (uRam020b3698 & 3) * -8 + 0x20) = 1;
      }
      return;
    }
    if ((*(ushort *)
          ((*(uint *)(uRam020b36a0 & 0xfffffffc) >> (uRam020b36a0 & 3) * 8 |
           *(uint *)(uRam020b36a0 & 0xfffffffc) << (uRam020b36a0 & 3) * -8 + 0x20) + 0x75c) & 2) !=
        0) {
      *puVar1 = 1;
      func_020617f0();
      func_020d3c7c();
      return;
    }
    return;
  }
  uVar4 = (uint)(puVar1 + 2) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 2) & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (199 < (int)uVar4) {
    if ((int)uVar4 < 0x7fffffff) {
      puVar1[2] = uVar4 + 1;
    }
    return;
  }
  puVar1[2] = uVar4 + 1;
  if (uVar4 != 0xffffffff) {
    if (uVar4 == 0xb4) {
      func_02106efc();
      func_02061fcc();
      *(undefined4 *)
       ((*(uint *)(uRam020b3698 & 0xfffffffc) >> (uRam020b3698 & 3) * 8 |
        *(uint *)(uRam020b3698 & 0xfffffffc) << (uRam020b3698 & 3) * -8 + 0x20) + 4) = 1;
      return;
    }
    return;
  }
  func_0203c98c();
  return;
}

