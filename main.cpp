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
#include "linearinterpolatedcoloring.h"
#include "simplecoloring.h"

using std::cout;
using std::endl;
using std::chrono::system_clock;
using std::chrono::duration;

using namespace fractal;

void drawFractal(FractalCreator& fc, const string& file_name);

int main() {
	cout << "Fractal generation started" << endl;
	try {
		const int WIDTH {1800};
		const int HEIGHT {1200};

		std::shared_ptr<SimpleColoring> simple_coloring {new SimpleColoring()};

		std::shared_ptr<LinearInterpolatedColoring> linear_coloring {new LinearInterpolatedColoring()};

		linear_coloring->addColor(0.0, {100, 7, 0});
		linear_coloring->addColor(0.02, {120, 230, 62});
		linear_coloring->addColor(0.10, {203, 107, 32});
		linear_coloring->addColor(0.42, {255, 255, 237});
		linear_coloring->addColor(0.6425, {0, 170, 255});
		linear_coloring->addColor(0.8575, {0, 2, 0});
		linear_coloring->addColor(1, {0, 0, 0});

		FractalCreator fc(WIDTH, HEIGHT, linear_coloring);

		drawFractal(fc, "bitmap_1.bmp");

		fc.addZoom(Zoom({WIDTH/4, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, 3*HEIGHT/4}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, HEIGHT/2}, 0.5));

		drawFractal(fc, "bitmap_2.bmp");

		fc.addZoom(Zoom({3*WIDTH/4, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));
		fc.addZoom(Zoom({WIDTH/3, HEIGHT/2}, 0.1));
		fc.addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));
		drawFractal(fc, "bitmap_3.bmp");

		while(fc.removeZoom());
		fc.setColoringAlgorithm(simple_coloring);

		drawFractal(fc, "bitmap_4.bmp");

	} catch (std::exception& e) {
		e.what();
	}
	return 0;
}

void drawFractal(FractalCreator& fc, const string& file_name) {
	system_clock::time_point start_point;
	duration<double> elapsed;

	start_point = system_clock::now();
	fc.calcuclateIterationsPerPixel();
	fc.generateIterationHistogram();
	elapsed = system_clock::now() - start_point;
	cout << "calcuclateIterationsPerPixel: " << elapsed.count() << endl;

//	start_point = system_clock::now();
//	fc.calcualtePixelsPerColorRange();
//	elapsed = system_clock::now() - start_point;
//	cout << "calcualtePixelsPerColorRange: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.drawFractal();
	elapsed = system_clock::now() - start_point;
	cout << "drawFractal: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.writeBitmap(file_name);
	elapsed = system_clock::now() - start_point;
	cout << "writeBitmap: " << elapsed.count() << endl;

	cout << "Fractal generation finished" << endl;
}

