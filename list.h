#pragma once

typedef struct
{
    NNSFndLink link;
    NNSFndList* list;
} list_link_t;

void list_initLink(list_link_t* link);
BOOL list_append(NNSFndList* list, void* object);
void list_remove(NNSFndList* list, void* object);
