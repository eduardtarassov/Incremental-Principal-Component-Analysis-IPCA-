#pragma once
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

class CPCA
{
public:
	CPCA(int n, bool copy = true, bool whiten = false);
	~CPCA();
	void Fit(Mat x);
	void FitI(Mat x);
	void PartialFit(Mat x);

private:
	Mat x;
	int n; // Maximum number of components to keep. 

};

