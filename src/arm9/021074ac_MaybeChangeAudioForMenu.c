/* Decompiled C draft; module arm9; ROM address 021074ac. No matching claim. */
#include "types.h"
#include "deps/021074ac_MaybeChangeAudioForMenu.h"

void MaybeChangeAudioForMenu(void)

{
  bool bVar1;
  bool bVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  uint *puVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  
  if ((*DAT_021081b4 == 2) && (iVar9 = GetCurrentSceneId(), iVar9 == 6)) {
    return;
  }
  ClearGlobalVA();
  iVar9 = GetCurrentSceneId();
  uVar14 = 0x69;
  bVar2 = false;
  iVar10 = GetCurrentSceneId();
  if (iVar10 == 2) {
    bVar1 = true;
    uVar11 = (*(uint *)(DAT_021081b8 & 0xfffffffc) >> (DAT_021081b8 & 3) * 8 |
             *(uint *)(DAT_021081b8 & 0xfffffffc) << (DAT_021081b8 & 3) * -8 + 0x20) + 0xc;
    uVar12 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar11 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    if ((uVar11 != 0) && (uVar11 != 2)) {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    uVar12 = *(uint *)(DAT_021081b8 & 0xfffffffc) >> (DAT_021081b8 & 3) * 8 |
             *(uint *)(DAT_021081b8 & 0xfffffffc) << (DAT_021081b8 & 3) * -8 + 0x20;
    uVar11 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar11 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
    if ((int)uVar11 < 0x20) {
      if ((int)uVar11 < 0x1f) {
        if (((int)uVar11 < 0xe) && (9 < (int)uVar11)) {
          if (uVar11 == 10) {
            uVar14 = 0x6a;
          }
          else if (uVar11 == 0xb) {
            uVar14 = 0x6e;
          }
          else if (uVar11 == 0xd) goto LAB_021075ac;
        }
      }
      else {
        uVar14 = 0x80;
      }
    }
    else if ((int)uVar11 < 0x24) {
      if (uVar11 == 0x23) {
        uVar14 = 0x6e;
      }
    }
    else if (uVar11 == 0x25) {
LAB_021075ac:
      uVar14 = 0x76;
    }
  }
  if (0x7f < uVar14) {
    uVar14 = 0x7f;
  }
  *DAT_021081bc = uVar14;
  uVar8 = MaybeGetMusicForMenu(iVar9,&uStack_20);
  if (*(uint *)(DAT_021081c0 & 0xfffffffc) >> (DAT_021081c0 & 3) * 8 == 0 &&
      *(uint *)(DAT_021081c0 & 0xfffffffc) << (DAT_021081c0 & 3) * -8 + 0x20 == 0) {
    func_0210f808();
    func_0210f868(0,0);
    func_0210f868(1,0);
  }
  func_02110a60();
  func_02110838();
  func_021104dc(0);
  func_0204a4e4();
  func_0210d970();
  func_02110484();
  func_021103c0();
  if (2 < iVar9) {
    if ((iVar9 == 0xc) &&
       ((uVar14 = (uint)(DAT_0210821c + 2) & 3,
        uVar12 = *(uint *)((uint)(DAT_0210821c + 2) & 0xfffffffc), uVar11 = (uint)DAT_02108220 & 3,
        uVar15 = *(uint *)((uint)DAT_02108220 & 0xfffffffc),
        (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) == 0xff00 ||
        (*DAT_0210821c != DAT_02108224)))) {
      Sound_Context_DisposeLoadedStuff
                (*(uint *)(DAT_02108228 & 0xfffffffc) >> (DAT_02108228 & 3) * 8 |
                 *(uint *)(DAT_02108228 & 0xfffffffc) << (DAT_02108228 & 3) * -8 + 0x20);
      puVar7 = DAT_02108220;
      puVar5 = DAT_0210821c;
      uVar14 = DAT_02108228 & 3;
      uVar12 = *(uint *)(DAT_02108228 & 0xfffffffc);
      puVar5[2] = 0xff00;
      puVar5[3] = 0;
      *puVar5 = 0;
      *puVar7 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
      iVar10 = Sound_LoadSbnk(0x2c);
      if ((iVar10 != 0) &&
         (iVar10 = Sound_LoadSarc(3,*(uint *)((uint)DAT_02108220 & 0xfffffffc) >>
                                    ((uint)DAT_02108220 & 3) * 8 |
                                    *(uint *)((uint)DAT_02108220 & 0xfffffffc) <<
                                    ((uint)DAT_02108220 & 3) * -8 + 0x20), puVar5 = DAT_0210821c,
         iVar10 != 0)) {
        uVar4 = (ushort)DAT_02108224;
        *DAT_02108220 = uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20;
        *puVar5 = uVar4;
        puVar5[2] = 0xfe00;
        puVar5[3] = 0;
      }
    }
    goto switchD_02107e30_default;
  }
  if ((iVar9 < 0) || (iVar9 == 0)) goto switchD_02107e30_default;
  if (iVar9 == 1) {
    if ((*DAT_021081b4 != 2) &&
       ((uVar14 = (uint)(DAT_0210821c + 2) & 3,
        uVar12 = *(uint *)((uint)(DAT_0210821c + 2) & 0xfffffffc), uVar11 = (uint)DAT_02108220 & 3,
        uVar15 = *(uint *)((uint)DAT_02108220 & 0xfffffffc),
        (uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20) == 0xff00 ||
        (*DAT_0210821c != DAT_02108224)))) {
      Sound_Context_DisposeLoadedStuff
                (*(uint *)(DAT_02108228 & 0xfffffffc) >> (DAT_02108228 & 3) * 8 |
                 *(uint *)(DAT_02108228 & 0xfffffffc) << (DAT_02108228 & 3) * -8 + 0x20);
      puVar7 = DAT_02108220;
      puVar5 = DAT_0210821c;
      uVar14 = DAT_02108228 & 3;
      uVar12 = *(uint *)(DAT_02108228 & 0xfffffffc);
      puVar5[2] = 0xff00;
      puVar5[3] = 0;
      *puVar5 = 0;
      *puVar7 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
      iVar10 = Sound_LoadSbnk(0x2c);
      if ((iVar10 != 0) &&
         (iVar10 = Sound_LoadSarc(3,*(uint *)((uint)DAT_02108220 & 0xfffffffc) >>
                                    ((uint)DAT_02108220 & 3) * 8 |
                                    *(uint *)((uint)DAT_02108220 & 0xfffffffc) <<
                                    ((uint)DAT_02108220 & 3) * -8 + 0x20), puVar5 = DAT_0210821c,
         iVar10 != 0)) {
        uVar4 = (ushort)DAT_02108224;
        *DAT_02108220 = uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20;
        *puVar5 = uVar4;
        puVar5[2] = 0xfe00;
        puVar5[3] = 0;
      }
    }
    goto switchD_02107e30_default;
  }
  if (iVar9 != 2) goto switchD_02107e30_default;
  uVar11 = *(uint *)(DAT_021081b8 & 0xfffffffc) >> (DAT_021081b8 & 3) * 8 |
           *(uint *)(DAT_021081b8 & 0xfffffffc) << (DAT_021081b8 & 3) * -8 + 0x20;
  uVar14 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar14 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
  if ((int)uVar14 < 0x27) {
                    /* WARNING: Could not recover jumptable at 0x0210766c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (-1 < (int)(uVar14 - 9)) {
      (*(code *)((uVar14 - 9) * 4 + 0x2107674))();
      return;
    }
  }
  else if (((int)uVar14 < 0x33) && (0x2e < (int)uVar14)) {
    if (uVar14 == 0x2f) {
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(0x15,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(8,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(9,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(0xd,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(0xe,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
      uVar11 = (uint)(PTR_data_021081c4 + 100) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 100) & 0xfffffffc);
      SetSomeVAVO(0x10,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081f4);
    }
    else if (uVar14 == 0x32) {
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(0x15,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(8,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(9,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(0xd,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(0xe,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (uint)(PTR_data_021081c4 + 0x6c) & 3;
      uVar12 = *(uint *)((uint)(PTR_data_021081c4 + 0x6c) & 0xfffffffc);
      SetSomeVAVO(0x10,uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,DAT_021081fc);
      uVar11 = (*(uint *)(DAT_021081b8 & 0xfffffffc) >> (DAT_021081b8 & 3) * 8 |
               *(uint *)(DAT_021081b8 & 0xfffffffc) << (DAT_021081b8 & 3) * -8 + 0x20) + 0xc;
      uVar12 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (uVar11 >> uVar12 * 8 == 0 && uVar11 << uVar12 * -8 + 0x20 == 0) {
        func_021104dc(1);
      }
    }
  }
  func_0210f5d4(uVar14);
  puVar6 = DAT_02108208;
  uVar12 = *(uint *)(DAT_021081b8 & 0xfffffffc) >> (DAT_021081b8 & 3) * 8 |
           *(uint *)(DAT_021081b8 & 0xfffffffc) << (DAT_021081b8 & 3) * -8 + 0x20;
  uVar14 = uVar12 + 8 & 3;
  uVar11 = *(uint *)(uVar12 + 8 & 0xfffffffc);
  if ((uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) != 4) goto switchD_02107e30_default;
  uVar3 = (undefined2)DAT_02108218;
  switch(*(undefined1 *)(uVar12 + 0x2f)) {
  case 0:
    *DAT_02108204 = (short)DAT_02108210;
    *puVar6 = 0x1dc;
    break;
  case 1:
    uVar3 = (undefined2)DAT_02108200;
    *DAT_02108204 = uVar3;
    *puVar6 = uVar3;
    break;
  case 2:
    goto LAB_02107ed4;
  case 3:
    *DAT_02108204 = (short)DAT_02108214;
    *puVar6 = uVar3;
    break;
  case 4:
    *DAT_02108204 = (short)DAT_02108214;
    *puVar6 = uVar3;
    break;
  case 5:
    break;
  case 6:
LAB_02107ed4:
    *DAT_02108204 = 0xff;
    *puVar6 = 0xff;
    break;
  case 7:
    uVar3 = (undefined2)DAT_0210820c;
    *DAT_02108204 = 0x1e0;
    *puVar6 = uVar3;
    if ((*(char *)(uVar12 + 0x2e) == '\t') || (*(char *)(uVar12 + 0x2e) == '\n')) {
      *DAT_02108208 = 0xff;
    }
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
  }
switchD_02107e30_default:
  uStack_1c = 0xff;
  uStack_1b = uStack_20;
  uStack_1a = uStack_1f;
  func_021103c0();
  MKDS_SLICE_2(uStack_24,0) = CONCAT11(uStack_1b,uStack_1c);
  uStack_24._0_3_ = CONCAT12(uStack_1a,(undefined2)uStack_24);
  func_021073ec(uVar8,(undefined3)uStack_24,DAT_0210822c);
  func_0210912c();
  func_0210b870();
  func_0210aefc();
  func_021105a0();
  func_0210fb68();
  if (*DAT_021081b4 != 2) {
    MKDS_SLICE_2(uStack_24,0) = CONCAT11(uStack_1f,uStack_20);
    uStack_24._0_3_ = CONCAT12(uStack_1e,(undefined2)uStack_24);
    uStack_24 = CONCAT13(uStack_1d,(undefined3)uStack_24);
    func_0210e888(uStack_24,0);
  }
  if (iVar9 != 1) {
    return;
  }
  if (*DAT_021081b4 != 2) {
    Sound_LoadSbnk(2,*(uint *)((uint)DAT_02108220 & 0xfffffffc) >> ((uint)DAT_02108220 & 3) * 8 |
                     *(uint *)((uint)DAT_02108220 & 0xfffffffc) <<
                     ((uint)DAT_02108220 & 3) * -8 + 0x20);
  }
  if (*DAT_021081b4 == 2) {
    return;
  }
  uVar13 = Sound_Context_BackupFrameState
                     (*(uint *)((uint)DAT_02108220 & 0xfffffffc) >> ((uint)DAT_02108220 & 3) * 8 |
                      *(uint *)((uint)DAT_02108220 & 0xfffffffc) <<
                      ((uint)DAT_02108220 & 3) * -8 + 0x20);
  *DAT_02108230 = uVar13;
  iVar9 = GetCurrentSceneId();
  if (iVar9 != 1) {
    return;
  }
  uVar14 = (*(uint *)(DAT_02108234 & 0xfffffffc) >> (DAT_02108234 & 3) * 8 |
           *(uint *)(DAT_02108234 & 0xfffffffc) << (DAT_02108234 & 3) * -8 + 0x20) + 8;
  uVar11 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  if ((uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) == 3) {
    *(undefined1 *)(DAT_02108238 + 10) = 0xff;
  }
  return;
}

