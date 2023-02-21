#pragma once
#include "kcollision.h"

#define COL_ENTRY_COUNT_MAX             256
#define COL_QUERY_RESULT_COUNT_MAX      128

typedef enum
{
    COL_TYPE_ROAD,
    COL_TYPE_SLIPPERY_ROAD,
    COL_TYPE_WEAK_OFF_ROAD,
    COL_TYPE_OFF_ROAD,
    COL_TYPE_SOUND_TRIGGER,
    COL_TYPE_HEAVY_OFF_ROAD,
    COL_TYPE_SLIPPERY_ROAD_2,
    COL_TYPE_BOOST_PAD,
    COL_TYPE_WALL,
    COL_TYPE_INVISIBLE_WALL, //ignored by cameras, should also have the ignore items flag set
    COL_TYPE_OUT_OF_BOUNDS,
    COL_TYPE_FALL_BOUNDARY,
    COL_TYPE_JUMP_PAD,
    COL_TYPE_ROAD_NO_DRIVERS, //should have the ignore drivers flag set
    COL_TYPE_WALL_NO_DRIVERS, //should have the ignore drivers flag set
    COL_TYPE_CANNON_ACTIVATOR,
    COL_TYPE_EDGE_WALL,
    COL_TYPE_FALLS_WATER,
    COL_TYPE_BOOST_PAD_MIN_SPEED, //forces a minimum speed to ensure certain jumps can be at all times
    COL_TYPE_LOOPING,
    COL_TYPE_SPECIAL_ROAD,
    COL_TYPE_WALL_3,
    COL_TYPE_FORCE_RECALCULATE_ROUTE,

    COL_TYPE_COUNT
} ColType;

//prism attribute

#define COL_PRISM_ATTRIBUTE_MAP2D_SHADOW_SHIFT  1
#define COL_PRISM_ATTRIBUTE_MAP2D_SHADOW        (1 << COL_PRISM_ATTRIBUTE_MAP2D_SHADOW_SHIFT)

#define COL_PRISM_ATTRIBUTE_LIGHT_ID_SHIFT      2
#define COL_PRISM_ATTRIBUTE_LIGHT_ID_MASK       (3 << COL_PRISM_ATTRIBUTE_LIGHT_ID_SHIFT)

#define COL_PRISM_ATTRIBUTE_IGNORE_DRIVERS      (1 << 4)

#define COL_PRISM_ATTRIBUTE_VARIANT_SHIFT       5
#define COL_PRISM_ATTRIBUTE_VARIANT_MASK        (7 << COL_PRISM_ATTRIBUTE_VARIANT_SHIFT)
#define COL_PRISM_ATTRIBUTE_VARIANT(x)          ((x) << COL_PRISM_ATTRIBUTE_VARIANT_SHIFT)

#define COL_PRISM_ATTRIBUTE_COL_TYPE_SHIFT      8
#define COL_PRISM_ATTRIBUTE_COL_TYPE_MASK       (0x1F << COL_PRISM_ATTRIBUTE_COL_TYPE_SHIFT)
#define COL_PRISM_ATTRIBUTE_COL_TYPE(x)         ((x) << COL_PRISM_ATTRIBUTE_COL_TYPE_SHIFT)

#define COL_PRISM_ATTRIBUTE_IGNORE_ITEMS        (1 << 13)
#define COL_PRISM_ATTRIBUTE_IS_WALL             (1 << 14)
#define COL_PRISM_ATTRIBUTE_IS_FLOOR            (1 << 15)

static inline u16 col_getPrismAttrVariant(u16 prismAttr)
{
    return (prismAttr & COL_PRISM_ATTRIBUTE_VARIANT_MASK) >> COL_PRISM_ATTRIBUTE_VARIANT_SHIFT;
}

static inline int col_getPrismAttrColType(u16 prismAttr)
{
    return (prismAttr & COL_PRISM_ATTRIBUTE_COL_TYPE_MASK) >> COL_PRISM_ATTRIBUTE_COL_TYPE_SHIFT;
}

//flags

#define COL_FLAGS_TYPE(x)                       (1 << (x))

#define COL_FLAGS_MAP2D_SHADOW_SHIFT            24
#define COL_FLAGS_MAP2D_SHADOW                  (1 << COL_FLAGS_MAP2D_SHADOW_SHIFT)

