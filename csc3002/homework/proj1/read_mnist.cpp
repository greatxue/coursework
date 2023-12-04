#include "read_mnist.h"

string train_images_path = "/Users/kevinshuey/Github/coursework/csc3002/homework/proj1/mnist_raw/train-images.idx3-ubyte";
string train_labels_path = "/Users/kevinshuey/Github/coursework/csc3002/homework/proj1/mnist_raw/train-labels.idx1-ubyte";
string test_images_path = "/Users/kevinshuey/Github/coursework/csc3002/homework/proj1/mnist_raw/t10k-images.idx3-ubyte";
string test_labels_path = "/Users/kevinshuey/Github/coursework/csc3002/homework/proj1/mnist_raw/t10k-labels.idx1-ubyte";

int reverseInt(int i) {
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

Mat read_mnist_image(const string& fileName) {
    int magic_number = 0;
    int number_of_images = 0;
    int n_rows = 0;
    int n_cols = 0;

    Mat DataMat;

    ifstream file(fileName, ios::binary);
    if (file.is_open())
    {
        cout << "成功打开图像集 ..." << endl;

        file.read((char*)&magic_number, sizeof(magic_number));//幻数（文件格式）
        file.read((char*)&number_of_images, sizeof(number_of_images));//图像总数
        file.read((char*)&n_rows, sizeof(n_rows));//每个图像的行数
        file.read((char*)&n_cols, sizeof(n_cols));//每个图像的列数

        magic_number = reverseInt(magic_number);
        number_of_images = reverseInt(number_of_images);
        n_rows = reverseInt(n_rows);
        n_cols = reverseInt(n_cols);
        cout << "幻数（文件格式）:" << magic_number
             << " 图像总数:" << number_of_images
             << " 每个图像的行数:" << n_rows
             << " 每个图像的列数:" << n_cols << endl;

        cout << "开始读取Image数据......" << endl;

        DataMat = Mat::zeros(number_of_images, n_rows * n_cols, CV_32FC1);
        for (int i = 0; i < number_of_images; i++) {
            for (int j = 0; j < n_rows * n_cols; j++) {
                unsigned char temp = 0;
                file.read((char*)&temp, sizeof(temp));
                //可以在下面这一步将每个像素值归一化
                float pixel_value = float(temp);
                //按照行将像素值一个个写入Mat中
                DataMat.at<float>(i, j) = pixel_value;
            }
        }

        cout << "读取Image数据完毕......" << endl;

    }
    file.close();
    return DataMat;
}

Mat read_mnist_label(const string& fileName) {
    int magic_number;
    int number_of_items;

    Mat LabelMat;

    ifstream file(fileName, ios::binary);
    if (file.is_open())
    {
        cout << "成功打开标签集 ... " << endl;

        file.read((char*)&magic_number, sizeof(magic_number));
        file.read((char*)&number_of_items, sizeof(number_of_items));
        magic_number = reverseInt(magic_number);
        number_of_items = reverseInt(number_of_items);

        cout << "幻数（文件格式）:" << magic_number << "  ;标签总数:" << number_of_items << endl;

        cout << "开始读取Label数据......" << endl;
        //CV_32SC1代表32位有符号整型 通道数为1
        LabelMat = Mat::zeros(number_of_items, 1, CV_32SC1);
        for (int i = 0; i < number_of_items; i++) {
            unsigned char temp = 0;
            file.read((char*)&temp, sizeof(temp));
            LabelMat.at<unsigned int>(i, 0) = (unsigned int)temp;
        }
        cout << "读取Label数据完毕......" << endl;

    }
    file.close();
    return LabelMat;
}



