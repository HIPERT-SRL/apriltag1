#ifndef TAGDETECTOR_H
#define TAGDETECTOR_H

#include <vector>

#include "opencv2/opencv.hpp"

#include "apriltag1/TagDetection.h"
#include "apriltag1/TagFamily.h"
#include "apriltag1/FloatImage.h"

namespace AprilTags {

class TagDetector {
public:
	
	const TagFamily thisTagFamily;

	//! Constructor
  // note: TagFamily is instantiated here from TagCodes
	TagDetector(const TagCodes& tagCodes) : thisTagFamily(tagCodes) {}
	
	std::vector<TagDetection> extractTags(const cv::Mat& image);
	
};

} // namespace

#endif
