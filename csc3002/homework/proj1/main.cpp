#include "read_mnist.h"

int main()
{
    /*
    ---------第一部分：训练数据准备-----------
    */
    //读取训练标签数据 (60000,1) 类型为int32
    Mat train_labels = read_mnist_label(train_labels_path);

    //读取训练图像数据 (60000,784) 类型为float32 数据未归一化
    Mat train_images = read_mnist_image(train_images_path);
    //将图像数据归一化
    train_images = train_images / 255.0;

    //读取测试数据标签(10000,1) 类型为int32
    Mat test_labels = read_mnist_label(test_labels_path);

    //读取测试数据图像 (10000,784) 类型为float32 数据未归一化
    Mat test_images = read_mnist_image(test_images_path);
    //归一化
    test_images = test_images / 255.0;

    /*
    ---------第二部分：构建svm训练模型并进行训练-----------
    */
    cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
    //设置类型为C_SVC代表分类
    svm->setType(cv::ml::SVM::C_SVC);
    //设置核函数
    svm->setKernel(cv::ml::SVM::POLY);
    //设置其它属性
    svm->setGamma(3.0);
    svm->setDegree(3.0);
    //设置迭代终止条件
    svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, 300, 0.0001));

    //开始训练
    cv::Ptr<cv::ml::TrainData> train_data = cv::ml::TrainData::create(train_images, cv::ml::ROW_SAMPLE, train_labels);
    cout << "开始进行训练..." << endl;
    svm->train(train_data);
    cout << "训练完成" << endl;

    /*
    ---------第三部分：在测试数据集上预测计算准确率-----------
    */
    Mat pre_out;
    //返回值为第一个图像的预测值 pre_out为整个batch的预测值集合
    cout << "开始进行预测..." << endl;
    float ret = svm->predict(test_images, pre_out);
    cout << "预测完成" << endl;

    //计算准确率必须将两种标签化为同一数据类型
    pre_out.convertTo(pre_out, CV_8UC1);
    test_labels.convertTo(test_labels, CV_8UC1);

    int equal_nums = 0;
    for (int i = 0; i <pre_out.rows; i++)
    {
        if (pre_out.at<uchar>(i, 0) == test_labels.at<uchar>(i, 0))
        {
            equal_nums++;
        }
    }
    float acc = float(equal_nums) / float(pre_out.rows);
    cout << "测试数据集上的准确率为：" << acc * 100 << "%" << endl;

    //保存模型
    svm->save("mnist_svm.xml");


    getchar();
    return 0;
}

