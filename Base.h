#pragma once
#include <iostream>
#include<vector>
using namespace std;
using namespace System;
using namespace System::Drawing;

public enum direction { right, left, down, up ,stop};
class Base
{
protected:
	int x, y, w, h, dx, dy;
	bool eliminar;
	int max_Fil, max_col, fil, col;//sprites
	direction orientacion;
	Rectangle rectangleF;
	int fraccion_movimientoW; int fraccion_movimientoH;
	int tipo;
public:
	Base();
	Base(int px,int py,int pw,int ph);
	Base(int px, int py, int pw, int ph, int pmax_fil,int pmax_col,int pfil,int pcol);
	~Base();
	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_w();
	int get_h();
	int get_tipo();
	bool get_eliminar();
	int get_max_F();
	int get_max_col();
	int get_fil();
	int get_col();
	Rectangle get_rectangle();
	int get_fraccion_movimientoW();
	int get_fraccion_movimientoH(); 
	direction get_direction();
	//
	void set_tipo(int nuevo);
	void set_x(int nuevo);
	void set_y(int nuevo);
	void set_dx(int nuevo);
	void set_dy(int nuevo);
	void set_w(int nuevo);
	void set_h(int nuevo);
	void set_eliminar(bool nuevo);
	virtual  void set_direction(direction nuevo);
	void set_max_F(int nuevo);
	void set_max_col(int nuevo);
	void set_fil(int nuevo);
	void set_col(int nuevo);
	void set_fraccion_movimientoW(int nuevo);
	void set_fraccion_movimientoH(int nuevo); 
	//
	virtual void Mover(Graphics^ g);
	void Dibujar(Graphics^ g);
	virtual void Dibujar_con_Imagen(Graphics^ g, Bitmap^ bmp);
	void Borrar(Graphics^ g);
};

