/*********************************************************************/
/* Bibliotheque graphique graphlib pour l'enseignement universitaire */
/* D'apres les idees de Francoise et Jean-Paul Bertrandias sur Atari */
/* Implementation sous X Windows: Michel Bonin et Xavier Girod       */
/* UFR IMA - Universite Joseph Fourier (Grenoble)                    */
/* Centre Joseph Fourier Drome-Ardeche (Valence)                     */
/* email: Michel.Bonin@ujf-grenoble.fr                               */
/* modifi� par Christophe Deleuze                                    */
/*********************************************************************/

/* Fichiers X inclus */

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "graphlib.h"
#include <string.h>

/* D�clarations de variables globales */

Display *mydisplay;
Display *Moniteur;
Window mywindow;
Window FenetreParDefaut;
GC mygc;

XColor XBleu, XRouge, XVert, XJaune;
GC Zone; 
int myscreen, Ecran;
unsigned long myforeground, mybackground;
XEvent myevent;

/*************************************************************************/
/* gr_inits_w(larg,haut,titre) : initialisation de l'�cran graphique 
  cr�e une fen�tre par defaut X-Window de taille larg X haut avec un titre */

void gr_inits_w(int larg, int haut, char titre[])
{
  
  XSizeHints myhint;
  
  /* Initialisation */

  mydisplay = XOpenDisplay("");
  Moniteur = mydisplay;
  
  myscreen = DefaultScreen(mydisplay);
  Ecran = myscreen;
  mybackground = WhitePixel(mydisplay,myscreen);
  myforeground = BlackPixel(mydisplay,myscreen);
  
  myhint.x = 10; myhint.y = 10;
  myhint.width = larg; myhint.height = haut;
  myhint.flags = PPosition | PSize;
  
  mywindow = XCreateSimpleWindow (mydisplay,
				  DefaultRootWindow (mydisplay),
				  myhint.x, myhint.y, myhint.width,
				  myhint.height,
				  5, myforeground, mybackground);
  
  FenetreParDefaut = mywindow;
  
  XSetStandardProperties (mydisplay, mywindow, titre, titre, 
			  None, NULL, 0, &myhint);

  mygc = XCreateGC (mydisplay, mywindow, 0, 0);
  Zone = mygc;
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);
  
  XAllocNamedColor(mydisplay, DefaultColormap(mydisplay, myscreen),
		   "blue", &XBleu, &XBleu);
  XAllocNamedColor(mydisplay, DefaultColormap(mydisplay, myscreen),
		   "red", &XRouge, &XRouge);
  XAllocNamedColor(mydisplay, DefaultColormap(mydisplay, myscreen),
		   "green", &XVert, &XVert);
  XAllocNamedColor(mydisplay, DefaultColormap(mydisplay, myscreen),
		   "yellow", &XJaune, &XJaune);

  /* Solicitation des �v�nements en entr�e. Indispensable */

  XSelectInput (mydisplay, mywindow,
		ButtonPressMask | KeyPressMask | ExposureMask );

  /* Affichage sur l'�cran */

  XFlush(mydisplay); 
  XMapRaised (mydisplay, mywindow);
  XNextEvent ( mydisplay, &myevent );  /* visiblement obligatoire */ 
}

/*************************************************************************/


/* Ouverture d'une fen�tre */

void open_w(Window *W, int abs, int ord, int larg, int haut, char titre[])

{

XSizeHints myhint;

/* Initialisation */

myhint.x = abs; myhint.y = ord;
myhint.width = larg; myhint.height = haut;
myhint.flags = PPosition | PSize;

mywindow = XCreateSimpleWindow (mydisplay,
	DefaultRootWindow (mydisplay),
	myhint.x, myhint.y, myhint.width, myhint.height,
	5, myforeground, mybackground);
	
*W = mywindow;

XSetStandardProperties (mydisplay, mywindow, titre, titre, 
	None, NULL, 0, &myhint);

/* Solicitation des e've'nements en entre'e. Indispensable */

XSelectInput (mydisplay, mywindow,
	ButtonPressMask | KeyPressMask | ExposureMask );

/* Affichage sur l'e'cran */


XFlush(mydisplay); 
XMapRaised (mydisplay, mywindow);
XNextEvent ( mydisplay, &myevent );  /* visiblement obligatoire */

}

