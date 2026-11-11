#pragma once

#include "types.h"
#include "Main/Unknown/code_0207ffa4.h"

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor);
void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused);
void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink);
