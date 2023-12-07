#include "predict.h"

using namespace chrono;

int main() {
    // Load the Training Set and the Testing Set

    cout << "--------------------------Read Training Set------------------------------" << endl;

    Mat train_images = readAndNormalizeImages(train_images_path);
    Mat train_labels = readLabels(train_labels_path);

    cout << "--------------------------Read Testing Set------------------------------" << endl;

    Mat test_images = readAndNormalizeImages(test_images_path);
    Mat test_labels = readLabels(test_labels_path);


    // Construct and train the model.

    cout << "--------------------------Training Section------------------------------" << endl;

    cv::Ptr<cv::ml::SVM> svm = trainSVMModel(train_images, train_labels);
    cv::Ptr<cv::ml::KNearest> knn = trainKNNModel(train_images, train_labels);
    cv::Ptr<cv::ml::ANN_MLP> ann = trainANNModel(train_images, train_labels);
    cv::Ptr<cv::ml::DTrees> dtrees = trainDTreeModel(train_images, train_labels);

    // Evaluate the model via accuracy.

    cout << "--------------------------Evaluation Section------------------------------" << endl;

    evaluateModel(svm, test_images, test_labels, "SVM");
    evaluateModel(knn, test_images, test_labels, "KNN");
    evaluateModel(dtrees, test_images, test_labels, "DTrees");
    evaluateModelANN(ann, test_images, test_labels, "ANN");

    // Save the model file for further analysis.

    cout << "Start Saving Models." << endl;

    svm->save("mnist_svm.xml");
    knn->save("mnist_knn.xml");
    dtrees->save("mnist_dtrees.xml");
    ann->save("mnist_ann.xml");
    cout << "Models Saved." << endl;

    getchar();
    return 0;
}


Mat readAndNormalizeImages(const string &images_path) {
    Mat images = read_mnist_image(images_path);
    images = images / 255.0;
    return images;
}

Mat readLabels(const string &labels_path) {
    return read_mnist_label(labels_path);
}

cv::Ptr<cv::ml::SVM> trainSVMModel(const Mat &train_images, const Mat &train_labels) {
    cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
    // Set C_SVC for a classification problem.
    svm->setType(cv::ml::SVM::C_SVC);
    // Set the Kernel Function as polynomials.
    svm->setKernel(cv::ml::SVM::POLY);
    // Set Gamma and Degree.
    svm->setGamma(3.0);
    svm->setDegree(3.0);
    // Set the terminal condition.
    svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS, 300, 0.0001));


    cv::Ptr<cv::ml::TrainData> train_data = cv::ml::TrainData::create(train_images, cv::ml::ROW_SAMPLE, train_labels);
    cout << "Start SVM Training..." << endl;

    auto start = high_resolution_clock::now(); // Set the timer
    svm->train(train_data); // Train SVM
    auto end = high_resolution_clock::now(); // Terminate the timer

    duration<double> elapsed = end - start; // Calculate the time spending


    cout << "SVM Training Finished." << endl;
    cout << "SVM Training Time: " << elapsed.count() << " seconds" << "\n" << endl;
    return svm;
}

cv::Ptr<cv::ml::DTrees> trainDTreeModel(const Mat &train_images, const Mat &train_labels) {
    // Apply Gaussian Blur
    cv::GaussianBlur(train_images, train_images, cv::Size(5, 5), 0);


    cv::Ptr<cv::ml::DTrees> dtree = cv::ml::DTrees::create();
    // Set the DTree parameters.
    dtree->setMaxCategories(10);
    dtree->setMaxDepth(15);
    dtree->setMinSampleCount(5);
    dtree->setCVFolds(0); // Setting to 0 disables cross-validation
    dtree->setUseSurrogates(false);
    dtree->setUse1SERule(false);
    dtree->setTruncatePrunedTree(false);
    dtree->setRegressionAccuracy(0); // Used for regression problems
    dtree->setPriors(cv::Mat()); // Setting priors to an empty matrix

    cv::Ptr<cv::ml::TrainData> train_data = cv::ml::TrainData::create(train_images, cv::ml::ROW_SAMPLE, train_labels);

    cout << "Start DTree Training..." << endl;

    auto start = high_resolution_clock::now();
    dtree->train(train_data);
    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    cout << "DTree Training Finished." << endl;
    cout << "DTree Training Time: " << elapsed.count() << " seconds" << "\n" << endl;
    return dtree;
}

