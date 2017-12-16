#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>

#define PROGRAM "glversion"

int main(int argc, char **argv)
{
  char *version = NULL;
  char *vendor = NULL;
  char *renderer = NULL;
  char *extensions = NULL;
  GLuint idWindow = 0;
  int	glutVersion;

  glutInit(&argc, argv);
  glutInitWindowSize(1,1);
  glutInitDisplayMode(GLUT_RGBA);
  idWindow = glutCreateWindow(PROGRAM);
  glutHideWindow();

  glutVersion = glutGet(0x01FC);
  version =     (char*)glGetString(GL_VERSION);
  vendor =      (char*)glGetString(GL_VENDOR);
  renderer =    (char*)glGetString(GL_RENDERER);
  extensions =  (char*)glGetString(GL_EXTENSIONS);

  printf("GLUT=%d\nVERSION=%s\nVENDOR=%s\nRENDERER=%s\nEXTENSIONS=%s\n",
    glutVersion,version,vendor,renderer,extensions);

  glutDestroyWindow(idWindow);
  return(0);
}