#define COL_FLAGS_BIT25                         (1 << 25)

#define COL_FLAGS_LIGHT_SHIFT                   26
#define COL_FLAGS_LIGHT(x)                      (1 << ((x) + COL_FLAGS_LIGHT_SHIFT))
#define COL_FLAGS_LIGHT_MASK                    (0xF << COL_FLAGS_LIGHT_SHIFT)
#define COL_FLAGS_LIGHT_0_SHIFT                 COL_FLAGS_LIGHT_SHIFT
#define COL_FLAGS_LIGHT_0_MASK                  (COL_FLAGS_LIGHT(0))
#define COL_FLAGS_LIGHT_1_SHIFT                 (COL_FLAGS_LIGHT_SHIFT + 1)
#define COL_FLAGS_LIGHT_1_MASK                  (COL_FLAGS_LIGHT(1))
#define COL_FLAGS_LIGHT_2_SHIFT                 (COL_FLAGS_LIGHT_SHIFT + 2)
#define COL_FLAGS_LIGHT_2_MASK                  (COL_FLAGS_LIGHT(2))
#define COL_FLAGS_LIGHT_3_SHIFT                 (COL_FLAGS_LIGHT_SHIFT + 3)
#define COL_FLAGS_LIGHT_3_MASK                  ((COL_FLAGS_LIGHT(3))

#define COL_FLAGS_DCOL                          (1 << 30)
#define COL_FLAGS_KCOL                          (1 << 31)

#define COL_FLAGS_TYPE_FLOOR_MASK    (\
    COL_FLAGS_TYPE(COL_TYPE_ROAD) | \
    COL_FLAGS_TYPE(COL_TYPE_SLIPPERY_ROAD) | \
    COL_FLAGS_TYPE(COL_TYPE_WEAK_OFF_ROAD) | \
    COL_FLAGS_TYPE(COL_TYPE_OFF_ROAD) | \
    COL_FLAGS_TYPE(COL_TYPE_HEAVY_OFF_ROAD) | \
    COL_FLAGS_TYPE(COL_TYPE_SLIPPERY_ROAD_2) | \
    COL_FLAGS_TYPE(COL_TYPE_BOOST_PAD) | \
    COL_FLAGS_TYPE(COL_TYPE_OUT_OF_BOUNDS) | \
    COL_FLAGS_TYPE(COL_TYPE_JUMP_PAD) | \
    COL_FLAGS_TYPE(COL_TYPE_ROAD_NO_DRIVERS) | \
    COL_FLAGS_TYPE(COL_TYPE_FALLS_WATER) | \
    COL_FLAGS_TYPE(COL_TYPE_BOOST_PAD_MIN_SPEED) | \
    COL_FLAGS_TYPE(COL_TYPE_LOOPING) | \
    COL_FLAGS_TYPE(COL_TYPE_SPECIAL_ROAD))

#define COL_FLAGS_TYPE_WALL_MASK    (\
    COL_FLAGS_TYPE(COL_TYPE_WALL) | \
    COL_FLAGS_TYPE(COL_TYPE_INVISIBLE_WALL) | \
    COL_FLAGS_TYPE(COL_TYPE_WALL_NO_DRIVERS) | \
    COL_FLAGS_TYPE(COL_TYPE_EDGE_WALL) | \
    COL_FLAGS_TYPE(COL_TYPE_WALL_3))

#define COL_FLAGS_TYPE_RESPAWN_MASK    (\
    COL_FLAGS_TYPE(COL_TYPE_OUT_OF_BOUNDS) | \
    COL_FLAGS_TYPE(COL_TYPE_FALL_BOUNDARY))

//collide flags
//roughly, there are some exceptions
#define COL_COLLIDE_FLAGS_IS_DRIVER         (1 << 0)
#define COL_COLLIDE_FLAGS_IS_CAMERA         (1 << 1)
#define COL_COLLIDE_FLAGS_IS_ITEM           (1 << 2)
#define COL_COLLIDE_FLAGS_IS_MAPOBJ         (1 << 3)
#define COL_COLLIDE_FLAGS_IS_JUGEM          (1 << 4)
#define COL_COLLIDE_FLAGS_BIT5              (1 << 5)
#define COL_COLLIDE_FLAGS_BIT6              (1 << 6)

