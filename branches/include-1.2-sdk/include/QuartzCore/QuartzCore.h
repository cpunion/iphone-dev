#ifndef QUARTZCORE_H
#define QUARTZCORE_H
#import <CoreFoundation/CoreFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/CAAnimation.h>
#import <QuartzCore/CAAnimationGroup.h>
#import <QuartzCore/CABasicAnimation.h>
#import <QuartzCore/CAContext.h>
#import <QuartzCore/CAContextImpl.h>
#import <QuartzCore/CAFilter.h>
#import <QuartzCore/CAKeyframeAnimation.h>
#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAPropertyAnimation.h>
#import <QuartzCore/CAScrollLayer.h>
#import <QuartzCore/CASlotProxy.h>
#import <QuartzCore/CASublayerEnumerator.h>
#import <QuartzCore/CATimingFunction.h>
#import <QuartzCore/CATransaction.h>
#import <QuartzCore/CATransform.h>
#import <QuartzCore/CATransition.h>
#import <QuartzCore/NSValue-CATransformAdditions.h>

int CAPurpleServerIsRunning();
void CAPurpleServerStart();

extern CFStringRef kCATransactionDisableActions;

#ifndef kCALayerLeftEdge
#define kCALayerLeftEdge 1
#define kCALayerRightEdge 2
#define kCALayerBottomEdge 4
#define kCALayerTopEdge 8
#endif


#endif
