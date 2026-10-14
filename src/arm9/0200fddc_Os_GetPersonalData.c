/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopy16 CopyMemory16
#define OS_GetOwnerInfo Os_GetPersonalData
#include "OS_ownerInfo.h"

#include "nitro/types.h"
#include "systemWork.h"
#include "MI_memory.h"
#include "code32.h"

void OS_GetOwnerInfo(OSOwnerInfo* info)
{
    NVRAMConfig *src = (NVRAMConfig *)OS_GetSystemWork()->nvramUserInfo;
    info->language = (u8)src->ncd.option.language;
    info->favoriteColour = (u8)src->ncd.owner.favouriteColour;
    info->birthday.month = (u8)src->ncd.owner.birthday.month;
    info->birthday.day = (u8)src->ncd.owner.birthday.day;
    info->nickNameLength = (u16)src->ncd.owner.nickname.length;
    info->commentLength = (u16)src->ncd.owner.comment.length;
    MIi_CpuCopy16(src->ncd.owner.nickname.str, info->nickName, 10 * sizeof(u16));
    MIi_CpuCopy16(src->ncd.owner.comment.str, info->comment, 26 * sizeof(u16));
}
