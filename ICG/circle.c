#include <GL/glut.h>
#include <math.h>

void display(){
    GLfloat x, y, angle;
glClear( GL_COLOR_BUFFER_BIT);
glBegin( GL_LINE_STRIP);
for (angle = 0.0f; angle <= (2.0f * M_PI); angle += 0.01f)
{
x = 0.5f * sin(angle);
y = 0.5f * cos(angle);
glColor3f(0.0, 1.0, 1.0);
glVertex2f(x, y);
}
glEnd();
glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("GLUT Circle");

    glutDisplayFunc(display);

    glutMainLoop();
}