cv::Ptr<cv::ml::ANN_MLP> trainANNModel(const Mat &train_images, const Mat &train_labels) {
    Mat train_labels_modified = one_hot(train_labels, 10);
    cv::Ptr<cv::ml::ANN_MLP> ann = cv::ml::ANN_MLP::create();
    // Set the layer structure.
    Mat layerSizes = (Mat_<int>(1, 3) << 784, 64, 10);
    ann->setLayerSizes(layerSizes);
    // Set the backdrop as the update method.
    ann->setTrainMethod(cv::ml::ANN_MLP::BACKPROP, 0.001, 0.1);
    // Set the sigmod function.
    ann->setActivationFunction(cv::ml::ANN_MLP::SIGMOID_SYM, 1.0, 1.0);
    // Set the termination condition for a maximum of 10 times.
    ann->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER | TermCriteria::EPS, 10, 0.0001));

    cv::Ptr<cv::ml::TrainData> train_data = cv::ml::TrainData::create(train_images, cv::ml::ROW_SAMPLE,
                                                                      train_labels_modified);
    cout << "Start ANN Training..." << endl;

    auto start = high_resolution_clock::now();
    ann->train(train_data);
    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    cout << "ANN Training Finished." << endl;
    cout << "ANN Training Time: " << elapsed.count() << " seconds" << "\n" << endl;
    return ann;
}

cv::Ptr<cv::ml::KNearest> trainKNNModel(const Mat &train_images, const Mat &train_labels) {
    Ptr<cv::ml::KNearest> knn = cv::ml::KNearest::create();
    // Set KNN parameters
    knn->setDefaultK(3);
    knn->setIsClassifier(true);
    knn->setAlgorithmType(cv::ml::KNearest::BRUTE_FORCE);


    cout << "Start KNN Training..." << endl;

    auto start = high_resolution_clock::now();
    knn->train(train_images, cv::ml::ROW_SAMPLE, train_labels);
    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    cout << "KNN Training Finished." << endl;
    cout << "KNN Training Time: " << elapsed.count() << " seconds" << "\n" << endl;
    return knn;
}

void evaluateModelANN(const Ptr<cv::ml::StatModel> &model, const Mat &test_images, const Mat &test_labels,
                      const string &model_name) {

    Mat pre_out;
    cout << "Start " << model_name << " Prediction..." << endl;
    float ret = model->predict(test_images, pre_out);
    cout << model_name << " Prediction Finished. " << endl;

    int equal_nums = 0;
    for (int i = 0; i < pre_out.rows; i++) {

        // Get the one-hot index.
        Mat temp = pre_out.rowRange(i, i + 1);
        double maxVal = 0;
        cv::Point maxPoint;
        cv::minMaxLoc(temp, nullptr, &maxVal, nullptr, &maxPoint);
        int max_index = maxPoint.x;
        int test_index = test_labels.at<int32_t>(i, 0);
        if (max_index == test_index) {
            equal_nums++;
        }
    }
    float acc = float(equal_nums) / float(pre_out.rows);
    cout << "Prediction Accuracy on Testing Set: " << acc * 100 << "%" << "\n" << endl;
}

void evaluateModel(const Ptr<cv::ml::StatModel> &model, const Mat &test_images, const Mat &test_labels,
                   const string &model_name) {
    Mat pre_out;
    cout << "Start " << model_name << " Prediction..." << endl;
    float ret = model->predict(test_images, pre_out);
    cout << model_name << " Prediction Finished. " << endl;

    // Calculate the accuracy.
    pre_out.convertTo(pre_out, CV_8UC1);
    Mat test_labels_converted;
    test_labels.convertTo(test_labels_converted, CV_8UC1);

    int equal_nums = 0;
    for (int i = 0; i < pre_out.rows; i++) {
        if (pre_out.at<uchar>(i, 0) == test_labels_converted.at<uchar>(i, 0)) {
            equal_nums++;
        }
    }
    float acc = float(equal_nums) / float(pre_out.rows);
    cout << model_name << " Prediction Accuracy on Testing Set: " << acc * 100 << "%" << "\n" << endl;
}

