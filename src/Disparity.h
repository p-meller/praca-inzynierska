//
// Created by Piotr Meller on 14.11.18.
//

#ifndef PRACA_INZYNIERSKA_DISPARITY_H
#define PRACA_INZYNIERSKA_DISPARITY_H

#include <opencv2/core.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/stereo/stereo.hpp>

class Disparity
{
public:

	cv::Mat left_image, right_image, left_preview, right_preview;
    cv::Mat left_disp, right_disp, filtered_disp;

    cv::Mat vis_left, vis_right, vis_filter;

    //cv::Ptr<cv::StereoSGBM> left_matcher, right_matcher;
    cv::Ptr<cv::StereoSGBM> left_matcher;
    cv::Ptr<cv::StereoMatcher> right_matcher;

	float contrast;

	cv::Ptr<cv::ximgproc::DisparityWLSFilter> wls_filter;

    int minDisparity, numDisparity, blockSize, P1, P2, disp12MaxDiff, preFilterCap, uniquenessRatio,
        speckleWindowSize, speckleRange, mode;

	int filterType;

	double wlsLambda, wlsSigma, fbsSpatial, fbsLuma, fbsChroma, fbsLambda;

	void setFilterType(int filter_type)
	{
		filterType = filter_type;
	}

	void setWlsLambda(double wls_lambda)
	{
		wlsLambda = wls_lambda;
	}

	void setWlsSigma(double wls_sigma)
	{
		wlsSigma = wls_sigma;
	}

	void setFbsSpatial(double fbs_spatial)
	{
		fbsSpatial = fbs_spatial;
	}

	void setFbsLuma(double fbs_luma)
	{
		fbsLuma = fbs_luma;
	}

	void setFbsChroma(double fbs_chroma)
	{
		fbsChroma = fbs_chroma;
	}

	void setFbsLambda(double fbs_lambda)
	{
		fbsLambda = fbs_lambda;
	}

    void setMatcher()
    {
        left_matcher->setMinDisparity(minDisparity);
        left_matcher->setNumDisparities(numDisparity);
        left_matcher->setBlockSize(blockSize);
        left_matcher->setP1(P1);
        left_matcher->setP2(P2);
        left_matcher->setDisp12MaxDiff(disp12MaxDiff);
        left_matcher->setPreFilterCap(preFilterCap);
        left_matcher->setUniquenessRatio(uniquenessRatio);
        left_matcher->setSpeckleWindowSize(speckleWindowSize);
        left_matcher->setSpeckleRange(speckleRange);
        left_matcher->setMode(mode);

        right_matcher = cv::ximgproc::createRightMatcher(left_matcher);
    };

public:

    enum
    {
        MODE_SGBM,
        MODE_HH,
        MODE_SGBM_3WAY,
        MODE_HH4,
    };

    Disparity();
    ~Disparity();

    void initSGBM(int minDisparity = 0,
                  int maxDisparities = 16,
                  int blockSize = 3,
                  int P1 = 0,
                  int P2 = 0,
                  int disp12MaxDiff = 0,
                  int preFilterCap = 1,
                  int uniquenessRatio = 0,
                  int speckleWindowSize = 0,
                  int speckleRange = 0,
                  int mode = MODE_SGBM);

	void initImages(const cv::Mat& left, const cv::Mat& right);

    void SGBM();

	void filterDisparity();

	const cv::Mat& getDisparity(int color = -1);
	const cv::Mat& getDisparityFiltered(int color = -1);

    int getMinDisparity() const
    {
        return minDisparity;
    }
    void setMinDisparity(int minDisparity)
    {
        this->minDisparity = minDisparity;
    }
    int getNumDisparity() const
    {
        return  numDisparity;
    }
    void setNumDisparity(int numDisparities)
    {
        this->numDisparity = numDisparities;
    }
    int getBlockSize() const
    {
        return blockSize;
    }
    void setBlockSize(int blockSize)
    {
        this->blockSize = blockSize;
    }
    int getP1() const
    {
        return P1;
    }
    void setP1(int P1)
    {
        this->P1 = P1;
    }
    int getP2() const
    {
        return P2;
    }
    void setP2(int P2)
    {
        this->P2 = P2;
    }
    int getDisp12MaxDiff() const
    {
        return disp12MaxDiff;
    }
    void setDisp12MaxDiff(int disp12MaxDiff)
    {
        this->disp12MaxDiff = disp12MaxDiff;
    }
    int getPreFilterCap() const
    {
        return preFilterCap;
    }
    void setPreFilterCap(int preFilterCap)
    {
        this->preFilterCap = preFilterCap;
    }
    int getUniquenessRatio() const
    {
        return uniquenessRatio;
    }
    void setUniquenessRatio(int uniquenessRatio)
    {
        this->uniquenessRatio = uniquenessRatio;
    }
    int getSpeckleWindowSize() const
    {
        return speckleWindowSize;
    }
    void setSpeckleWindowSize(int speckleWindowSize)
    {
        this->speckleWindowSize = speckleWindowSize;
    }
    int getSpeckleRange() const
    {
        return speckleRange;
    }
    void setSpeckleRange(int speckleRange)
    {
        this->speckleRange = speckleRange;
    }
    int getMode() const
    {
        return mode;
    }
    void setMode(int mode)
    {
        this->mode = mode;
    }
	void setContrast(float contrast)
    {
		this->contrast = contrast;
    }

};

#endif //PRACA_INZYNIERSKA_DISPARITY_H

