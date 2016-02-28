#include "stdafx.h"
#include "CPCA.h"


CPCA::CPCA(int n, bool copy, bool whiten)
{
	this->n = n;

}


void CPCA::Fit(Mat x){
	int n_samples = x.rows;    // 10
	int n_features = x.cols;   // 2

	/*
	* Unnecessary block of code now as we calculate mean and covariance from calcCovarMatrix opencv function.
	* Calculating the mean.
	* Storing mean for each column in 'mean' matrix.
	* Subtract mean from the dataset;
	*/
	Mat mean = Mat_<float>(1, x.cols);
	Mat dataAdjust = Mat_<float>(x.rows, x.cols);
	for (int i = 0; i < x.cols; i++){
		mean.col(i) = cv::mean(x.col(i));  // [1.81, 1.19]]

		//for (int j = 0; j < x.rows; j++)
		dataAdjust.col(i) = x.col(i) - mean.col(i).at<float>(0);  // DataAdjust

	}


	/*Mat cov; // we don't need covariance mat anymore (but we need mean)
	Mat mean;
	try{
	calcCovarMatrix(x, cov, mean, CV_COVAR_NORMAL | CV_COVAR_ROWS);
	}
	catch (Exception e) {
	cout << e.msg << endl;
	}

	cov = cov / (x.rows - 1);*/

	/*
	* Calculation of eigenvectors and eigenvalues this way is now unnecessary.
	* As now we are getting eigenvectors ordered by eigenvalues from SVD calculation.
	Mat eval;
	Mat evec;
	eigen(cov, eval, evec);*/

	/*Mat dataAdjust = x.clone();
	for (int i = 0; i < x.cols; i++){
	for (int j = 0; j < x.rows; j++)
	dataAdjust.col(i).at<float>(j) -= mean.col(i).at<double>(0);  // NewData
	}*/



	Mat S, U, V;
	SVD::compute(dataAdjust, S, U, V);


	Mat transformedData = Mat_<float>(10, 2);

	for (int i = 0; i < 2; i++){
		transformedData.col(i) = U.col(i) * S.at<float>(i);
	}

	cout << transformedData << endl << endl << endl;
}


/*void PCAmodel::PartialFit(Mat x){
int n_samples = x.rows;    // 10
int n_features = x.cols;   // 2

}

void PCAmodel::FitI(Mat x){
int n_samples = x.rows;    // 10
int n_features = x.cols;   // 2


for (int i = 0; i < x.cols; i++){
PartialFit(x.col(i));
}*/


/*Mat cov;
Mat mean;
try{
calcCovarMatrix(x, cov, mean, CV_COVAR_NORMAL | CV_COVAR_ROWS);
}
catch (Exception e) {
cout << e.msg << endl;
}

cov = cov / (x.rows - 1);*/


/*}*/


CPCA::~CPCA()
{

}
