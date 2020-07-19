#include<windows.h>
#include<gl/glut.h>
#include "math.h"

void init(void);
void tampil(void);
void keyboard(unsigned char key, int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void ukuran(int, int);
void lapangan();
void lingkaran();
void kursi();
void tembok();
void tutup();
void tribun();

float xrot=0.0f;
float yrot=0.0f;
float xdiff=0.0f;
float ydiff=0.0f;
bool mouseDown=false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("672018174 - 672018084 - 672018217");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(3);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

const double phi = 3.141592653589793;
int i;

void lingkaran(int xb, int yb, int zb, int r, int n){
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<=360; i++){
    	float angle = i*(2*phi/n);
        float x = xb+r * cos(angle);
        float y = yb+r * sin(angle);
        float z = zb+r;
        glVertex3d(x,y,z);
    }
    glEnd();
}

void lapangan(){
    //lapangan
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.7,0.0);
    glVertex3f(-33,-30,13);
    glVertex3f(33,-30,13);
    glVertex3f(33,-30,-28);
    glVertex3f(-33,-30,-28);
	glEnd();

    //garislapangan
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,10);
    glVertex3f(30,-30,10);
    glVertex3f(30,-30,-25);
    glVertex3f(-30,-30,-25);
    glEnd();

    /*//garislapangantengah
    glColor3f(1,1,1);
    lingkaran(0,0,0,20,40);
    */
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(0,-30,10);
    glVertex3f(0,-30,-25);
    glEnd();

    //gariskotakgawangluar1
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,2);
    glVertex3f(-30,-30,-17);
    glVertex3f(-21,-30,-17);
    glVertex3f(-21,-30,2);
    glEnd();

    //gariskotakgawangdalam1
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,-3);
    glVertex3f(-30,-30,-12);
    glVertex3f(-27,-30,-12);
    glVertex3f(-27,-30,-3);
    glEnd();

    //gariskotakgawangluar2
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(30,-30,2);
    glVertex3f(30,-30,-17);
    glVertex3f(21,-30,-17);
    glVertex3f(21,-30,2);
    glEnd();

    //gariskotakgawangdalam2
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(30,-30,-3);
    glVertex3f(30,-30,-12);
    glVertex3f(27,-30,-12);
    glVertex3f(27,-30,-3);
    glEnd();

    //tianggawang1
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(30,-30,-5);
    glVertex3f(30,-30,-10);
    glVertex3f(30,-27,-10);
    glVertex3f(30,-27,-5);
    glEnd();

    //tianggawang2
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,-5);
    glVertex3f(-30,-30,-10);
    glVertex3f(-30,-27,-10);
    glVertex3f(-30,-27,-5);
    glEnd();
    
    //iklan depan
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.5);
    glVertex3f(-32,-30,15);
    glVertex3f(-32,-28,15);
    glVertex3f(32,-28,15);
    glVertex3f(32,-30,15);
    glEnd();
    
    //iklan belakang
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex3f(-32,-30,-30);
    glVertex3f(-32,-28,-30);
    glVertex3f(32,-28,-30);
    glVertex3f(32,-30,-30);
    glEnd();
    
    //iklan samping kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5,0,0);
    glVertex3f(36,-30,13);
    glVertex3f(36,-28,13);
    glVertex3f(36,-28,-28);
    glVertex3f(36,-30,-28);
    glEnd();
    
    //iklan samping kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,1);
    glVertex3f(-36,-30,13);
    glVertex3f(-36,-28,13);
    glVertex3f(-36,-28,-28);
    glVertex3f(-36,-30,-28);
    glEnd();
    
    //tiang bendera 1
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,10);
    glVertex3f(-30,-28,10);
	glEnd();
	
	//tiang bendera 2
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(30,-30,-25);
    glVertex3f(30,-28,-25);
	glEnd();
	
	//tiang bendera 3
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-30,-30,-25);
    glVertex3f(-30,-28,-25);
	glEnd();

	//tiang bendera 4
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(30,-30,10);
    glVertex3f(30,-28,10);
	glEnd();
	
	//bendera 1
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(-30,-28,10);
    glVertex3f(-30,-27,10);
    glVertex3f(-29,-27.5,10);
	glEnd();
	
	//bendera 2
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(30,-28,-25);
    glVertex3f(30,-27,-25);
    glVertex3f(31,-27.5,-25);
	glEnd();
	
	//bendera 3
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(-30,-28,-25);
    glVertex3f(-30,-27,-25);
    glVertex3f(-29,-27.5,-25);
	glEnd();
	
	//bendera 4
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(30,-28,10);
    glVertex3f(30,-27,10);
    glVertex3f(31,-27.5,10);
	glEnd();
}

