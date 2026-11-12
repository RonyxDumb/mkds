#pragma once

#include "types.h"
#include "Main/Kart/kart_effects_ahead.h"

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor);
void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused);
void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink);
