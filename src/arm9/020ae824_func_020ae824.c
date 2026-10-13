/* Decompiled C draft; module arm9; ROM address 020ae824. No matching claim. */
#include "types.h"
#include "deps/020ae824_func_020ae824.h"

void func_020ae824(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (*(uint *)(DAT_020aeb6c & 0xfffffffc) >> (DAT_020aeb6c & 3) * 8 |
          *(uint *)(DAT_020aeb6c & 0xfffffffc) << (DAT_020aeb6c & 3) * -8 + 0x20) + 0xc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar1 == 3) {
    func_020c4ae8();
    return;
  }
  if (uVar1 == 5) {
    return;
  }
  if (uVar1 == 6) {
    func_020d12e0();
    return;
  }
  uVar1 = (*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
          *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 0x898;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  func_020b3410();
  func_020b3724();
  uVar4 = DAT_020aeb70;
  uVar2 = DAT_020aeb6c;
  *(undefined2 *)
   ((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
    *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 0x404) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x406) = 0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 4) {
    func_020d1198((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4);
  }
  uVar1 = (*(uint *)(DAT_020aeb6c & 0xfffffffc) >> (DAT_020aeb6c & 3) * 8 |
          *(uint *)(DAT_020aeb6c & 0xfffffffc) << (DAT_020aeb6c & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar1 == 2) {
    uVar1 = (*(uint *)(DAT_020aeb74 & 0xfffffffc) >> (DAT_020aeb74 & 3) * 8 |
            *(uint *)(DAT_020aeb74 & 0xfffffffc) << (DAT_020aeb74 & 3) * -8 + 0x20) + 0x4cc;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  else if (uVar1 == 4) {
    uVar1 = func_0203c174();
  }
  else {
    GetCurrentPlayerRacerId();
    iVar3 = IsRacerFinishedRace();
    if ((iVar3 == 0) ||
       (uVar1 = (*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 0x8dc,
       uVar2 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
       uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  if (uVar1 == 0) {
    func_020ba63c((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020bc208((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020d1fd4((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020d06b8((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020c4f08((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020b9dfc((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020c5804((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
  }
  else {
    func_020d06b8((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020c4f08((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
    func_020c5804((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                  *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4);
  }
  Arm_FlushRange((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                 *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 4,0x400);
  uVar1 = *(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
          *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar1 + 0x404);
  Mem_DmaFill32(3,uVar1 + 4 + uVar2 * 8,0xc0,(0x80 - uVar2) * 8);
  uVar1 = DAT_020aeb70;
  *(undefined2 *)
   ((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
    *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) + 0x808) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x80a) = 0;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0x828;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar1 != 4) && (uVar1 != 5)) {
    func_020bb5ec(uVar4 + DAT_020aeb78);
  }
  func_020be2f4((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) +
                DAT_020aeb78);
  Arm_FlushRange((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                 *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) +
                 DAT_020aeb78,0x400);
  uVar1 = *(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
          *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar1 + 0x808);
  Mem_DmaFill32(3,uVar1 + DAT_020aeb78 + uVar2 * 8,0xc0,(0x80 - uVar2) * 8);
  uVar4 = *(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
          *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0x828 & 3;
  uVar2 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    OamBuffer_SomeFn_0(uVar4 + DAT_020aeb78);
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    goto LAB_020aeb3c;
  case 5:
LAB_020aeb3c:
    StructRA_SomeFn_1(uVar4 + DAT_020aeb78);
    return;
  case 6:
    StructRA_SomeFn_4(uVar4 + DAT_020aeb78);
  default:
    return;
  }
  OamBuffer_SomeFn_0(uVar4 + DAT_020aeb78);
  func_020c3e44((*(uint *)(DAT_020aeb70 & 0xfffffffc) >> (DAT_020aeb70 & 3) * 8 |
                *(uint *)(DAT_020aeb70 & 0xfffffffc) << (DAT_020aeb70 & 3) * -8 + 0x20) +
                DAT_020aeb78);
  return;
}

