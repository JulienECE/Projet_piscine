#include "menu.h"
#include "graphe.h"
using namespace std;


/*int main()
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


    BITMAP * page;
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    graphe g("manhattan.txt","manhattan_weights_0.txt");

    while(!key[KEY_ESC])
    {

        Menu a,b,c;
        a.dessinerBasique(page,g);
        if ((mouse_b &1 == 1)&&(mouse_x >500)&&(mouse_x< 580)&&(mouse_y<115)&&(mouse_y >95))
        {
             while (!key [KEY_N]){
            b.dessinerKrusP1(page,g);}
        }
        if ((mouse_b &1 == 1)&&(mouse_x >460)&&(mouse_x< 720)&&(mouse_y<180)&&(mouse_y >150))
        {
            while (!key [KEY_N]){
            c.dessinerPareto(page,g);}
        }
        clear_bitmap(page);
    }
    return 0;
}END_OF_MAIN();*/

int main()
{
    graphe g("broadway.txt","broadway_weights_0.txt");
    g.brutForce();
}END_OF_MAIN();
