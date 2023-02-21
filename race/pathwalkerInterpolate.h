#pragma once
#include "pathwalker.h"

void pw_interpolateXYZ(const pw_path_part_t* part, pw_progress_t t, VecFx32* dst);
void pw_20D939C(const pw_path_part_t* part, pw_progress_t a2, pw_progress_t a3, VecFx32* a4, VecFx32* a5);
void pw_interpolateXZ(const pw_path_part_t* part, pw_progress_t t, VecFx32* dst);
void pw_20D9270_XZ(const pw_path_part_t* part, pw_progress_t a2, pw_progress_t a3, VecFx32* a4, VecFx32* a5);
void pw_interpolateXZLinearY(const pw_path_part_t* part, pw_progress_t t, VecFx32* dst);
