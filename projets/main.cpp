
#include "menu.h"

using namespace std;

int main()
{
        srand(time(NULL));                                  /// On va utiliser du hasard
    allegro_init();                                     /// Lancer allegro et le mode graphique
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT,NULL);
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0){
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);}

int rouge= makecol(255,0,0);
    BITMAP * page;
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);


    while(!key[KEY_ESC])
    {

    Menu a;
    a.dessiner(page);
if ((mouse_b &1 == 1)&&(mouse_x >460)&&(mouse_x< 720)&&(mouse_y<90)&&(mouse_y >60))
    {
        Rectangle a(30,30,300,300,rouge);
        a.dessinerFill(page);
        blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
    }
if ((mouse_b &1 == 1)&&(mouse_x >460)&&(mouse_x< 720)&&(mouse_y<180)&&(mouse_y >150))
    {

    }

    }
    return 0;
}END_OF_MAIN();
