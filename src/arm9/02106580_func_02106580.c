/* Decompiled C draft; module arm9; ROM address 02106580. No matching claim. */
#include "types.h"
#include "deps/02106580_func_02106580.h"

void func_02106580(void)

{
  int *piVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar9;
  uint uVar8;
  
  uVar8 = (uint)(piRam02106854 + 3) & 3;
  uVar7 = *(uint *)((uint)(piRam02106854 + 3) & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (uVar8 == 1) {
    iVar6 = (*(uint *)((uint)piRam02106854 & 0xfffffffc) >> ((uint)piRam02106854 & 3) * 8 |
            *(uint *)((uint)piRam02106854 & 0xfffffffc) << ((uint)piRam02106854 & 3) * -8 + 0x20) +
            1;
    *piRam02106854 = iVar6;
    if (iVar6 == 0x28) {
      func_0210d5c0(uRam02106858);
      uVar8 = iRam0210685c + 4U & 3;
      uVar7 = *(uint *)(iRam0210685c + 4U & 0xfffffffc);
      func_0212c678(uRam02106860,(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) >> 0xc);
    }
    iVar6 = iRam0210686c;
    puVar2 = puRam02106864;
    uVar8 = (uint)(puRam02106864 + 2) & 3;
    uVar7 = *(uint *)((uint)(puRam02106864 + 2) & 0xfffffffc);
    if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) {
      uVar8 = iRam02106868 + 4U & 3;
      uVar7 = *(uint *)(iRam02106868 + 4U & 0xfffffffc);
      *puRam02106864 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      uVar8 = iVar6 + 4U & 3;
      uVar7 = *(uint *)(iVar6 + 4U & 0xfffffffc);
      iVar6 = func_02110640((uint)(uintptr_t)(puVar2),uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
      if (iVar6 != -1) {
        uVar8 = iRam02106870 + 4U & 3;
        uVar7 = *(uint *)(iRam02106870 + 4U & 0xfffffffc);
        iVar4 = Sound_IsGlobalSdatUsed();
        if (iVar4 != 0) {
          uVar5 = Sound_GetActiveSdat();
          Sound_MaybeSetActiveSdat(uRam02106874);
          uVar9 = 1;
          do {
            iVar4 = Sound_GetPlayerInfoEntry(uVar9);
            if ((iVar4 != 0) &&
               (((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) >> (uVar9 & 0xff) & 1U) != 0
               )) {
              MaybeSetPlayerVolume(uVar9,iVar6);
            }
            uVar9 = uVar9 + 1;
          } while ((int)uVar9 < 8);
          Sound_MaybeSetActiveSdat(uVar5);
        }
      }
    }
    func_0210faf4();
    func_0210b610();
  }
  else if (uVar8 == 2) {
    func_02111024();
  }
  uVar9 = uRam02106860;
  uVar8 = (*(uint *)(uRam02106878 & 0xfffffffc) >> (uRam02106878 & 3) * 8 |
          *(uint *)(uRam02106878 & 0xfffffffc) << (uRam02106878 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) == 2) {
    func_0210add4();
  }
  else {
    iVar6 = func_0210f858();
    if (((iVar6 != 0) &&
        (func_0210f780(uVar9),
        uVar7 = *(uint *)(uRam02106878 & 0xfffffffc) >> (uRam02106878 & 3) * 8 |
                *(uint *)(uRam02106878 & 0xfffffffc) << (uRam02106878 & 3) * -8 + 0x20,
        uVar8 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 0x1c)) &&
       ((iVar6 = func_0210f75c(0), iVar6 != 0 || (iVar6 = func_0210f75c(1), iVar6 != 0)))) {
      func_0210f35c(0,uRam0210687c);
    }
    uVar7 = *(uint *)(uRam02106878 & 0xfffffffc) >> (uRam02106878 & 3) * 8 |
            *(uint *)(uRam02106878 & 0xfffffffc) << (uRam02106878 & 3) * -8 + 0x20;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 0x20) {
      func_0210f230(0,uRam02106880);
    }
    piVar1 = piRam02106854;
    uVar8 = (uint)(piRam02106854 + 7) & 3;
    uVar7 = *(uint *)((uint)(piRam02106854 + 7) & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((uVar8 != 0xffffffff) && (iVar6 = uVar8 + 1, piRam02106854[7] = iVar6, 0x3b < iVar6)) {
      piVar1[7] = -1;
    }
    piVar1 = piRam02106854;
    if ((*(char *)((int)piRam02106854 + 0x16) == '\x01') &&
       (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 == 0 &&
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20 == 0)) {
      uVar8 = (uint)puRam02106884 & 3;
      uVar7 = *(uint *)((uint)puRam02106884 & 0xfffffffc);
      *(undefined1 *)((int)piRam02106854 + 0x16) = 0;
      if ((uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) ||
         (*(char *)((int)piVar1 + 0x17) != '\x01')) {
        uVar8 = (uint)(piRam02106854 + 2) & 3;
        uVar7 = *(uint *)((uint)(piRam02106854 + 2) & 0xfffffffc);
        if (uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) {
          uVar8 = (uint)(piRam02106854 + 3) & 3;
          uVar7 = *(uint *)((uint)(piRam02106854 + 3) & 0xfffffffc);
          if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) {
            func_0210d5c0(uRam02106858);
            uVar8 = iRam0210685c + 4U & 3;
            uVar7 = *(uint *)(iRam0210685c + 4U & 0xfffffffc);
            func_0212c678(uRam02106860,(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) >> 0xc
                         );
            func_0212c494(uRam02106860,300);
            func_0210faac();
          }
        }
        else {
          NNS_SndPlayerSetTrackMute(uRam0210688c,uRam02106888,0);
          *puRam02106890 = 1;
        }
      }
      else {
        uVar8 = (uint)(piVar1 + 3) & 3;
        uVar7 = *(uint *)((uint)(piVar1 + 3) & 0xfffffffc);
        if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) &&
           (*(undefined1 *)((int)piVar1 + 0x17) = 1, (*(byte *)((int)piVar1 + 0x16) & 1) == 0)) {
          NNS_SndPlayerSetTrackMute(uRam02106860,uRam02106888);
          func_0210d614(uRam02106858,0x49,uRam0210688c);
        }
        puVar3 = puRam02106890;
        *puRam02106884 = 0;
        *puVar3 = 1;
      }
    }
  }
  *puRam02106898 =
       *(uint *)(uRam02106894 & 0xfffffffc) >> (uRam02106894 & 3) * 8 |
       *(uint *)(uRam02106894 & 0xfffffffc) << (uRam02106894 & 3) * -8 + 0x20;
  return;
}

