#ifndef READ_MNIST_H
#define READ_MNIST_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include <string>
#include <fstream>

using namespace std;
using namespace cv;

//小端存储转换
int reverseInt(int i);
//读取image数据集信息
Mat read_mnist_image(const string& fileName);
//读取label数据集信息
Mat read_mnist_label(const string& fileName);

extern string train_images_path;
extern string train_labels_path;
extern string test_images_path;
extern string test_labels_path;

#endif //READ_MNIST_H
