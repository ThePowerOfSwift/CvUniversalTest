//
//  CameraViewController.h
//  CvUniversalTest
//
//  Created by Michael Kalinin on 23/10/14.
//  Copyright (c) 2014 Michael. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifdef __cplusplus
    #import <opencv2/highgui/ios.h>
    #import <opencv2/opencv.hpp>
#endif

#import "TestSuite/TestSuite.h"
#import "AnimatedPathView.h"
#import "DynamicResultView.h"

using namespace std;

@protocol CameraViewControllerDelegate <NSObject>

- (void)cameraViewControllerDidFinishedWithCompletion:(void (^)(void))completion;

@end


@interface CameraViewController : UIViewController

@property (weak, nonatomic) TestSuite* testSuite;

@property (weak, nonatomic) id<CameraViewControllerDelegate> delegate;

@property (nonatomic, strong) UIButton* undoButton;
@property (nonatomic, strong) UIButton* startButton;
@property (nonatomic, strong) UIButton* settingsButton;
@property (nonatomic, strong) UIButton* switchCameraButton;

@property (nonatomic, strong) UILabel* testNameLabel;

@property (nonatomic, strong) AnimatedPathView* animatedPathView;
@property (nonatomic, strong) DynamicResultView* dynamicResultView;

@property (nonatomic) CGSize frameSize;

#pragma mark - CvVideoCamera

@property (nonatomic, strong) CvVideoCamera* videoCamera;
@property (nonatomic) BOOL shouldProcessFrames;

- (void)initCamera;

- (cv::Mat&)currentFrame;
- (void)processCurrentFrame: (cv::Mat&)frame;

#pragma mark - UI

- (void)startButtonAction;
- (void)presentResultViewController;

- (void)setupUI;
- (void)addButtons: (NSArray *)buttons;

@end
