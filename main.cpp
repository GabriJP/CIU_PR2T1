/*
Prototipo de programa principal
ULPGC, EII, Creando Interfaces de Usuario
*/

#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

float red = 1.0, green = 1.0, blue = 1.0;

void InitGlew() {
    GLenum glew_init = glewInit();
    if (glew_init != GLEW_OK) {
        fprintf(stderr, "Error %s\n", glewGetErrorString(glew_init));
    } else {
        printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    }
}

void Init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(red, green, blue);

    glutWireTeapot(0.5);
    glFlush();
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void Teclado1(unsigned char key, int x, int y) {
#pragma clang diagnostic pop
    switch (key) {
        case '1':
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case '2':
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case '3':
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        case '4':
            red = 1.0;
            green = 1.0;
            blue = 0.0;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void Teclado2(int key, int x, int y) {
#pragma clang diagnostic pop
    if (key == GLUT_KEY_F1) {
        red = 1.0;
        green = 1.0;
        blue = 1.0;
    }
    glutPostRedisplay();
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutCreateWindow("OpenGL Práctica 2_1");
    glutSetCursor(GLUT_CURSOR_WAIT);
    InitGlew();
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(Teclado1);
    glutSpecialFunc(Teclado2);

    glutMainLoop();

    return 0;
}