#ifndef SUPPORT_CLASSES_H
#define SUPPORT_CLASSES_H

#include <ros/package.h>
#include <ros/ros.h>


static const std::string PACKAGE_NAME = "vfh_recognition";
static const std::string PACKAGE_PATH = ros::package::getPath(PACKAGE_NAME);
namespace RosParams
{
	namespace Names
	{
		static const std::string InputDataDirectory = "InputDataDirectory";
		static const std::string InputDataExtension = "InputDataExtension";
		static const std::string InputCloudTopicName = "InputCloudTopic";
		static const std::string RecognitionServiceName = "Recognition/ServiceName";
		static const std::string RecognitionHistogramSize = "Recognition/HistogramSize";
		static const std::string RecognitionSimilarityThreshold = "Recognition/SimilarityThreshold";
		static const std::string RecognitionNumNeighbors = "Recognition/NumberOfNeighbors";
		static const std::string RecognitionNormalEstimationRadius = "Recognition/NormalEstimationRadius";
		static const std::string SegmentationMaxIterations = "Segmentation/MaxIterations";
		static const std::string SegmentationDistanceThreshold = "Segmentation/DistanceThreshold";
		static const std::string SegmentationLeafSizeX = "Segmentation/LeafSize/X";
		static const std::string SegmentationLeafSizeY = "Segmentation/LeafSize/Y";
		static const std::string SegmentationLeafSizeZ = "Segmentation/LeafSize/Z";
		static const std::string SegmentationSpatialFilterMinX = "Segmentation/SpatialFilter/MinX";
		static const std::string SegmentationSpatialFilterMaxX = "Segmentation/SpatialFilter/MaxX";
		static const std::string SegmentationSpatialFilterMinY = "Segmentation/SpatialFilter/MinY";
		static const std::string SegmentationSpatialFilterMaxY = "Segmentation/SpatialFilter/MaxY";
		static const std::string SegmentationSpatialFilterMinZ = "Segmentation/SpatialFilter/MinZ";
		static const std::string SegmentationSpatialFilterMaxZ = "Segmentation/SpatialFilter/MaxZ";
		static const std::string SegmentationClusterConfigAcctPercnt = "Segmentation/ClusterConfiguration/AcceptablePercentage";
		static const std::string SegmentationClusterConfigSpatialTolerance = "Segmentation/ClusterConfiguration/Tolerance";
		static const std::string SegmentationClusterConfigMinSize = "Segmentation/ClusterConfiguration/MinSize";
		static const std::string SegmentationClusterConfigMaxSize = "Segmentation/ClusterConfiguration/MaxSize";
	};

	namespace Defaults
	{
		static const std::string InputDataDirectory = PACKAGE_PATH +  "/data";
		static const std::string InputDataExtension = ".pcd";
		static const std::string InputCloudTopicName = "/camera/depth_registered/points";
		static const std::string RecognitionServiceName = "/object_recognition";

		static const int RecognitionHistogramSize = 300;
		static const int RecognitionNumNeighbors = 1;
		static const double RecognitionSimilarityThreshold = 100.0f;
		static const double RecognitionNormalEstimationRadius = 0.03f;

		static const int SegmentationMaxIterations = 100;
		static const double SegmentationDistanceThreshold = 0.02f;
		static const double SegmentationLeafSizeX = 0.01f;
		static const double SegmentationLeafSizeY = 0.01f;
		static const double SegmentationLeafSizeZ = 0.01f;
		static const double SegmentationSpatialFilterMinX = -0.7f;
		static const double SegmentationSpatialFilterMaxX = 0.7f;
		static const double SegmentationSpatialFilterMinY = 10.0f;
		static const double SegmentationSpatialFilterMaxY = -10;
		static const double SegmentationSpatialFilterMinZ = 0.0f;
		static const double SegmentationSpatialFilterMaxZ = 2.0f;
		static const double SegmentationClusterConfigAcctPercnt = 0.30f;
		static const double SegmentationClusterConfigSpatialTolerance = 0.02; // meters
		static const int SegmentationClusterConfigMinSize = 100;
		static const int SegmentationClusterConfigMaxSize = 25000;
	};

	struct Values
	{
		Values()
		{

		}

		std::string InputDataDirectory;
		std::string InputDataExtension;
		std::string InputCloudTopicName;

