/* Decompiled C draft; module arm9; ROM address 0203c5f8. No matching claim. */
#include "types.h"
#include "deps/0203c5f8_GetLeastTimeLap.h"

/* WARNING: Removing unreachable block (ram,0x0203c6f0) */

uint GetLeastTimeLap(int param_1,undefined1 *param_2,undefined1 *param_3,ushort *param_4)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  ushort local_2c;
  undefined2 local_2a;
  
  uVar7 = 1;
  uVar6 = (*(uint *)(uRam0203c770 & 0xfffffffc) >> (uRam0203c770 & 3) * 8 |
          *(uint *)(uRam0203c770 & 0xfffffffc) << (uRam0203c770 & 3) * -8 + 0x20) + 0x18;
  uVar3 = uVar6 & 3;
  uVar4 = *(uint *)(uVar6 & 0xfffffffc);
  bVar1 = true;
  uVar6 = 1;
  if (*(short *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 2) != 0) {
    do {
      puVar5 = (ushort *)
               ((*(uint *)(uRam0203c774 & 0xfffffffc) >> (uRam0203c774 & 3) * 8 |
                *(uint *)(uRam0203c774 & 0xfffffffc) << (uRam0203c774 & 3) * -8 + 0x20) + 0x20 +
                param_1 * 0x8c + (uVar6 - 1) * 4);
      if (bVar1) {
        local_2c = *puVar5;
        local_2a = puVar5[1];
        bVar1 = false;
        uVar7 = uVar6;
      }
      else {
        bVar2 = false;
        if ((((uint)(byte)puVar5[1] * 0x3c + (uint)*(byte *)((int)puVar5 + 3)) * 1000 +
             (uint)*puVar5 <=
             ((uint)(byte)local_2a * 0x3c + (uint)MKDS_SLICE_1(local_2a,1)) * 1000 + (uint)local_2c) &&
           (bVar2 = true, puVar5 != &local_2c)) {
          Mem_CpuCopy8(puVar5,&local_2c,4);
        }
        if (bVar2) {
          local_2c = *puVar5;
          local_2a = puVar5[1];
          uVar7 = uVar6;
        }
      }
      uVar6 = uVar6 + 1 & 0xffff;
      uVar3 = (*(uint *)(uRam0203c770 & 0xfffffffc) >> (uRam0203c770 & 3) * 8 |
              *(uint *)(uRam0203c770 & 0xfffffffc) << (uRam0203c770 & 3) * -8 + 0x20) + 0x18;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    } while (uVar6 <= *(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 2));
  }
  *param_2 = (byte)local_2a;
  *param_3 = MKDS_SLICE_1(local_2a,1);
  *param_4 = local_2c;
  return uVar7;
}

