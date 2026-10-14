/* Decompiled C draft; module arm9; ROM address 020885d0. No matching claim. */
#include "types.h"
#include "deps/020885d0_FormatCharacterKartNsbtxPath.h"

char * FormatCharacterKartNsbtxPath(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar3 = iRam02088658 *
          ((int)((ulonglong)((longlong)(int)uRam02088654 * (longlong)param_1) >> 0x20) -
          (param_1 >> 0x1f));
  lVar2 = CONCAT44(iRam02088658,iVar3);
  bVar6 = param_1 == iVar3;
  uVar5 = uRam02088654;
  if (bVar6) {
    uVar5 = uRam0208865c;
  }
  if (!bVar6) {
    lVar2 = (longlong)(int)uVar5 * (longlong)param_1;
  }
  if (!bVar6) {
    lVar2 = CONCAT44((int)((ulonglong)lVar2 >> 0x20) - (param_1 >> 0x1f),uRam02088660);
  }
  if (!bVar6) {
    uVar5 = (int)lVar2 + (int)((ulonglong)lVar2 >> 0x20) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  }
  uVar4 = iRam02088664 + param_1 * 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  _snprintf(pcRam02088674,0x100,pcRam02088678,
            *(uint *)(uRam02088670 & 0xfffffffc) >> (uRam02088670 & 3) * 8 |
            *(uint *)(uRam02088670 & 0xfffffffc) << (uRam02088670 & 3) * -8 + 0x20,
            *(uint *)(uRam02088668 & 0xfffffffc) >> (uRam02088668 & 3) * 8 |
            *(uint *)(uRam02088668 & 0xfffffffc) << (uRam02088668 & 3) * -8 + 0x20,uVar5,
            uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uRam0208866c);
  return pcRam02088674;
}

