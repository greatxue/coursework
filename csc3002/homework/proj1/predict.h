#ifndef PREDICT_H
#define PREDICT_H

#include "read_mnist.h"
#include <chrono> // necessary for timer in training

/* Function: readAndNormalizeImages(const string& images_path);
 * -----------------------------------------------------------
 * Reads image data from the specified file path and normalizes it.
 * Normalization typically involves scaling pixel values to a standard range,
 * which is essential for consistent processing and training in machine learning.
 *
 * Parameters:
 * images_path - The path to the file containing image data.
 *
 * Returns:
 * Mat - A matrix of normalized image data.
 */

Mat readAndNormalizeImages(const string& images_path);

/* Function: readLabels(const string& labels_path);
 * -----------------------------------------------
 * Reads label data from the specified file path.
 * Labels are typically integers representing different classes in a dataset.
 *
 * Parameters:
 * labels_path - The path to the file containing label data.
 *
 * Returns:
 * Mat - A matrix of label data.
 */

Mat readLabels(const string& labels_path);


/* Function: trainSVMModel(const Mat& train_images, const Mat& train_labels);
 * ------------------------------------------------------------------------
 * Trains a Support Vector Machine (SVM) model using the provided training images and labels.
 * SVM is a supervised machine learning algorithm used for classification and regression.
 *
 * Parameters:
 * train_images - The training images.
 * train_labels - The labels corresponding to the training images.
 *
 * Returns:
 * cv::Ptr<cv::ml::SVM> - A pointer to the trained SVM model.
 */

cv::Ptr<cv::ml::SVM> trainSVMModel(const Mat& train_images, const Mat& train_labels);

/* Function: trainDTreeModel(const Mat& train_images, const Mat& train_labels);
 * --------------------------------------------------------------------------------
 * Trains a Decision Tree (DTree) model using the provided training images and labels.
 * Decision Trees are a non-linear predictive model used for classification and regression.
 *
 * Parameters:
 * train_images - The training images.
 * train_labels - The labels corresponding to the training images.
 *
 * Returns:
 * cv::Ptr<cv::ml::DTrees> - A pointer to the trained Decision Tree model.
 */

cv::Ptr<cv::ml::DTrees> trainDTreeModel(const Mat& train_images, const Mat& train_labels);

/* Function: trainKNNModel(const Mat& train_images, const Mat& train_labels);
 * -------------------------------------------------------------------------
 * Trains a k-Nearest Neighbors (KNN) model using the provided training images and labels.
 * KNN is a simple, instance-based learning algorithm used in classification.
 *
 * Parameters:
 * train_images - The training images.
 * train_labels - The labels corresponding to the training images.
 *
 * Returns:
 * cv::Ptr<cv::ml::KNearest> - A pointer to the trained KNN model.
 */

cv::Ptr<cv::ml::KNearest> trainKNNModel(const Mat& train_images, const Mat& train_labels);

/* Function: trainANNModel(const Mat &train_images, const Mat &train_labels);
 * ---------------------------------------------------------------------------
 * Trains an Artificial Neural Network (ANN) model using the provided training images and labels.
 * ANNs are computational models inspired by the human brain, widely used in machine learning.
 *
 * Parameters:
 * train_images - The training images.
 * train_labels - The labels corresponding to the training images.
 *
 * Returns:
 * cv::Ptr<cv::ml::ANN_MLP> - A pointer to the trained ANN model.
 */

cv::Ptr<cv::ml::ANN_MLP> trainANNModel(const Mat &train_images, const Mat &train_labels);

/* Function: evaluateModel(const Ptr<cv::ml::StatModel>& model, const Mat &test_images,
 *                         const Mat &test_labels, const string &model_name);
 * ----------------------------------------------------------------------------------------------------------------
 * Evaluates the performance of a statistical model (SVM, DTree, KNN, etc.) on the test dataset.
 * It assesses how well the model performs on unseen data, using metrics like accuracy, precision, recall, etc.
 *
 * Parameters:
 * model - The model to be evaluated.
 * test_images - The test images.
 * test_labels - The labels corresponding to the test images.
 * model_name - The name of the model, used for identification in evaluation reports.
 */

void evaluateModel(const Ptr<cv::ml::StatModel>& model, const Mat &test_images,
                   const Mat &test_labels, const string &model_name);

/* Function: evaluateModelANN(const Ptr<cv::ml::StatModel> &model, const Mat &test_images,
 *                            const Mat &test_labels,const string &model_name);
 * -------------------------------------------------------------------------------------------------------------
 * Specifically evaluates the performance of an Artificial Neural Network (ANN) model on the test dataset.
 * Similar to 'evaluateModel', but potentially includes additional steps or metrics specific to ANN models.
 *
 * Parameters:
 * model - The ANN model to be evaluated.
 * test_images - The test images.
 * test_labels - The labels corresponding to the test images.
 * model_name - The name of the ANN model, used for identification in evaluation reports.
 */

void evaluateModelANN(const Ptr<cv::ml::StatModel> &model, const Mat &test_images,
                      const Mat &test_labels,const string &model_name);


#endif //PREDICT_H