typedef struct
{
    VecFx32 maxSomething;
    VecFx32 minSomething;
    fx32 distance;
    VecFx32 normal;
} col_response_t;

typedef struct
{
    u8 rightEndpoint; //right endpoint idx of this segment
    u8 colEntryId; //col entry corresponding to this segment
    s16 xPos;
} col_segment_left_endpoint_t;

typedef struct
{
    u8 leftEndpoint; //left endpoint idx of this segment
    u8 minLeftEndpoint; //from all segments overlapping this x, the left most left-endpoint idx
    s16 xPos;
} col_segment_right_endpoint_t;

#define COL_ENTRY_FLAGS_INVALIDATED         (1 << 8) //forces an update when disabled or static
#define COL_ENTRY_FLAGS_DISABLED            (1 << 9)
#define COL_ENTRY_FLAGS_STATIC              (1 << 10) //the position doesn't change
#define COL_ENTRY_FLAGS_IS_DRIVER2          (1 << 11)
#define COL_ENTRY_FLAGS_IS_DCOL             (1 << 12)
#define COL_ENTRY_FLAGS_IS_MAPOBJ           (1 << 13)
#define COL_ENTRY_FLAGS_IS_ITEM             (1 << 14)
#define COL_ENTRY_FLAGS_IS_DRIVER1          (1 << 15)

//these flags were probably just static consts or so
static inline void col_orrStaticFlag(u16* flags)
{
    static const u16 flag = COL_ENTRY_FLAGS_STATIC;
    *flags |= flag;
}

static inline void col_orrIsDcolFlag(u16* flags)
{
    static const u16 flag = COL_ENTRY_FLAGS_IS_DCOL;
    *flags |= flag;
}

typedef struct
{
    s16 segmentRightEndpoint;
    s16 segmentLeftEndpoint;
    fx32 zMax;
    fx32 zMin;
    const VecFx32* position;
    fx32 boundingSphereRadius;
    u16 flags;
    void* object;
} col_entry_t;

static inline void col_invalidateColEntry(col_entry_t* colEntry)
{
    static const u16 flag = COL_ENTRY_FLAGS_INVALIDATED;
    colEntry->flags |= flag;
}

extern void** gColQueryResultObjects;
extern u16* gColQueryResultFlags;
extern s16 gColQueryResultCount;
extern u16* gColQueryResultEntryIds;

struct dcol_inst_t;

void col_loadCourseCollision();
void sub_20D5AA0(struct dcol_inst_t*** a1, u32 colFlags, u32* a3, VecFx32* a4, VecFx32* a5);
BOOL sub_20D5A68(struct dcol_inst_t*** a1, u32 colFlags, u32* a3);
u16 col_findResponsePrismAttribute(u32 colFlagsMask);
void col_init();
int col_createColEntry(const VecFx32* position, fx32 boundingSphereSize, u16 flags, void* object);
int col_deleteColEntry(s16 entryId);
void col_queryBySphere(const VecFx32* position, fx32 sphereRadius, u16 flagMask);
void col_setBoundingSphereRadius(s16 entryId, fx32 sphereRadius);
void col_disableColEntry(s16 entryId);
void col_enableColEntry(s16 entryId);

BOOL col_collide(
    const VecFx32* position, const VecFx32* prevPosition, const VecFx32* direction, fx32 sphereSize, u16 flags, s16 colEntryId,
    VecFx32* pushback, VecFx32* floorNormal, VecFx32* wallNormal, u32* outColFlags, VecFx32* a11, VecFx32* dcolA9,
    u16* dcolA10, struct dcol_inst_t*** dcolResults);
void col_update();
void col_queryByColEntry(s16 colEntryId, u16 flagMask);

static inline void col_updateResponseMinMax(col_response_t* response, const VecFx32* vec)
{
    if (vec->x > response->maxSomething.x)
        response->maxSomething.x = vec->x;
    else if (vec->x < response->minSomething.x)
        response->minSomething.x = vec->x;
    if (vec->y > response->maxSomething.y)
        response->maxSomething.y = vec->y;
    else if (vec->y < response->minSomething.y)
        response->minSomething.y = vec->y;
    if (vec->z > response->maxSomething.z)
        response->maxSomething.z = vec->z;
    else if (vec->z < response->minSomething.z)
        response->minSomething.z = vec->z;
}
