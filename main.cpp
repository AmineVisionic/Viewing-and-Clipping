#include "FrameBuffer.cpp"
#include <cstring>
#include <termios.h>
#include <fstream>
#include "assets.h"

using namespace std;

FrameBuffer FB;
bool quit = false;
vector<Polygon> map;
Window window;
int key;

int kbhit(void);
Polygon matrixToPolygon(int object[][2], int col);
void drawMap();
void redraw();
void move(int key);

View view;
Polygon map_border = matrixToPolygon(border,sizeof(border)/sizeof(*border));
Polygon p_sumatra = matrixToPolygon(sumatra,sizeof(sumatra)/sizeof(*sumatra));
Polygon p_kalimantan = matrixToPolygon(kalimantan,sizeof(kalimantan)/sizeof(*kalimantan));
Polygon p_sulawesi = matrixToPolygon(sulawesi,sizeof(sulawesi)/sizeof(*sulawesi));
Polygon p_papua = matrixToPolygon(papua,sizeof(papua)/sizeof(*papua));

int main() {
	// Adjust positions of the islands
	p_sumatra.moveDown(20);
	p_kalimantan.scale(1.55);
	p_kalimantan.moveRight(150);
	p_kalimantan.moveDown(40);
	p_sulawesi.scale(1.25);
	p_sulawesi.moveRight(320);
	p_sulawesi.moveDown(90);
	p_papua.scale(2);
	p_papua.moveRight(430);
	p_papua.moveDown(110);

	map.push_back(p_sumatra);
	map.push_back(p_kalimantan);
	map.push_back(p_sulawesi);
	map.push_back(p_papua);

	system("clear");

	drawMap();
	FB.drawPolygon(view.pol,255,255,255,0);
	FB.drawWindow(window,255,255,255,0);
	redraw();

	while(!quit){
		if(kbhit()){
			key=getchar();
			//PANGGIL FUNGSI UNTUK REDRAW MOVEMENT
			move(key);
		}
	}

	//system("clear");

	return 0;
}

int kbhit(void) {
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

Polygon matrixToPolygon(int object[][2], int col) {
	vector<Point> points;
	points.clear();
	for(int i=0;i<col;i++) {
		points.push_back(Point(object[i][0],object[i][1]));
	}
	return Polygon(points);
}

void drawMap() {
	FB.drawPolygon(map_border,0, 255, 255,0);
	FB.drawPolygon(p_sumatra,255,255,0,0);
	FB.drawPolygon(p_kalimantan,255,255,0,0);
	FB.drawPolygon(p_sulawesi,255,255,0,0);
	FB.drawPolygon(p_papua,255,255,0,0);
}

void redraw() { //untuk redraw view
	vector<Polygon> temp;
	for(int i=0;i<map.size();i++) {
		int j=0;
		bool found = false;
		while(j<map[i].e.size() && !found) {
			if(not(map[i].e[j].x<window.getTopLeft().x || map[i].e[j].y<window.getTopLeft().y 
				|| map[i].e[j].y>window.getBottomRight().y || map[i].e[j].x>window.getBottomRight().x)) {
				found = true;
				temp.push_back(map[i]);
			}
			j++;
		}
	}

	if(!window.lines.empty()) {
		FB.cleararea(view.P1.x,view.P1.y,view.P2.x,view.P2.y);
	}

	if(!temp.empty()) {
		window.clipAllPolygon(temp);
		if(!window.lines.empty()) {
			view.setViewLines(window);
			FB.drawView(view,0,250,250,0);	
			view.lines.clear();
			window.lines.clear();
			temp.clear();
		}	
	}
}

void move(int key) {
	system("clear");
	//int border[][2]={{0,0},{599,0},{599,400},{0,400}};
	if((window.square.e[0].y>0)&&(window.square.e[0].x>0)&&
		(window.square.e[1].x<599)&&(window.square.e[1].y<400)) {
		if(key=='w'){
			window.square.e[0] = Point(window.square.e[0].x,window.square.e[0].y-=10);
			window.square.e[1] = Point(window.square.e[1].x,window.square.e[1].y-=10);
			window.square.e[2] = Point(window.square.e[2].x,window.square.e[2].y-=10);
			window.square.e[3] = Point(window.square.e[3].x,window.square.e[3].y-=10);
		}
		else if(key=='a'){
			window.square.e[0] = Point(window.square.e[0].x-=10,window.square.e[0].y);
			window.square.e[1] = Point(window.square.e[1].x-=10,window.square.e[1].y);
			window.square.e[2] = Point(window.square.e[2].x-=10,window.square.e[2].y);
			window.square.e[3] = Point(window.square.e[3].x-=10,window.square.e[3].y);
		}
		else if(key=='d'){
			window.square.e[0] = Point(window.square.e[0].x+=10,window.square.e[0].y);
			window.square.e[1] = Point(window.square.e[1].x+=10,window.square.e[1].y);
			window.square.e[2] = Point(window.square.e[2].x+=10,window.square.e[2].y);
			window.square.e[3] = Point(window.square.e[3].x+=10,window.square.e[3].y);
		}
		else if(key=='x'){
			window.square.e[0] = Point(window.square.e[0].x,window.square.e[0].y+=10);
			window.square.e[1] = Point(window.square.e[1].x,window.square.e[1].y+=10);
			window.square.e[2] = Point(window.square.e[2].x,window.square.e[2].y+=10);
			window.square.e[3] = Point(window.square.e[3].x,window.square.e[3].y+=10);
		}
		else if(key=='m') {
			window.zoomOut(1.1);
		}
		else if(key=='k') {
			window.zoomIn(1.1);
		}
	}
	if(key=='q') {
		// OTHER KEYS
		quit=true;
		system("clear");
	}
	//menggambar ulang peta
	drawMap();

	//menggambar ulang window & view
	FB.drawPolygon(view.pol,255,255,255,0);
	FB.cleararea(view.P1.x,view.P1.y,view.P2.x,view.P2.y);
	FB.drawWindow(window,255,255,255,0);
	redraw();
}