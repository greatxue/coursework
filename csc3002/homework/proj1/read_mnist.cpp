#include "read_mnist.h"

string train_images_path = "mnist_raw/train-images.idx3-ubyte";
string train_labels_path = "mnist_raw/train-labels.idx1-ubyte";
string test_images_path = "mnist_raw/t10k-images.idx3-ubyte";
string test_labels_path = "mnist_raw/t10k-labels.idx1-ubyte";

int reverseInt(int i) {
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

Mat one_hot(Mat label, int classes_num) {
    // One-hot: [5] -> [0 0 0 0 5 0 0 0 0 0]
    int rows = label.rows;
    Mat one_hot = Mat::zeros(rows, classes_num, CV_32FC1);

    for (int i = 0; i < label.rows; i++) {
        int index = label.at<int32_t>(i, 0);
        one_hot.at<float>(i, index) = 1.0;
    }

    return one_hot;
}

Mat read_mnist_image(const string& fileName) {
    int magic_number = 0;
    int number_of_images = 0;
    int n_rows = 0;
    int n_cols = 0;

    Mat DataMat;
    ifstream file(fileName, ios::binary);

    if (file.is_open()) {
        cout << "Succeed in Opening the Image Set. " << endl;

        file.read((char*)&magic_number, sizeof(magic_number)); // Magic Number
        file.read((char*)&number_of_images, sizeof(number_of_images)); // No. of images
        file.read((char*)&n_rows, sizeof(n_rows)); // Rows for each image
        file.read((char*)&n_cols, sizeof(n_cols)); // Columns for each image

        magic_number = reverseInt(magic_number);
        number_of_images = reverseInt(number_of_images);
        n_rows = reverseInt(n_rows);
        n_cols = reverseInt(n_cols);

        cout << "Magic Number: " << magic_number
             << "; No. of Images: " << number_of_images
             << "; Rows for Each Image: " << n_rows
             << "; Columns for Each Image: " << n_cols << endl;

        cout << "Start Reading Images..." << endl;

        DataMat = Mat::zeros(number_of_images, n_rows * n_cols, CV_32FC1);
        for (int i = 0; i < number_of_images; i++) {
            for (int j = 0; j < n_rows * n_cols; j++) {
                unsigned char temp = 0;
                file.read((char*)&temp, sizeof(temp));
                auto pixel_value = float(temp);
                // Write the pixel into the matrix one by one.
                DataMat.at<float>(i, j) = pixel_value;
            }
        }
        cout << "Images Reading Finished. \n" << endl;
    }
    file.close();
    return DataMat;
}

Mat read_mnist_label(const string& fileName) {
    int magic_number;
    int number_of_items;

    Mat LabelMat;

    ifstream file(fileName, ios::binary);
    if (file.is_open()) {
        cout << "Succeed in Reading Labels. " << endl;

        file.read((char*)&magic_number, sizeof(magic_number));
        file.read((char*)&number_of_items, sizeof(number_of_items));
        magic_number = reverseInt(magic_number);
        number_of_items = reverseInt(number_of_items);

        cout << "Magic Number " << magic_number
             << "; No. of Labels " << number_of_items << endl;

        cout << "Start Reading Labels..." << endl;

        // CV_32SC1: 32-bit signed integer type ，with 1 channel
        LabelMat = Mat::zeros(number_of_items, 1, CV_32SC1);

        for (int i = 0; i < number_of_items; i++) {
            unsigned char temp = 0;
            file.read((char*)&temp, sizeof(temp));
            LabelMat.at<unsigned int>(i, 0) = (unsigned int)temp;
        }
        cout << "Reading Labels Finished. \n" << endl;
    }
    file.close();
    return LabelMat;
}



