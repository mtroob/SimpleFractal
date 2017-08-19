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
#include <exception>

#include "fractalcreator.h"

using std::cout;
using std::endl;
using std::chrono::system_clock;
using std::chrono::duration;

using namespace fractal;

int main() {
	cout << "Fractal generation started" << endl;
	try {
		const int WIDTH {800};
		const int HEIGHT {600};

		FractalCreator fc(WIDTH, HEIGHT);

		fc.addZoom(Zoom({WIDTH/4, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, 3*HEIGHT/4}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({3*WIDTH/4, HEIGHT/2}, 0.5));

		// TODO: need to change this in a way that will check values
		fc.addRange(0.0, {100, 7, 0});
		fc.addRange(0.16, {203, 107, 32});
		fc.addRange(0.42, {255, 255, 237});
		fc.addRange(0.6425, {0, 170, 255});
		fc.addRange(0.8575, {0, 2, 0});
		fc.addRange(1, {0, 0, 0});

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
	} catch (std::exception& e) {
		e.what();
	}
	return 0;
}