void tribun(){
	//tribun kiri
	glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-45,-30,15);
    glVertex3f(-65,-30,23);
    glVertex3f(-65,-15,23);
    glVertex3f(-45,-27,15);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-45,-30,-30);
    glVertex3f(-65,-30,-38);
    glVertex3f(-65,-15,-38);
    glVertex3f(-45,-27,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-30,23);
    glVertex3f(-65,-30,-38);
    glVertex3f(-65,-15,-38);
    glVertex3f(-65,-15,23);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-45,-30,15);
    glVertex3f(-45,-30,-30);
    glVertex3f(-45,-27,-30);
    glVertex3f(-45,-27,15);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-45,-30,15);
    glVertex3f(-65,-30,23);
    glVertex3f(-65,-30,-38);
    glVertex3f(-45,-30,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-45,-27,15);
    glVertex3f(-65,-15,23);
    glVertex3f(-65,-15,-38);
    glVertex3f(-45,-27,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-15,23);
    glVertex3f(-70,-15,25);
    glVertex3f(-70,-30,25);
    glVertex3f(-65,-30,23);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-15,-38);
    glVertex3f(-70,-15,-40);
    glVertex3f(-70,-30,-40);
    glVertex3f(-65,-30,-38);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-30,23);
    glVertex3f(-70,-30,25);
    glVertex3f(-70,-30,-40);
    glVertex3f(-65,-30,-38);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-15,23);
    glVertex3f(-70,-15,25);
    glVertex3f(-70,-15,-40);
    glVertex3f(-65,-15,-38);
    glEnd();
    
    //tribun 2 kiri
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-70,-15,25);
    glVertex3f(-70,-12,25);
    glVertex3f(-85,-3,30);
    glVertex3f(-85,-15,30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-70,-15,-40);
    glVertex3f(-70,-12,-40);
    glVertex3f(-85,-3,-45);
    glVertex3f(-85,-15,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-85,-15,30);
    glVertex3f(-85,-3,30);
    glVertex3f(-85,-3,-45);
    glVertex3f(-85,-15,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-70,-15,25);
    glVertex3f(-70,-12,25);
    glVertex3f(-70,-12,-40);
    glVertex3f(-70,-15,-40);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-70,-12,25);
    glVertex3f(-85,-3,30);
    glVertex3f(-85,-3,-45);
    glVertex3f(-70,-12,-40);
    glEnd();
    
    //tribun 3 kiri
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-85,-3,30);
    glVertex3f(-85,0,30);
    glVertex3f(-100,7,35);
    glVertex3f(-100,-3,35);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-85,-3,-45);
    glVertex3f(-85,-0,-45);
    glVertex3f(-100,7,-50);
    glVertex3f(-100,-3,-50);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-100,-3,35);
    glVertex3f(-100,7,35);
    glVertex3f(-100,7,-50);
    glVertex3f(-100,-3,-50);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-85,-3,30);
    glVertex3f(-85,0,30);
    glVertex3f(-85,0,-45);
    glVertex3f(-85,-3,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-85,0,30);
    glVertex3f(-100,7,35);
    glVertex3f(-100,7,-50);
    glVertex3f(-85,0,-45);
    glEnd();
    
    //tribun kiri ke depan
    glBegin(GL_LINES);
    glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-15.5,23);
    glVertex3f(-45,-15.5,44);
    glEnd();
    
    //tribun kiri ke belakang
    glBegin(GL_LINES);
    glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-15.5,-38);
    glVertex3f(-46,-15.5,-59);
    glEnd();
    
    //tribun kanan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(45,-30,15);
    glVertex3f(65,-30,23);
    glVertex3f(65,-15,23);
    glVertex3f(45,-27,15);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(45,-30,-30);
    glVertex3f(65,-30,-38);
    glVertex3f(65,-15,-38);
    glVertex3f(45,-27,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-30,23);
    glVertex3f(65,-30,-38);
    glVertex3f(65,-15,-38);
    glVertex3f(65,-15,23);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(45,-30,15);
    glVertex3f(45,-30,-30);
    glVertex3f(45,-27,-30);
    glVertex3f(45,-27,15);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(45,-30,15);
    glVertex3f(65,-30,23);
    glVertex3f(65,-30,-38);
    glVertex3f(45,-30,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(45,-27,15);
    glVertex3f(65,-15,23);
    glVertex3f(65,-15,-38);
    glVertex3f(45,-27,-30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-15,23);
    glVertex3f(70,-15,25);
    glVertex3f(70,-30,25);
    glVertex3f(65,-30,23);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-15,-38);
    glVertex3f(70,-15,-40);
    glVertex3f(70,-30,-40);
    glVertex3f(65,-30,-38);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-30,23);
    glVertex3f(70,-30,25);
    glVertex3f(70,-30,-40);
    glVertex3f(65,-30,-38);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-15,23);
    glVertex3f(70,-15,25);
    glVertex3f(70,-15,-40);
    glVertex3f(65,-15,-38);
    glEnd();
    
    //tribun 2 kanan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(70,-15,25);
    glVertex3f(70,-12,25);
    glVertex3f(85,-3,30);
    glVertex3f(85,-15,30);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(70,-15,-40);
    glVertex3f(70,-12,-40);
    glVertex3f(85,-3,-45);
    glVertex3f(85,-15,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(85,-15,30);
    glVertex3f(85,-3,30);
    glVertex3f(85,-3,-45);
    glVertex3f(85,-15,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(70,-15,25);
    glVertex3f(70,-12,25);
    glVertex3f(70,-12,-40);
    glVertex3f(70,-15,-40);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(70,-12,25);
    glVertex3f(85,-3,30);
    glVertex3f(85,-3,-45);
    glVertex3f(70,-12,-40);
    glEnd();
    
    //tribun 3 kanan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(85,-3,30);
    glVertex3f(85,0,30);
    glVertex3f(100,7,35);
    glVertex3f(100,-3,35);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(85,-3,-45);
    glVertex3f(85,-0,-45);
    glVertex3f(100,7,-50);
    glVertex3f(100,-3,-50);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(100,-3,35);
    glVertex3f(100,7,35);
    glVertex3f(100,7,-50);
    glVertex3f(100,-3,-50);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(85,-3,30);
    glVertex3f(85,0,30);
    glVertex3f(85,0,-45);
    glVertex3f(85,-3,-45);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(85,0,30);
    glVertex3f(100,7,35);
    glVertex3f(100,7,-50);
    glVertex3f(85,0,-45);
    glEnd();
    
    //tribun kanan ke depan
    glBegin(GL_LINES);
    glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-15.5,23);
    glVertex3f(46,-15.5,44);
    glEnd();
    
    //tribun kanan ke belakang
    glBegin(GL_LINES);
    glColor3f(0.85,0.85,0.7);
    glVertex3f(65,-15.5,-38);
    glVertex3f(46,-15.5,-59);
    glEnd();
    
    //tribun depan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,24);
    glVertex3f(36,-30,24);
    glVertex3f(36,-27,24);
    glVertex3f(-36,-27,24);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-46,-30,44);
    glVertex3f(46,-30,44);
    glVertex3f(46,-15,44);
    glVertex3f(-46,-15,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,24);
    glVertex3f(-46,-30,44);
    glVertex3f(-46,-15,44);
    glVertex3f(-36,-27,24);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(36,-30,24);
    glVertex3f(46,-30,44);
    glVertex3f(46,-15,44);
    glVertex3f(36,-27,24);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,24);
    glVertex3f(36,-30,24);
    glVertex3f(46,-30,44);
    glVertex3f(-46,-30,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-36,-27,24);
    glVertex3f(36,-27,24);
    glVertex3f(46,-15,44);
    glVertex3f(-46,-15,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-15,44);
    glVertex3f(-51,-15,54);
    glVertex3f(51,-15,54);
    glVertex3f(46,-15,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-30,44);
    glVertex3f(-51,-30,54);
    glVertex3f(51,-30,54);
    glVertex3f(46,-30,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-30,44);
    glVertex3f(-51,-30,54);
    glVertex3f(-51,-15,54);
    glVertex3f(-46,-15,44);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(46,-30,44);
    glVertex3f(51,-30,54);
    glVertex3f(51,-15,54);
    glVertex3f(46,-15,44);
    glEnd();
    
    //tribun 2 depan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(51,-15,54);
    glVertex3f(51,-12,54);
    glVertex3f(58,-3,69);
    glVertex3f(58,-15,69);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-15,54);
    glVertex3f(-51,-12,54);
    glVertex3f(-58,-3,69);
    glVertex3f(-58,-15,69);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(58,-15,69);
    glVertex3f(58,-3,69);
    glVertex3f(-58,-3,69);
    glVertex3f(-58,-15,69);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-15,54);
    glVertex3f(-51,-12,54);
    glVertex3f(51,-12,54);
    glVertex3f(51,-15,54);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-12,54);
    glVertex3f(-58,-3,69);
    glVertex3f(58,-3,69);
    glVertex3f(51,-12,54);
    glEnd();
    
    //tribun 3 depan
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(58,-3,69);
    glVertex3f(58,0,69);
    glVertex3f(65,7,84);
    glVertex3f(65,-3,84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,-3,69);
    glVertex3f(-58,-0,69);
    glVertex3f(-65,7,84);
    glVertex3f(-65,-3,84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-3,84);
    glVertex3f(-65,7,84);
    glVertex3f(65,7,84);
    glVertex3f(65,-3,84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,-3,69);
    glVertex3f(-58,0,69);
    glVertex3f(58,0,69);
    glVertex3f(58,-3,69);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,0,69);
    glVertex3f(-65,7,84);
    glVertex3f(65,7,84);
    glVertex3f(58,0,69);
    glEnd();
    
    //tribun belakang    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,-39);
    glVertex3f(36,-30,-39);
    glVertex3f(36,-27,-39);
    glVertex3f(-36,-27,-39);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-46,-30,-59);
    glVertex3f(46,-30,-59);
    glVertex3f(46,-15,-59);
    glVertex3f(-46,-15,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,-39);
    glVertex3f(-46,-30,-59);
    glVertex3f(-46,-15,-59);
    glVertex3f(-36,-27,-39);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(36,-30,-39);
    glVertex3f(46,-30,-59);
    glVertex3f(46,-15,-59);
    glVertex3f(36,-27,-39);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
	glVertex3f(-36,-30,-39);
    glVertex3f(36,-30,-39);
    glVertex3f(46,-30,-59);
    glVertex3f(-46,-30,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-36,-27,-39);
    glVertex3f(36,-27,-39);
    glVertex3f(46,-15,-59);
    glVertex3f(-46,-15,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-15,-59);
    glVertex3f(-51,-15,-69);
    glVertex3f(51,-15,-69);
    glVertex3f(46,-15,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-30,-59);
    glVertex3f(-51,-30,-69);
    glVertex3f(51,-30,-69);
    glVertex3f(46,-30,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-46,-30,-59);
    glVertex3f(-51,-30,-69);
    glVertex3f(-51,-15,-69);
    glVertex3f(-46,-15,-59);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(46,-30,-59);
    glVertex3f(51,-30,-69);
    glVertex3f(51,-15,-69);
    glVertex3f(46,-15,-59);
    glEnd();
    
    //tribun 2 belakang
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(51,-15,-69);
    glVertex3f(51,-12,-69);
    glVertex3f(58,-3,-84);
    glVertex3f(58,-15,-84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-15,-69);
    glVertex3f(-51,-12,-69);
    glVertex3f(-58,-3,-84);
    glVertex3f(-58,-15,-84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(58,-15,-84);
    glVertex3f(58,-3,-84);
    glVertex3f(-58,-3,-84);
    glVertex3f(-58,-15,-84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-15,-69);
    glVertex3f(-51,-12,-69);
    glVertex3f(51,-12,-69);
    glVertex3f(51,-15,-69);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-51,-12,-69);
    glVertex3f(-58,-3,-84);
    glVertex3f(58,-3,-84);
    glVertex3f(51,-12,-69);
    glEnd();
    
    //tribun 3 belakang
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(58,-3,-84);
    glVertex3f(58,0,-84);
    glVertex3f(65,7,-99);
    glVertex3f(65,-3,-99);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,-3,-84);
    glVertex3f(-58,-0,-84);
    glVertex3f(-65,7,-99);
    glVertex3f(-65,-3,-99);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-65,-3,-99);
    glVertex3f(-65,7,-99);
    glVertex3f(65,7,-99);
    glVertex3f(65,-3,-99);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,-3,-84);
    glVertex3f(-58,0,-84);
    glVertex3f(58,0,-84);
    glVertex3f(58,-3,-84);
    glEnd();
    
    glBegin(GL_POLYGON);
	glColor3f(0.85,0.85,0.7);
    glVertex3f(-58,0,-84);
    glVertex3f(-65,7,-99);
    glVertex3f(65,7,-99);
    glVertex3f(58,0,-84);
    glEnd();
}

