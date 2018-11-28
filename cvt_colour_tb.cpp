#include <hls_opencv.h>
#include "cvt_colour.hpp"
#include <iostream>

using namespace std;

int main (int argc, char** argv) {

IplImage* src;
IplImage* dst;
AXI_STREAM src_axi, dst_axi;
src = cvLoadImage("D:/Vivado_workspace/phase2/edge_detection/test.bmp");
if(src == NULL) {
	cout << "cannot read image" << endl;
}
dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);

IplImage2AXIvideo(src, src_axi);

image_filter(src_axi, dst_axi, src->height,src->width);

AXIvideo2IplImage(dst_axi, dst);

cvSaveImage("D:/Vivado_workspace/phase2/edge_detection/op.bmp", dst);
cvReleaseImage(&src);
cvReleaseImage(&dst);
}
