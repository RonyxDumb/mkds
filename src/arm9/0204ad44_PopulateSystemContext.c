/* Decompiled C draft; module arm9; ROM address 0204ad44. No matching claim. */
#include "types.h"
#include "deps/0204ad44_PopulateSystemContext.h"

void PopulateSystemContext(void)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 auStack_54 [20];
  undefined2 local_40;
  uint uVar6;
  
  Os_GetPersonalData(&local_58);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
               *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20) + 0x2a),0,0x14
              );
  uVar5 = DAT_0204af5c;
  *(undefined2 *)
   ((*(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
    *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20) + 0x3e) = local_40;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  Mem_CpuCopy8((ushort *)(void *)(auStack_54),(uint *)(uintptr_t)(uVar6 + 0x2a),(uint)*(ushort *)(uVar6 + 0x3e) << 1);
  uVar6 = DAT_0204af5c;
  *(undefined1 *)
   ((*(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
    *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20) + 0x40) = local_57;
  *(undefined4 *)
   (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
   *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) = 2;
  switch(local_58) {
  case 0:
  default:
    *(undefined4 *)
     ((*(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
      *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20) + 4) = 1;
    break;
  case 1:
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 1;
    break;
  case 2:
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 2;
    break;
  case 3:
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 3;
    break;
  case 4:
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 4;
    break;
  case 5:
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 5;
  }
  uVar7 = DAT_0204af5c;
  *(undefined4 *)
   ((*(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
    *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20) + 0x20) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x28) = 0xffff;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x44) = 0xffffffff;
  uVar8 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar6 = uVar8 + 0x1c;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar8 + 0x1c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffe;
  uVar8 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar6 = uVar8 + 0x1c;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar8 + 0x1c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffd;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x58) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x5c) = 0;
  func_02012b20();
  psVar1 = DAT_0204af60;
  uVar7 = DAT_0204af5c;
  uVar8 = *(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
          *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20;
  uVar6 = uVar8 + 0x1c;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(uVar8 + 0x1c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffff7;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x54) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x50) = 0;
  if (*psVar1 == 2) {
    uVar7 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar6 = uVar7 + 0x1c;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar7 + 0x1c) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20 | 4;
  }
  else {
    uVar7 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar6 = uVar7 + 0x1c;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(uVar7 + 0x1c) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffb;
  }
  iVar3 = Os_GetTick();
  iVar4 = Os_GetTick();
  uVar6 = *(uint *)(DAT_0204af5c & 0xfffffffc) >> (DAT_0204af5c & 3) * 8 |
          *(uint *)(DAT_0204af5c & 0xfffffffc) << (DAT_0204af5c & 3) * -8 + 0x20;
  *(int *)(uVar6 + 0x60) = iVar3 * 0x10000 + iVar4;
  uVar2 = DAT_0204af64;
  *(undefined4 *)(uVar6 + 100) = 0;
  *(undefined4 *)(uVar6 + 0x68) = uVar2;
  uVar2 = DAT_0204af6c;
  *(undefined4 *)(uVar6 + 0x6c) = DAT_0204af68;
  *(undefined4 *)(uVar6 + 0x70) = uVar2;
  *(undefined4 *)(uVar6 + 0x74) = 0;
  iVar3 = Pm_GetBacklightStatus((uint *)(uintptr_t)(uVar6 + 0x48),(uint *)(uintptr_t)(uVar6 + 0x4c));
  if (iVar3 == 0) {
    return;
  }
  func_0204aab4(1,1);
  return;
}

