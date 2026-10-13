/* Decompiled C draft; module arm9; ROM address 0205b32c. No matching claim. */
#include "types.h"
#include "deps/0205b32c_func_0205b32c.h"

void func_0205b32c(void)

{
  int iVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  short unaff_r6;
  uint uVar10;
  uint uVar11;
  uint local_4c;
  uint local_40;
  short local_38 [4];
  short local_30 [6];
  
  uVar11 = uRam0205b4f8;
  sVar3 = (short)uRam0205b4f4;
  uVar10 = 0;
  do {
    uVar9 = uVar11 & 3;
    uVar6 = *(uint *)(uVar11 & 0xfffffffc);
    if (*(char *)((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + uVar10 + 6) == -1) {
      local_38[uVar10] = sVar3;
    }
    else {
      sVar5 = GetTKSomeSize(uVar10);
      local_38[uVar10] = sVar5;
    }
    iVar4 = iRam0205b4fc;
    uVar10 = uVar10 + 1 & 0xff;
  } while (uVar10 < 4);
  uVar11 = 0;
  local_40 = 0;
  local_4c = 0;
  do {
    uVar10 = (uint)*(char *)((*(uint *)(uRam0205b4f8 & 0xfffffffc) >> (uRam0205b4f8 & 3) * 8 |
                             *(uint *)(uRam0205b4f8 & 0xfffffffc) << (uRam0205b4f8 & 3) * -8 + 0x20)
                             + uVar11 + 6);
    if (uVar10 != 0xffffffff) {
      local_30[uVar11] = local_38[uVar11];
      uVar9 = local_4c;
      do {
        uVar6 = (uint)*(char *)((*(uint *)(uRam0205b4f8 & 0xfffffffc) >> (uRam0205b4f8 & 3) * 8 |
                                *(uint *)(uRam0205b4f8 & 0xfffffffc) <<
                                (uRam0205b4f8 & 3) * -8 + 0x20) + uVar9 + 6);
        if ((uVar6 != 0xffffffff) && (uVar10 != uVar6)) {
          uVar7 = GetDriverPlace(uVar10 & 0xffff);
          uVar8 = GetDriverPlace(uVar6 & 0xffff);
          uVar6 = local_40;
          do {
            iVar1 = uVar6 * 4;
            if ((int)*(short *)(iVar4 + iVar1) <
                ((int)local_38[uVar9] - (int)local_38[uVar11]) * 0x10000 >> 0x10) {
              if (uVar8 < uVar7) {
                cVar2 = *(char *)(iVar4 + iVar1 + 3);
              }
              else {
                cVar2 = *(char *)(iVar4 + iVar1 + 2);
              }
              unaff_r6 = (short)cVar2;
              break;
            }
            uVar6 = uVar6 + 1 & 0xff;
          } while (uVar6 < 9);
          local_30[uVar11] = local_30[uVar11] + unaff_r6;
          if (local_30[uVar11] < 0) {
            local_30[uVar11] = 0;
          }
          else if (iRam0205b500 < local_30[uVar11]) {
            local_30[uVar11] = (short)iRam0205b500;
          }
        }
        uVar9 = uVar9 + 1 & 0xff;
      } while (uVar9 < 4);
      SetTKSomeSize(uVar11,(int)local_30[uVar11]);
    }
    uVar11 = uVar11 + 1 & 0xff;
    if (3 < uVar11) {
      return;
    }
  } while( true );
}

