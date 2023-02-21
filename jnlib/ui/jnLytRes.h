#pragma once

#define JNUI_COORD_H_ORIGIN_LEFT    0
#define JNUI_COORD_H_ORIGIN_CENTER  1
#define JNUI_COORD_H_ORIGIN_RIGHT   2

#define JNUI_COORD_V_ORIGIN_TOP     0
#define JNUI_COORD_V_ORIGIN_MIDDLE  1
#define JNUI_COORD_V_ORIGIN_BOTTOM  2

typedef struct
{
    s16 coord : 12;
    u16 origin : 2;
    u16 unk : 2;
} jnui_coord_t;

SDK_COMPILER_ASSERT(sizeof(jnui_coord_t) == 2);

typedef struct
{
    u32 magic;
    u16 unknown;
    u16 nrElements;
} jnui_bncl_res_header_t;

typedef struct
{
    jnui_coord_t x;
    jnui_coord_t y;
    u32 cellId;
} jnui_bncl_res_element_t;

typedef struct
{
    jnui_bncl_res_header_t header;
    jnui_bncl_res_element_t elements[0];
} jnui_bncl_res_t;

typedef struct
{
    u32 magic;
    u16 unknown;
    u16 nrElements;
} jnui_bnll_res_header_t;

typedef struct
{
    jnui_coord_t x;
    jnui_coord_t y;
    s8 hSpace;
    s8 vSpace;
    u16 color : 8;
    u16 palette : 4;
    u16 font : 4;
    u32 stringPtr;
} jnui_bnll_res_element_t;

typedef struct
{
    jnui_bnll_res_header_t header;
    jnui_bnll_res_element_t elements[0];
} jnui_bnll_res_t;

typedef struct
{
    u32 magic;
    u16 unknown;
    u16 nrElements;
} jnui_bnbl_res_header_t;

typedef struct
{
    jnui_coord_t x;
    jnui_coord_t y;
    u8 width;
    u8 height;
} jnui_bnbl_res_element_t;

SDK_COMPILER_ASSERT(sizeof(jnui_bnbl_res_element_t) == 6);

typedef struct
{
    jnui_bnbl_res_header_t header;
    jnui_bnbl_res_element_t elements[0];
} jnui_bnbl_res_t;