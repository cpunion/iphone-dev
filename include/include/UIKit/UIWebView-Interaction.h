/*
 *     Generated by class-dump 3.1.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2006 by Steve Nygard.
 */

#import <UIKit/UIWebView.h>

@interface UIWebView (Interaction)
+ (id)_calloutViewForWebView:(id)fp8;	// IMP=0x3246a798
+ (id)_highlightView;	// IMP=0x3246a804
- (id)approximateNodeAtViewportLocation:(struct CGPoint *)fp8;	// IMP=0x3246b35c
- (void)attemptClick:(id)fp8;	// IMP=0x3246b194
- (void)calloutApproximateNode;	// IMP=0x3246b418
- (void)cancelInteraction;	// IMP=0x3246bee0
- (void)cancelInteractionWithCandidate;	// IMP=0x3246ad80
- (void)cancelInteractionWithImmediateDisplay:(BOOL)fp8;	// IMP=0x3246bf8c
- (void)clearInteractionTimer;	// IMP=0x3246a8f8
- (void)completeInteraction;	// IMP=0x3246be68
- (struct CGPoint)convertWindowPointToViewport:(struct CGPoint)fp8;	// IMP=0x3246aa40
- (void)deferInteraction;	// IMP=0x3246bf3c
- (BOOL)eventCanTriggerGestureScrolling:(struct __GSEvent *)fp8;	// IMP=0x3246c15c
- (void)forwardEventsToInteractionCandidate;	// IMP=0x3246ae04
- (void)forwardMouseDraggedToInteractionCandidate:(struct __GSEvent *)fp8;	// IMP=0x3246ade4
- (void)forwardMouseUpToInteractionCandidate:(struct __GSEvent *)fp8;	// IMP=0x3246adac
- (void)hideCalloutAndHighlight;	// IMP=0x3246bd9c
- (void)highlightApproximateNode;	// IMP=0x3246b7c0
- (void)highlightApproximateNodeAndDisplayCallout;	// IMP=0x3246bd38
- (void)interactionMouseDown:(struct __GSEvent *)fp8;	// IMP=0x3246ac9c
- (void)interactionMouseUp:(struct __GSEvent *)fp8;	// IMP=0x3246ac08
- (void)mouseDragged:(struct __GSEvent *)fp8;	// IMP=0x3246abb8
- (void)mouseUp:(struct __GSEvent *)fp8;	// IMP=0x3246ab38
- (void)performCandidateClick:(id)fp8;	// IMP=0x3246af14
- (void)performClick:(id)fp8;	// IMP=0x3246af8c
- (void)performInteractionSelector:(SEL)fp8 afterDelay:(double)fp12;	// IMP=0x3246a938
- (void)resetInteraction;	// IMP=0x3246be18
- (void)sendScrollWheelEvents;	// IMP=0x3246c058
- (void)webView:(id)fp8 didObserveDeferredContentChange:(int)fp12 forFrame:(id)fp16;	// IMP=0x3246b320
@end

