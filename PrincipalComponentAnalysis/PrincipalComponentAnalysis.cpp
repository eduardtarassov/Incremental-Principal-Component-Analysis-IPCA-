// PCA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

#include "CPCA.h"


using namespace cv;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Mat data = (Mat_<float>(10, 2) << 2.5, 0.5, 2.2, 1.9, 3.1, 2.3, 2.0, 1.0, 1.5, 1.1, 2.4, 0.7, 2.9, 2.2, 3.0, 2.7, 1.6, 1.1, 1.6, 0.9);
	int n_components = 3;
	Mat data = (Mat_<float>(10, 2) << 2.5, 2.4, 0.5, 0.7, 2.2, 2.9, 1.9, 2.2, 3.1, 3.0, 2.3, 2.7, 2.0, 1.6, 1.0, 1.1, 1.5, 1.6, 1.1, 0.9); // Each dataset is stored in a certain column and 10 rows

	//Mat data = (Mat_<float>(10, 3) << 2.5, 2.4, 1.1, 0.5, 0.7, 1.3, 2.2, 2.9, 2.6, 1.9, 2.2, 0.3, 3.1, 3.0, 0.4, 2.3, 2.7, 0.1, 2.0, 1.6, 2.3, 1.0, 1.1, 3.0, 1.5, 1.6, 2.9, 1.1, 0.9, 2.7);



	CPCA model = CPCA(n_components);
	model.Fit(data);


	return 0;
}