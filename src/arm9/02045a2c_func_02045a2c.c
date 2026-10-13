/* Decompiled C draft; module arm9; ROM address 02045a2c. No matching claim. */
#include "types.h"
#include "deps/02045a2c_func_02045a2c.h"

/* WARNING: Removing unreachable block (ram,0x02045afc) */
/* WARNING: Removing unreachable block (ram,0x02045b10) */

void func_02045a2c(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_30;
  uint local_28;
  
  uVar1 = uRam02045bcc;
  bVar7 = param_1 != 0;
  if (bVar7) {
    param_1 = uRam02045bcc;
  }
  uVar6 = 0;
  if (bVar7) {
    *(undefined4 *)
     ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x1e8) = 0x36;
    uVar1 = uRam02045bcc;
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uRam02045bcc & 0xfffffffc) >> (uRam02045bcc & 3) * 8 |
      *(uint *)(uRam02045bcc & 0xfffffffc) << (uRam02045bcc & 3) * -8 + 0x20) + 0x1e8) = 0x35;
  }
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 500) = 6;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f8) = 1;
  local_28 = 0;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x24b) = 0;
  local_30 = 0;
  do {
    if (*(char *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      uVar5 = local_30;
      do {
        iVar2 = GetSomeRacerPosition(uVar5 & 0xffff);
        if (uVar6 + 1 == iVar2) break;
        uVar5 = (int)((uVar5 + 1) * 0x1000000) >> 0x18;
      } while ((int)uVar5 <
               (int)(uint)*(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
                                   0x3d0));
    }
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar5 = uVar3 + 8 & 3;
    uVar4 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar6;
    if (uVar4 == 4) {
      if ((*(char *)(uVar3 + 0x54) == '\x06') && (*(char *)(uVar3 + 0x55) == '\t')) {
        if (uVar6 == 0) {
          uVar5 = 7;
        }
        else {
          uVar5 = local_28;
          if (uVar6 != 7) {
            uVar5 = uVar6;
          }
        }
      }
    }
    else if ((uVar4 == 0) && (iVar2 = func_020909cc(), iVar2 == 2)) {
      uVar5 = (*(uint *)(uRam02045bd0 & 0xfffffffc) >> (uRam02045bd0 & 3) * 8 |
              *(uint *)(uRam02045bd0 & 0xfffffffc) << (uRam02045bd0 & 3) * -8 + 0x20) + uVar6 * 4 +
              0xac;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    }
    StructCO_ConfigureRacerDefault(uVar6,uVar5);
    uVar6 = uVar6 + 1 & 0xff;
    if (7 < uVar6) {
      return;
    }
  } while( true );
}

