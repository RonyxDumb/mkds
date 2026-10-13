/* Decompiled C draft; module arm9; ROM address 0211acec. No matching claim. */
#include "types.h"
#include "deps/0211acec_func_0211acec.h"

void func_0211acec(void)

{
  bool bVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  
  uVar7 = 0xffffffff;
  func_0211c818();
  func_0211c14c();
  bVar5 = false;
  bVar1 = false;
  psVar3 = (short *)(iRam0211af9c + 0x2e0);
  if ((*(short *)(iRam0211af9c + 0x2e0) == 0) && (*(ushort *)(iRam0211afa0 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(iRam0211afa4 + 0x2e0) == 0)) &&
     (*(short *)(iRam0211af9c + 0x2e0) != 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    puVar8 = (ushort *)(iRam0211afa8 + 0x2e0);
    puVar9 = (undefined2 *)(iRam0211afac + 0x2e0);
    uVar7 = func_0201ea84(*(undefined4 *)(*piRam0211afb0 + 8),*(undefined2 *)(iRam0211afac + 0x2e0),
                          *(undefined2 *)(iRam0211afa8 + 0x2e0));
    if ((uVar7 != 0x13) &&
       (uVar7 = func_0201ea84(*(undefined4 *)(*piRam0211afb0 + 8),*puVar9,
                              (uint)*puVar8 - (int)*(short *)(*piRam0211afb0 + 0x58)), uVar7 == 0x13
       )) {
      uVar7 = 0xffffffff;
    }
  }
  puVar8 = (ushort *)(iRam0211afb4 + 0x2e0);
  if ((*(ushort *)(iRam0211afb4 + 0x2e0) & 2) == 0) {
    bVar5 = false;
    bVar1 = false;
    if ((*psVar3 == 0) && (*(ushort *)(iRam0211afa0 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(iRam0211afa4 + 0x2e0) == 0)) && (*psVar3 != 0)) {
      bVar5 = true;
    }
    if ((!bVar5) ||
       (iVar4 = func_02128210(*(undefined2 *)(iRam0211afac + 0x2e0),
                              *(undefined2 *)(iRam0211afa8 + 0x2e0)), iVar4 == 0)) {
      piVar2 = piRam0211afb0;
      if (uVar7 < 5) {
        iVar6 = *(int *)(iRam0211afb8 + uVar7 * 4);
        iVar4 = func_0211d650();
        piVar2 = piRam0211afb0;
        if ((iVar4 != 8) || (iVar6 != 1)) {
          *(int *)(*piRam0211afb0 + 0x60) = iVar6;
          *(undefined4 *)(*piVar2 + 0x7c) = 0;
          func_0211cb6c(1);
        }
      }
      else if (uVar7 - 5 < 5) {
        iVar6 = *(int *)(iRam0211afbc + uVar7 * 4);
        iVar4 = func_0211d650();
        piVar2 = piRam0211afb0;
        if ((iVar4 != 8) || (iVar6 != 1)) {
          *(int *)(*piRam0211afb0 + 0x60) = iVar6;
          *(undefined4 *)(*piVar2 + 0x7c) = 0;
          func_0211ccac(1);
        }
      }
      else if (uVar7 == 0x13) {
        if (*(int *)(*piRam0211afb0 + 0x7c) != 0) {
          *(undefined4 *)(*piRam0211afb0 + 0x84) = 0;
        }
        *(undefined4 *)(*piRam0211afb0 + 0x7c) = 1;
        func_0211ba58();
      }
      else if (uVar7 - 10 < 5) {
        iVar6 = *(int *)(iRam0211afc0 + uVar7 * 4);
        iVar4 = func_0211d650();
        piVar2 = piRam0211afb0;
        if ((iVar4 != 8) || (iVar6 != 1)) {
          *(int *)(*piRam0211afb0 + 0x60) = iVar6;
          *(undefined4 *)(*piVar2 + 0x7c) = 0;
          NNSi_MaybeSndPlayerStartSeq(uRam0211afc4,0,0);
        }
      }
      else if ((*puVar8 & 1) == 0) {
        if (uVar7 == 0xf) {
          if (*(int *)(*piRam0211afb0 + 0x74) != 2) {
            *(undefined4 *)(*piRam0211afb0 + 0x60) = 3;
            *(undefined4 *)(*piVar2 + 0x7c) = 0;
            func_0211ca8c();
          }
        }
        else if (uVar7 == 0x10) {
          if (*(int *)(*piRam0211afb0 + 0x74) != 2) {
            *(undefined4 *)(*piRam0211afb0 + 0x60) = 3;
            *(undefined4 *)(*piVar2 + 0x7c) = 0;
            func_0211cafc();
          }
        }
        else {
          iVar4 = func_020ae408(8,0x40);
          if (iVar4 == 0) {
            iVar4 = func_020ae408(8,0x80);
            if (iVar4 == 0) {
              iVar4 = func_020ae408(8,0x20);
              if (iVar4 == 0) {
                iVar4 = func_020ae408(8,0x10);
                if (iVar4 == 0) {
                  iVar4 = func_020ae408(8,uRam0211afc8);
                  if (iVar4 == 0) {
                    iVar4 = func_020ae408(8,uRam0211afcc);
                    if (iVar4 != 0) {
                      func_0211cafc();
                    }
                  }
                  else {
                    func_0211ca8c();
                  }
                }
                else if (*(int *)(*piRam0211afb0 + 0x7c) == 0) {
                  func_0211ccac(1);
                }
              }
              else if (*(int *)(*piRam0211afb0 + 0x7c) == 0) {
                func_0211cb6c(1);
              }
            }
            else {
              func_0211d56c();
            }
          }
          else {
            func_0211d4a8();
          }
        }
      }
      else if (*(int *)(*piRam0211afb0 + 0x7c) == 0) {
        func_0211d56c();
      }
      else {
        func_0211ba58();
        *(undefined4 *)(*piRam0211afb0 + 0x84) = 0;
      }
      goto LAB_0211af86;
    }
  }
  if ((*(int *)(*piRam0211afb0 + 0x2c) == 0) || (*(int *)(*piRam0211afb0 + 0x2c) == 1)) {
    func_021281c8(0xe);
    func_0211b9d8();
    *(undefined4 *)(*piRam0211afb0 + 0xb8) = 2;
    func_02128310(0);
    func_0202b7c0(1);
  }
LAB_0211af86:
  if (*(int *)(*piRam0211afb0 + 0x34) != 4) {
    func_0211bf94();
  }
  return;
}

