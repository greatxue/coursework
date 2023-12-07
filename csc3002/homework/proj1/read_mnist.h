#ifndef READ_MNIST_H
#define READ_MNIST_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include <string>
#include <fstream>

using namespace std;
using namespace cv;

/* Function: reverseInt(int i);
 * ----------------------------
 * Reverses the byte order of an integer.
 * This function is typically used for converting between big-endian and
 * little-endian formats, as endianness dictates the byte order in memory.
 *
 * Parameters:
 * i - The integer whose byte order will be reversed.
 *
 * Returns:
 * int - The integer with its byte order reversed.
 */

int reverseInt(int i);

/* Function: read_mnist_image(const string& fileName);
 * ---------------------------------------------------
 * Reads and returns MNIST images from the specified file.
 * The MNIST database contains handwritten digits and is commonly
 * used for training and testing in the field of machine learning.
 *
 * Parameters:
 * fileName - The name of the file containing MNIST images.
 *
 * Returns:
 * Mat - A matrix representing the read MNIST images.
 */

Mat read_mnist_image(const string& fileName);

/* Function: read_mnist_label(const string& fileName);
 * ---------------------------------------------------
 * Reads and returns the labels associated with MNIST images from the specified file.
 * The MNIST dataset labels represent the digit each image corresponds to.
 *
 * Parameters:
 * fileName - The name of the file containing MNIST labels.
 *
 * Returns:
 * Mat - A matrix representing the read MNIST labels.
 */

Mat read_mnist_label(const string& fileName);

/* Function: one_hot(Mat label, int classes_num);
 * ----------------------------------------------
 * Converts a label matrix to one-hot encoding.
 * In one-hot encoding, each label is represented as a binary vector with all
 * zeros except for a single one at the index of the class the label represents.
 *
 * Parameters:
 * label - The matrix of labels to be converted.
 * classes_num - The total number of classes.
 *
 * Returns:
 * Mat - A matrix representing the labels in one-hot encoded format.
 */

Mat one_hot(Mat label, int classes_num);



/* train_images_path
 * ------------------
 * Path to the training images file of the MNIST dataset.
 * This file contains the image data used for training a model.
 */

extern string train_images_path;

/* train_labels_path
 * ------------------
 * Path to the training labels file of the MNIST dataset.
 * This file contains the labels corresponding to the training images.
 */

extern string train_labels_path;

/* test_images_path
 * -----------------
 * Path to the test images file of the MNIST dataset.
 * This file contains the image data used for testing a model.
 */

extern string test_images_path;

/* test_labels_path
 * -----------------
 * Path to the test labels file of the MNIST dataset.
 * This file contains the labels corresponding to the test images.
 */

extern string test_labels_path;

#endif //READ_MNIST_H
