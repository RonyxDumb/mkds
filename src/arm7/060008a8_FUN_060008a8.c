/* Decompiled C draft; module arm7; ROM address 060008a8. No matching claim. */
#include "types.h"
#include "deps/060008a8_FUN_060008a8.h"

void FUN_060008a8(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  bool bVar10;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  uint uVar9;
  
  iVar2 = FUN_06000680();
  uVar9 = iVar2 + 0x154cU & 3;
  uVar8 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  psVar6 = (short *)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20);
  if ((*psVar6 == 7) || (*psVar6 == 9)) {
    thunk_FUN_037fb390(param_1 + 0x10,&local_28,6);
    uVar9 = 0;
    for (iVar2 = 0; iVar2 < 0xf; iVar2 = iVar2 + 1) {
      iVar7 = iVar2 * 6;
      if ((((local_28 == (char)psVar6[iVar2 * 3 + 0x92]) &&
           (local_27 == *(char *)((int)psVar6 + iVar7 + 0x125))) &&
          (local_26 == (char)psVar6[iVar2 * 3 + 0x93])) &&
         (((local_25 == *(char *)((int)psVar6 + iVar7 + 0x127) &&
           (local_24 == (char)psVar6[iVar2 * 3 + 0x94])) &&
          (local_23 == *(char *)((int)psVar6 + iVar7 + 0x129))))) {
        uVar9 = iVar2 + 1U & 0xffff;
        thunk_FUN_037faf70();
        uVar1 = ~(ushort)(1 << (iVar2 + 1U & 0xff));
        psVar6[0xbf] = psVar6[0xbf] & uVar1;
        psVar6[0x43] = psVar6[0x43] & uVar1;
        (psVar6 + uVar9 * 4 + 0x39a)[0] = 0;
        (psVar6 + uVar9 * 4 + 0x39a)[1] = 0;
        (psVar6 + uVar9 * 4 + 0x39c)[0] = 0;
        (psVar6 + uVar9 * 4 + 0x39c)[1] = 0;
        thunk_FUN_037faf84();
        *(undefined1 *)(psVar6 + iVar2 * 3 + 0x92) = 0;
        *(undefined1 *)((int)psVar6 + iVar7 + 0x125) = 0;
        *(undefined1 *)(psVar6 + iVar2 * 3 + 0x93) = 0;
        *(undefined1 *)((int)psVar6 + iVar7 + 0x127) = 0;
        *(undefined1 *)(psVar6 + iVar2 * 3 + 0x94) = 0;
        *(undefined1 *)((int)psVar6 + iVar7 + 0x129) = 0;
        break;
      }
    }
    if (uVar9 != 0) {
      puVar3 = (undefined2 *)thunk_FUN_03807424();
      *puVar3 = 8;
      puVar3[1] = 0;
      puVar3[4] = 9;
      puVar3[9] = *(undefined2 *)(param_1 + 0x16);
      puVar3[8] = (short)uVar9;
      thunk_FUN_037fb390(param_1 + 0x10,puVar3 + 5,6);
      thunk_FUN_038074cc(puVar3);
      uVar8 = (uint)(psVar6 + 6) & 3;
      uVar4 = *(uint *)((uint)(psVar6 + 6) & 0xfffffffc);
      if ((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) == 1) {
        FUN_06006d24(1 << (uVar9 & 0xff) & 0xffff);
      }
    }
  }
  else {
    uVar5 = thunk_FUN_037faf70();
    uVar8 = (uint)(psVar6 + 6) & 3;
    uVar4 = *(uint *)((uint)(psVar6 + 6) & 0xfffffffc);
    bVar10 = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) == 1;
    if (bVar10) {
      psVar6[6] = 0;
      psVar6[7] = 0;
      thunk_FUN_037fabc0(uVar9 + 0xd0);
      FUN_06000154();
    }
    psVar6[0xbf] = 0;
    psVar6[0x43] = 0;
    psVar6[10] = 0;
    psVar6[0xb] = 0;
    psVar6[8] = 0;
    psVar6[9] = 0;
    psVar6[0xe] = 0;
    psVar6[0xf] = 0;
    psVar6[0x5f] = 0;
    *psVar6 = 3;
    thunk_FUN_037faf84(uVar5);
    puVar3 = (undefined2 *)thunk_FUN_03807424();
    *puVar3 = 0xc;
    puVar3[1] = 0;
    puVar3[4] = 9;
    puVar3[6] = *(undefined2 *)(param_1 + 0x16);
    puVar3[5] = psVar6[0xc2];
    psVar6[199] = 0;
    psVar6[200] = 0;
    thunk_FUN_038074cc();
    if (bVar10) {
      FUN_06006d24(1);
    }
  }
  return;
}

