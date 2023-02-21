#pragma once

#include "camera.h"

void camr_initRouteStat(came_routestat_t* rstat, const nkm_came_entry_t* came);
void camr_initRouteStatReversed(came_routestat_t* rstat, const nkm_came_entry_t* came);
void camr_updateRoute(VecFx32* dst, came_routestat_t* rstat, const nkm_came_entry_t* came, int pointSpeed);
