#define IMPL

#include <colour.h>
#include <defines.h>
#include <stdlib.h>

struct colour_vtable {
    colour_t* (*fb_make_colour)(u8 r, u8 g, u8 b, u8 a);
    void (*fb_delete_colour)(colour_t* colour_ptr);
};

colour_t* fb_make_colour(u8 r, u8 g, u8 b, u8 a) {
    colour_t* colour_ptr = (colour_t*)malloc(sizeof(colour_t));

    colour_ptr->r = r;
    colour_ptr->g = g;
    colour_ptr->b = b;
    colour_ptr->a = a;

    return colour_ptr;
}

void fb_delete_colour(colour_t* colour_ptr) {
    free(colour_ptr);
}

struct colour_vtable exports = { fb_make_colour, fb_delete_colour };