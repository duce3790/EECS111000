#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

/*
    TODO: Include the head files containing the fuctions we want to use
*/

ALLEGRO_DISPLAY* display = NULL;

/*
    TODO: Declare the variable of font and image.
*/
ALLEGRO_FONT* font;
ALLEGRO_BITMAP* img=NULL;


const int width = 800;
const int height = 600;

const int img_width = 640;
const int img_height = 480;

void show_err_msg(int msg);
void game_init();
void game_begin();
void game_destroy();


int main(int argc, char *argv[]) {
    int msg = 0;

    game_init();
    game_begin();
    printf("Hello world!!!\n");
    al_rest(5);

    game_destroy();
    return 0;
}


void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(5);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(-1);
    }

    display = al_create_display(width, height);
    if (display == NULL) {
        show_err_msg(-1);
    }


    /*
        TODO: Initialize the image and the font.
    */
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
}

void game_begin() {
    al_clear_to_color(al_map_rgb(100,100,100));
    /*
        TODO: Load and draw all!!!
    */
    font = al_load_ttf_font("pirulen.ttf", 30, 0);
    al_draw_text(font,al_map_rgb(255,0,0),width/2,height/2,ALLEGRO_ALIGN_CENTER,"TAIWAN NUMBER 1");
    al_draw_rectangle(width/2-350,height/2-30,width/2+350,height/2+50,al_map_rgb(255,0,0),3);
    img=al_load_bitmap("img.png");
    al_draw_bitmap(img,30,30,0);
    al_flip_display();
}
void game_destroy() {
    al_destroy_display(display);
    al_destroy_bitmap(img);
}
