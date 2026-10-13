/* Decompiled C draft; module arm9; ROM address 020abae0. No matching claim. */
#include "types.h"
#include "deps/020abae0_func_020abae0.h"

void func_020abae0(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = func_020ac238();
  func_020aa81c();
  func_020aa810();
  if ((*(ushort *)(iRam020abcd8 + 0x2e0) & 8) == 0) {
    iVar4 = func_020aa810();
    piVar1 = piRam020abcdc;
    if (iVar4 == 8) {
      *(undefined2 *)(*piRam020abcdc + 0x48) = *(undefined2 *)(*piRam020abcdc + 0x46);
      iVar3 = *piVar1;
      if (*(ushort *)(iVar3 + 0x46) != 0) {
        if (*(short *)(*(int *)(iVar3 + 0x40) + (uint)*(ushort *)(iVar3 + 0x46) * 2) == 0) {
          *(short *)(iVar3 + 0x46) = *(short *)(iVar3 + 0x46) + -1;
        }
        *(undefined2 *)
         (*(int *)(*piRam020abcdc + 0x40) + (uint)*(ushort *)(*piRam020abcdc + 0x46) * 2) = 0;
        NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abce4);
      }
    }
    else {
      uVar5 = func_020aa810();
      piVar1 = piRam020abcdc;
      if (uVar5 < 0x20) {
        iVar4 = func_020aa810();
        if (iVar4 == 0x10) {
          iVar3 = iVar3 * 2;
          uVar5 = func_020aa790(*(undefined2 *)(*(int *)(*piRam020abcdc + 0x40) + iVar3));
          if (uVar5 != *(ushort *)(*(int *)(*piRam020abcdc + 0x40) + iVar3)) {
            *(short *)(*(int *)(*piRam020abcdc + 0x40) + iVar3) = (short)uVar5;
            NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abcec);
          }
        }
        else {
          iVar4 = func_020aa810();
          if (iVar4 == 0x11) {
            iVar3 = iVar3 * 2;
            uVar5 = func_020aa738(*(undefined2 *)(*(int *)(*piRam020abcdc + 0x40) + iVar3));
            if (uVar5 != *(ushort *)(*(int *)(*piRam020abcdc + 0x40) + iVar3)) {
              *(short *)(*(int *)(*piRam020abcdc + 0x40) + iVar3) = (short)uVar5;
              NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abcec);
            }
          }
          else {
            iVar4 = func_020aa810();
            if (iVar4 == 0x12) {
              iVar3 = iVar3 * 2;
              uVar5 = func_020aa6e0(*(undefined2 *)(*(int *)(*piRam020abcdc + 0x40) + iVar3));
              if (uVar5 != *(ushort *)(*(int *)(*piRam020abcdc + 0x40) + iVar3)) {
                *(short *)(*(int *)(*piRam020abcdc + 0x40) + iVar3) = (short)uVar5;
                NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abcec);
              }
            }
            else {
              iVar4 = func_020aa810();
              if (iVar4 == 0x13) {
                iVar3 = iVar3 * 2;
                uVar5 = func_020aa650(*(undefined2 *)(*(int *)(*piRam020abcdc + 0x40) + iVar3));
                if (uVar5 == *(ushort *)(*(int *)(*piRam020abcdc + 0x40) + iVar3)) {
                  NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abcf0);
                }
                else {
                  *(short *)(*(int *)(*piRam020abcdc + 0x40) + iVar3) = (short)uVar5;
                  NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abcec);
                }
              }
            }
          }
        }
      }
      else {
        *(undefined2 *)(*piRam020abcdc + 0x48) = *(undefined2 *)(*piRam020abcdc + 0x46);
        iVar3 = *piVar1;
        if ((*(ushort *)(iVar3 + 0x46) < *(ushort *)(iVar3 + 0x4a)) &&
           (uVar5 = func_020aa810(),
           *(ushort *)(*(int *)(iVar3 + 0x40) + (uint)*(ushort *)(iVar3 + 0x46) * 2) != uVar5)) {
          iVar3 = *piRam020abcdc;
          uVar2 = func_020aa810();
          *(undefined2 *)(*(int *)(iVar3 + 0x40) + (uint)*(ushort *)(iVar3 + 0x46) * 2) = uVar2;
          piVar1 = piRam020abcdc;
          *(undefined2 *)
           (*(int *)(*piRam020abcdc + 0x40) + (*(ushort *)(*piRam020abcdc + 0x46) + 1) * 2) = 0;
          iVar3 = *piVar1;
          if ((int)(uint)*(ushort *)(iVar3 + 0x46) < (int)(*(ushort *)(iVar3 + 0x4a) - 1)) {
            *(short *)(iVar3 + 0x46) = *(short *)(iVar3 + 0x46) + 1;
          }
          NNSi_MaybeSndPlayerStartSeq(uRam020abce0,0,uRam020abce8);
        }
      }
    }
  }
  else {
    iVar3 = func_020ab8c4();
    if (iVar3 != 1) {
      func_020ab8cc(1);
    }
  }
  func_020aa810();
  return;
}

