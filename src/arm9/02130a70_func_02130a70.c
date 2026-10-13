/* Decompiled C draft; module arm9; ROM address 02130a70. No matching claim. */
#include "types.h"
#include "deps/02130a70_func_02130a70.h"

undefined8 func_02130a70(uint param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  byte bVar13;
  undefined8 uVar14;
  
  uVar6 = DAT_02130ca8;
  if (param_2 < uRam02130ca4) {
    uVar6 = param_2 >> 0x14;
    if (uVar6 == 0) {
      if (param_2 == 0) {
        if (param_1 == 0) {
          return 0;
        }
        uVar8 = param_1 << LZCOUNT(param_1);
        uVar6 = -LZCOUNT(param_1) - 0x14;
        uVar3 = uVar8 >> 0xb;
        param_1 = uVar8 << 0x15;
      }
      else {
        uVar6 = 0x2b - LZCOUNT(param_2);
        uVar3 = (param_2 << LZCOUNT(param_2)) >> 0xb | param_1 >> (uVar6 & 0xff);
        uVar6 = 0x20 - uVar6;
        param_1 = param_1 << (uVar6 & 0xff);
        uVar6 = 1 - uVar6;
      }
    }
    else {
      uVar3 = param_2 & ~uRam02130ca4 | 0x100000;
    }
    iVar11 = (int)uVar6 >> 1;
    if (!(bool)((byte)uVar6 & 1)) {
      iVar11 = iVar11 + -1;
      iVar9 = (int)param_1 >> 0x1f;
      param_1 = param_1 << 1;
      uVar3 = uVar3 * 2 - iVar9;
    }
    uVar6 = param_1 << 1;
    uVar4 = uVar3 * 2 - ((int)param_1 >> 0x1f);
    uVar5 = 0;
    uVar8 = 0;
    uVar3 = 0x200000;
    do {
      iVar9 = uVar8 + uVar3;
      if (iVar9 <= (int)uVar4) {
        uVar8 = iVar9 + uVar3;
        uVar4 = uVar4 - iVar9;
        uVar5 = uVar5 + uVar3;
      }
      iVar9 = (int)uVar6 >> 0x1f;
      uVar6 = uVar6 * 2;
      uVar4 = uVar4 * 2 - iVar9;
      uVar3 = uVar3 >> 1;
    } while (uVar3 != 0);
    uVar3 = 0;
    iVar9 = 0;
    bVar12 = uVar8 <= uVar4;
    if (uVar4 == uVar8) {
      bVar12 = 0x7fffffff < uVar6;
    }
    if (bVar12) {
      bVar12 = uVar6 < 0x80000000;
      uVar6 = uVar6 + 0x80000000;
      uVar4 = uVar4 - (uVar8 + bVar12);
      uVar8 = uVar8 + 1;
      uVar3 = 0x80000000;
    }
    uVar7 = uVar6 << 1;
    uVar4 = uVar4 * 2 - ((int)uVar6 >> 0x1f);
    uVar6 = 0x40000000;
    do {
      uVar10 = iVar9 + uVar6;
      bVar12 = uVar4 <= uVar8;
      if (uVar8 == uVar4) {
        bVar12 = uVar7 <= uVar10;
      }
      if (!bVar12 || uVar8 == uVar4 && uVar10 == uVar7) {
        iVar9 = uVar10 + uVar6;
        bVar12 = uVar7 < uVar10;
        uVar7 = uVar7 - uVar10;
        uVar4 = uVar4 - (uVar8 + bVar12);
        uVar3 = uVar3 + uVar6;
      }
      iVar1 = (int)uVar7 >> 0x1f;
      uVar7 = uVar7 << 1;
      uVar4 = uVar4 * 2 - iVar1;
      uVar6 = uVar6 >> 1;
    } while (uVar6 != 0);
    if (uVar4 == 0 && uVar7 == 0) {
      uVar3 = uVar3 & 0xfffffffe;
    }
    else {
      puVar2 = (uint *)GetAlphaFlagsRef();
      uVar6 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
      if ((uVar6 & 0x1000) != 0) {
        uVar14 = func_0213412c((uint)((byte)uVar5 & 1) << 0x1f | uVar3 >> 1,
                               (uVar5 >> 1) + 0x1ff00000 + iVar11 * 0x100000,DAT_02130cb0,uVar7);
        return uVar14;
      }
      *puVar2 = uVar6 | 0x10;
      if ((uVar6 & 0x800000) == 0) {
        if ((uVar6 & 0x400000) != 0) {
          uVar3 = uVar3 | 1;
        }
      }
      else {
        uVar3 = uVar3 & 0xfffffffe;
      }
    }
    bVar13 = (byte)uVar3 & 1;
    uVar6 = (uint)((byte)uVar5 & 1) << 0x1f | uVar3 >> 1;
    return CONCAT44((uVar5 >> 1) + (uint)CARRY4(uVar6,(uint)bVar13) + 0x1ff00000 + iVar11 * 0x100000
                    ,uVar6 + bVar13);
  }
  if ((param_2 & 0x80000000) == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return CONCAT44(param_2,param_1);
    }
    if (((param_2 & 0x7fffffff) < uRam02130ca4) || (param_1 == 0 && (param_2 & 0xfffff) == 0))
    goto LAB_02130c3c;
  }
  if ((param_2 & 0x80000) != 0) {
    return CONCAT44(param_2,param_1);
  }
LAB_02130c3c:
  puVar2 = (uint *)GetAlphaFlagsRef();
  uVar3 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  if ((uVar3 & 0x100) != 0) {
    uVar14 = func_0213412c(param_1,param_2,DAT_02130cac);
    return uVar14;
  }
  *puVar2 = uVar3 | 1;
  return CONCAT44(param_2 | uVar6,param_1);
}