void tampil(void){
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    lapangan();
    tribun();
    kursi();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int bx, int by){
    switch (key)
    {
		//maju
		case 'w':
		case 'W':
			glTranslatef(0, 0, 5);
			break;

		//kanan
		case 'd':
		case 'D':
			glTranslatef(5, 0, 0);
			break;

		//mundur
		case 's':
		case 'S':
			glTranslatef(0, 0, -5);
			break;

		//kiri
		case 'a':
		case 'A':
			glTranslatef(-5, 0, 0);
			break;
			
		//atas
		case '9':
			glTranslatef(0, 5, 0);
			break;
		
		//bawah
		case '0':
			glTranslatef(0, -5, 0);
			break;
			
		//rotasi bawah
		case 'k':
		case 'K':
			glRotatef(3, 1, 0, 0);
			break;
		
		//rotas atas
		case 'i':
		case 'I':
			glRotatef(-3, 1, 0, 0);
			break;
		
		//rotasi kanan
		case 'l':
		case 'L':
			glRotatef(3, 0, 1, 0);
			break;
			
		//rotasi kiri
		case 'j':
		case 'J':
			glRotatef(-3, 0, 1, 0);
			break;
			
		//rotasi miring kiri
		case '7':
			glRotatef(3, 0, 0, 1);
			break;
			
		//rotasi miring kanan
		case '8':
			glRotatef(-3, 0, 0, 1);
			break;
		
		//buka objek
    	case '5':
        	if (is_depth)
        	{
            	is_depth = 0;
            	glDisable(GL_DEPTH_TEST);
        	}
        	else
        	{
            	is_depth = 1;
            	glEnable(GL_DEPTH_TEST);
        	}
		}
		tampil();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(140, lebar / tinggi, 5, 500);
    glTranslatef(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);
}
