/* Decompiled C draft; module arm9_ov003; ROM address 021c6f64. No matching claim. */
#include "types.h"
#include "deps/021c6f64_FUN_021c6f64.h"

undefined4 FUN_021c6f64(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  byte local_24 [4];
  int local_20;
  byte local_1c [8];
  
  local_24[0] = *DAT_021c7048;
  local_24[1] = DAT_021c7048[1];
  local_24[2] = DAT_021c7048[2];
  local_24[3] = DAT_021c7048[3];
  iVar7 = 0;
  iVar5 = 0;
  do {
    iVar3 = *DAT_021c704c + 8;
    if (*(char *)(iVar3 + iVar5) != ' ') {
      iVar6 = 0;
      pbVar4 = local_24;
      do {
        bVar1 = *(byte *)(iVar3 + iVar5 + iVar6);
        if (*pbVar4 < bVar1) {
          return 0;
        }
        if (bVar1 < *pbVar4) break;
        pbVar4 = pbVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
    }
    iVar5 = iVar5 + 3;
    iVar7 = iVar7 + 1;
    if (3 < iVar7) {
      FUN_021cd2e0(*DAT_021c704c + 8,local_1c);
      FUN_021c20dc(&local_20,0);
      if (local_20 != 1) {
        iVar5 = func_0x02151620(local_1c);
        if (iVar5 != 0) {
          return 1;
        }
        return 0;
      }
      bVar2 = false;
      local_30 = 0;
      pbVar4 = local_1c;
      do {
        iVar5 = 0;
        do {
          if (bVar2) {
            if (((uint)*pbVar4 & 1 << (7U - iVar5 & 0xff)) != 0) {
              return 0;
            }
          }
          else if (((uint)*pbVar4 & 1 << (7U - iVar5 & 0xff)) == 0) {
            bVar2 = true;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 8);
        pbVar4 = pbVar4 + 1;
        local_30 = local_30 + 1;
      } while (local_30 < 4);
      return 1;
    }
  } while( true );
}

