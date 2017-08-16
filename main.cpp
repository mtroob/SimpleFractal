/*
 * main.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#include <iostream>
#include <limits>
#include <memory>
#include <chrono>

#include "fractalcreator.h"

using std::cout;
using std::endl;
using std::chrono::system_clock;
using std::chrono::duration;

using namespace fractal;

int main() {
	cout << "Fractal generation started" << endl;

	const int WIDTH {800};
	const int HEIGHT {600};

	FractalCreator fc(WIDTH, HEIGHT);

	fc.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	fc.addZoom(Zoom(295, HEIGHT-202, 0.1));
	fc.addZoom(Zoom(312, HEIGHT-304, 0.1));

	// TODO: need to change this in a way that will check values
	fc.addRange(0.0, {0, 0, 0});
	fc.addRange(0.3, {0, 120, 0});
	fc.addRange(0.5, {0, 120, 180});
	fc.addRange(1, {255, 255, 255});

	system_clock::time_point start_point;
	duration<double> elapsed;

	start_point = system_clock::now();
	fc.calcuclateIterationsPerPixel();
	elapsed = system_clock::now() - start_point;
	cout << "calcuclateIterationsPerPixel: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.calcualtePixelsPerColorRange();
	elapsed = system_clock::now() - start_point;
	cout << "calcualtePixelsPerColorRange: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.drawFractal();
	elapsed = system_clock::now() - start_point;
	cout << "drawFractal: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.writeBitmap("bitmap_2.bmp");
	elapsed = system_clock::now() - start_point;
	cout << "writeBitmap: " << elapsed.count() << endl;

	cout << "Fractal generation finished" << endl;
	return 0;
}

