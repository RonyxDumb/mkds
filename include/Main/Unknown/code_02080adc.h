#pragma once

#include "types.h"

typedef struct PointLinkCursor PointLinkCursor;
typedef struct RacePointLink RacePointLink;

void AdvancePointLinkCursorTo(PointLinkCursor *linkCursor, RacePointLink *pointLink);
