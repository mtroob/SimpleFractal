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
#include <string>
#include <algorithm>

#include "fractalcreator.h"
#include "color/linearinterpolatedcoloring.h"
#include "color/simplecoloring.h"
#include "fractal/mandelbrot.h"
#include "output/bmp/bmpfile.h"

using std::cout;
using std::endl;
using std::chrono::system_clock;
using std::chrono::duration;

using namespace fractal;

void drawFractal(FractalCreator& fc, std::shared_ptr<ColoringAlgorithm> coloring_algorithm, const string& file_name);
void drawFractalCircle(FractalCreator& fc, std::shared_ptr<ColoringAlgorithm> coloring_algorithm, const string& file_name);

int main() {
	cout << "Fractal generation started" << endl;
	try {
		const int WIDTH {1800};
		const int HEIGHT {1200};

		const int MAX_ITERATIONS {1000};

		std::shared_ptr<Fractal> fractal{new Mandelbrot (MAX_ITERATIONS, 2)};

		FractalCreator fc(WIDTH, HEIGHT, fractal);

		std::shared_ptr<SimpleColoring> simple_coloring {new SimpleColoring(MAX_ITERATIONS)};

		std::shared_ptr<LinearInterpolatedColoring> linear_coloring {new LinearInterpolatedColoring(MAX_ITERATIONS)};

		linear_coloring->addColor(0.0, {100, 7, 0});
		linear_coloring->addColor(0.02, {120, 230, 62});
		linear_coloring->addColor(0.08, {203, 107, 50});
		linear_coloring->addColor(0.32, {255, 255, 237});
		linear_coloring->addColor(0.6425, {0, 170, 255});
		linear_coloring->addColor(0.8575, {0, 2, 200});
		linear_coloring->addColor(1, {0, 0, 0});

//		drawFractalCircle(fc, linear_coloring, "rotation.bmp");

		drawFractal(fc, linear_coloring, "bitmap_1.bmp");

//		fc.addZoom(Zoom({759, 1200-490}, 0.001));

		fc.addZoom(Zoom({WIDTH/4, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, 3*HEIGHT/4}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, HEIGHT/2}, 0.5));

		drawFractal(fc, linear_coloring, "bitmap_2.bmp");

		fc.addZoom(Zoom({3*WIDTH/4, HEIGHT/2}, 0.5));
		fc.addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));
		fc.addZoom(Zoom({WIDTH/3, HEIGHT/2}, 0.1));
		fc.addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));

		drawFractal(fc, linear_coloring, "bitmap_3.bmp");

		while(fc.removeZoom());

		drawFractal(fc, simple_coloring, "bitmap_4.bmp");

		cout << "Fractal generation finished" << endl;
	} catch (std::exception& e) {
		e.what();
	}
	return 0;
}

void drawFractal(FractalCreator& fc, std::shared_ptr<ColoringAlgorithm> coloring_algorithm, const string& file_name) {
	system_clock::time_point start_point;
	duration<double> elapsed;

	start_point = system_clock::now();
	fc.calcuclateIterationsPerPixel();
	//fc.generateIterationHistogram();
	elapsed = system_clock::now() - start_point;
	cout << "calcuclateIterationsPerPixel: " << elapsed.count() << endl;

	start_point = system_clock::now();
	fc.drawFractal(coloring_algorithm);
	elapsed = system_clock::now() - start_point;
	cout << "drawFractal: " << elapsed.count() << endl;

	start_point = system_clock::now();
	BMPFile file;
   fc.save(&file, file_name);
	elapsed = system_clock::now() - start_point;
	cout << "writeBitmap: " << elapsed.count() << endl;
}

void drawFractalCircle(FractalCreator& fc, std::shared_ptr<ColoringAlgorithm> coloring_algorithm, const string& file_name) {
	auto step_number = 72;
	auto angle_step = 360.0 / step_number;

	auto last_dot_position = --std::find(file_name.rbegin(), file_name.rend(), '.').base();
	std::string file_name_base(file_name.begin(), last_dot_position);
	std::string file_extension(last_dot_position, file_name.end());

	for (auto i = 0; i < step_number; ++i) {
		auto angle = angle_step*i;
		fc.rotate(angle);
		fc.calcuclateIterationsPerPixel();
		fc.drawFractal(coloring_algorithm);

		fc.writeBitmap(file_name_base + "_" + std::to_string(static_cast<int>(angle)) + file_extension);
	}
}
