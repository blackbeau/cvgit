#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
class PeopleDetect{

public:
	PeopleDetect()
	{
		hog.setSVMDetector(hog.getDefaultPeopleDetector());
	}
	void Detect(const Mat& src, vector<Rect>& found,
				Size maxsize,Size minsize){
		hog.detectMultiScale(src, found);
		vector<Rect> foundtemp;
		for (Rect r : found){
			if (maxsize.area() > r.area() && minsize.area() < r.area())
				foundtemp.push_back(r);
		}
		found = foundtemp;
	} 
private:
	HOGDescriptor hog;
};