/*************************************************************************/

/* Selection d'une fenetre */

void set_w(Window W)
{
mywindow = W;
}


/*************************************************************************/

/* Fermeture d'une fenetre */

void close_w(Window W)
{
XDestroyWindow (mydisplay, W);
}

/*************************************************************************/

/* gr_close : fermeture de l'�cran graphique */

void gr_close(void)
{
  XFreeGC (mydisplay, mygc);
  XDestroyWindow (mydisplay, mywindow);
  XCloseDisplay (mydisplay);
}

/*************************************************************************/

/* set_blue: changement de couleur */

void set_blue(void)
{
  myforeground = XBleu.pixel;
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* set_red: changement de couleur */

void set_red(void)
{
  myforeground = XRouge.pixel;
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* set_green: changement de couleur */

void set_green(void)
{
  myforeground = XVert.pixel;
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* set_yellow: changement de couleur */

void set_yellow(void)
{
  myforeground = XJaune.pixel;
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* set_black: changement de couleur */

void set_black(void)
{
  myforeground = BlackPixel(mydisplay,myscreen);
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* set_black: changement de couleur */
/* Rajouté par Jean Rougé */
void set_white(void)
{
  myforeground = XWhitePixel(mydisplay,myscreen);
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/
/*ecriture de texte en blanc sur fond noir*/

void video_inv(void)
{
  mybackground = XBlackPixel(mydisplay,myscreen);
  myforeground = XWhitePixel(mydisplay,myscreen);
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);
}
/*************************************************************************/

/*dessin en blanc sur fond noir*/

void graph_inv(void)
{
  mybackground = XBlackPixel(mydisplay,myscreen);
  myforeground = XWhitePixel(mydisplay,myscreen);
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);
  XSetWindowBackground (mydisplay, mywindow, mybackground);
}

/*************************************************************************/

/*ecriture de texte en noir sur fond blanc*/

void video_nor(void)
{
  mybackground = XWhitePixel(mydisplay,myscreen);
  myforeground = XBlackPixel(mydisplay,myscreen);
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/*dessin en noir sur fond blanc*/

void graph_nor(void)
{
  mybackground = XWhitePixel(mydisplay,myscreen);
  myforeground = XBlackPixel(mydisplay,myscreen);
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);
  XSetWindowBackground (mydisplay, mywindow, mybackground);
}

/*************************************************************************/

/* clear_screen : effacement de l'�cran */

void clear_screen(void)
{
  XFlush(mydisplay);
  XClearWindow (mydisplay, mywindow);
}

/*************************************************************************/
/* line : trace une ligne */

void line(int x1,int y1,int x2,int y2)
{
  XFlush(mydisplay);
  XDrawLine(mydisplay, mywindow, mygc, x1, y1, x2, y2);
}

/*************************************************************************/

/* line_off : efface une ligne */

void line_off(int x1,int y1,int x2,int y2)
{
  unsigned long couleur_trait;

  couleur_trait = myforeground;
  myforeground = mybackground;
  XSetForeground (mydisplay, mygc, myforeground);
  XFlush(mydisplay);
  XDrawLine(mydisplay, mywindow, mygc, x1, y1, x2, y2);
  myforeground = couleur_trait;
  XSetForeground (mydisplay, mygc, myforeground);
}

/*************************************************************************/

/* point :  affichage du point (x,y) */

void point(int x,int y)
{
  XFlush(mydisplay);
  XDrawPoint(mydisplay, mywindow, mygc, x, y);
}

/*************************************************************************/

/* point_off : effacement du point (x,y) */

void point_off(int x,int y)
{
  unsigned long couleur_trait;

  couleur_trait = myforeground;
  myforeground = mybackground;
  XSetForeground (mydisplay, mygc, myforeground);
  XFlush(mydisplay);
  XDrawPoint(mydisplay, mywindow, mygc, x, y);
  myforeground = couleur_trait;
  XSetForeground (mydisplay, mygc, myforeground);
}

/***********************************************************************/

/*fill_triangle: remplit un triangle*/

void fill_triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
  XPoint triangle[3];

  triangle[0].x = x1;
  triangle[0].y = y1;
  triangle[1].x = x2;
  triangle[1].y = y2;
  triangle[2].x = x3;
  triangle[2].y = y3;
  XFlush(mydisplay);
  XFillPolygon(mydisplay, mywindow, mygc,triangle,3,Convex,CoordModeOrigin);
}

/*************************************************************************/

/* circle : trace un cercle */

void circle (int x,int y,int R)
{
  XFlush(mydisplay);
  XDrawArc(mydisplay, mywindow, mygc, x-R, y-R, 2*R, 2*R, 0, 23040);
}

/*************************************************************************/

/* fill_circle : remplit un cercle */

void fill_circle (int x,int y,int R)
{
  XFlush(mydisplay);
  XFillArc(mydisplay, mywindow, mygc, x-R, y-R, 2*R, 2*R, 0, 23040);
}

/*************************************************************************/

/* circle_off : efface un cercle */

void circle_off (int x,int y,int R)
{
  unsigned long couleur_trait;

  couleur_trait = myforeground;
  myforeground = mybackground;
  XSetForeground (mydisplay, mygc, myforeground);
  XFlush(mydisplay);
  XDrawArc(mydisplay, mywindow, mygc, x-R, y-R, 2*R, 2*R, 0, 23040);
  myforeground = couleur_trait;
  XSetForeground (mydisplay, mygc, myforeground);
}



/*************************************************************************/

/* write_gr : e'criture sur l'e'cran graphique en superposition */

void write_gr(int x,int y, char str[])
{
  XFlush(mydisplay);
  XDrawString(mydisplay, mywindow, mygc, x, y, str, strlen(str));
}

/*************************************************************************/

/* overwrite_gr : e'criture sur l'e'cran graphique avec effacement */

void overwrite_gr(int x,int y, char str[])
{
  XFlush(mydisplay);
  XDrawImageString(mydisplay, mywindow, mygc, x, y, str, strlen(str));
}

/*************************************************************************/

void cliquer(void)
{
  XWindowEvent (mydisplay, mywindow, ButtonPressMask, &myevent);
}

/*************************************************************************/

void cliquer_xy(int *x, int *y)
{
  XWindowEvent (mydisplay, mywindow, ButtonPressMask, &myevent);
  *x = myevent.xbutton.x ;
  *y = myevent.xbutton.y;
}

/***********************************************************************/

/*pour la compatibilite' avec Atari*/

void wait_kbd(void)
{ 
  int X;

  X = XGrabKeyboard(mydisplay, mywindow, True, GrabModeAsync,
		    GrabModeAsync, CurrentTime);
  XWindowEvent (mydisplay, mywindow, KeyPressMask, &myevent);
  XUngrabKeyboard(mydisplay, CurrentTime);
}

/***********************************************************************/

/*cstat teste l'enfoncement d'une touche du clavier*/

Bool cstat(void)
{
  Bool c;
  int X;
  
  X = XGrabKeyboard(mydisplay, mywindow, True, GrabModeAsync,
		    GrabModeAsync, CurrentTime);
  c = XCheckWindowEvent(mydisplay, mywindow, KeyPressMask, &myevent);
  if (c == True)
    XPutBackEvent(mydisplay, &myevent);
  XUngrabKeyboard(mydisplay, CurrentTime);	
  return c;
}

/***********************************************************************/	
/*consilent fournit le caractere present s'il y en a un, 
  le caractere nul sinon*/

char consilent(void)
{
  KeySym touche;
  int X;
  Bool c;
  char *s;
  char car;
		
  X = XGrabKeyboard(mydisplay, mywindow, True, GrabModeAsync,
		    GrabModeAsync, CurrentTime);
  c = XCheckWindowEvent(mydisplay, mywindow, KeyPressMask, &myevent);
  if (c == True)
    {
      touche = XLookupKeysym(&(myevent.xkey), 0);
      s = XKeysymToString(touche);
      car = *s;
    }
  else
    car = '\0';
  XUngrabKeyboard(mydisplay, CurrentTime);
  return car;
}


/***********************************************************************/	

/*bouton fournit le numero de bouton si un bouton de la souris a �t�
  enfonc�, 0 sinon */

int bouton(void)
{
  Bool B;
  int X;
  
  B = XCheckWindowEvent(mydisplay, mywindow, ButtonPressMask, &myevent);
  if (B == True) 
    X = myevent.xbutton.button;
  else 
    X = 0;
  return X;
}
