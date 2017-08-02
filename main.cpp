/*
 * main.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#include <iostream>
#include <limits>
#include <memory>

#include "fractalcreator.h"

using std::cout;
using std::endl;

using namespace fractal;

int main() {
	cout << "Fractal generation started" << endl;

	const int WIDTH {800};
	const int HEIGHT {600};

	FractalCreator fc(WIDTH, HEIGHT);
	fc.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	fc.addZoom(Zoom(295, HEIGHT-202, 0.1));
	fc.addZoom(Zoom(312, HEIGHT-304, 0.1));
	fc.calculateIteration();
	fc.drawFractal();
	fc.writeBitmap("bitmap_2.bmp");

	cout << "Fractal generation finished" << endl;
	return 0;
}

