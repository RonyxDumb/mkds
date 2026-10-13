/* Decompiled C draft; module arm9_ov000; ROM address 021a1140. No matching claim. */
#include "types.h"
#include "deps/021a1140_FUN_021a1140.h"

void FUN_021a1140(int param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_021a1364;
  *(undefined1 *)(*DAT_021a1364 + 0xc) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a1368) = 0;
  uVar2 = FUN_021a3448(DAT_021a136c);
  piVar1 = DAT_021a1364;
  *(undefined2 *)(*DAT_021a1364 + DAT_021a1370) = uVar2;
  *(undefined4 *)(*piVar1 + DAT_021a1374) = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(iVar3 + DAT_021a1378) = 0;
  *(undefined4 *)(iVar3 + DAT_021a137c) = 0;
  *(undefined4 *)(iVar3 + DAT_021a1380) = 0;
  *(undefined4 *)(iVar3 + DAT_021a1384) = 0;
  *(undefined1 *)(iVar3 + DAT_021a1388) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a138c) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a1390) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a1394) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a1398) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a139c) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a13a0) = 0;
  *(undefined2 *)(*piVar1 + DAT_021a13a4) = 0;
  *(undefined2 *)(*piVar1 + DAT_021a13a8) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a13ac) = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(iVar3 + DAT_021a13b0) = 0;
  *(undefined4 *)(iVar3 + DAT_021a13b4) = 0;
  *(undefined4 *)(iVar3 + DAT_021a13b8) = 0;
  *(undefined4 *)(iVar3 + DAT_021a13bc) = 0;
  func_0x0214d018(0,iVar3 + DAT_021a13c0,0x98);
  piVar1 = DAT_021a1364;
  if (param_1 == 2) {
    *(undefined1 *)(*DAT_021a1364 + 0x14) = *(undefined1 *)(*DAT_021a1364 + 0xd);
    iVar3 = *piVar1;
    if (*(char *)(iVar3 + 0x15) == '\x03') {
      *(undefined4 *)(iVar3 + DAT_021a13c4) = 1;
      return;
    }
    if (*(char *)(iVar3 + 0x15) == '\x02') {
      *(undefined4 *)(iVar3 + DAT_021a13c4) = 10;
      return;
    }
  }
  else {
    *(undefined1 *)(*DAT_021a1364 + 0xd) = 0;
    *(undefined1 *)(*piVar1 + 0xe) = 0;
    *(undefined1 *)(*piVar1 + 0x14) = 0;
    *(undefined1 *)(*piVar1 + 0x17) = 0;
    *(undefined4 *)(*piVar1 + 0x20) = 0;
    *(undefined4 *)(*piVar1 + 0xe8) = 0;
    *(undefined1 *)(*piVar1 + DAT_021a13c8) = 0;
    *(undefined2 *)(*piVar1 + DAT_021a13cc) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a13d0) = 0;
    iVar3 = *piVar1;
    *(undefined4 *)(iVar3 + DAT_021a13d4) = 0;
    *(undefined4 *)(iVar3 + DAT_021a13d8) = 0;
    *(undefined4 *)(iVar3 + DAT_021a13dc) = 0;
    iVar3 = *piVar1;
    *(undefined4 *)(iVar3 + DAT_021a13e0) = 0;
    *(undefined4 *)(iVar3 + DAT_021a13e4) = 0;
    *(undefined4 *)(iVar3 + DAT_021a13e8) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a13ec) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a13f0) = 0;
    *(undefined4 *)(*piVar1 + DAT_021a13f4) = 0;
    func_0x0214d018(0,*piVar1 + 0x24,0x80);
    func_0x0214cfe4(0,*DAT_021a1364 + 0xa4,0x40);
    func_0x0214d018(0,*DAT_021a1364 + 0xf4,0x80);
    func_0x0214d018(0,*DAT_021a1364 + DAT_021a13f8,0xc);
    func_0x0214d018(0,*DAT_021a1364 + DAT_021a13fc,0x80);
    func_0x0214cfe4(0,*DAT_021a1364 + DAT_021a1400,0x40);
    func_0x0214d168(*DAT_021a1364 + DAT_021a1404,0,0x20);
    func_0x0214d018(0,*DAT_021a1364 + DAT_021a1408,0x84);
    piVar1 = DAT_021a1364;
    if (param_1 == 1) {
      iVar3 = *DAT_021a1364;
      if (*(char *)(iVar3 + 0x15) == '\0') {
        *(undefined4 *)(iVar3 + DAT_021a13c4) = 3;
        return;
      }
      if (*(char *)(iVar3 + 0x15) == '\x01') {
        *(undefined4 *)(iVar3 + DAT_021a13c4) = 4;
        return;
      }
    }
    else {
      *(undefined1 *)(*DAT_021a1364 + 0x15) = 0;
      *(undefined1 *)(*piVar1 + 0x16) = 0;
      *(undefined1 *)(*piVar1 + 0x18) = 0;
      *(undefined4 *)(*piVar1 + DAT_021a140c) = 0;
      *(undefined1 *)(*piVar1 + DAT_021a1410) = 0;
      *(undefined4 *)(*piVar1 + DAT_021a1414) = 0;
      *(undefined4 *)(*piVar1 + DAT_021a1418) = 0;
    }
  }
  return;
}

