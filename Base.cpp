#include "Base.h"

Base::Base() {
	dx = dy = 0;
	orientacion = direction::stop;
	eliminar = false;
	
}
Base::Base(int px, int py, int pw, int ph){
	x = px;
	y = py;
	w = pw;
	h = ph;
	dx = dy = 0;
	orientacion = direction::stop;
	eliminar = false;
}
Base::Base(int px, int py, int pw, int ph, int pmax_fil, int pmax_col,int pfil,int pcol) {
	x = px;
	y = py;
	w = pw;
	h = ph;
	max_Fil = pmax_fil;
	max_col = pmax_col;
	fil = pfil;
	col = pcol;
	dx = dy = 0;
	orientacion = direction::stop;
	eliminar = false;

}
Base::~Base() {
}
int Base::get_x() { return x; }
int Base::get_y() { return y; }
int Base::get_dx() { return dy; }
int Base::get_dy() { return dx; }
int Base::get_w() { return w; }
int Base::get_h() { return h; }
bool Base::get_eliminar() { return eliminar; }
Rectangle Base::get_rectangle(){ return Rectangle(x, y, w, h); }
int Base::get_max_F() { return max_Fil; }
int Base::get_max_col() { return max_col; }
int Base::get_fil() { return fil; }
int Base::get_col() { return col; }
int Base::get_fraccion_movimientoW() { return fraccion_movimientoW; }
int Base::get_fraccion_movimientoH() { return fraccion_movimientoH; }
direction Base::get_direction() { return orientacion; }
//
void Base::set_x(int nuevo) { x = nuevo; }
void Base::set_y(int nuevo) { y = nuevo; }
void Base::set_dx(int nuevo) { dx = nuevo; }
void Base::set_dy(int nuevo) { dy = nuevo; }
void Base::set_w(int nuevo) { w = nuevo; }
void Base::set_h(int nuevo) { h = nuevo; }
void Base::set_eliminar(bool nuevo) { eliminar = nuevo; }
 void Base::set_direction(direction nuevo) {
	orientacion = nuevo;
	dx = dy = 0;
	if (orientacion == direction::up) { dy = -(h/ fraccion_movimientoH); fil = 0; }
	if (orientacion == direction::down) { dy = (h / fraccion_movimientoH); fil = 2; }
	if (orientacion == direction::left) { dx = -(w / fraccion_movimientoW); fil = 1; }
	if (orientacion == direction::right) { dx = (w / fraccion_movimientoW); fil = 3; }
}
void Base::set_max_F(int nuevo) { max_Fil = nuevo; }
void Base::set_max_col(int nuevo) { max_col = nuevo; }
void Base::set_fil(int nuevo) { fil = nuevo; }
void Base::set_col(int nuevo) { col = nuevo; }

void Base::set_fraccion_movimientoW(int nuevo) { fraccion_movimientoW=nuevo; }
void Base::set_fraccion_movimientoH(int nuevo) { fraccion_movimientoH = nuevo; }
//
void Base::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)dx = dx * -1;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy = dy * -1;
	x += dx;
	y += dy;
}
void Base::Dibujar(Graphics^ g){}
void Base::Dibujar_con_Imagen(Graphics^ g, Bitmap^ bmp){

	w = bmp->Width / max_col;
	h = bmp->Height / max_Fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	col++;
	if (col >= max_col)
	{
		col = 0;
		fil++;
		if (fil == max_Fil)
			fil = 0;
	}	
	
}
void Base::Borrar(Graphics^ g){}

int Base::get_tipo() {
	return tipo;
}
void Base::set_tipo(int nuevo) { tipo = nuevo; }