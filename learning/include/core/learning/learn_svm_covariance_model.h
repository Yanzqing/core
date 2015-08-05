/*
 * Cloud-based Object Recognition Engine (CORE)
 *
 */

#ifndef LEARN_SVM_COVARIANCE_MODEL_H
#define LEARN_SVM_COVARIANCE_MODEL_H

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fstream>
#include <vector>
#include <cerrno>
#include <core/console/print.h>
#include "svm.h"

int learnModel (double, const std::string);

#endif  // LEARN_SVM_COVARIANCE_MODEL_H