		std::string RecognitionServiceName;
		int RecognitionHistogramSize;
		int RecognitionNumNeighbors;
		double RecognitionSimilarityThreshold;
		double RecognitionNormalEstimationRadius;

		int SegmentationMaxIterations;
		double SegmentationDistanceThreshold;
		double SegmentationLeafSizeX;
		double SegmentationLeafSizeY;
		double SegmentationLeafSizeZ;
		double SegmentationSpatialFilterMinX;
		double SegmentationSpatialFilterMaxX;
		double SegmentationSpatialFilterMinY;
		double SegmentationSpatialFilterMaxY;
		double SegmentationSpatialFilterMinZ;
		double SegmentationSpatialFilterMaxZ;
		double SegmentationClusterConfigAcctPercnt;
		double SegmentationClusterConfigSpatialTolerance; // meters
		int SegmentationClusterConfigMinSize;
		int SegmentationClusterConfigMaxSize;
	};

};

class RosParametersList
{
public:

	std::string NameSpace;
	RosParams::Values Vals;

public:

	RosParametersList()
	{
		loadParams();
	}

	~RosParametersList()
	{

	}

	void loadParams(ros::NodeHandle &nh,bool useRelativeNamespace = true)
	{
		using namespace RosParams;

		std::string paramScope;
		if(useRelativeNamespace)
		{
			paramScope = "";
		}
		else
		{
			paramScope = "/";
		}

		nh.param<std::string>(paramScope + Names::InputCloudTopicName,Vals.InputCloudTopicName,Defaults::InputCloudTopicName);
		nh.param<std::string>(paramScope + Names::InputDataDirectory,Vals.InputDataDirectory,Defaults::InputDataDirectory);
		nh.param<std::string>(paramScope + Names::InputDataExtension,Vals.InputDataExtension,Defaults::InputDataExtension);

		nh.param<std::string>(paramScope + Names::RecognitionServiceName,Vals.RecognitionServiceName,Defaults::RecognitionServiceName);
		nh.param<int>(paramScope + Names::RecognitionHistogramSize,Vals.RecognitionHistogramSize,Defaults::RecognitionHistogramSize);
		nh.param<int>(paramScope + Names::RecognitionNumNeighbors,Vals.RecognitionNumNeighbors,Defaults::RecognitionNumNeighbors);
		nh.param<double>(paramScope + Names::RecognitionSimilarityThreshold,Vals.RecognitionSimilarityThreshold,Defaults::RecognitionSimilarityThreshold);
		nh.param<double>(paramScope + Names::RecognitionNormalEstimationRadius,Vals.RecognitionNormalEstimationRadius,Defaults::RecognitionNormalEstimationRadius);

		nh.param<int>(paramScope + Names::SegmentationMaxIterations,Vals.SegmentationMaxIterations,Defaults::SegmentationMaxIterations);
		nh.param<double>(paramScope + Names::SegmentationDistanceThreshold,Vals.SegmentationDistanceThreshold,Defaults::SegmentationLeafSizeX);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeX,Vals.SegmentationLeafSizeX,Defaults::SegmentationMaxIterations);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeY,Vals.SegmentationLeafSizeY,Defaults::SegmentationLeafSizeY);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeZ,Vals.SegmentationLeafSizeZ,Defaults::SegmentationLeafSizeZ);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinX,Vals.SegmentationSpatialFilterMinX,Defaults::SegmentationSpatialFilterMinX);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxX,Vals.SegmentationSpatialFilterMaxX,Defaults::SegmentationSpatialFilterMaxX);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinY,Vals.SegmentationSpatialFilterMinY,Defaults::SegmentationSpatialFilterMinY);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxY,Vals.SegmentationSpatialFilterMaxY,Defaults::SegmentationSpatialFilterMaxY);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinZ,Vals.SegmentationSpatialFilterMinZ,Defaults::SegmentationSpatialFilterMinZ);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxZ,Vals.SegmentationSpatialFilterMinZ,Defaults::SegmentationSpatialFilterMinZ);
		nh.param<double>(paramScope + Names::SegmentationClusterConfigAcctPercnt,Vals.SegmentationClusterConfigAcctPercnt,Defaults::SegmentationClusterConfigAcctPercnt);
		nh.param<double>(paramScope + Names::SegmentationClusterConfigSpatialTolerance,Vals.SegmentationClusterConfigSpatialTolerance,
				Defaults::SegmentationClusterConfigSpatialTolerance);
		nh.param<int>(paramScope + Names::SegmentationClusterConfigMinSize,Vals.SegmentationClusterConfigMinSize,Defaults::SegmentationClusterConfigMinSize);
		nh.param<int>(paramScope + Names::SegmentationClusterConfigMaxSize,Vals.SegmentationClusterConfigMaxSize,Defaults::SegmentationClusterConfigMaxSize);
	}

	void loadParams(bool useRelativeNamespace = false)
	{
		using namespace RosParams;
		ros::NodeHandle nh;

		std::string paramScope;
		if(useRelativeNamespace)
		{
			paramScope = "";
		}
		else
		{
			paramScope = "/";
		}

		nh.param<std::string>(paramScope + Names::InputCloudTopicName,Vals.InputCloudTopicName,Defaults::InputCloudTopicName);
		nh.param<std::string>(paramScope + Names::InputDataDirectory,Vals.InputDataDirectory,Defaults::InputDataDirectory);
		nh.param<std::string>(paramScope + Names::InputDataExtension,Vals.InputDataExtension,Defaults::InputDataExtension);

		nh.param<std::string>(paramScope + Names::RecognitionServiceName,Vals.RecognitionServiceName,Defaults::RecognitionServiceName);
		nh.param<int>(paramScope + Names::RecognitionHistogramSize,Vals.RecognitionHistogramSize,Defaults::RecognitionHistogramSize);
		nh.param<int>(paramScope + Names::RecognitionNumNeighbors,Vals.RecognitionNumNeighbors,Defaults::RecognitionNumNeighbors);
		nh.param<double>(paramScope + Names::RecognitionSimilarityThreshold,Vals.RecognitionSimilarityThreshold,Defaults::RecognitionSimilarityThreshold);
		nh.param<double>(paramScope + Names::RecognitionNormalEstimationRadius,Vals.RecognitionNormalEstimationRadius,Defaults::RecognitionNormalEstimationRadius);

		nh.param<int>(paramScope + Names::SegmentationMaxIterations,Vals.SegmentationMaxIterations,Defaults::SegmentationMaxIterations);
		nh.param<double>(paramScope + Names::SegmentationDistanceThreshold,Vals.SegmentationDistanceThreshold,Defaults::SegmentationLeafSizeX);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeX,Vals.SegmentationLeafSizeX,Defaults::SegmentationMaxIterations);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeY,Vals.SegmentationLeafSizeY,Defaults::SegmentationLeafSizeY);
		nh.param<double>(paramScope + Names::SegmentationLeafSizeZ,Vals.SegmentationLeafSizeZ,Defaults::SegmentationLeafSizeZ);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinX,Vals.SegmentationSpatialFilterMinX,Defaults::SegmentationSpatialFilterMinX);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxX,Vals.SegmentationSpatialFilterMaxX,Defaults::SegmentationSpatialFilterMaxX);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinY,Vals.SegmentationSpatialFilterMinY,Defaults::SegmentationSpatialFilterMinY);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxY,Vals.SegmentationSpatialFilterMaxY,Defaults::SegmentationSpatialFilterMaxY);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMinZ,Vals.SegmentationSpatialFilterMinZ,Defaults::SegmentationSpatialFilterMinZ);
		nh.param<double>(paramScope + Names::SegmentationSpatialFilterMaxZ,Vals.SegmentationSpatialFilterMinZ,Defaults::SegmentationSpatialFilterMinZ);
		nh.param<double>(paramScope + Names::SegmentationClusterConfigAcctPercnt,Vals.SegmentationClusterConfigAcctPercnt,Defaults::SegmentationClusterConfigAcctPercnt);
		nh.param<double>(paramScope + Names::SegmentationClusterConfigSpatialTolerance,Vals.SegmentationClusterConfigSpatialTolerance,
				Defaults::SegmentationClusterConfigSpatialTolerance);
		nh.param<int>(paramScope + Names::SegmentationClusterConfigMinSize,Vals.SegmentationClusterConfigMinSize,Defaults::SegmentationClusterConfigMinSize);
		nh.param<int>(paramScope + Names::SegmentationClusterConfigMaxSize,Vals.SegmentationClusterConfigMaxSize,Defaults::SegmentationClusterConfigMaxSize);
	}
};

#endif
